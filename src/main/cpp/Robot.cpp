// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//TODO: Organizar melhor a localização do autônomo do robô -> Já sei, utilizar o mesmo CommandGroup, separando as funções em autônomo e teleop, criando um arquivo para cada

#include "Robot.h"

void Robot::RobotInit() {

  // Adiciona as opções do modo autônomo
  m_chooser.SetDefaultOption(AutoConstants::oneCargoAutoVariableDist, AutoConstants::oneCargoAutoVariableDist);
  m_chooser.AddOption(AutoConstants::nothingAuto, AutoConstants::nothingAuto);

  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  // Inicializa o robô
  RobotCommands.InitCommands();
  
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  m_autoSelected = m_chooser.GetSelected();

  // Inicializa o autônomo do robô
  RobotCommands.InitAutoCommands();

}

void Robot::AutonomousPeriodic() {

  // Executa o autônomo relacionado ao valor escolhido na driver station
  if(m_autoSelected == AutoConstants::oneCargoAutoVariableDist){RobotCommands.OneCargoAuto(frc::SmartDashboard::GetNumber("Tempo", 0.0), frc::SmartDashboard::GetNumber("Aproximar", 0.5), frc::SmartDashboard::GetNumber("SairTarmac", 2.0));}

}

void Robot::TeleopInit() {

  // Inicializa o robô
  RobotCommands.InitCommands();

}

void Robot::TeleopPeriodic() {

  // Executa os diversos tipos de comandos do robô
  RobotCommands.PeriodicCommands();
  RobotCommands.PilotCommands();
  RobotCommands.OperatorCommands();
  RobotCommands.Log();

}

void Robot::DisabledInit() {

  // Esse comando é executado aqui para resetar as variáveis do robô
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