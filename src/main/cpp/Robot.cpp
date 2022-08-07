// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {

  // Adiciona as opções de autônomo
  m_chooser.SetDefaultOption(AutoConstants::OneCargoAutoVariableDist, AutoConstants::OneCargoAutoVariableDist);

  m_chooser.AddOption(AutoConstants::OneCargoAutoOption, AutoConstants::OneCargoAutoOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacDelayOption, AutoConstants::ExitTarmacDelayOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacOption, AutoConstants::ExitTarmacOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoDelayOption, AutoConstants::OneCargoAutoDelayOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoDelayWalkOption, AutoConstants::OneCargoAutoDelayWalkOption);

  m_chooser.AddOption(AutoConstants::OneCargoAutoWalkOption, AutoConstants::OneCargoAutoWalkOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoMoreOption, AutoConstants::OneCargoAutoMoreOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoLessOption, AutoConstants::OneCargoAutoLessOption);

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
  if (m_autoSelected == AutoConstants::ExitTarmacOption){RobotCommands.ExitTarmacAuto(0.0);
  }else if(m_autoSelected == AutoConstants::ExitTarmacDelayOption){RobotCommands.ExitTarmacAuto(AutoConstants::ExitTarmac::delayExitTarmacAuto); // Estamos com delay de 7 segundos 
  }else if(m_autoSelected == AutoConstants::OneCargoAutoDelayOption){RobotCommands.OneCargoAuto(AutoConstants::OneCargoAuto::delayOneCargoAuto, 0.0, AutoConstants::OneCargoAuto::exitingTarmacDistance); // Estamos com delay de 7 segundos
  }else if(m_autoSelected == AutoConstants::OneCargoAutoWalkOption){RobotCommands.OneCargoAuto(0.0, AutoConstants::OneCargoAuto::slightlyWalkForwardDistance, AutoConstants::OneCargoAuto::exitingTarmacDistance);
  }else if(m_autoSelected == AutoConstants::OneCargoAutoDelayWalkOption){RobotCommands.OneCargoAuto(AutoConstants::OneCargoAuto::delayOneCargoAuto, AutoConstants::OneCargoAuto::slightlyWalkForwardDistance, AutoConstants::OneCargoAuto::exitingTarmacDistance); // Estamos com delay de 7 segundos

  }else if(m_autoSelected == AutoConstants::OneCargoAutoOption){RobotCommands.OneCargoAuto(0.0, 0.0, AutoConstants::OneCargoAuto::exitingTarmacDistance);
  }else if(m_autoSelected == AutoConstants::OneCargoAutoMoreOption){RobotCommands.OneCargoAuto(0.0, 0.0, AutoConstants::OneCargoAuto::exitingTarmacDistanceMore);
  }else if(m_autoSelected == AutoConstants::OneCargoAutoLessOption){RobotCommands.OneCargoAuto(0.0, 0.0, AutoConstants::OneCargoAuto::exitingTarmacDistanceLess);
  
  }else if(m_autoSelected == AutoConstants::OneCargoAutoVariableDist){RobotCommands.OneCargoAuto(frc::SmartDashboard::GetNumber("Tempo", 0.0), frc::SmartDashboard::GetNumber("Aproximar", 0.5), frc::SmartDashboard::GetNumber("SairTarmac", 2.0));}

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