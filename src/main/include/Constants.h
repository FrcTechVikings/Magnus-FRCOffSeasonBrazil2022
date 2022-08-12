#pragma once

namespace AutoConstants{

    const std::string oneCargoAutoVariableDist = "Uma Cargo e distância variável";
    const std::string nothingAuto = "Nada";

    namespace OneCargoAuto{

        const double delayOneCargoAuto = 6.0; // Seconds ////////// Definir ainda!

        const double robotStartConfigTime = 0.2; // Seconds
        const double slightlyWalkForwardTime = 1.3; // Seconds
        const double intakeShootTime = 2.6; // Seconds
        const double exitingTarmacTime = 6.1; // Seconds

        const double slightlyWalkForwardDistance = 0.35; // Meters

        const double exitingTarmacDistance = 2.0; // Meters
        const double exitingTarmacDistanceMore = 2.2; //Meters
        const double exitingTarmacDistanceLess = 1.8; //Meters

    }

    namespace ExitTarmac{

        const double delayExitTarmacAuto = 7.0; // Seconds ////////// Definir ainda!

        const double robotStartConfigTime = 0.2; // Seconds
        const double exitingTarmacTime = 6.2; // Seconds

        const double exitingTarmacDistance = 1.8; // Meters

    }

}

namespace DriveTrainConstants {

    const double percentGain = 0.1; // Percentage
    const double maxSpeedPercentConstrain = 1.0; // Percentage
    const double minSpeedPercentConstrain = 0.2; // Percentage
    const double maxRotationPercentConstrain = 0.85; // Percentage
    const double minRotationPercentConstrain = 0.05; // Percentage
    const double standardPercentSpeed = 0.6; // Percentage
    const double standardPercentRotation = 0.45; // Percentage

}

namespace RobotConstants {

    const double wheelLenghtMeters = 0.4787; // Meters
    const double wheelRadiusMeters = 0.0762; // Meters

}

namespace IntakeConstants {

    const double percentIntakeCollect = 1.0; // Percentage
    const double percentIntakeStandardRelease = 0.7; // Percentage
    const double maxPercentIntakeRelease = 1.0; // Percentage
    const double minPercentIntakeRelease = 0.5; // Percentage
    const double percentGain = 0.1; // Percentage

}

namespace ArmConstants {

    const double armPercentConstrain = 0.8; // Percentage
    const double armKeepUp = 0.05; // Percentage
    const double holderPercent = 0.4; // Percentage
    const double operatorArmDeadBand = 0.5; // Percentage
    const double armPercentUp = 0.8; // Percentage
    const double armPercentDown = -0.7; // Percentage

}

namespace MotorsConstants {

    const int rearLeftCIN = 0; // ID
    const int frontLeftCIN = 1; // ID
    const int rearRightCIN = 2; // ID
    const int frontRightCIN = 3; // ID
    const int armRedline = 4; // ID
    const int intakeRedline = 5; // ID
    const int armSnowBlower = 6; // ID

}

namespace SensorsConstants {

    const int leftDriveEncoderAChannel = 0; // ID
    const int leftDriveEncoderBChannel = 1; // ID
    const int rightDriveEncoderAChannel = 2; // ID
    const int rightDriveEncoderBChannel = 3; // ID
    const int bottomMicroSwitchDIO = 4; // ID
    const int topMicroSwitchDIO = 5; // ID

}

namespace JoystickConstants {

    // Removido por agora

    //const double yStickBand = 0.1; // Percentage
    //const double zStickBand = 0.0; // Percentage

    const int buttonX = 1;
    const int buttonA = 2;
    const int buttonB = 3;
    const int buttonY = 4;
    const int buttonLB = 5;
    const int buttonRB = 6;
    const int buttonLT = 7;
    const int buttonRT = 8;
    const int buttonBACK = 9;
    const int buttonSTART = 10;

}