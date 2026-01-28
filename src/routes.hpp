#pragma once

#include "lemlib/api.hpp"
#include "lemlib_settings.h"
#include "intake.hpp"
#include "main.h"
#include "lemlib-tarball/api.hpp"


// skills route
ASSET(skills_txt);
inline lemlib_tarball::Decoder decoder(skills_txt);
inline void skills(){
    chassis.follow(decoder["Path0"], 15, 5000);
}