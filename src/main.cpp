#define TESTING_AUTON false //PLEASE PLEASE PLEASE PLEASE ALWAYS SET TO FALSE OUTSIDE OF THE LAB, GONNA LOOK SO STUPID IF YOU DONT

#include "main.h"
#include "robot.h"
#include "jank-lib/AutonSelector.h"

//autons
#include "autons/MatchAuton1.hpp"

#include "EZ-Template/api.hpp"
#include "okapi/api.hpp"

using namespace pros;

bool selectingAuton = false;
JAutonSelector selector;

void select_auton_thread() {
	if(selectingAuton)
		return; //no duplicate threads please

	selectingAuton = true;
	bool updateScreen = true;

	master.clear();
	delay(60);

	//Allow the user to select an auton
	while(selectingAuton) {
		if(updateScreen) {
			selector.display_autons(); //update screen
			updateScreen = false;
		}

		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
			selector.iterate();
			updateScreen = true;
		}

		delay(10);
  	}
}

void initialize() {
	//add all of the autons here
	//selector.add("AWP")
	//selector.add("Kill all", "humans")
	//selector.add("Launch", "Warheads")

	climbMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	//pid stuff
	chassis.pid_drive_constants_set(5, 0, 2);
	//chassis.slew_drive_constants_set(okapi::QLength(5.0), 40);
	chassis.pid_turn_constants_set(1, 0, 0);
}

void disabled() {}


void competition_initialize() {
	if(!selectingAuton) {
		//calibrate
		chassis.drive_imu_calibrate();

		Task t(select_auton_thread);
	}
}


void autonomous() {
	selectingAuton = false;

	switch(selector.getSelected()) 
	{
		case 0:
			//run auton
			break;
	}
}

bool leftBackWingDeployed = false;
bool rightBackWingDeployed = false;
void opcontrol() {

	if(TESTING_AUTON) {
		chassis.drive_imu_calibrate();
		matchAuton1();
	}

	chassis.drive_brake_set(E_MOTOR_BRAKE_COAST);

	while(!selectingAuton) {
		chassis.opcontrol_arcade_standard(ez::SPLIT);

		//intake
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			IntakeMotor.move(-127);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			IntakeMotor.move(127);
		else
			IntakeMotor.brake();

		//wing control
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
			leftBackWingDeployed = !leftBackWingDeployed;
			leftBackWings.set_value(leftBackWingDeployed);
		}
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
			rightBackWingDeployed = !rightBackWingDeployed;
			rightBackWings.set_value(rightBackWingDeployed); 
		}

		//slapper on left wing
		if(master.get_digital(E_CONTROLLER_DIGITAL_X))
			LeftSlapperMotor.move(110);
		else
			LeftSlapperMotor.brake();

		//climber
		if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
			climbMotor.move(-127);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			climbMotor.move(127);
		else
			climbMotor.brake();

		delay(ez::util::DELAY_TIME);
	}
}
