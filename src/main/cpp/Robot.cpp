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

void Robot::RobotInit() {

  m_chooser.SetDefaultOption(AutoConstants::DefaultOption, AutoConstants::DefaultOption);
  m_chooser.AddOption(AutoConstants::FirstOption, AutoConstants::FirstOption);
  m_chooser.AddOption(AutoConstants::SecondOption, AutoConstants::SecondOption);
  m_chooser.AddOption(AutoConstants::ThirdOption, AutoConstants::ThirdOption);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  RobotCommands.InitCommands();
  
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  m_autoSelected = m_chooser.GetSelected();
  RobotCommands.InitAutoCommands();

}

void Robot::AutonomousPeriodic() {

  if (m_autoSelected == AutoConstants::DefaultOption){

    RobotCommands.ExitTarmacAuto(0.0);
    
  }else if(m_autoSelected == AutoConstants::FirstOption){

    RobotCommands.ExitTarmacAuto(1.0); // Definir o delay
    
  }else if(m_autoSelected == AutoConstants::SecondOption){

    RobotCommands.OneCargoAuto(0.0);

  }else if(m_autoSelected == AutoConstants::ThirdOption){

    RobotCommands.OneCargoAuto(1.0); // Definir o delay

  }

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