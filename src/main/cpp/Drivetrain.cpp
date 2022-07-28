#include "Drivetrain.h"

void Drivetrain::DrivetrainLog(){

    // Valores do programador!

    frc::SmartDashboard::PutNumber("Nível de Velocidade", percentSpeed * 10);
    //frc::SmartDashboard::PutNumber("ySpeed", ySpeed);
    //frc::SmartDashboard::PutNumber("zRotation", zRotation);

    //frc::SmartDashboard::PutNumber("Encoder esquerdo metros", leftDriveEncoder.GetDistance());
    //frc::SmartDashboard::PutNumber("Encoder direito metros", rightDriveEconder.GetDistance());
    //frc::SmartDashboard::PutNumber("Média dos encoders", GetDistanceEncoder());

}

void Drivetrain::Drive(double yStick, double zStick, bool lock){

    // Está sem o DeadBand

    yAxis = (0.5 * pow(yStick, 3) + (0.5 * yStick));
    zAxis = zStick;

    ySpeed = -1 * yAxis * direction * lock * percentSpeed;
    zRotation = zAxis * lock * percentRotation;

    m_robotDrive.CurvatureDrive(ySpeed, zRotation, true);
    
}

void Drivetrain::ChangeSpeed(int proportion, double gain){

    percentRotation += gain * proportion; 
    percentSpeed += gain * proportion;

    if(percentSpeed > DriveTrainConstants::maxSpeedPercentConstrain){

        percentRotation = DriveTrainConstants::maxRotationPercentConstrain;
        percentSpeed = DriveTrainConstants::maxSpeedPercentConstrain;

    }else if(percentSpeed < DriveTrainConstants::minSpeedPercentConstrain){

        percentRotation = DriveTrainConstants::minRotationPercentConstrain;
        percentSpeed = DriveTrainConstants::minSpeedPercentConstrain;

    }

}

void Drivetrain::ChangeToMaxSpeed(){

    percentSpeed = DriveTrainConstants::maxSpeedPercentConstrain;
    percentRotation = DriveTrainConstants::maxRotationPercentConstrain;

}

void Drivetrain::ChangeToStandardSpeed(){

    percentSpeed = DriveTrainConstants::standardPercentSpeed;
    percentRotation = DriveTrainConstants::standardPercentRotation;

}

void Drivetrain::ChangeDirection(){

    direction *= -1;

}

void Drivetrain::DrivetrainInit(){

    // Metade dos motores no Brake e a outra metade em Coast

    rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
    rearRightDriving.SetNeutralMode(NeutralMode::Brake);
    frontLeftDriving.SetNeutralMode(NeutralMode::Coast);
    frontRightDriving.SetNeutralMode(NeutralMode::Coast);

    motorsRight.SetInverted(true);

    leftDriveEncoder.SetDistancePerPulse(RobotConstants::wheelLenghtMeters/2048.0); // In meters
    rightDriveEconder.SetDistancePerPulse(RobotConstants::wheelLenghtMeters/2048.0); // In meters

    // Segurança dos motores
    m_robotDrive.SetSafetyEnabled(true);
    m_robotDrive.SetExpiration(100_ms);

    m_robotDrive.CurvatureDrive(0.0, 0.0, true);

    leftDriveEncoder.Reset();
    rightDriveEconder.Reset();

    direction = 1;
    percentSpeed = DriveTrainConstants::standardPercentSpeed;
    percentRotation = DriveTrainConstants::standardPercentRotation;

}

void Drivetrain::ResetEncoders(){

    leftDriveEncoder.Reset();
    rightDriveEconder.Reset();

}

double Drivetrain::GetDistanceEncoder(){

    double left = leftDriveEncoder.GetDistance();
    double right = rightDriveEconder.GetDistance();

    if(left < 0) left *= -1;
    if(right < 0) right *= -1;

    return ((left + right)/2);

}