/*
* uc_clock.c
*
* Created: 2017-11-23 2:23:58 PM
*  Author: Amit Srivastava
*/
#include <avr/io.h>
#include "uc_clock.h"


void setUp32MhzInternalOsc()
{
	OSC.CTRL |= OSC_RC32MEN_bm | OSC_RC32KEN_bm;  /* Enable the internal 32MHz & 32KHz oscillators */
	while(!(OSC.STATUS & OSC_RC32KRDY_bm));       /* Wait for 32Khz oscillator to stabilize */
	while(!(OSC.STATUS & OSC_RC32MRDY_bm));       /* Wait for 32MHz oscillator to stabilize */
	DFLLRC32M.CTRL = DFLL_ENABLE_bm ;             /* Enable DFLL - defaults to calibrate against internal 32Khz clock */
	CCP = CCP_IOREG_gc;                           /* Disable register security for clock update */
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc;              /* Switch to 32MHz clock */
	OSC.CTRL &= ~OSC_RC2MEN_bm;                   /* Disable 2Mhz oscillator */
	
	//OSC_CTRL |= OSC_RC32MEN_bm; //Setup 32Mhz crystal
	//while(!(OSC_STATUS & OSC_RC32MRDY_bm));
	//CCP = CCP_IOREG_gc; //Trigger protection mechanism
	//CLK_CTRL = CLK_SCLKSEL_RC32M_gc; //Enable internal  32Mhz crystal

}
