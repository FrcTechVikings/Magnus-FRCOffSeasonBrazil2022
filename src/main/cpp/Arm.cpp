// Make the f PID
// Make the f one button click do

#include "Arm.h"

void Arm::ArmLog(){}

void Arm::ArmFeed(bool lock, double percent){

    armMotor.Set(ControlMode::PercentOutput, lock * percent * operatorDirection);

}

void Arm::ArmKeepUp(double percent){

    armMotor.Set(ControlMode::PercentOutput, percent * operatorDirection);

}

void Arm::ArmChangeDirection(){

    operatorDirection *= -1;

}

void Arm::ArmInit(){

    armMotor.SetNeutralMode(NeutralMode::Brake);

}