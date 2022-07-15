// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*                                      ┌────────────────
 *                                      │   TO DO LIST   
 *                                      └──────────────── 
 *      ╥
 *      ╠⇒ Testar o método de drive, definir o melhor e afinar para o nosso robô.
 *      ║
 *      ╠⇒ Testar os encoders do chassi, verificar a aceitabilidade deles e testar o associado ao braço.
 *      ║
 *      ╠⇒ PID para o braço? Verificar o encoder na subida e descida automática -> Poderíamos ter um fim de curso... -> Tempo?
 *      ║
 *      ╠⇒ Fazer o autônomo, definindo uma estratégia.
 *      ║
 *      ╠⇒ Brake ou coast, decida-se!
 *      ║
 *      ╠⇒ Comentar o código e organizar um pouco mais, removendo as inutilidades e valores temporários.
 *      ║
 *      ╠⇒ Afinar a deadband do controle e os valores para a velocidade do bot.
 *      ║
 *      ╠⇒ Organizar os arquivos em pastas para melhor compreensão?
 *      ╨
 */

#include "Robot.h"
#include <fmt/core.h>

void Robot::RobotInit() {

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  RobotDrivetrain.DrivetrainInit();
  RobotIntake.IntakeInit();
  RobotArm.ArmInit();

}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  /*m_autoSelected = m_chooser.GetSelected();

  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    
  } else {
    
  }*/

  RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Brake);
  RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Brake);
  RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
  RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Brake);

  RobotDrivetrain.ResetEncoders();

}

void Robot::AutonomousPeriodic() {

  /*if (m_autoSelected == kAutoNameCustom) {
  
  } else {
  
  }*/

  if(RobotDrivetrain.GetDistanceEncoder() < 1.0){

    RobotDrivetrain.m_robotDrive.TankDrive(0.7, 0.7);

  }else{

    RobotDrivetrain.m_robotDrive.TankDrive(0.0, 0.0);

  }

}

void Robot::TeleopInit() {

  RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Coast);
  RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Coast);
  RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Coast);
  RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Coast);
  //RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Brake);
  //RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Brake);
  //RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
  //RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Brake);

}

void Robot::TeleopPeriodic() {

  // Drive

  RobotDrivetrain.Drive(pilotStick.GetY(), pilotStick.GetZ(), safeLock);

  // Pilot Stick

  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRB)){RobotDrivetrain.ChangeSpeed(1, DriveTrainConstants::percentGain);}
  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLB)){RobotDrivetrain.ChangeSpeed(-1, DriveTrainConstants::percentGain);}
  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRT)){RobotDrivetrain.ChangeToMaxSpeed();}
  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLT)){RobotDrivetrain.ChangeToStandardSpeed();}
  if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonY)){RobotDrivetrain.ChangeDirection();}

  // Operator Stick

  if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
  if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonSTART)){RobotArm.ArmChangeDirection();}
  if(operatorStick.GetRawButton(JoystickConstants::buttonX)) {RobotIntake.IntakeFeed(safeLock, IntakeConstants::percentIntake);}
  else if(operatorStick.GetRawButton(JoystickConstants::buttonB)) {RobotIntake.IntakeFeed(safeLock, -1 * IntakeConstants::percentIntake);}
  else {RobotIntake.IntakeFeed(safeLock, 0.0);}
  if(operatorStick.GetRawButton(JoystickConstants::buttonY)) {RobotArm.ArmFeed(safeLock, ArmConstants::armPercent);}
  else if(operatorStick.GetRawButton(JoystickConstants::buttonA)) {RobotArm.ArmFeed(safeLock, -1 * ArmConstants::armPercent);}
  else {RobotArm.ArmKeepUp(ArmConstants::armKeepUp);}

  // Log

  RobotDrivetrain.DrivetrainLog();
  RobotIntake.IntakeLog();
  RobotArm.ArmLog();
  frc::SmartDashboard::PutNumber("JoyY", pilotStick.GetY());
  frc::SmartDashboard::PutNumber("JoyZ", pilotStick.GetZ());

}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {

  throttle = pilotStick.GetRawAxis(1);
  turn = pilotStick.GetRawAxis(3);
  leftMtr = throttle + turn;
  rightMtr = throttle - turn;

  left = (leftMtr + skin(rightMtr)) * 0.8;
  right = (rightMtr + skin(leftMtr)) * 0.8;

  RobotDrivetrain.m_robotDrive.TankDrive(left, right, true);

  //RobotDrivetrain.m_robotDrive.TankDrive(pilotStick.GetRawAxis(1), pilotStick.GetRawAxis(4), true);

  //Controlar Arcade com um stick

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif