#pragma once

#include "ctre/Phoenix.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Encoder.h>
#include "Constants.h"

class Drivetrain{

    public:

        WPI_VictorSPX rearLeftDriving = {MotorsConstants::rearLeftCIN};
        WPI_VictorSPX frontLeftDriving = {MotorsConstants::frontLeftCIN};
        WPI_VictorSPX rearRightDriving = {MotorsConstants::rearRightCIN};
        WPI_VictorSPX frontRightDriving = {MotorsConstants::frontRightCIN};

        frc::MotorControllerGroup motorsRight{frontRightDriving, rearRightDriving};
        frc::MotorControllerGroup motorsLeft{frontLeftDriving, rearLeftDriving};

        frc::DifferentialDrive m_robotDrive{motorsLeft, motorsRight};

        frc::Encoder leftDriveEncoder {SensorsConstants::leftDriveEncoderAChannel, SensorsConstants::leftDriveEncoderBChannel};
        frc::Encoder rightDriveEconder {SensorsConstants::rightDriveEncoderAChannel, SensorsConstants::rightDriveEncoderBChannel, true};

        void DrivetrainLog();
        void Drive(double yAxis, double zAxis, bool lock);
        void ChangeSpeed(int proportion, double gain);
        void ChangeToMaxSpeed();
        void ChangeToStandardSpeed();
        void ChangeDirection();
        void DrivetrainInit();
        void ResetEncoders();
        double GetDistanceEncoder();

    private:

        double ySpeed = 0.0;
        double zRotation = 0.0;
        double yAxis = 0.0;
        double zAxis = 0.0;
        int direction = 1;
        double percentSpeed = DriveTrainConstants::standardPercentSpeed;
        double percentRotation = DriveTrainConstants::standardPercentRotation;

};