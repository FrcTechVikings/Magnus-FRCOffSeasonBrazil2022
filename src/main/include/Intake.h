#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class Intake {

    public:

        WPI_VictorSPX intakeMotor = {MotorsConstants::intakeRedline};

        double ReleasePercent = IntakeConstants::percentIntakeStandardRelease;

        void IntakeLog();
        void IntakeFeed(bool lock, int direction, double velocity);
        void IntakeInit();
        void IntakeChangeSpeed(int proportion);
    
    private:

        double gain = IntakeConstants::percentGain;

};