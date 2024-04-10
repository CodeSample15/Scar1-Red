/*
  Author: Luke Crimi
  File: JAutonSelector.cpp
  Date Created: 1/30/2022
  
  Use this class to easily select autons in the preauton function
*/

#include <vector>
#include <cstring>
#include "jank-lib/AutonSelector.h"
#include "robot.h"

JAutonSelector::JAutonSelector() 
{
  JAutonSelector::selected = 0;
  JAutonSelector::numberOfAutons = 0;
}

JAutonSelector::JAutonSelector(int start)
{
  JAutonSelector::selected = start;
  JAutonSelector::numberOfAutons = 0;
}

JAutonSelector::~JAutonSelector() 
{
  //clear vectors
  JAutonSelector::autons.clear();
  JAutonSelector::descriptions.clear();
}

//return the selected auton
int JAutonSelector::getSelected() 
{
  return JAutonSelector::selected;
}

void JAutonSelector::add(std::string name, std::string description, std::string description2)
{
  JAutonSelector::numberOfAutons++;

  JAutonSelector::autons.push_back(name);

  std::vector<std::string> stringVector;
  stringVector.push_back(description);
  stringVector.push_back(description2);
  JAutonSelector::descriptions.push_back(stringVector);
}

//change the current selected auton and give haptic feedback to the driver
void JAutonSelector::iterate() 
{
  JAutonSelector::selected++;

  if(JAutonSelector::selected >= JAutonSelector::numberOfAutons)
    JAutonSelector::selected = 0;

  master.rumble(".");
}

//display the current auton on the remote screen
void JAutonSelector::display_autons() 
{
  master.clear();
  pros::delay(50);
  master.clear();
  pros::delay(50);

  if(numberOfAutons == 0) {
    master.print(0, 0, "NO AUTONS");
    pros::delay(50);
  }
  else {
    master.print(0, 0, "%s", JAutonSelector::autons[JAutonSelector::selected].c_str());
    pros::delay(50);
    master.print(1, 0, "%s", JAutonSelector::descriptions[JAutonSelector::selected][0].c_str());
    pros::delay(50);
    master.print(2, 0, "%s", JAutonSelector::descriptions[JAutonSelector::selected][1].c_str());
    pros::delay(50);
  }
}