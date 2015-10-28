#pragma once

#include "Defines.h"

// Выбираем частоту внешнего тактового генератора
#ifdef __GNUC__

    // Частота задаётся в makefile директивой
    // -DF_CPU=8000000UL
    #ifndef F_CPU
        #error "F_CPU undefined!"
    #endif

#elif defined( __ICCAVR__ )

    #define F_CPU 8000000UL

#endif

// Используется для отладочной конфигурации
#ifndef __DEBUG__
    // Закомментируйте эту строку для компиляции релиза
    //#define __DEBUG__
#endif

// Скорость работы внутреннего USART
//#define BAUD 9600UL
//#define BAUD 19200UL
#define BAUD 38400UL
//#define BAUD 57600UL
//#define BAUD 115200UL


/**
 * Таблица векторов прерываний [ATmega2560]
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Разрешаем/запрещаем обработку прерываний.
 *
 * Эти определения влияют на включение/выключение кода
 * обработчиков в модуле ISRList.cpp. Если используется сторонний
 * обработчик прерывания, который не определён в ISRList.cpp, то
 * соответствующие флаги здесь должны быть закомментированы, чтобы
 * избежать конфликта при определении одного вектора прерывания
 * одновременно в нескольких местах проекта.
 */

//#define External_Interrupt_Request_0
//#define External_Interrupt_Request_1 
//#define External_Interrupt_Request_2 
//#define External_Interrupt_Request_3 
//#define External_Interrupt_Request_4 
//#define External_Interrupt_Request_5 
//#define External_Interrupt_Request_6 
//#define External_Interrupt_Request_7 

//#define Pin_Change_Interrupt_Request_0 
//#define Pin_Change_Interrupt_Request_1 
//#define Pin_Change_Interrupt_Request_2 

//#define Watchdog_Timeout_Interrupt

//#define Timer_Counter2_Compare_Match_A
//#define Timer_Counter2_Compare_Match_B
//#define Timer_Counter2_Overflow

//#define Timer_Counter1_Capture_Event
//#define Timer_Counter1_Compare_Match_A 
//#define Timer_Counter1_Compare_Match_B 
//#define Timer_Counter1_Compare_Match_C     
//#define Timer_Counter1_Overflow

//#define Timer_Counter0_Compare_Match_A
//#define Timer_Counter0_Compare_Match_B
//#define Timer_Counter0_Overflow

//#define SPI_Serial_Transfer_Complete

//#define USART0_Rx_Complete
//#define USART0_Data_Register_Empty
//#define USART0_Tx_Complete

//#define Analog_Comparator

//#define ADC_Conversion_Complete

//#define EEPROM_Ready

//#define Timer_Counter3_Capture_Event
//#define Timer_Counter3_Compare_Match_A
//#define Timer_Counter3_Compare_Match_B 
//#define Timer_Counter3_Compare_Match_C 
//#define Timer_Counter3_Overflow

//#define USART1_Rx_Complete 
//#define USART1_Data_Register_Empty
//#define USART1_Tx_Complete

//#define TWI_Serial_Interface

//#define Store_Program_Memory_Read

//#define Timer_Counter4_Capture_Event
//#define Timer_Counter4_Compare_Match_A
//#define Timer_Counter4_Compare_Match_B
//#define Timer_Counter4_Compare_Match_C
//#define Timer_Counter4_Overflow

//#define Timer_Counter5_Capture_Event
//#define Timer_Counter5_Compare_Match_A
//#define Timer_Counter5_Compare_Match_B
//#define Timer_Counter5_Compare_Match_C
//#define Timer_Counter5_Overflow

//#define USART2_Rx_Complete
//#define USART2_Data_Register_Empty
//#define USART2_Tx_Complete

//#define USART3_Rx_Complete
//#define USART3_Data_Register_Empty
//#define USART3_Tx_Complete
