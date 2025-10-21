#include "main.h"


pros::MotorGroup left_motors({3, 4});        // left motors normal
pros::MotorGroup right_motors({-1, -13}); // reversed

pros::Optical optical_sensor(6);

void detect_color() {
    optical_sensor.set_led_pwm(100); // Turn on internal LED for lighting

    while (true) {
        double hue = optical_sensor.get_hue(); 

        if (hue < 30 || hue > 330) {
            std::cout << "Detected: RED" << std::endl;
        }
        else if (hue > 200 && hue < 260) {
            std::cout << "Detected: BLUE" << std::endl;
        }
        else {
            std::cout << "No clear color detected (Hue: " << hue << ")" << std::endl;
        }

        pros::delay(500); // Wait half a second between readings
    }
}


void move_forward(int distance_ms){
    left_motors.move_velocity(100);
    right_motors.move_velocity(100);
    pros::delay(distance_ms);

    left_motors.move_velocity(0);
    right_motors.move_velocity(0);
    pros::delay(100);
}

void move_backward(int distance_ms){
    left_motors.move_velocity(-100);
    right_motors.move_velocity(-100);
    pros::delay(distance_ms);

    left_motors.move_velocity(0);
    right_motors.move_velocity(0);
    pros::delay(100);
}

void turn_right(){
    left_motors.move_velocity(100);
    right_motors.move_velocity(-100);
    pros::delay(1000);

    left_motors.move_velocity(0);
    right_motors.move_velocity(0);
    pros::delay(100);
}

void route() {
    for (int i = 0; i < 4; i++){
        move_forward(1000);
        turn_right();
        pros::delay(10);
    }
}

