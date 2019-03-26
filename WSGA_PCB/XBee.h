/*
 * XBee.h
 *
 * Created: 2017-11-14 11:03:30 PM
 *  Author: Amit Srivastava
 */ 


#ifndef XBEE_H_
#define XBEE_H_

#include <avr/io.h>
/***********************************************
PIN Definitions

************************************************/

#define FROM_XBEE_PIN						PIN2_bm
#define TO_XBEE_PIN							PIN3_bm
#define RESET_XBEE_PIN						PIN4_bm
#define DTR_XBEE_PIN						PIN5_bm
#define CTS_XBEE_PIN						PIN6_bm
#define RTS_XBEE_PIN						PIN7_bm


/*******************************************************
PORT Direction (SET/CLR) registers (All XBEE related pins are in one port (PORT F) only)

********************************************************/

#define XBEE_PORT_DIRSET					PORTF_DIRSET
#define XBEE_PORT_DIRCLR					PORTF_DIRCLR

/*******************************************************
Set Direction to INPUT or OUTPUT

********************************************************/

#define FROM_XBEE_DIR_INPUT					XBEE_PORT_DIRCLR = FROM_XBEE_PIN
#define TO_XBEE_DIR_OUTPUT					XBEE_PORT_DIRSET = TO_XBEE_PIN
#define RESET_XBEE_DIR_OUTPUT				XBEE_PORT_DIRSET = RESET_XBEE_PIN
#define DTR_XBEE_DIR_OUTPUT					XBEE_PORT_DIRSET = DTR_XBEE_PIN
#define CTS_XBEE_DIR_INPUT					XBEE_PORT_DIRCLR = CTS_XBEE_PIN
#define RTS_XBEE_DIR_INPUT					XBEE_PORT_DIRCLR = RTS_XBEE_PIN

/*******************************************************
PORT Output (SET/CLR) registers

********************************************************/
#define XBEE_PORT_OUTSET					PORTF_OUTSET
#define XBEE_PORT_OUTCLR					PORTF_OUTCLR


/*******************************************************
XBEE (USART) control registers

********************************************************/
#define XBEE_USART_BAUDCTRLA					USARTF0_BAUDCTRLA
#define XBEE_USART_BAUDCTRLB					USARTF0_BAUDCTRLB
#define XBEE_USART_CTRLA						USARTF0_CTRLA
#define XBEE_USART_CTRLB						USARTF0_CTRLB
#define XBEE_USART_CTRLC						USARTF0_CTRLC

/*******************************************************
Set OUTPUT to HIGH or LOW

********************************************************/

#define RESET_XBEE_PIN_HIGH						XBEE_PORT_OUTSET = RESET_XBEE_PIN
#define RESET_XBEE_PIN_LOW						XBEE_PORT_OUTCLR = RESET_XBEE_PIN
#define DTR_XBEE_PIN_HIGH						XBEE_PORT_OUTSET = DTR_XBEE_PIN
#define	DTR_XBEE_PIN_LOW						XBEE_PORT_OUTCLR = DTR_XBEE_PIN


void setUp_XBEE();							// This function sets the USART_F0 port for the XBEE
void send_Byte_To_XBEE(uint8_t byte);		// This function sends a byte to the TO_XBEE pin.
uint8_t read_Byte_From_XBEE ();


#endif /* XBEE_H_ */