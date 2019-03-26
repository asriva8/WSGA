/*
 * ADC_E2.h
 *
 * Created: 2017-11-23 2:41:17 PM
 *  Author: Amit Srivastava
 */ 


#ifndef ADC_E2_H_
#define ADC_E2_H_

#define F_CPU 32000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>


/***********************************************
PIN Definitions

************************************************/
#define ADC_E2_DRDY_PIN					PIN7_bm   // Earlier it was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly.
#define ADC_E2_START_PIN				PIN0_bm
#define ADC_E2_RESET_PIN				PIN1_bm
#define ADC_E2_CS_PIN					PIN4_bm
#define ADC_E2_SCK_PIN					PIN7_bm
#define ADC_E2_MISO_PIN					PIN6_bm
#define ADC_E2_MOSI_PIN					PIN5_bm


/*******************************************************
PORT Direction (SET/CLR) registers

********************************************************/

#define ADC_E2_PORT						PORTE
#define ADC_E2_DRDY_PORT				PORTB	// Earlier it was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly.
#define ADC_E2_DRDY_DIRCLR				PORTB_DIRCLR // Earlier it was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly.
#define ADC_E2_START_DIRSET				PORTR_DIRSET
#define ADC_E2_RESET_DIRSET				PORTR_DIRSET
#define ADC_E2_CS_DIRSET				PORTE_DIRSET
#define ADC_E2_SCK_DIRSET				PORTE_DIRSET
#define ADC_E2_MISO_DIRCLR				PORTE_DIRCLR
#define ADC_E2_MOSI_DIRSET				PORTE_DIRSET

/*******************************************************
Set Direction to INPUT or OUTPUT

********************************************************/

#define ADC_E2_DRDY_DIR_INPUT			ADC_E2_DRDY_DIRCLR = ADC_E2_DRDY_PIN
#define ADC_E2_START_DIR_OUTPUT			ADC_E2_START_DIRSET = ADC_E2_START_PIN
#define ADC_E2_RESET_DIR_OUTPUT			ADC_E2_RESET_DIRSET = ADC_E2_RESET_PIN
#define ADC_E2_CS_DIR_OUTPUT			ADC_E2_CS_DIRSET = ADC_E2_CS_PIN
#define ADC_E2_SCK_DIR_OUTPUT			ADC_E2_SCK_DIRSET = ADC_E2_SCK_PIN
#define ADC_E2_MISO_DIR_INPUT			ADC_E2_MISO_DIRCLR = ADC_E2_MISO_PIN
#define ADC_E2_MOSI_DIR_OUTPUT			ADC_E2_MOSI_DIRSET = ADC_E2_MOSI_PIN

/*******************************************************
PORT Output (SET/CLR) registers

********************************************************/
#define ADC_E2_START_OUTSET				PORTR_OUTSET
#define ADC_E2_START_OUTCLR				PORTR_OUTCLR
#define ADC_E2_RESET_OUTSET				PORTR_OUTSET
#define ADC_E2_RESET_OUTCLR				PORTR_OUTCLR
#define ADC_E2_CS_OUTSET				PORTE_OUTSET
#define ADC_E2_CS_OUTCLR				PORTE_OUTCLR


/*******************************************************
Set OUTPUT to HIGH or LOW

********************************************************/
#define ADC_E2_START_PIN_HIGH				ADC_E2_START_OUTSET = ADC_E2_START_PIN
#define ADC_E2_START_PIN_LOW				ADC_E2_START_OUTCLR = ADC_E2_START_PIN
#define ADC_E2_RESET_PIN_HIGH				ADC_E2_RESET_OUTSET = ADC_E2_RESET_PIN
#define ADC_E2_RESET_PIN_LOW				ADC_E2_RESET_OUTCLR = ADC_E2_RESET_PIN
#define ADC_E2_CS_PIN_HIGH					ADC_E2_START_OUTSET = ADC_E2_START_PIN
#define ADC_E2_CS_PIN_LOW					ADC_E2_START_OUTSET = ADC_E2_START_PIN



/******************************************
ADC SPI Control Register
****************************************/

#define ADC_E2_SPI_INTCTRL					SPIE_INTCTRL
#define ADC_E2_SPI_CTRL						SPIE_CTRL
#define ADC_E2_DRDYPINCTRL					PORTB_PIN7CTRL		// // Earlier it was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly. This register depends upon the pin connected to the DRDY of ADC
#define ADC_E2_PORT_INTMASK					PORTB_INT1MASK		// Earlier it was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly. // Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to INT1MASK
#define ADC_E2_SET_INTMASK					ADC_E2_PORT_INTMASK = ADC_E2_DRDY_PIN	//This will overwrite any other mask applied to PORTA_INT0MASK (Better to use in |= style)
#define ADC_E2_INTCTRL						PORTB_INTCTRL		// This register depends upon the pin connected to the DRDY of ADC
#define ADC_E2_ENABLE_INTERRUPT				ADC_E2_INTCTRL = PORT_INT1LVL_MED_gc	// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_MED_gc
#define ADC_E2_DISABLE_INTERRUPT			ADC_E2_INTCTRL = PORT_INT1LVL_OFF_gc	// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_OFF_gc
#define ADC_E2_INT_vect						PORTB_INT1_vect		//Earlier DRDY pin was pin7 of PortB. Later, you had connected it to pin1 of PortR. So, define here accordingly.






void setUp_ADC_E2();							// Sets up the SPI port for ADC_E2
void config_ADC_E2_registers();					// Configures ADC_E2 registers
void setUp_ADC_E2_Interrupt();					// Sets up the interrupt for DRDY pin of ADC_E2
void Initialize_ADC_E2();						// Initialize ADC_E2
void Send_Command_to_ADC_E2(uint8_t byte);		// Sends a byte to ADC_E2
uint8_t Read_from_ADC_E2();						// Reads a byte from ADC_E2





#endif /* ADC_E2_H_ */