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
**    para la gesti�n de la uart 0 del chip S3C44BOX
**
**  Notas de dise�o:
**
**-----------------------------------------------------------------*/

#include "44b.h"
#include "utils.h"
#include "uart.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MCLK 64000000

void Uart_Init(int baud)
{
	rPCONE = (rPCONE & ~(0xf<<2)) | (2<<4) | (2<<2); 	// PE[2] = RxD0, PE[1] = TxD0
	
    /* UART0 */
	// Modo normal, no paridad, 1b stop, 8b char

	// tx=nivel, rx=flanco, no rx-timeout ni rx-error, normal, int/polling


	rUBRDIV0=( (int)(MCLK/16./baud + 0.5) -1 ); // formula division de frecuencia

	// Desactivar FIFO

	// Desactivar control de flujo


}


// Funci�n que lee un caracter del puerto serie
// Realiza espera activa (bucle hasta que recibe un byte)
char Uart_Getch(void)
{
     // esperar a que el buffer contenga datos


	// devolver el caracter


}


// Funci�n que env�a un byte por puerto serie
// Espera activa (espera hasta que se haya enviado)
void Uart_SendByte(char data)
{
	// Comprobamos si lo que se env�a es el caracter fin de l�nea
    if(data == '\n')		
	{
    	 // esperar a que THR se vacie
	   while (!(rUTRSTAT0 & 0x2));

	   // escribir retorno de carro (caracter \r)

	}
    // esperar a que THR se vacie
	while (!(rUTRSTAT0 & 0x2));

	// escribir data


}


// Funci�n ya implementada: env�a una cadena de caracteres completa (hasta que encuentra \0)
void Uart_SendString(char *pt)
{
	 // mandar byte a byte hasta completar string
    while (*pt)
    	Uart_SendByte(*pt++);
}

// Funci�n ya implementado: similar a printf pero enviando por puerto serie
void Uart_Printf(char *fmt,...)
{
    va_list ap;
    char string[256];

    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    Uart_SendString(string);
    va_end(ap);
}



