/*
* ADC_D2.c
*
* Created: 2017-11-23 4:17:49 PM
*  Author: Amit Srivastava
*/

#include "ADC_D2.h"

/*************************************************
setUp_ADC_D2():	Sets up the SPI port for ADC_D2
*************************************************/

void setUp_ADC_D2()
{
	ADC_D2_CS_DIR_OUTPUT;
	ADC_D2_SCK_DIR_OUTPUT;
	ADC_D2_MISO_DIR_INPUT;
	ADC_D2_MOSI_DIR_OUTPUT;
	ADC_D2_START_DIR_OUTPUT;
	ADC_D2_RESET_DIR_OUTPUT;
	ADC_D2_DRDY_DIR_INPUT;

	/* Double clock=0, SPI enable = 1, DORD = 0(mSB first), MASTER = 1 (MASTER MODE), Transfer mode = 01 (mode 1), SCK frequency = 01 (CLK_PER/16 (bcoz Maximum = f_clk_ADS1259/1.8))  */
	ADC_D2_SPI_CTRL = 0b01010101;
	ADC_D2_SPI_INTCTRL = 0x00; // Interrupts are disabled.
}



/*************************************************************
void config_ADC_D2_registers():	Configures ADC_D2 registers
**************************************************************/
void config_ADC_D2_registers()
{
	ADC_D2_RESET_PIN_HIGH;   //!RESET pin High.
	_delay_us(100);
	ADC_D2_START_PIN_LOW;	// START pin Low.
	_delay_us(100);
	_delay_us(100);
	ADC_D2_CS_PIN_HIGH;		// !CS pin high
	_delay_us(1000);
	ADC_D2_CS_PIN_LOW;		// !CS pin LOW
	_delay_us(1000);

	// Send SDATA command
	Send_Command_to_ADC_D2(0x11);
	_delay_us(100);
	Send_Command_to_ADC_D2(0x11);
	_delay_us(100);
	// Write register opcode bytes, starting at address 2, 1-byte block
	Send_Command_to_ADC_D2(0b01000010);			//1st byte of Write register opcode
	_delay_us(100);
	Send_Command_to_ADC_D2(0b00000000);			//2nd byte of Write register opcode
	_delay_us(100);

	//CONFIG2; Gate Convert mode, 3600SPS ([2:0]--> 110)
	Send_Command_to_ADC_D2(0b00000110);
	_delay_us(100);

	//send the RDATAC (Read data continuous) command
	Send_Command_to_ADC_D2(0x10);

	ADC_D2_START_PIN_HIGH;  // START pin HIGH.
	_delay_us(100);
}


/**************************************************************************
void setUp_ADC_D2(): This function sets up the interrupt for DRDY pin of ADC_D2
**************************************************************************/

void setUp_ADC_D2_Interrupt()
{
	ADC_D2_DRDYPINCTRL = PORT_OPC_PULLDOWN_gc | PORT_ISC_FALLING_gc;
	ADC_D2_SET_INTMASK;
	ADC_D2_ENABLE_INTERRUPT;
	// Enable low level interrupts
	PMIC.CTRL |= PMIC_MEDLVLEN_bm;
}


/*******************************************************************************************
ISR(ADC_D2_INT_vect): This function sends one byte COMMAND to ADC_D2
*******************************************************************************************/

ISR(ADC_D2_INT_vect)
{
	PORTR_DIRSET = 0x01;
	PORTR_OUTTGL=0x01;
}

/*******************************************************************************************
void Send_Command_to_ADC_D2(uint8_t byte): This function sends one byte COMMAND to ADC_D2
*******************************************************************************************/
void Send_Command_to_ADC_D2(uint8_t byte)
{
	SPID_DATA = byte;
}

/**************************************************************************
uint8_t Read_from_ADC_D2(): This function reads a byte data from ADC_D2
**************************************************************************/
uint8_t Read_from_ADC_D2()
{
	SPID_DATA = 0x7f;     // Sending dummy data
	while(!(SPID_STATUS & (1<<7)));
	return SPID_DATA;
}


/**************************************************************************
setUp_ADC_D2(): This function initializes ADC_D2
**************************************************************************/
void Initialize_ADC_D2()
{
	setUp_ADC_D2();
	config_ADC_D2_registers();
	setUp_ADC_D2_Interrupt();
}
