/*
 * ADC_C2.h
 *
 * Created: 2017-11-23 2:40:12 PM
 *  Author: Amit Srivastava
 */ 


#ifndef ADC_C2_H_
#define ADC_C2_H_

#define F_CPU 32000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>


/***********************************************
PIN Definitions

************************************************/
#define ADC_C2_DRDY_PIN					PIN0_bm
#define ADC_C2_START_PIN				PIN1_bm
#define ADC_C2_RESET_PIN				PIN2_bm
#define ADC_C2_CS_PIN					PIN4_bm
#define ADC_C2_SCK_PIN					PIN7_bm
#define ADC_C2_MISO_PIN					PIN6_bm
#define ADC_C2_MOSI_PIN					PIN5_bm


/*******************************************************
PORT Direction (SET/CLR) registers

********************************************************/

#define ADC_C2_PORT						PORTC
#define ADC_C2_DRDY_PORT				PORTA
#define ADC_C2_DRDY_DIRCLR				PORTA_DIRCLR
#define ADC_C2_START_DIRSET				PORTA_DIRSET
#define ADC_C2_RESET_DIRSET				PORTA_DIRSET
#define ADC_C2_CS_DIRSET				PORTC_DIRSET
#define ADC_C2_SCK_DIRSET				PORTC_DIRSET
#define ADC_C2_MISO_DIRCLR				PORTC_DIRCLR
#define ADC_C2_MOSI_DIRSET				PORTC_DIRSET

/*******************************************************
Set Direction to INPUT or OUTPUT

********************************************************/

#define ADC_C2_DRDY_DIR_INPUT			ADC_C2_DRDY_DIRCLR = ADC_C2_DRDY_PIN
#define ADC_C2_START_DIR_OUTPUT			ADC_C2_START_DIRSET = ADC_C2_START_PIN
#define ADC_C2_RESET_DIR_OUTPUT			ADC_C2_RESET_DIRSET = ADC_C2_RESET_PIN
#define ADC_C2_CS_DIR_OUTPUT			ADC_C2_CS_DIRSET = ADC_C2_CS_PIN
#define ADC_C2_SCK_DIR_OUTPUT			ADC_C2_SCK_DIRSET = ADC_C2_SCK_PIN
#define ADC_C2_MISO_DIR_INPUT			ADC_C2_MISO_DIRCLR = ADC_C2_MISO_PIN
#define ADC_C2_MOSI_DIR_OUTPUT			ADC_C2_MOSI_DIRSET = ADC_C2_MOSI_PIN

/*******************************************************
PORT Output (SET/CLR) registers

********************************************************/
#define ADC_C2_START_OUTSET				PORTA_OUTSET
#define ADC_C2_START_OUTCLR				PORTA_OUTCLR
#define ADC_C2_RESET_OUTSET				PORTA_OUTSET
#define ADC_C2_RESET_OUTCLR				PORTA_OUTCLR
#define ADC_C2_CS_OUTSET				PORTC_OUTSET
#define ADC_C2_CS_OUTCLR				PORTC_OUTCLR


/*******************************************************
Set OUTPUT to HIGH or LOW

********************************************************/
#define ADC_C2_START_PIN_HIGH				ADC_C2_START_OUTSET = ADC_C2_START_PIN
#define ADC_C2_START_PIN_LOW				ADC_C2_START_OUTCLR = ADC_C2_START_PIN
#define ADC_C2_RESET_PIN_HIGH				ADC_C2_RESET_OUTSET = ADC_C2_RESET_PIN
#define ADC_C2_RESET_PIN_LOW				ADC_C2_RESET_OUTCLR = ADC_C2_RESET_PIN
#define ADC_C2_CS_PIN_HIGH					ADC_C2_START_OUTSET = ADC_C2_START_PIN
#define ADC_C2_CS_PIN_LOW					ADC_C2_START_OUTSET = ADC_C2_START_PIN



/******************************************
ADC SPI Control Register
****************************************/

#define ADC_C2_SPI_INTCTRL					SPIC_INTCTRL
#define ADC_C2_SPI_CTRL						SPIC_CTRL
#define ADC_C2_DRDYPINCTRL					PORTA_PIN0CTRL		// This register depends upon the pin connected to the DRDY of ADC
#define ADC_C2_PORT_INTMASK					PORTA_INT0MASK		// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to INT1MASK
#define ADC_C2_SET_INTMASK					ADC_C2_PORT_INTMASK = ADC_C2_DRDY_PIN	//This will overwrite any other mask applied to PORTA_INT0MASK (Better to use in |= style)
#define ADC_C2_INTCTRL						PORTA_INTCTRL		// This register depends upon the pin connected to the DRDY of ADC
#define ADC_C2_ENABLE_INTERRUPT				ADC_C2_INTCTRL = PORT_INT0LVL_MED_gc // Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_MED_gc
#define ADC_C2_DISABLE_INTERRUPT			ADC_C2_INTCTRL = PORT_INT0LVL_OFF_gc	// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_OFF_gc
#define ADC_C2_INT_vect						PORTA_INT0_vect




void setUp_ADC_C2();							// Sets up the SPI port for ADC_C2
void config_ADC_C2_registers();					// Configures ADC_C2 registers
void setUp_ADC_C2_Interrupt();					// Sets up the interrupt for DRDY pin of ADC_C2
void Initialize_ADC_C2();						// Initialize ADC_C2
void Send_Command_to_ADC_C2(uint8_t byte);		// Sends a byte to ADC_C2
uint8_t Read_from_ADC_C2();						// Reads a byte from ADC_C2



#endif /* ADC_C2_H_ */