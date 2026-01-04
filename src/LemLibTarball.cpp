#include "lemlib-tarball/api.hpp"
#include "lemlib/logger/logger.hpp"

namespace lemlib_tarball {

Decoder::Decoder(const asset& tarball) {
    const std::string tarball_str = std::string(reinterpret_cast<const char*>(tarball.buf), tarball.size);

    std::size_t pos = 0;
    std::size_t delimiter_pos = 0;

    bool recording_path = false;
    std::string path_name = "";
    std::size_t path_content_start = 0;

    while ((delimiter_pos = tarball_str.find('\n', pos)) != std::string::npos) {
        std::string line = tarball_str.substr(pos, delimiter_pos - pos); // processed substring without \n

        if (line.starts_with("#") && recording_path) {
            std::size_t path_content_end = pos;
            asset path = {tarball.buf + path_content_start, path_content_end - path_content_start};

            // commit the path
            paths.push_back(path_name);
            assets.push_back(path);
            recording_path = false;
        }

        if (line.starts_with("#PATH-POINTS-START ")) {
            recording_path = true;
            path_name = line.substr(19);
            path_content_start = delimiter_pos + 1;
        }

        pos = delimiter_pos + 1;
    }

    if (recording_path) {
        std::string last_line = tarball_str.substr(pos);
        std::size_t path_content_end = last_line.starts_with("#") ? pos : tarball.size;
        asset path = {tarball.buf + path_content_start, path_content_end - path_content_start};

        // commit the path
        paths.push_back(path_name);
        assets.push_back(path);
    }
}

asset& Decoder::operator[](const char* path_name) { return get(path_name); }

asset& Decoder::get(const char* path_name) {
    for (size_t i = 0; i < paths.size(); i++) {
        if (paths[i] == path_name) { return assets[i]; }
    }

    lemlib::infoSink()->error("Path not found: {}", path_name);
    static asset empty = {nullptr, 0};
    return empty;
}

bool Decoder::has(const char* path_name) { return std::find(paths.begin(), paths.end(), path_name) != paths.end(); }

} // namespace lemlib_tarball