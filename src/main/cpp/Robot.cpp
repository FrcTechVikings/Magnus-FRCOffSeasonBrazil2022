// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*                                      ┌────────────────┐
 *                                      │   TO DO LIST   │
 *                                      └────────────────┘ 
 *      ╥
 *      ╠⇒ Calibrar o autônomo e afins
 *      ║
 *      ╠⇒ Deixar a Shuffleboard bonita
 *      ║
 *      ╠⇒ Estratégias usadas para fazer as programações
 *      ║
 *      ╠⇒ Comentar o código e organizar um pouco mais, removendo as inutilidades e valores temporários.
 *      ╨
 */

#include "Robot.h"

void Robot::RobotInit() {

  m_chooser.SetDefaultOption(AutoConstants::ExitTarmacOption, AutoConstants::ExitTarmacOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacDelayOption, AutoConstants::ExitTarmacDelayOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoOption, AutoConstants::OneCargoAutoOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoDelayOption, AutoConstants::OneCargoAutoDelayOption);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  RobotCommands.InitCommands();
  
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  m_autoSelected = m_chooser.GetSelected();
  RobotCommands.InitAutoCommands();

}

void Robot::AutonomousPeriodic() {

  if (m_autoSelected == AutoConstants::ExitTarmacOption){

    RobotCommands.ExitTarmacAuto(0.0);
    
  }else if(m_autoSelected == AutoConstants::ExitTarmacDelayOption){

    RobotCommands.ExitTarmacAuto(AutoConstants::ExitTarmac::delayExitTarmacAuto); // Estamos com delay de 7 segundos
    
  }else if(m_autoSelected == AutoConstants::OneCargoAutoOption){

    RobotCommands.OneCargoAuto(0.0);

  }else if(m_autoSelected == AutoConstants::OneCargoAutoDelayOption){

    RobotCommands.OneCargoAuto(AutoConstants::OneCargoAuto::delayOneCargoAuto); // Estamos com delay de 7 segundos

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

void Robot::TestInit() { }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif