// Make the f PID -> With what?
// Make the f one button click do -> Doing rn

#include "Arm.h"

void Arm::ArmLog(){

    frc::SmartDashboard::PutNumber("Limit switch de cima", topLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Limit switch de baixo", bottomLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Estado do Braço", armIsUp);
    frc::SmartDashboard::PutNumber("OperatorStickValue", operatorStickValue);

}

void Arm::ArmFeed(bool lock, double percent){

    if(percent > ArmConstants::operatorArmDeadBand || percent < -1 * ArmConstants::operatorArmDeadBand){
        
        operatorStickValue = -1 * operatorDirection * percent * lock * ArmConstants::armPercentMax;
        
    }else{
        
        operatorStickValue = ArmConstants::armKeepUp * operatorDirection * (!bottomLimitSwitch.Get());
        
    }

    armMotor.Set(ControlMode::PercentOutput, operatorStickValue);

}

void Arm::ArmChangeDirection(){

    operatorDirection *= -1;

}

void Arm::ArmHolderFeed(bool lock, int direction){

    armHolder.Set(ControlMode::PercentOutput, ArmConstants::holderPercent * direction * lock * -1);

}

void Arm::ArmInit(){

    armMotor.SetNeutralMode(NeutralMode::Brake);
    armHolder.SetNeutralMode(NeutralMode::Brake);

}

void Arm::ArmSwitchUp(){

    //if(armIsUp == false){armControlDirection = 1;}
    armControlDirection = 1;

}

void Arm::ArmSwitchDown(){

    //if(armIsUp == true){armControlDirection = -1;}
    armControlDirection = -1;

}

void Arm::ArmState(){

    if(topLimitSwitch.Get() == true && armIsUp == false){armIsUp = true;}
    else if(bottomLimitSwitch.Get() == true && armIsUp == true){armIsUp = false;}

}

void Arm::ArmPeriodic(bool lock, double JoyStickY){

    if(armControlDirection == 1){

        armMotor.Set(ControlMode::PercentOutput, ArmConstants::armPercentUp);

        if(topLimitSwitch.Get()){armControlDirection = 0;}

    }else if(armControlDirection == -1){

        armMotor.Set(ControlMode::PercentOutput, ArmConstants::armPercentDown);

        if(bottomLimitSwitch.Get()){armControlDirection = 0;}

    }else{

        ArmFeed(lock, JoyStickY);

    }

    ArmState();

}