#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class Intake {

    public:

        WPI_VictorSPX intakeMotor = {MotorsConstants::intakeRedline};

        double ReleasePercent = IntakeConstants::percentIntakeStandardRelease;

        void IntakeLog(); // Registro do Intake
        void IntakeFeed(bool lock, int direction, double velocity); // Alimentação do Intake
        void IntakeInit(); // Inicialização do Intake
        void IntakeChangeSpeed(int proportion); // Modificar a velocidade do Intake
    
    private:

        const double gain = IntakeConstants::percentGain;

};