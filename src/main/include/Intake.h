#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class Intake {

    public:

        WPI_VictorSPX intakeMotor = {MotorsConstants::intakeRedline};

        void IntakeLog();
        void IntakeFeed(bool lock, double percent);
        void IntakeInit();

};