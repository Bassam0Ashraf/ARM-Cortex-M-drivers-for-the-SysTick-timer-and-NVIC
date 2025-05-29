# SysTick & NVIC Driver Development  

## 📖 Project Overview  
Develop drivers for the SysTick timer and Nested Vectored Interrupt Controller (NVIC) on TM4C123GH6PM microcontroller. This project provides hands-on experience in embedded systems programming, focusing on system timers and interrupt management with a 16MHz clock speed.

## 🎯 Objectives  
- **SysTick Driver:** Initialize and control system timers, including interrupt and polling modes.  
- **NVIC Driver:** Manage interrupts, set priorities, and handle system exceptions with robust error handling.  

## 💡 Features  
- SysTick periodic interrupt generation and busy-wait delay.  
- NVIC interrupt enabling/disabling with configurable priority.  
- Handling of ARM system exceptions like Bus Fault and SysTick.  
- Safe and modular driver structure with clear APIs.

## 📚 Drivers & APIs  
Complies with ARM Cortex-M NVIC and SysTick design principles:  
```c
// SysTick Driver
void SysTick_Init(uint16 a_TimeInMilliSeconds);
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);
void SysTick_Handler(void);
void SysTick_SetCallBack(volatile void (*Ptr2Func)(void));
void SysTick_Stop(void);
void SysTick_Start(void);
void SysTick_DeInit(void);

// NVIC Driver
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);
void NVIC_EnableException(NVIC_ExceptionType Exception_Num);
void NVIC_DisableException(NVIC_ExceptionType Exception_Num);
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);
```

## 📋 Requirements  
- Compliance with ARM Cortex-M architecture standards.  
- Modular code with separate `src/`, `include/`, and `tests/` directories.  
- Doxygen-style comments for documentation and maintainability.

## 🚀 Implementation Highlights  
- SysTick and NVIC integration for time-critical and interrupt-driven tasks.  
- Support for dynamic configuration and robust error handling.  
- Efficient bit-level manipulation for register access.
