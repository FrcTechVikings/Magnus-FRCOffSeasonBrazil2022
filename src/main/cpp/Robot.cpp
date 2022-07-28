// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*                                      ┌────────────────┐
 *                                      │   TO DO LIST   │
 *                                      └────────────────┘ 
 *      ╥
 *      ╠⇒ Deixar a Shuffleboard bonita
 *      ║
 *      ╠⇒ Estratégias usadas para fazer as programações
 *      ║
 *      ╠⇒ Comentar o código e organizar um pouco mais, removendo as inutilidades e valores temporários.
 *      ╨
 */

#include "Robot.h"

void Robot::RobotInit() {

  // Adiciona as opções de autônomo
  m_chooser.SetDefaultOption(AutoConstants::ExitTarmacOption, AutoConstants::ExitTarmacOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacDelayOption, AutoConstants::ExitTarmacDelayOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacArmDownOption, AutoConstants::ExitTarmacArmDownOption);
  m_chooser.AddOption(AutoConstants::ExitTarmacArmDownDelayOption, AutoConstants::ExitTarmacArmDownDelayOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoOption, AutoConstants::OneCargoAutoOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoDelayOption, AutoConstants::OneCargoAutoDelayOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoArmDownOption, AutoConstants::OneCargoAutoArmDownOption);
  m_chooser.AddOption(AutoConstants::OneCargoAutoArmDownDelayOption, AutoConstants::OneCargoAutoArmDownDelayOption);

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
  if (m_autoSelected == AutoConstants::ExitTarmacOption){RobotCommands.ExitTarmacAuto(0.0, false);
  }else if(m_autoSelected == AutoConstants::ExitTarmacDelayOption){RobotCommands.ExitTarmacAuto(AutoConstants::ExitTarmac::delayExitTarmacAuto, false); // Estamos com delay de 7 segundos 
  }else if(m_autoSelected == AutoConstants::ExitTarmacArmDownOption){RobotCommands.ExitTarmacAuto(0.0, true);
  }else if(m_autoSelected == AutoConstants::ExitTarmacArmDownDelayOption){RobotCommands.ExitTarmacAuto(AutoConstants::ExitTarmac::delayExitTarmacAuto, true); // Estamos com delay de 7 segundos
  }else if(m_autoSelected == AutoConstants::OneCargoAutoOption){RobotCommands.OneCargoAuto(0.0, false);
  }else if(m_autoSelected == AutoConstants::OneCargoAutoDelayOption){RobotCommands.OneCargoAuto(AutoConstants::OneCargoAuto::delayOneCargoAuto, false); // Estamos com delay de 7 segundos
  }else if(m_autoSelected == AutoConstants::OneCargoAutoArmDownOption){RobotCommands.OneCargoAuto(0.0, true);
  }else if(m_autoSelected == AutoConstants::OneCargoAutoArmDownDelayOption){RobotCommands.OneCargoAuto(AutoConstants::OneCargoAuto::delayOneCargoAuto, true);}

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