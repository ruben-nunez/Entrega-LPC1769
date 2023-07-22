//!< ////////////////// HEADERS //////////////////////////////
#include "Aplicacion.h"

//!< ////////////////// VARIABLES EXTERNAS //////////////////////////////
extern volatile estados_led estado_mde;
extern volatile uint32_t SysTicks = 0;


//!< ////////////////// INICIALIZACION MDE //////////////////////////////
void init_mde_blinky(void)
{
		MAX_TIME=TIME1
		estado_mde = DEFAULT;
		return;
}

//!< //////////////////  MDE //////////////////////////////
void mde_blinky(void)
{
	static uint32_t ticks=0;

	switch(estado_mde){

		case DEFAULT:
			RGB_LEDXpresso(ROJO, OFF);			
			ticks=0;
			estado_mde=APAGADO;
			break;
		case APAGADO:
			if(SysTicks-ticks>=TIME1) // TIME1 = 100 ms
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = ENCENDIDO;
				MAX_TIME=TIME2;
			}
			else(SysTicks-ticks>=TIME2) // TIME2 = 300 ms
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = ENCENDIDO;
				MAX_TIME=TIME3;
			}
			else(SysTicks-ticks>=TIME3) // TIME3 = 500 ms
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = ENCENDIDO;
				MAX_TIME=TIME4;
			}
			else(SysTicks-ticks>=TIME4) // TIME4 = 1 s
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = ENCENDIDO;
				MAX_TIME=TIME1;
			}
			break;
		case ENCENDIDO:
			if(SysTicks-ticks>=TIME1)
			{
				RGB_LEDXpresso(ROJO, OFF);
				ticks=SysTicks;
				estado_mde = APAGADO;
				MAX_TIME=TIME2;
			}
			else(SysTicks-ticks>=TIME2) // TIME2 = 300 ms
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = APAGADO;
				MAX_TIME=TIME3;
			}
			else(SysTicks-ticks>=TIME3) // TIME3 = 500 ms
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = APAGADO;
				MAX_TIME=TIME4;
			}
			else(SysTicks-ticks>=TIME4) // TIME4 = 1 s
			{
				RGB_LEDXpresso(ROJO, ON);
				ticks=SysTicks;
				estado_mde = APAGADO;
				MAX_TIME=TIME1;
			}
			break;
		default:
			estado_mde=DEFAULT;
			break;

	}
	return;
}

void SysTick_Handler(void)
{
	SysTicks++;
	return;
}