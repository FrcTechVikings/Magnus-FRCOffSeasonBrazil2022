#include "Intake.h"

void Intake::IntakeLog(){

    frc::SmartDashboard::PutNumber("Nível Intake", percent * 10);

}

void Intake::IntakeFeed(bool lock, int direction){

    intakeMotor.Set(ControlMode::PercentOutput, lock * percent * direction);

}

void Intake::IntakeInit(){

    intakeMotor.SetNeutralMode(NeutralMode::Coast);

}

void Intake::IntakeChangeSpeed(int proportion){

    percent += gain*proportion;

    if(percent > IntakeConstants::maxPercentIntake){

        percent = IntakeConstants::maxPercentIntake;

    }else if(percent < IntakeConstants::minPercentIntake){

        percent = IntakeConstants::minPercentIntake;

    }

}