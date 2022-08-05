#include "Intake.h"

void Intake::IntakeLog(){

    frc::SmartDashboard::PutNumber("Nível Intake", round(ReleasePercent * 10));

}

void Intake::IntakeFeed(bool lock, int direction, double velocity){

    intakeMotor.Set(ControlMode::PercentOutput, lock * velocity * direction);
    //intakeMotor.SetVoltage(units::volt_t(12.0) * lock * velocity * direction);

}

void Intake::IntakeInit(){

    intakeMotor.SetNeutralMode(NeutralMode::Coast);

    // Segurança do motor
    intakeMotor.SetSafetyEnabled(true);
    intakeMotor.SetExpiration(100_ms);

    intakeMotor.Set(ControlMode::PercentOutput, 0.0);

    ReleasePercent = IntakeConstants::percentIntakeStandardRelease;

}

void Intake::IntakeChangeSpeed(int proportion){

    ReleasePercent += gain*proportion;

    if(ReleasePercent > IntakeConstants::maxPercentIntakeRelease){ReleasePercent = IntakeConstants::maxPercentIntakeRelease;}
    else if(ReleasePercent < IntakeConstants::minPercentIntakeRelease){ReleasePercent = IntakeConstants::minPercentIntakeRelease;}

}