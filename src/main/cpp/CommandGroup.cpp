#include "CommandGroup.h"

void CommandGroup::InitAutoCommands(){

    RobotDrivetrain.frontLeftDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.frontRightDriving.SetNeutralMode(NeutralMode::Brake);
    RobotDrivetrain.rearRightDriving.SetNeutralMode(NeutralMode::Brake);

    // Levanta o braço do robô no início do autônomo
    RobotArm.ArmSwitchUp();

    RobotDrivetrain.ResetEncoders();

    autoTimer.Reset();
    autoTimer.Start();

    executeOnce = 0;

}

void CommandGroup::OneCargoAuto(double delaySeconds, double dist, double tarmacExitDist){

    RobotArm.ArmPeriodic(1, 0.0);

    if(autoTimer.Get().value() <= AutoConstants::OneCargoAuto::robotStartConfigTime){

        // Levanta o braço e solta a trava de segurança
        RobotArm.armHolder.Set(ControlMode::PercentOutput, -0.3);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if(autoTimer.Get().value() <= AutoConstants::OneCargoAuto::robotStartConfigTime + delaySeconds){

        // Método de espera, caso delaySeconds seja maior que 0
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if (autoTimer.Get().value() <= AutoConstants::OneCargoAuto::slightlyWalkForwardTime + delaySeconds){
        
        // Movimentação suave para frente (a fim de se aproximar do hub)
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= dist){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.3, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else if (autoTimer.Get().value() <= AutoConstants::OneCargoAuto::intakeShootTime + delaySeconds){

        // Aciona o intake para a liberação da cargo inicial
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 1.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);
        RobotDrivetrain.ResetEncoders();

    }else if (autoTimer.Get().value() <= AutoConstants::OneCargoAuto::exitingTarmacTime + delaySeconds){

        // Sai do tarmac e abaixa o braço
        if(executeOnce == 0){

            RobotArm.ArmSwitchDown();
            executeOnce = 1;

        }

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= tarmacExitDist){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(-0.4, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else{
        
        // Espera o autônomo acabar
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }

}

void CommandGroup::ExitTarmacAuto(double delaySeconds){

    RobotArm.ArmPeriodic(1, 0.0);

    if(autoTimer.Get().value() <= AutoConstants::ExitTarmac::robotStartConfigTime){

        // Levanta o braço e solta a trava de segurança
        RobotArm.armHolder.Set(ControlMode::PercentOutput, -0.3);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if(autoTimer.Get().value() <= AutoConstants::ExitTarmac::robotStartConfigTime + delaySeconds){

        // Método de espera, caso delaySeconds seja maior que 0
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }else if(autoTimer.Get().value() <= AutoConstants::ExitTarmac::exitingTarmacTime + delaySeconds){

        // Sai do tarmac e abaixa o braço
        if(executeOnce == 0){

            RobotArm.ArmSwitchDown();
            executeOnce = 1;

        }

        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);

        if(RobotDrivetrain.GetDistanceEncoder() <= AutoConstants::ExitTarmac::exitingTarmacDistance){

            RobotDrivetrain.m_robotDrive.CurvatureDrive(-0.4, 0.0, true);

        }else{

            RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

        }

    }else{

        // Espera o autônomo acabar
        RobotArm.armHolder.Set(ControlMode::PercentOutput, 0.0);
        RobotIntake.intakeMotor.Set(ControlMode::PercentOutput, 0.0);
        RobotDrivetrain.m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    }

}

void CommandGroup::InitCommands(){

    // Inicializa todos os sistemas e reseta variáveis
    RobotDrivetrain.DrivetrainInit();
    RobotIntake.IntakeInit();
    RobotArm.ArmInit();

    frc::SmartDashboard::PutNumber("SairTarmac", 2.0);
    frc::SmartDashboard::PutNumber("Aproximar", 0.0);
    frc::SmartDashboard::PutNumber("Tempo", 0.0);

    safeLock = 1;

}

void CommandGroup::PeriodicCommands(){

    RobotDrivetrain.Drive(pilotStick.GetY(), pilotStick.GetZ(), safeLock);
    RobotArm.ArmPeriodic(safeLock, operatorStick.GetY());

}

void CommandGroup::PilotCommands(){

    // Comandos do Piloto

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRB)){RobotDrivetrain.ChangeSpeed(1, DriveTrainConstants::percentGain);}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLB)){RobotDrivetrain.ChangeSpeed(-1, DriveTrainConstants::percentGain);}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRT)){RobotDrivetrain.ChangeToMaxSpeed();}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLT)){RobotDrivetrain.ChangeToStandardSpeed();}
    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonY)){RobotDrivetrain.ChangeDirection();}

}

void CommandGroup::OperatorCommands(){

    // Comandos do Operador

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){safeLock = !safeLock;}
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonSTART)){RobotArm.armControlDirection = 0;}
    if(operatorStick.GetRawButton(JoystickConstants::buttonX)) {RobotIntake.IntakeFeed(safeLock, 1, RobotIntake.ReleasePercent);}
    else if(operatorStick.GetRawButton(JoystickConstants::buttonB)) {RobotIntake.IntakeFeed(safeLock, -1, IntakeConstants::percentIntakeCollect);}
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
    
    // Valores do programador!

    frc::SmartDashboard::PutNumber("Piloto JoyY", pilotStick.GetY());
    frc::SmartDashboard::PutNumber("Piloto JoyZ", pilotStick.GetZ());
    frc::SmartDashboard::PutNumber("Operador JoyY", operatorStick.GetY());

    frc::SmartDashboard::PutNumber("Delay Autônomo", AutoConstants::OneCargoAuto::delayOneCargoAuto);

    if(safeLock == 1){frc::SmartDashboard::PutBoolean("SafeLock", 1);}
    else{frc::SmartDashboard::PutBoolean("SafeLock", 0);}


    
}