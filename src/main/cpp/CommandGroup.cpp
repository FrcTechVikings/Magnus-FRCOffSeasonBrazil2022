#include "CommandGroup.h"

void CommandGroup::InitCommands(){

    RobotDrivetrain.DrivetrainInit();
    RobotIntake.IntakeInit();
    RobotArm.ArmInit();

}

void CommandGroup::PeriodicCommands(){

    RobotDrivetrain.Drive(pilotStick.GetY(), pilotStick.GetZ(), safeLock);
    RobotArm.ArmPeriodic(safeLock, operatorStick.GetY());

}

void CommandGroup::PilotCommands(){

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRB)){RobotDrivetrain.ChangeSpeed(1, DriveTrainConstants::percentGain);}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLB)){RobotDrivetrain.ChangeSpeed(-1, DriveTrainConstants::percentGain);}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRT)){RobotDrivetrain.ChangeToMaxSpeed();}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLT)){RobotDrivetrain.ChangeToStandardSpeed();}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonY)){RobotDrivetrain.ChangeDirection();}

}

void CommandGroup::OperatorCommands(){

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonSTART)){RobotArm.ArmChangeDirection();}
    if(operatorStick.GetRawButton(JoystickConstants::buttonX)) {RobotIntake.IntakeFeed(safeLock, 1);}
    else if(operatorStick.GetRawButton(JoystickConstants::buttonB)) {RobotIntake.IntakeFeed(safeLock, -1);}
    else {RobotIntake.IntakeFeed(safeLock, 0.0);}
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonRB)){RobotIntake.IntakeChangeSpeed(1);}
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonLB)){RobotIntake.IntakeChangeSpeed(-1);}
    if(operatorStick.GetRawButton(JoystickConstants::buttonRT)){RobotArm.ArmHolderFeed(safeLock, 1);}
    else if (operatorStick.GetRawButton(JoystickConstants::buttonLT)){RobotArm.ArmHolderFeed(safeLock, -1);}
    else {RobotArm.ArmHolderFeed(0, 0);}
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonY)){RobotArm.ArmSwitchUp();}
    else if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonA)){RobotArm.ArmSwitchDown();}

}

void CommandGroup::Log(){

    RobotDrivetrain.DrivetrainLog();
    RobotIntake.IntakeLog();
    RobotArm.ArmLog();
    
    frc::SmartDashboard::PutNumber("Piloto JoyY", pilotStick.GetY());
    frc::SmartDashboard::PutNumber("Piloto JoyZ", pilotStick.GetZ());
    frc::SmartDashboard::PutNumber("Operador JoyY", operatorStick.GetY());
    frc::SmartDashboard::PutNumber("SafeLock", safeLock);
    
}