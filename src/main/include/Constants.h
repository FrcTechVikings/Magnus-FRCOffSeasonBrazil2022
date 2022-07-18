#pragma once

namespace DriveTrainConstants {

    const double percentGain = 0.1;
    const double maxSpeedPercentConstrain = 1.0;
    const double minSpeedPercentConstrain = 0.4;
    const double maxRotationPercentConstrain = 1.05;
    const double minRotationPercentConstrain = 0.45;
    const double standardPercentSpeed = 0.7;
    const double standardPercentRotation = 0.75;

}

namespace RobotConstants {

    const double wheelLenghtMeters = 0.4787;
    const double wheelRadiusMeters = 0.0762;

}

namespace IntakeConstants {

    const double percentIntake = 1.0;

}

namespace ArmConstants {

    const double armPercent = 1.0;
    const double armKeepUp = 0.05;

}

namespace MotorsConstants {

    const int rearLeftCIN = 0;
    const int frontLeftCIN = 1;
    const int rearRightCIN = 2;
    const int frontRightCIN = 3;
    const int armRedline = 4;
    const int intakeRedline = 5;

}

namespace SensorsConstants {

    const int leftDriveEncoderAChannel = 0;
    const int leftDriveEncoderBChannel = 1;
    const int rightDriveEncoderAChannel = 2;
    const int rightDriveEncoderBChannel = 3;

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
    const int AxisY = 1; // Left joystick up and down
    const int AxisX = 2; // Left joystick left and right
    const int AxisZ = 3; // Right joystick left and right
    const int OtherAxis = 4; // Right joystick up and down

}