/*
* WSGA_PCB.c
*
* Created: 2017-11-14 10:31:23 PM
* Author : Amit Srivastava
*/



#define F_CPU 32000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>
#include "uc_clock.h"
#include "XBee.h"
#include "ADC_D2.h"


int main(void)
{
	setUp32MhzInternalOsc();
	setUp_XBEE();
	setUp_ADC_D2();
	_delay_ms(100);
	config_ADC_D2_registers();
	setUp_ADC_D2_Interrupt();
	//Initialize_ADC_D2();
	uint8_t data;
	sei();
	uint8_t byte[8] = {0x00, 0x65, 0x62, 0x69, 0x60, 0x61, 0x63, 0xff};
	while (1)
	{
		for (uint8_t i =0; i<8; ++i)
		{
			send_Byte_To_XBEE(byte[i]);
		}
		
		//	data = Read_from_ADC_D2();
		_delay_ms(50);
	}
}

