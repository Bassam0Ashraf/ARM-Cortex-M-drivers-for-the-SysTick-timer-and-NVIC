 /******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.h
 *
 * Description: Header file for the TM4C123GH6PM NVIC driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                             PreProcessor Macros                             *
 *******************************************************************************/

#define Enable_Exceptions()     __asm(" CPSIE I ")       // Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK.
#define Disable_Exceptions()    __asm(" CPSID I ")       // Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK.
#define Enable_Faults()         __asm(" CPSIE F ")       // Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK.
#define Disable_Faults()        __asm(" CPSID F ")       // Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK.
#define Trigger_SVC_Exception() __asm(" SVC #0 ")        // Trigger SVC Exception ... This Macro use the SVC instruction to make SW Interrupt.

#define EN_0_REG                          0              // Used in switch function to indicate that we will write in NVIC_EN0_REG.
#define EN_1_REG                          1              // Used in switch function to indicate that we will write in NVIC_EN1_REG.
#define EN_2_REG                          2              // Used in switch function to indicate that we will write in NVIC_EN2_REG.
#define EN_3_REG                          3              // Used in switch function to indicate that we will write in NVIC_EN3_REG.
#define EN_4_REG                          4              // Used in switch function to indicate that we will write in NVIC_EN4_REG.

#define DIS_0_REG                         0              // Used in switch function to indicate that we will write in  NVIC_DIS0_REG.
#define DIS_1_REG                         1              // Used in switch function to indicate that we will write in  NVIC_DIS1_REG.
#define DIS_2_REG                         2              // Used in switch function to indicate that we will write in  NVIC_DIS2_REG.
#define DIS_3_REG                         3              // Used in switch function to indicate that we will write in  NVIC_DIS3_REG.
#define DIS_4_REG                         4              // Used in switch function to indicate that we will write in  NVIC_DIS4_REG.

#define MEM_FAULT_ENABLE_MASK             0x00010000
#define MEM_FAULT_EXCEPTION_BIT_POS       16
#define MEM_FAULT_PRIORITY_MASK           0x000000E0
#define MEM_FAULT_PRIORITY_BITS_POS       5

#define BUS_FAULT_ENABLE_MASK             0x00020000
#define BUS_FAULT_EXCEPTION_BIT_POS       17
#define BUS_FAULT_PRIORITY_MASK           0x0000E000
#define BUS_FAULT_PRIORITY_BITS_POS       13

#define USAGE_FAULT_ENABLE_MASK           0x00040000
#define USAGE_FAULT_EXCEPTION_BIT_POS     18
#define USAGE_FAULT_PRIORITY_MASK         0x00E00000
#define USAGE_FAULT_PRIORITY_BITS_POS     21

#define SVC_PRIORITY_MASK                 0xE0000000
#define SVC_PRIORITY_BITS_POS             29

#define DEBUG_MONITOR_PRIORITY_MASK       0x000000E0
#define DEBUG_MONITOR_PRIORITY_BITS_POS   5

#define PENDSV_PRIORITY_MASK              0x00E00000
#define PENDSV_PRIORITY_BITS_POS          21

#define SYSTICK_PRIORITY_MASK             0xE0000000
#define SYSTICK_PRIORITY_BITS_POS         29

/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/

typedef uint8 NVIC_IRQType;


typedef uint8 NVIC_IRQPriorityType;


typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE,
    EXCEPTION_INTERRUPT_TYPE
}NVIC_ExceptionType;


typedef enum
{
    EXCEPTION_PRIORITY_LEVEL_0,
    EXCEPTION_PRIORITY_LEVEL_1,
    EXCEPTION_PRIORITY_LEVEL_2,
    EXCEPTION_PRIORITY_LEVEL_3,
    EXCEPTION_PRIORITY_LEVEL_4,
    EXCEPTION_PRIORITY_LEVEL_5,
    EXCEPTION_PRIORITY_LEVEL_6,
    EXCEPTION_PRIORITY_LEVEL_7
}NVIC_ExceptionPriorityType;

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/


/*********************************************************************
* Service Name: NVIC_EnableIRQ
* Sync/Async:
* Reentrancy:
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable Interrupt request for specific IRQ
**********************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);


/*********************************************************************
 * Service Name: NVIC_DisableIRQ
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable Interrupt request for specific IRQ
 * **********************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);


/*********************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 *                  IRQ_Priority - Priority of the IRQ
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority of specific IRQ
 * **********************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);


/*********************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Exception_Num - Number of the Exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable specific ARM system or fault exceptions
 * **********************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);


/*********************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async:
 * Reentrancy:
 * Parameters (in): Exception_Num - Number of the Exception
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable specific ARM system or fault exceptions
 * **********************************************************************/
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);


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
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);


#endif /* NVIC_H_ */
