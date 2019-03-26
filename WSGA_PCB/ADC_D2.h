/*
 * ADC_D2.h
 *
 * Created: 2017-11-23 2:40:42 PM
 *  Author: Amit Srivastava
 */ 


#ifndef ADC_D2_H_
#define ADC_D2_H_
#define F_CPU 32000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>


/***********************************************
PIN Definitions

************************************************/
#define ADC_D2_DRDY_PIN					PIN1_bm
#define ADC_D2_START_PIN				PIN2_bm
#define ADC_D2_RESET_PIN				PIN3_bm
#define ADC_D2_CS_PIN					PIN4_bm
#define ADC_D2_SCK_PIN					PIN7_bm
#define ADC_D2_MISO_PIN					PIN6_bm
#define ADC_D2_MOSI_PIN					PIN5_bm


/*******************************************************
PORT Direction (SET/CLR) registers

********************************************************/

#define ADC_D2_PORT						PORTD
#define ADC_D2_DRDY_PORT				PORTB
#define ADC_D2_DRDY_DIRCLR				PORTB_DIRCLR
#define ADC_D2_START_DIRSET				PORTB_DIRSET
#define ADC_D2_RESET_DIRSET				PORTB_DIRSET
#define ADC_D2_CS_DIRSET				PORTD_DIRSET
#define ADC_D2_SCK_DIRSET				PORTD_DIRSET
#define ADC_D2_MISO_DIRCLR				PORTD_DIRCLR
#define ADC_D2_MOSI_DIRSET				PORTD_DIRSET

/*******************************************************
Set Direction to INPUT or OUTPUT

********************************************************/

#define ADC_D2_DRDY_DIR_INPUT			ADC_D2_DRDY_DIRCLR = ADC_D2_DRDY_PIN
#define ADC_D2_START_DIR_OUTPUT			ADC_D2_START_DIRSET = ADC_D2_START_PIN
#define ADC_D2_RESET_DIR_OUTPUT			ADC_D2_RESET_DIRSET = ADC_D2_RESET_PIN
#define ADC_D2_CS_DIR_OUTPUT			ADC_D2_CS_DIRSET = ADC_D2_CS_PIN
#define ADC_D2_SCK_DIR_OUTPUT			ADC_D2_SCK_DIRSET = ADC_D2_SCK_PIN
#define ADC_D2_MISO_DIR_INPUT			ADC_D2_MISO_DIRCLR = ADC_D2_MISO_PIN
#define ADC_D2_MOSI_DIR_OUTPUT			ADC_D2_MOSI_DIRSET = ADC_D2_MOSI_PIN

/*******************************************************
PORT Output (SET/CLR) registers

********************************************************/
#define ADC_D2_START_OUTSET				PORTB_OUTSET
#define ADC_D2_START_OUTCLR				PORTB_OUTCLR
#define ADC_D2_RESET_OUTSET				PORTB_OUTSET
#define ADC_D2_RESET_OUTCLR				PORTB_OUTCLR
#define ADC_D2_CS_OUTSET				PORTD_OUTSET
#define ADC_D2_CS_OUTCLR				PORTD_OUTCLR


/*******************************************************
Set OUTPUT to HIGH or LOW

********************************************************/
#define ADC_D2_START_PIN_HIGH				ADC_D2_START_OUTSET = ADC_D2_START_PIN
#define ADC_D2_START_PIN_LOW				ADC_D2_START_OUTCLR = ADC_D2_START_PIN
#define ADC_D2_RESET_PIN_HIGH				ADC_D2_RESET_OUTSET = ADC_D2_RESET_PIN
#define ADC_D2_RESET_PIN_LOW				ADC_D2_RESET_OUTCLR = ADC_D2_RESET_PIN
#define ADC_D2_CS_PIN_HIGH					ADC_D2_START_OUTSET = ADC_D2_START_PIN
#define ADC_D2_CS_PIN_LOW					ADC_D2_START_OUTSET = ADC_D2_START_PIN



/******************************************
ADC SPI Control Register
****************************************/

#define ADC_D2_SPI_INTCTRL					SPID_INTCTRL
#define ADC_D2_SPI_CTRL						SPID_CTRL
#define ADC_D2_DRDYPINCTRL					PORTB_PIN1CTRL		// This register depends upon the pin connected to the DRDY of ADC
#define ADC_D2_PORT_INTMASK					PORTB_INT0MASK		// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to INT1MASK
#define ADC_D2_SET_INTMASK					ADC_D2_PORT_INTMASK = ADC_D2_DRDY_PIN	//This will overwrite any other mask applied to PORTB_INT0MASK
#define ADC_D2_INTCTRL						PORTB_INTCTRL		// This register depends upon the pin connected to the DRDY of ADC
#define ADC_D2_ENABLE_INTERRUPT				ADC_D2_INTCTRL = PORT_INT0LVL_MED_gc	// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_MED_gc
#define ADC_D2_DISABLE_INTERRUPT			ADC_D2_INTCTRL = PORT_INT0LVL_OFF_gc	// Make sure, INT0MASK of this port is NOT used by other ADC. If IT IS, change it to PORT_INT1LVL_OFF_gc
#define ADC_D2_INT_vect						PORTB_INT0_vect




void setUp_ADC_D2();							// Sets up the SPI port for ADC_D2
void config_ADC_D2_registers();					// Configures ADC_D2 registers
void setUp_ADC_D2_Interrupt();					// Sets up the interrupt for DRDY pin of ADC_D2
void Initialize_ADC_D2();						// Initialize ADC_D2
void Send_Command_to_ADC_D2(uint8_t byte);		// Sends a byte to ADC_D2
uint8_t Read_from_ADC_D2();						// Reads a byte from ADC_D2

#endif /* ADC_D2_H_ */