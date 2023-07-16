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

    Frequency currentFreq = FREQ_100MS;
    uint32_t buttonState = 0;

    while (1) {
        // Leer el estado del botón
        uint32_t currentButtonState = Leer_Estado_Boton_LPCXpresso1769();

        // Cambiar la frecuencia de parpadeo del LED al detectar un flanco de bajada en el botón
        if (currentButtonState == 0 && buttonState == 1) {
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

        // Actualizar el estado del botón
        buttonState = currentButtonState;

        // Cambiar el estado del LED según la frecuencia actual
        switch (currentFreq) {
            case FREQ_100MS:
                Encender_Led_LPCXpresso1769();
                break;
            case FREQ_300MS:
                if (buttonState == 0) {
                    Encender_Led_LPCXpresso1769();
                } else {
                    Apagar_Led_LPCXpresso1769();
                }
                break;
            case FREQ_500MS:
                if (buttonState == 0) {
                    Apagar_Led_LPCXpresso1769();
                } else {
                    Encender_Led_LPCXpresso1769();
                }
                break;
            case FREQ_1S:
                Apagar_Led_LPCXpresso1769();
                break;
            default:
                break;
        }
    }

    return 0;
}
