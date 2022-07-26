#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <frc/DigitalInput.h>
#include <string.h>

class Arm {

    public:

        WPI_VictorSPX armMotor = {MotorsConstants::armRedline};
        WPI_VictorSPX armHolder = {MotorsConstants::armSnowBlower};

        frc::DigitalInput topLimitSwitch {SensorsConstants::topMicroSwitchDIO};
        frc::DigitalInput bottomLimitSwitch {SensorsConstants::bottomMicroSwitchDIO};

        bool armIsUp = true;

        void ArmLog();
        void ArmFeed(bool lock, double percent);
        void ArmHolderFeed(bool lock, int direction);
        void ArmSwitchUp();
        void ArmSwitchDown();
        void ArmState();
        void ArmInit();
        void ArmPeriodic(bool lock, double joyStickY);

    private:

        double operatorStickValue = 0.0;
        int armControlDirection = 0;

};