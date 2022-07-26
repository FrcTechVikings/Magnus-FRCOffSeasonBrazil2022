#include "Arm.h"

void Arm::ArmLog(){

    frc::SmartDashboard::PutNumber("Limit switch de cima", topLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Limit switch de baixo", bottomLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Estado do Braço", armIsUp);
    frc::SmartDashboard::PutNumber("OperatorStickValue", operatorStickValue);

}

void Arm::ArmFeed(bool lock, double percent){

    if(percent > ArmConstants::operatorArmDeadBand || percent < -1 * ArmConstants::operatorArmDeadBand){
        
        operatorStickValue = -1 * percent * lock * ArmConstants::armPercentMax;
        
    }else{
        
        operatorStickValue = ArmConstants::armKeepUp * (!bottomLimitSwitch.Get());
        
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

    armMotor.Set(ControlMode::PercentOutput, 0.0);
    armHolder.Set(ControlMode::PercentOutput, 0.0);

    armControlDirection = 0;

}

void Arm::ArmSwitchUp(){

    armControlDirection = 1;

}

void Arm::ArmSwitchDown(){

    armControlDirection = -1;

}

void Arm::ArmState(){

    if(topLimitSwitch.Get() == true && armIsUp == false){armIsUp = true;}
    else if(bottomLimitSwitch.Get() == true && armIsUp == true){armIsUp = false;}

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

    ArmState();

}