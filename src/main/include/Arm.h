#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class Arm {

    public:

        WPI_VictorSPX armMotor = {MotorsConstants::armRedline};
        WPI_VictorSPX armHolder = {MotorsConstants::armSnowBlower};

        void ArmLog();
        void ArmFeed(bool lock, double percent);
        void ArmKeepUp(double percent);
        void ArmChangeDirection();
        void ArmHolderFeed(bool lock, int direction);
        void ArmInit();

    private:

        int operatorDirection = 1;

};