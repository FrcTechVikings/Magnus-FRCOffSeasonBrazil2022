#pragma once

#include <frc/Joystick.h>
#include "Constants.h"

#include "Drivetrain.h"
#include "Intake.h"
#include "Arm.h"

class CommandGroup {

    public:

        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        Drivetrain RobotDrivetrain;
        Intake RobotIntake;
        Arm RobotArm;

        void InitCommands();
        void PeriodicCommands();
        void PilotCommands();
        void OperatorCommands();
        void Log();

    private:

        bool safeLock = 1;

};