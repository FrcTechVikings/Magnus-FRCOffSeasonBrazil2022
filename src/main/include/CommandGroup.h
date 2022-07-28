#pragma once

// O objetivo dessa classe é juntar os sistemas, para o teleoperado e autônomo

#include <frc/Joystick.h>
#include "Constants.h"

// Inclui os outros sistemas, para serem integrados juntos
#include "Drivetrain.h"
#include "Intake.h"
#include "Arm.h"

class CommandGroup {

    public:

        // Declaração dos joysticks
        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        Drivetrain RobotDrivetrain;
        Intake RobotIntake;
        Arm RobotArm;

        void InitAutoCommands(); // Inicialização do autônomo do robô
        void OneCargoAuto(double delaySeconds, bool armDown); // Método autônomo de pontuar uma cargo
        void ExitTarmacAuto(double delaySeconds, bool armDown); // Metódo autônomo de apenas sair do tarmac

        void InitCommands(); // Inicialização dos comandos teleoperados do robô
        void PeriodicCommands(); // Comandos periódicos do teleoperado
        void PilotCommands(); // Verificação dos botões do Joystick do piloto
        void OperatorCommands(); // Verificação dos botões do Joystick do operador
        void Log(); // Registro Geral do robô

    private:

        bool safeLock = 1;
        bool executeOnce = 0;
        frc::Timer autoTimer;

};