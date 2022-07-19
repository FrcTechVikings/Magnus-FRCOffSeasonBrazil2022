// Make the f PID
// Make the f one button click do

#include "Arm.h"

void Arm::ArmLog(){

    frc::SmartDashboard::PutBoolean("Braço está travado?", armIsHeld);

}

void Arm::ArmFeed(bool lock, double percent){

    armMotor.Set(ControlMode::PercentOutput, lock * percent * operatorDirection * ArmConstants::armPercent);
}

void Arm::ArmKeepUp(double percent){

    armMotor.Set(ControlMode::PercentOutput, percent * operatorDirection);

}

void Arm::ArmChangeDirection(){

    operatorDirection *= -1;

}

void Arm::ArmInit(){

    armMotor.SetNeutralMode(NeutralMode::Brake);
    armHolder.SetNeutralMode(NeutralMode::Coast);
    armTimer.Reset();
    armTimer.Start();

}

void Arm::ArmHoldState(){

    motorTranslationTime = armTimer.Get().value();
    armIsHeld = !armIsHeld;

}

void Arm::ArmPeriodicCheck(){

    if(armIsHeld){

        if(armTimer.Get().value() - motorTranslationTime <= ArmConstants::armTimeHoldSeconds){
            
            armHolder.Set(ControlMode::PercentOutput, ArmConstants::holdMotorPercent);
            
        }else{

            armHolder.Set(ControlMode::PercentOutput, 0.0);

        }

    }else{

        if(armTimer.Get().value() - motorTranslationTime <= ArmConstants::armTimeHoldSeconds){

            armHolder.Set(ControlMode::PercentOutput, ArmConstants::holdMotorPercent * -1);

        }else{

            armHolder.Set(ControlMode::PercentOutput, 0.0);

        }

    }

}