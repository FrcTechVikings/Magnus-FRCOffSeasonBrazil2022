#pragma once

#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <frc/DigitalInput.h>

class Arm {

    public:

        WPI_VictorSPX armMotor = {MotorsConstants::armRedline};
        WPI_VictorSPX armHolder = {MotorsConstants::armSnowBlower};

        // Microswitches para o controle do braço
        frc::DigitalInput topLimitSwitch {SensorsConstants::topMicroSwitchDIO};
        frc::DigitalInput bottomLimitSwitch {SensorsConstants::bottomMicroSwitchDIO};

        void ArmLog(); // Registro do Braço
        void ArmFeed(bool lock, double percent); // Alimentação do motor do Braço
        void ArmHolderFeed(bool lock, int direction); // Alimentação do Snow Blower
        void ArmSwitchUp(); // Comando para executar a subida automática do Braço
        void ArmSwitchDown(); // Comando para executar a descida automática do Braço
        void ArmInit(); // Inicializa o Braço
        void ArmPeriodic(bool lock, double joyStickY); // Realiza a checagem periódica do controle do Braço e executa o movimento

    private:

        double operatorStickValue = 0.0;
        int armControlDirection = 0;

};