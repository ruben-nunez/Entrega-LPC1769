	volatile uint32_t key;							// Variable de teclado
	volatile uint32_t SysTicks = 0;
	volatile estados_led estado_mde;



	int main(void) {

		Inicializar_KIT();	
		init_mde_blinky();



		while(1)
		{

			mde_blinky();

		}
		return 0 ;
	}