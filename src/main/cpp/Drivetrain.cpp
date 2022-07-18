#include "Drivetrain.h"

void Drivetrain::DrivetrainLog(){

    frc::SmartDashboard::PutNumber("Nível de Velocidade", percentSpeed * 10);
    frc::SmartDashboard::PutNumber("ySpeed", ySpeed);
    frc::SmartDashboard::PutNumber("zRotation", zRotation);

    frc::SmartDashboard::PutNumber("Encoder esquerdo metros", leftDriveEncoder.GetDistance());
    frc::SmartDashboard::PutNumber("Encoder direito metros", rightDriveEconder.GetDistance());
    frc::SmartDashboard::PutNumber("Média dos encoders", (abs(rightDriveEconder.GetDistance() + leftDriveEncoder.GetDistance())/2));

}

void Drivetrain::Drive(double yStick, double zStick, bool lock){

    if(abs(yStick) >= JoystickConstants::yStickBand){
        yAxis = (0.5 * pow(yStick, 3) + (0.5 * yStick));
    }else{yAxis = 0;}

    if(abs(zStick) >= JoystickConstants::zStickBand){
        zAxis = (0.5 * pow(zStick, 3) + (0.5 * zStick));
    }else{zAxis = 0;}

    ySpeed = -1 * yAxis * direction * lock * percentSpeed;
    zRotation = zAxis * lock * percentRotation;

    m_robotDrive.ArcadeDrive(ySpeed, zRotation);
    
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

    rearLeftDriving.SetNeutralMode(NeutralMode::Brake);
    rearRightDriving.SetNeutralMode(NeutralMode::Brake);
    frontLeftDriving.SetNeutralMode(NeutralMode::Coast);
    frontRightDriving.SetNeutralMode(NeutralMode::Coast);

    motorsRight.SetInverted(true);

    leftDriveEncoder.SetDistancePerPulse(RobotConstants::wheelLenghtMeters/2048.0); // In meters
    rightDriveEconder.SetDistancePerPulse(RobotConstants::wheelLenghtMeters/2048.0); // In meters

    leftDriveEncoder.Reset();
    rightDriveEconder.Reset();

}

void Drivetrain::ResetEncoders(){

    leftDriveEncoder.Reset();
    rightDriveEconder.Reset();

}

double Drivetrain::GetDistanceEncoder(){

    return abs(leftDriveEncoder.GetDistance() + rightDriveEconder.GetDistance())/2;

}