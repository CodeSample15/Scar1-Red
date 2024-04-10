// define robot ports here
#pragma once

#include "api.h"
#include "EZ-Template/api.hpp"

#define RIGHT_MOTOR_1_PORT 4
#define RIGHT_MOTOR_2_PORT 3
#define RIGHT_MOTOR_3_PORT 2
#define RIGHT_MOTOR_4_PORT 1

#define INERTIAL_PORT 13
#define STATIC_INERTIAL_PORT 18

#define INTAKE_PORT 11

#define LEFT_MOTOR_1_PORT 10
#define LEFT_MOTOR_2_PORT 9
#define LEFT_MOTOR_3_PORT 8
#define LEFT_MOTOR_4_PORT 7

#define CLIMB_MOTOR_PORT 20

#define RIGHT_SLAPPER_MOTOR_PORT 5
#define RIGHT_SLAPPER_SENSOR_PORT 14

#define LEFT_SLAPPER_MOTOR_PORT 6
#define LEFT_SLAPPER_SENSOR_PORT 19

#define LEFT_BACK_WINGS_PORT 'B'
#define RIGHT_BACK_WINGS_PORT 'A'


extern pros::Controller master;

extern ez::Drive chassis;

extern pros::Motor IntakeMotor;

extern pros::Motor LeftSlapperMotor;
extern pros::Rotation LeftSlapperSensor;

extern pros::Motor climbMotor;

extern pros::Imu imu;
extern pros::Imu static_imu;

extern pros::ADIDigitalOut leftBackWings;
extern pros::ADIDigitalOut rightBackWings;