 /******************************************************************************
 *
 * Module: SysTick
 *
 * File Name: SysTick.c
 *
 * Description: Source file for the TM4C123GH6PM SysTick driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

#include "SysTick.h"
#include "tm4c123gh6pm_registers.h"

/* #define SYSTICK_PRIORITY_MASK        0x1FFFFFFF
 * #define SYSTICK_INTERRUPT_PRIORITY       3
 * #define SYSTICK_PRIORITY_BITS_POS        29 */

/*******************************************************************************
 *                             Global Variables                                *
 *******************************************************************************/

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/


/*****************************************************************************
 * Service Name: SysTick_Init
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): a_TimeInMilliSeconds - Time in MilliSeconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initialize the SysTick timer with the specified time
 * in milliseconds using interrupts. This function is used to setup the
 * timer to generate periodic interrupts every specified time in milliseconds.
 * ****************************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;                                                                // Disable the SysTick Timer by Clear the ENABLE Bit.

    SYSTICK_RELOAD_REG  = ( (uint32) a_TimeInMilliSeconds * SYSTICK_RELOAD_VALUE ) - 1;     // Set the Reload value to count Seconds.

    SYSTICK_CURRENT_REG = 0;                                                                // Clear the Current Register value.

    SYSTICK_CTRL_REG   |= 0x07;                                                             // Enable SysTick timer & Interrupt & choose the clock source to be system clock.
}


/*********************************************************************
 * Service Name: SysTick_StartBusyWait
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): a_TimeInMilliSeconds - Time in MilliSeconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initialize the SysTick timer with the specified time
 * in milliseconds using polling or busy-wait technique. The function
 * should exit when the time is elapsed and stops the timer at the end.
 * ********************************************************************/
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;                                                                // Disable the SysTick Timer by Clear the ENABLE Bit.

    SYSTICK_RELOAD_REG  = ( (uint32) a_TimeInMilliSeconds * SYSTICK_RELOAD_VALUE ) - 1;     // Set the Reload value to count Seconds.

    SYSTICK_CURRENT_REG = 0;                                                                // Clear the Current Register value.

    SYSTICK_CTRL_REG   |= 0x05;                                                             // Enable SysTick timer & choose the clock source to be system clock.

    while( !(SYSTICK_CTRL_REG  &  SYSTICK_CTRL_COUNT_FLAG_MASK) );                          // Wait until the COUNT flag = 1.

    SYSTICK_CTRL_REG    = 0;                                                                // Disable the SysTick Timer by Clear the ENABLE Bit.

    SYSTICK_RELOAD_REG  = 0;                                                                // Set the Reload value 0.

    SYSTICK_CURRENT_REG = 0;                                                                // Clear the Current Register value.
}


/*********************************************************************
 * Service Name: SysTick_Handler
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Handler for SysTick interrupt use to call
 * the call-back function.
 * ********************************************************************/
void SysTick_Handler(void)
{
    if(g_callBackPtr != NULL_PTR)
    {
        (*g_callBackPtr)();             // Call the function that the pointer had address.
    }
}


/*********************************************************************
 * Service Name: SysTick_SetCallBack
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Ptr2Func - Pointer to function
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to setup the SysTick Timer call back
 * to be executed in the SysTick Handler.
 * ********************************************************************/
void SysTick_SetCallBack(volatile void (*Ptr2Func) (void))
{
    g_callBackPtr = Ptr2Func;           // Make pointer have address of given function.
}


/*********************************************************************
 * Service Name: SysTick_Stop
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to stop (pause) the SysTick Timer.
 * ********************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG  &= ~ SYSTICK_CTRL_ENABLE_MASK;               // Stop the timer.
}


/*********************************************************************
 * Service Name: SysTick_Start
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to start/resume the SysTick Timer.
 * ********************************************************************/
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG  |=  SYSTICK_CTRL_ENABLE_MASK;               // Start timer.
}


/*********************************************************************
 * Service Name: SysTick_DeInit
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Deinitialize the SysTick Timer.
 * ********************************************************************/
void SysTick_DeInit(void)
{
    SYSTICK_CTRL_REG    = 0;        // Disable the SysTick Timer by Clear the ENABLE Bit.

    SYSTICK_RELOAD_REG  = 0;        // Set the Reload value 0.

    SYSTICK_CURRENT_REG = 0;        // Clear the Current Register value.

    g_callBackPtr = NULL_PTR;
}
