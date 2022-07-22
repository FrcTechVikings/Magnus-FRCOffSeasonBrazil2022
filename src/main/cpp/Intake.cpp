#include "Intake.h"

void Intake::IntakeLog(){

    frc::SmartDashboard::PutNumber("Nível Intake", ReleasePercent * 10);

}

void Intake::IntakeFeed(bool lock, int direction, double velocity){

    intakeMotor.Set(ControlMode::PercentOutput, lock * velocity * direction);

}

void Intake::IntakeInit(){

    intakeMotor.SetNeutralMode(NeutralMode::Coast);

}

void Intake::IntakeChangeSpeed(int proportion){

    ReleasePercent += gain*proportion;

    if(ReleasePercent > IntakeConstants::maxPercentIntakeRelease){

        ReleasePercent = IntakeConstants::maxPercentIntakeRelease;

    }else if(ReleasePercent < IntakeConstants::minPercentIntakeRelease){

        ReleasePercent = IntakeConstants::minPercentIntakeRelease;

    }

}