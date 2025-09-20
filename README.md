# ARM Cortex-M SysTick & NVIC Driver Development

## Table of Contents
- [Project Overview](#project-overview)
- [Project Objectives](#project-objectives)
- [Technical Features](#technical-features)
- [API Reference](#api-reference)
- [System Requirements](#system-requirements)
- [Documentation Standards](#documentation-standards)
- [Testing & Validation](#testing--validation)
- [Implementation Highlights](#implementation-highlights)
- [Development Environment](#development-environment)
- [License](#license)

## Project Overview

This project implements comprehensive device drivers for the SysTick timer and Nested Vectored Interrupt Controller (NVIC) targeting TM4C series microcontrollers. The implementation focuses on embedded systems programming principles, emphasizing real-time system timing mechanisms and sophisticated interrupt management architectures. The system is configured to operate at a 16MHz clock frequency, providing precise timing control for embedded applications.

## Project Objectives

### SysTick Timer Driver Development
- Initialize and configure the SysTick timer with millisecond-precision timing
- Implement dual-mode operation supporting both interrupt-driven and polling-based techniques
- Develop interrupt service routine with callback function support
- Provide comprehensive timer control including start, stop, and deinitialization functions

### NVIC Driver Implementation
- Enable and disable interrupt requests for specific IRQ numbers from the target vector table
- Configure interrupt priority levels with full priority range support
- Manage ARM Cortex-M system and fault exceptions including Bus Fault and SysTick exceptions
- Implement exception priority configuration for system-level interrupt management

## Technical Features

### Core Functionality
- **Dual-Mode Timer Operation**: SysTick implementation supporting both periodic interrupt generation and precision busy-wait delay mechanisms
- **Priority-Based Interrupt Management**: NVIC driver with configurable interrupt priorities and comprehensive IRQ control
- **System Exception Handling**: Complete ARM Cortex-M system exception management including fault exception processing
- **Callback Function Architecture**: Flexible callback mechanism for interrupt service routine customization

### Design Characteristics
- Modular driver architecture with clear separation of concerns
- Hardware abstraction layer compliant with ARM Cortex-M specifications
- Reentrant and thread-safe function implementations
- Comprehensive error handling and validation mechanisms

## API Reference

### SysTick Driver Interface

```c
/**
 * @brief Initialize SysTick timer for periodic interrupt generation
 * @param a_TimeInMilliSeconds: Timer period in milliseconds
 */
void SysTick_Init(uint16 a_TimeInMilliSeconds);

/**
 * @brief Initialize SysTick timer using busy-wait technique
 * @param a_TimeInMilliSeconds: Delay duration in milliseconds
 */
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);

/**
 * @brief SysTick interrupt service routine handler
 */
void SysTick_Handler(void);

/**
 * @brief Configure callback function for SysTick interrupt
 * @param Ptr2Func: Pointer to callback function
 */
void SysTick_SetCallBack(volatile void (*Ptr2Func)(void));

/**
 * @brief Stop SysTick timer operation
 */
void SysTick_Stop(void);

/**
 * @brief Start/Resume SysTick timer operation
 */
void SysTick_Start(void);

/**
 * @brief Deinitialize SysTick timer
 */
void SysTick_DeInit(void);
```

### NVIC Driver Interface

```c
/**
 * @brief Enable interrupt request for specific IRQ number
 * @param IRQ_Num: IRQ number from target vector table
 */
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);

/**
 * @brief Disable interrupt request for specific IRQ number
 * @param IRQ_Num: IRQ number from target vector table
 */
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);

/**
 * @brief Set priority for specific IRQ number
 * @param IRQ_Num: IRQ number from target vector table
 * @param IRQ_Priority: Priority level for the IRQ
 */
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);

/**
 * @brief Enable specific ARM system or fault exception
 * @param Exception_Num: Exception number
 */
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);

/**
 * @brief Disable specific ARM system or fault exception
 * @param Exception_Num: Exception number
 */
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);

/**
 * @brief Set priority for specific ARM system or fault exception
 * @param Exception_Num: Exception number
 * @param Exception_Priority: Priority level for the exception
 */
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);
```

## System Requirements

### Hardware Platform
- **Target Microcontroller**: TM4C series (TM4C123GH6PM)
- **System Clock**: 16MHz operation frequency
- **Architecture**: ARM Cortex-M4F processor core

### Software Requirements
- ARM Cortex-M architecture compliance
- Modular project structure with organized directory hierarchy
- Comprehensive documentation using standardized comment format
- Source and header file separation following embedded software best practices

## Documentation Standards

All driver functions include comprehensive documentation following this standardized format:

```c
/*********************************************************************
* Service Name: NVIC_EnableIRQ
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to enable Interrupt request for specific IRQ
**********************************************************************/
```

## Testing & Validation

### Test Application 1: Interrupt-Driven Operation
- Validates SysTick interrupt functionality with NVIC IRQ management
- Tests GPIO Port F interrupt configuration and priority settings
- Demonstrates LED rolling pattern control with switch-based timer control
- Verifies register-level configuration including NVIC_EN0_REG and NVIC_PRI7_REG

### Test Application 2: Polling-Based Operation  
- Tests SysTick busy-wait implementation
- Validates system exception configuration and priority management
- Includes comprehensive assertion-based validation for exception settings
- Demonstrates LED control using polling-based timing mechanisms



## Implementation Highlights

- **Register-Level Programming**: Direct manipulation of ARM Cortex-M system registers including NVIC_EN0_REG, NVIC_PRI7_REG, and NVIC_SYSTEM_PRI3_REG
- **Real-Time Performance**: Optimized implementations ensuring deterministic timing behavior
- **Comprehensive Exception Management**: Full support for ARM Cortex-M system and fault exceptions
- **Industrial-Grade Quality**: Professional-level code structure suitable for production embedded systems

## Development Environment

**IDE**: Code Composer Studio (CCS)  
**Target Platform**: ARM Cortex-M4F (TM4C123GH6PM)  
**Programming Language**: C  
**Testing Framework**: CUnit Testing Framework

## License

This is an educational Advanced Embedded systems project for the EDGES Training Program.

---

**Developed by**: Bassam Ashraf  
**Course**: Advanced Embedded Diploma  
**Program**: EDGES Training Program  
**IDE**: Code Composer Studio  
**Language**: C

---

*This project serves as a comprehensive demonstration of embedded systems programming principles, focusing on low-level hardware interaction and real-time system design using ARM Cortex-M architecture.*
