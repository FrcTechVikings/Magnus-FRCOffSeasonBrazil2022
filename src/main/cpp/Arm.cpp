// Make the f PID -> With what?
// Make the f one button click do -> Doing rn

#include "Arm.h"

void Arm::ArmLog(){}

void Arm::ArmFeed(bool lock, double percent){

    armMotor.Set(ControlMode::PercentOutput, lock * percent * operatorDirection * ArmConstants::armPercentMax);
}

void Arm::ArmKeepUp(double percent){

    armMotor.Set(ControlMode::PercentOutput, percent * operatorDirection);

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