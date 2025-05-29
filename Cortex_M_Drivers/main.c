 /******************************************************************************
 *
 * Module: APP
 *
 * File Name: main.c
 *
 * Description: Source file for APP
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "tm4c123gh6pm_registers.h"
#include "NVIC/NVIC.h"
#include "SysTick/SysTick.h"

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/*******************************************************************************
 *                               Main Program                                  *
 *******************************************************************************/

/* Write your program here */

int main(void)
{
    return 0;
}
