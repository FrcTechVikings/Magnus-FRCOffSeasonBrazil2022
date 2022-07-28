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

        // Declaração dos encoders do Drivetrain
        frc::Encoder leftDriveEncoder {SensorsConstants::leftDriveEncoderAChannel, SensorsConstants::leftDriveEncoderBChannel};
        frc::Encoder rightDriveEconder {SensorsConstants::rightDriveEncoderAChannel, SensorsConstants::rightDriveEncoderBChannel, true};

        void DrivetrainLog(); // Registro de valores do Drivetrain
        void Drive(double yAxis, double zAxis, bool lock); // Método de Drive do robô. Ps: Curvature/Cheesy drive
        void ChangeSpeed(int proportion, double gain); // Modifica a porcentagem de uso dos motores do Drivetrain
        void ChangeToMaxSpeed(); // Altera para o uso máximo estabelecido do Drivetrain
        void ChangeToStandardSpeed(); // Altera para o uso padrão estabelecido do Drivetrain
        void ChangeDirection(); // Altera a direção dos motores do Drivetrain
        void DrivetrainInit(); // Inicializa o Drivetrain
        void ResetEncoders(); // Reseta os encoders
        double GetDistanceEncoder(); // Retorna a média da distância lida pelos encoders -> Movimentação linear

    private:

        double ySpeed = 0.0;
        double zRotation = 0.0;
        double yAxis = 0.0;
        double zAxis = 0.0;
        int direction = 1;
        double percentSpeed = DriveTrainConstants::standardPercentSpeed;
        double percentRotation = DriveTrainConstants::standardPercentRotation;

};