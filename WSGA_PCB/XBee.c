/*
* XBee.c
*
* Created: 2017-11-14 11:03:51 PM
*  Author: Amit Srivastava
*/

#include <avr/io.h>
#include "XBee.h"

/***********************************************************************************
void setUp_XBEE() : This function sets up the USART on PORTF of the uc (ATXMEGA128A3U)
to communicate with the XBEE
************************************************************************************/
void setUp_XBEE()
{
	// Setting the direction of the pins on the port for XBEE pins.
	TO_XBEE_DIR_OUTPUT;
	RESET_XBEE_DIR_OUTPUT;
	DTR_XBEE_DIR_OUTPUT;
	FROM_XBEE_DIR_INPUT;
	CTS_XBEE_DIR_INPUT;
	RTS_XBEE_DIR_INPUT;

	// Setting RESET_XBEE pin HIGH. (RESET is ACTIVE_LOW on XBEE)
	RESET_XBEE_PIN_HIGH;

	// for 32MHZ f_per and 115,200 baud rate.
	// BSEL = 131
	//BSCALE = -3 .........  This is set by upper four bits of BAUDCTRLB register in 2's complement form.
	XBEE_USART_BAUDCTRLB = 0b11010000; //Upper four bits -3 in two's complement form
	XBEE_USART_BAUDCTRLA = 0x83; // 131
	//Disable interrupts, just for safety
	XBEE_USART_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	XBEE_USART_CTRLC = USART_CHSIZE_8BIT_gc;
	//Enable receive and transmit
	XBEE_USART_CTRLB = USART_TXEN_bm | USART_RXEN_bm; // And enable high speed mode
}


/***********************************************************************************
void send_Byte_To_XBEE(uint8_t byte) : This function sends a byte to the TO_XBEE pin.
************************************************************************************/

void send_Byte_To_XBEE(uint8_t byte)
{
	while( !(USARTF0_STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	USARTF0_DATA = byte;
}

/****************************************************************************************
uint8_t read_Byte_From_XBEE() : This function returns a byte read from the FROM_XBEE pin.
*****************************************************************************************/

uint8_t read_Byte_From_XBEE()
{	
	while(!(USARTF0_STATUS & USART_RXCIF_bm));
	return USARTF0_DATA; //receive byte from XBEE	
}

