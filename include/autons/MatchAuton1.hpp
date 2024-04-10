#include "api.h"
#include "EZ-Template/api.hpp"
#include "robot.h"

inline void matchAuton1() 
{
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);

    chassis.pid_drive_set(15, 110, false);
    chassis.pid_wait();

    chassis.pid_drive_set(-15, 110, false);
    chassis.pid_wait();
}