#include <stdio.h>
#include "hardware.h"

typedef enum {
    FREQ_100MS,
    FREQ_300MS,
    FREQ_500MS,
    FREQ_1S
} Frequency;

int main() {
    // Inicializar el LED y el botón
    Inicializar_Led_LPCXpresso1769();
    Inicializar_Boton_LPCXpresso1769();

    // Máquina de Estados para el LED
    Frequency currentFreq = FREQ_100MS;
    uint32_t ledTimer = 0;

    while (1) {
        // Máquina de Estados para el botón
        if (Leer_Estado_Boton_LPCXpresso1769() == 0) {
            // Esperar a que se suelte el botón
            while (Leer_Estado_Boton_LPCXpresso1769() == 0);

            // Cambiar la frecuencia de parpadeo del LED
            switch (currentFreq) {
                case FREQ_100MS:
                    currentFreq = FREQ_300MS;
                    break;
                case FREQ_300MS:
                    currentFreq = FREQ_500MS;
                    break;
                case FREQ_500MS:
                    currentFreq = FREQ_1S;
                    break;
                case FREQ_1S:
                    currentFreq = FREQ_100MS;
                    break;
                default:
                    break;
            }
        }

        // Máquina de Estados para el LED
        switch (currentFreq) {
            case FREQ_100MS:
                if (ledTimer >= 10) {
                    Invertir_Led_LPCXpresso1769();
                    ledTimer = 0;
                }
                break;
            case FREQ_300MS:
                if (ledTimer >= 30) {
                    Invertir_Led_LPCXpresso1769();
                    ledTimer = 0;
                }
                break;
            case FREQ_500MS:
                if (ledTimer >= 50) {
                    Invertir_Led_LPCXpresso1769();
                    ledTimer = 0;
                }
                break;
            case FREQ_1S:
                if (ledTimer >= 100) {
                    Invertir_Led_LPCXpresso1769();
                    ledTimer = 0;
                }
                break;
            default:
                break;
        }

        // Retardo de 10 ms
        for (int i = 0; i < 10000; i++) {
            asm("nop");
        }
        
        // Incrementar el temporizador del LED
        ledTimer++;
    }

    return 0;
}
