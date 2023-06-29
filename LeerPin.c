#include <stdio.h>
#include "hardware.h"

int main() {
    // Inicializar el LED
    Inicializar_Led_LPCXpresso1769();

    // Preguntar por el estado del pin
    printf("Estado actual del pin: %d\n", Leer_Estado_Pin_LPCXpresso1769());

    // Cambiar el estado del LED en base a la respuesta
    int32_t estadoPin = Leer_Estado_Pin_LPCXpresso1769();
    if (estadoPin == LED_ON) {
        Apagar_Led_LPCXpresso1769();
    } else {
        Encender_Led_LPCXpresso1769();
    }

    // Mostrar el nuevo estado del pin
    printf("Estado actual del pin: %d\n", Leer_Estado_Pin_LPCXpresso1769());

    return 0;
}
