/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.c
 *
 * Description: Source file for the TM4C123GH6PM NVIC driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

#include "NVIC.h"
#include "tm4c123gh6pm_registers.h"



volatile uint32 * NVIC_PRI_n_REGS[35] = { &NVIC_PRI0_REG, &NVIC_PRI1_REG, &NVIC_PRI2_REG, &NVIC_PRI3_REG,
                                 &NVIC_PRI4_REG, &NVIC_PRI5_REG, &NVIC_PRI6_REG, &NVIC_PRI7_REG,
                                 &NVIC_PRI8_REG, &NVIC_PRI9_REG, &NVIC_PRI10_REG, &NVIC_PRI11_REG,
                                 &NVIC_PRI12_REG, &NVIC_PRI13_REG, &NVIC_PRI14_REG, &NVIC_PRI15_REG,
                                 &NVIC_PRI16_REG, &NVIC_PRI17_REG, &NVIC_PRI18_REG, &NVIC_PRI19_REG,
                                 &NVIC_PRI20_REG, &NVIC_PRI21_REG, &NVIC_PRI22_REG, &NVIC_PRI23_REG,
                                 &NVIC_PRI24_REG, &NVIC_PRI25_REG, &NVIC_PRI26_REG, &NVIC_PRI27_REG,
                                 &NVIC_PRI28_REG, &NVIC_PRI29_REG, &NVIC_PRI30_REG, &NVIC_PRI31_REG,
                                 &NVIC_PRI32_REG, &NVIC_PRI33_REG, &NVIC_PRI34_REG };




/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/


/***************************************************************************
* Service Name: NVIC_EnableIRQ
* Sync/Async:
* Reentrancy:
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable Interrupt request for specific IRQ
****************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
    uint8 EN_n_REG = IRQ_Num / 32;             // Determine which EN REG having IRQ number.
    uint8 bit_pos  = IRQ_Num % 32;             // Determine which bit responsible to enable the interrupt for the IRQ number given.

    switch (EN_n_REG)
    {
    case EN_0_REG :

        NVIC_EN0_REG  |= ( 1 << bit_pos );     // Enable interrupt for corresponding IRQ number.
        break;

    case EN_1_REG :

        NVIC_EN1_REG  |= ( 1 << bit_pos );     // Enable interrupt for corresponding IRQ number.
        break;

    case EN_2_REG :

        NVIC_EN2_REG  |= ( 1 << bit_pos );     // Enable interrupt for corresponding IRQ number.
        break;

    case EN_3_REG :

        NVIC_EN3_REG  |= ( 1 << bit_pos );     // Enable interrupt for corresponding IRQ number.
        break;

    case EN_4_REG :

        NVIC_EN4_REG  |= ( 1 << bit_pos );     // Enable interrupt for corresponding IRQ number.
        break;
    }
}


/***************************************************************************
 * Service Name: NVIC_DisableIRQ
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable Interrupt request for specific IRQ
 * **************************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{
    uint8 DIS_n_REG = IRQ_Num / 32;             // Determine which DIS REG having IRQ number.
    uint8 bit_pos   = IRQ_Num % 32;             // Determine which bit responsible to disable the interrupt for the IRQ number given.

    switch (DIS_n_REG)
    {
    case DIS_0_REG :

        NVIC_DIS0_REG  |= ( 1 << bit_pos );     // Disable interrupt for corresponding IRQ number.
        break;

    case DIS_1_REG :

        NVIC_DIS1_REG  |= ( 1 << bit_pos );     // Disable interrupt for corresponding IRQ number.
        break;

    case DIS_2_REG :

        NVIC_DIS2_REG  |= ( 1 << bit_pos );     // Disable interrupt for corresponding IRQ number.
        break;

    case DIS_3_REG :

        NVIC_DIS3_REG  |= ( 1 << bit_pos );     // Disable interrupt for corresponding IRQ number.
        break;

    case DIS_4_REG :

        NVIC_DIS4_REG  |= ( 1 << bit_pos );     // Disable interrupt for corresponding IRQ number.
        break;
    }
}


/***************************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 *                  IRQ_Priority - Priority of the IRQ
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority of specific IRQ
 * **************************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num,NVIC_IRQPriorityType IRQ_Priority)
{
    uint8 PRI_n_REG = IRQ_Num / 4;                  // Determine which priority REG having IRQ number.
    uint8 bit_pos   = ( IRQ_Num % 4 ) * 8 + 5;      // Determine which first bit (3 bits fields priority) responsible to set priority number in it for the IRQ number given.

    /* For safety we need first to clear 3 bits fields priority and then set priority level  */
    *NVIC_PRI_n_REGS[PRI_n_REG] = ( *NVIC_PRI_n_REGS[PRI_n_REG] & ~(0x7 << bit_pos) )  |  ( IRQ_Priority << bit_pos );
}


/***********************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Exception_Num - Number of the Exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable specific ARM system or fault exceptions
 * ************************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num)
    {
    case EXCEPTION_HARD_FAULT_TYPE :

        Enable_Faults();                                        // Enable hard fault.
        break;

    case EXCEPTION_MEM_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  |= MEM_FAULT_ENABLE_MASK;       // Enable MEM fault exception.
        break;

    case EXCEPTION_BUS_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  |= BUS_FAULT_ENABLE_MASK;       // Enable BUS fault exception.
        break;

    case EXCEPTION_USAGE_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  |= USAGE_FAULT_ENABLE_MASK;     // Enable USAGE fault exception.
        break;

    case EXCEPTION_SVC_TYPE :

        Trigger_SVC_Exception();                                // Enable SVC exception.
        break;

    case EXCEPTION_INTERRUPT_TYPE :

        Enable_Exceptions();                                    // Enable all interrupt.
        break;
    }
}


/************************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Exception_Num - Number of the Exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable specific ARM system or fault exceptions
 * *************************************************************************/
void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num)
    {
    case EXCEPTION_HARD_FAULT_TYPE :

        Disable_Faults();                                                                            // Disable all fault even hard fault.
        break;

    case EXCEPTION_MEM_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  &= ~ MEM_FAULT_ENABLE_MASK;        // Disable MEM fault exception.
        break;

    case EXCEPTION_BUS_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  &= ~ BUS_FAULT_ENABLE_MASK;        // Disable BUS fault exception.
        break;

    case EXCEPTION_USAGE_FAULT_TYPE :

        NVIC_SYSTEM_SYSHNDCTRL  &= ~ USAGE_FAULT_ENABLE_MASK;    // Disable USAGE fault exception.
        break;

    case EXCEPTION_SVC_TYPE :


        break;

    case EXCEPTION_INTERRUPT_TYPE :

        Disable_Exceptions();                                                                        // Disable all interrupt except (Hard fault,NMI,Reset).
        break;
    }
}


/*********************************************************************
 * Service Name: NVIC_SetPriorityException
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Exception_Num - Number of the Exception
 *                  Exception_Priority - Priority of the Exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority of specific Exception
 * **********************************************************************/
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
    switch (Exception_Num)
    {
    case EXCEPTION_MEM_FAULT_TYPE :

        NVIC_SYSTEM_PRI1_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << MEM_FAULT_PRIORITY_BITS_POS ) )  | ( Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_BUS_FAULT_TYPE :

        NVIC_SYSTEM_PRI1_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << BUS_FAULT_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_USAGE_FAULT_TYPE :

        NVIC_SYSTEM_PRI1_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << USAGE_FAULT_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_SVC_TYPE :

        NVIC_SYSTEM_PRI2_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << SVC_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << SVC_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_DEBUG_MONITOR_TYPE :

        NVIC_SYSTEM_PRI3_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << DEBUG_MONITOR_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << DEBUG_MONITOR_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_PEND_SV_TYPE :

        NVIC_SYSTEM_PRI3_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << PENDSV_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << PENDSV_PRIORITY_BITS_POS );
        break;

    case EXCEPTION_SYSTICK_TYPE :

        NVIC_SYSTEM_PRI3_REG  = ( NVIC_SYSTEM_PRI1_REG & ~(0x7 << SYSTICK_PRIORITY_BITS_POS ) )  |  ( Exception_Priority << SYSTICK_PRIORITY_BITS_POS );
        break;
    }
}

