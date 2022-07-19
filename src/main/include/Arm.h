#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <frc/Timer.h>

class Arm {

    public:

        WPI_VictorSPX armMotor = {MotorsConstants::armRedline};
        WPI_VictorSPX armHolder = {MotorsConstants::armSnowBlower};

        void ArmLog();
        void ArmFeed(bool lock, double percent);
        void ArmKeepUp(double percent);
        void ArmChangeDirection();
        void ArmInit();
        void ArmHoldState();
        void ArmPeriodicCheck();

    private:

        frc::Timer armTimer;

        int operatorDirection = 1;
        double motorTranslationTime = 0.0;
        bool armIsHeld = true;

};