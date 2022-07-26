// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*                                      ┌────────────────┐
 *                                      │   TO DO LIST   │
 *                                      └────────────────┘ 
 *      ╥
 *      ╠⇒ Fazer o autônomo, definindo uma estratégia.
 *      ║
 *      ╠⇒ Comentar o código e organizar um pouco mais, removendo as inutilidades e valores temporários.
 *      ╨
 */

#include "Robot.h"
#include <fmt/core.h>

void Robot::RobotInit() {

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  RobotCommands.InitCommands();
  
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  /*m_autoSelected = m_chooser.GetSelected();

  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    
  } else {
    
  }*/

  RobotCommands.RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Brake);
  RobotCommands.RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Brake);
  RobotCommands.RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
  RobotCommands.RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Brake);

  RobotCommands.RobotDrivetrain.ResetEncoders();

}

void Robot::AutonomousPeriodic() {

  /*if (m_autoSelected == kAutoNameCustom) {
  
  } else {
  
  }*/

  if(RobotCommands.RobotDrivetrain.GetDistanceEncoder() < 2.0){

    RobotCommands.RobotDrivetrain.m_robotDrive.TankDrive(0.5, 0.5);

  }else{

    RobotCommands.RobotDrivetrain.m_robotDrive.TankDrive(0, 0);

  }

  RobotCommands.RobotDrivetrain.DrivetrainLog();

}

void Robot::TeleopInit() {

  RobotCommands.InitCommands();

}

void Robot::TeleopPeriodic() {

  RobotCommands.PeriodicCommands();

  RobotCommands.PilotCommands();

  RobotCommands.OperatorCommands();

  RobotCommands.Log();

}

void Robot::DisabledInit() {

  RobotCommands.InitCommands();

}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif