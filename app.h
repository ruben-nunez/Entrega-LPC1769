//!< ////////////////// PRIMITIVAS  GENERALES //////////////////////////////
 	 void Inicializar_KIT( void );
 	 void mde_blinky(void);
 	 void init_mde_blinky(void);

//!< //////////////////  DEFINES GENERALES	 //////////////////////////////

	#define MAX_TIME	0
	#define TIME1	100
	#define TIME2	300
	#define TIME3	500
	#define TIME4	1000


//!< //////////////////  TIPOS DE DATOS GENERALES	 //////////////////////////////

	typedef enum{
		DEFAULT,
		ENCENDIDO,
		APAGADO
	}estados_led;
