/*-------------------------------------------------------------------
**
**  Fichero:
**    timer.h  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Contiene las definiciones de los prototipos de funciones
**    para la gesti�n del timer 0 del chip S3C44BOX
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include "44b.h"
#include "leds.h"
#include "D8led.h"
#include "timer.h"



static void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));

static void timer_ISR( void )
{
	
}

void timer_init(void)
{

}
