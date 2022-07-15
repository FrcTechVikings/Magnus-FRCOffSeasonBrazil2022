// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include "Constants.h"
#include <string>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>

#include<frc/PowerDistribution.h>

#include "Drivetrain.h"
#include "Intake.h"
#include "Arm.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

  // Temp

  double skin(double v){

    if (v > 1.0){
      return -((v - 1.0) * gain);
    }else if (v < -1.0){
      return -((v + 1.0) * gain);
    }
  return 0;

  }

 private:

  /*** Definições ***/

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::Joystick pilotStick {0};
  frc::Joystick operatorStick {1};

  //frc::PowerDistribution PDP{0, frc::PowerDistribution::ModuleType::kCTRE};

  Drivetrain RobotDrivetrain;
  Intake RobotIntake;
  Arm RobotArm;

  //Variables

  bool safeLock = true;

  //Temp

  double throttle = 0.0;
  double turn = 0.0;
  double leftMtr = 0.0;
  double rightMtr = 0.0;
  double gain = 1.0;
  double left = 0.0;
  double right = 0.0;
  
};