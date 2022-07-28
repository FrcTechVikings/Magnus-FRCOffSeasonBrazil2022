#include "Arm.h"

void Arm::ArmLog(){

    // Valores do programador!

    frc::SmartDashboard::PutNumber("Limit switch de cima", topLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Limit switch de baixo", bottomLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("ArmDirection", armControlDirection);
    frc::SmartDashboard::PutNumber("OperatorStickValue", operatorStickValue);

}

void Arm::ArmFeed(bool lock, double percent){

    // Controle do braço pelo joystick -> DeadBand
    if(percent > ArmConstants::operatorArmDeadBand || percent < -1 * ArmConstants::operatorArmDeadBand){
        
        operatorStickValue = -1 * percent * lock * ArmConstants::armPercentConstrain;
        
    }else{
        
        //operatorStickValue = ArmConstants::armKeepUp * (!bottomLimitSwitch.Get()); // ---> Relaxar o motor de acordo com o microswitch
        operatorStickValue = ArmConstants::armKeepUp;
        
    }

    armMotor.Set(ControlMode::PercentOutput, operatorStickValue);

}

void Arm::ArmHolderFeed(bool lock, int direction){

    armHolder.Set(ControlMode::PercentOutput, ArmConstants::holderPercent * direction * lock * -1);

}

void Arm::ArmInit(){

    armMotor.SetNeutralMode(NeutralMode::Brake);
    armHolder.SetNeutralMode(NeutralMode::Brake);

    armMotor.ConfigOpenloopRamp(0.1);

    armMotor.SetSafetyEnabled(true);
    armMotor.SetExpiration(100_ms);

    armHolder.SetSafetyEnabled(true);
    armHolder.SetExpiration(100_ms);

    armControlDirection = 0;

}

void Arm::ArmSwitchUp(){

    armControlDirection = 1;

}

void Arm::ArmSwitchDown(){

    armControlDirection = -1;

}

void Arm::ArmPeriodic(bool lock, double JoyStickY){

    if(armControlDirection == 1){

        armMotor.Set(ControlMode::PercentOutput, ArmConstants::armPercentUp * lock);

        if(topLimitSwitch.Get()){armControlDirection = 0;}

    }else if(armControlDirection == -1){

        armMotor.Set(ControlMode::PercentOutput, ArmConstants::armPercentDown * lock);

        if(bottomLimitSwitch.Get()){armControlDirection = 0;}

    }else{

        ArmFeed(lock, JoyStickY);

    }

    if(lock == 0){armControlDirection = 0;}

}