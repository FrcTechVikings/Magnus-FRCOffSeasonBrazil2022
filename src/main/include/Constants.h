#pragma once

namespace AutoConstants{

    const std::string ExitTarmacOption = "Sair Tarmac";
    const std::string ExitTarmacDelayOption = "Sair Tarmac Com Delay";
    const std::string OneCargoAutoOption = "Uma Cargo";
    const std::string OneCargoAutoDelayOption = "Uma Cargo Com Delay";

    namespace OneCargoAuto{

        const double delayOneCargoAuto = 7.0; // Seconds ////////// Definir ainda!

        const double robotStartConfigTime = 0.5; // Seconds
        const double slightlyWalkForwardTime = 1.7; // Seconds
        const double intakeShootTime = 2.9; // Seconds
        const double exitingTarmacTime = 6.4; // Seconds

        const double slightlyWalkForwardDistance = 0.25; // Meters
        const double exitingTarmacDistance = 2.2; // Meters

    }

    namespace ExitTarmac{

        const double delayExitTarmacAuto = 7.0; // Seconds ////////// Definir ainda!

        const double robotStartConfigTime = 0.5; // Seconds
        const double exitingTarmacTime = 6.5; // Seconds

        const double exitingTarmacDistance = 2.0; // Meters

    }

}

namespace DriveTrainConstants {

    const double percentGain = 0.1;
    const double maxSpeedPercentConstrain = 1.0;
    const double minSpeedPercentConstrain = 0.2;
    const double maxRotationPercentConstrain = 0.85;
    const double minRotationPercentConstrain = 0.05;
    const double standardPercentSpeed = 0.6;
    const double standardPercentRotation = 0.45;

}

namespace RobotConstants {

    const double wheelLenghtMeters = 0.4787;
    const double wheelRadiusMeters = 0.0762;

}

namespace IntakeConstants {

    const double percentIntakeStandardCollect = 1.0;
    const double percentIntakeStandardRelease = 0.7;
    const double maxPercentIntakeRelease = 1.0;
    const double minPercentIntakeRelease = 0.5;
    const double percentGain = 0.1;

}

namespace ArmConstants {

    const double armPercentMax = 0.8;
    const double armKeepUp = 0.05;
    const double holderPercent = 0.6;
    const double operatorArmDeadBand = 0.5;
    const double armPercentUp = 0.9;
    const double armPercentDown = -0.8;

}

namespace MotorsConstants {

    const int rearLeftCIN = 0;
    const int frontLeftCIN = 1;
    const int rearRightCIN = 2;
    const int frontRightCIN = 3;
    const int armRedline = 4;
    const int intakeRedline = 5;
    const int armSnowBlower = 6;

}

namespace SensorsConstants {

    const int leftDriveEncoderAChannel = 0;
    const int leftDriveEncoderBChannel = 1;
    const int rightDriveEncoderAChannel = 2;
    const int rightDriveEncoderBChannel = 3;
    const int bottomMicroSwitchDIO = 4;
    const int topMicroSwitchDIO = 5;

}

namespace JoystickConstants {

    const double yStickBand = 0.1;
    const double zStickBand = 0.0;

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