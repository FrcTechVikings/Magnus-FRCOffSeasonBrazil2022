#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class Arm {

    public:

        WPI_VictorSPX armMotor = {MotorsConstants::armRedline};

        void ArmLog();
        void ArmFeed(bool lock, double percent);
        void ArmKeepUp(double percent);
        void ArmChangeDirection();
        void ArmInit();

    private:

        int operatorDirection = 1;

};