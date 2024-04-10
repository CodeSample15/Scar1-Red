//initialize robot components here
#include "robot.h"

pros::Controller master = pros::Controller(pros::E_CONTROLLER_MASTER);

ez::Drive chassis = ez::Drive(
    {-LEFT_MOTOR_1_PORT, LEFT_MOTOR_2_PORT, -LEFT_MOTOR_3_PORT, LEFT_MOTOR_4_PORT},
    {-RIGHT_MOTOR_1_PORT, RIGHT_MOTOR_2_PORT, -RIGHT_MOTOR_3_PORT, RIGHT_MOTOR_4_PORT},
    INERTIAL_PORT,
    3.25, //wheel diam
    200, //rpm
    2.33 //gear ratio
);

pros::Motor RightSlapperMotor = pros::Motor(RIGHT_SLAPPER_MOTOR_PORT, true);
pros::Rotation RightSlapperSensor = pros::Rotation(RIGHT_SLAPPER_SENSOR_PORT);

pros::Motor IntakeMotor = pros::Motor(INTAKE_PORT);

pros::Imu imu = pros::Imu(INERTIAL_PORT);
pros::Imu static_imu = pros::Imu(STATIC_INERTIAL_PORT);

pros::ADIDigitalOut leftBackWings = pros::ADIDigitalOut(LEFT_BACK_WINGS_PORT);
pros::ADIDigitalOut rightBackWings = pros::ADIDigitalOut(RIGHT_BACK_WINGS_PORT);

pros::Motor climbMotor = pros::Motor(CLIMB_MOTOR_PORT);

pros::Motor LeftSlapperMotor = pros::Motor(LEFT_SLAPPER_MOTOR_PORT);
pros::Rotation LeftSlapperSensor = pros::Rotation(LEFT_SLAPPER_SENSOR_PORT);

