#include "CommandGroup.h"

void CommandGroup::InitAutoCommands(){

    RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Brake);

    RobotArm.ArmSwitchUp(); // CUIDADO

    RobotDrivetrain.ResetEncoders();

    autoTimer.Reset();
    autoTimer.Start();

}

void CommandGroup::OneCargoAuto(double delaySeconds){

    RobotArm.ArmPeriodic(1, 0.0);

    if(autoTimer.Get().value() <= 0.5 + delaySeconds){

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.5);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if (autoTimer.Get().value() <= 1.7 + delaySeconds){
        
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= 0.25){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.3, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else if (autoTimer.Get().value() <= 2.9 + delaySeconds){

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 1.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        RobotDrivetrain.ResetEncoders();

    }else if (autoTimer.Get().value() <= 6.4 + delaySeconds){

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= 2.2){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(-0.4, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else{

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }

    Log();

}

void CommandGroup::ExitTarmacAuto(double delaySeconds){

    RobotArm.ArmPeriodic(1, 0.0);

    if(autoTimer.Get().value() <= 0.5 + delaySeconds){

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.5);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if(autoTimer.Get().value() <= 6.5 + delaySeconds){

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= 2.0){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(-0.4, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else{

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }

}

void CommandGroup::InitCommands(){

    RobotDrivetrain.DrivetrainInit();
    RobotIntake.IntakeInit();
    RobotArm.ArmInit();

    safeLock = 1;

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
    if(operatorStick.GetRawButton(JoystickConstants::buttonX)) {RobotIntake.IntakeFeed(safeLock, 1, RobotIntake.ReleasePercent);}
    else if(operatorStick.GetRawButton(JoystickConstants::buttonB)) {RobotIntake.IntakeFeed(safeLock, -1, IntakeConstants::percentIntakeStandardCollect);}
    else {RobotIntake.IntakeFeed(safeLock, 0.0, 0.0);}
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