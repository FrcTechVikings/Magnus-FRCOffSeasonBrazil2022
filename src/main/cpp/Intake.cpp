#include "Intake.h"

void Intake::IntakeLog(){}

void Intake::IntakeFeed(bool lock, double percent){

    intakeMotor.Set(ControlMode::PercentOutput, lock * percent);

}

void Intake::IntakeInit(){

    intakeMotor.SetNeutralMode(NeutralMode::Coast);

}