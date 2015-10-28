///////////////////////////////////////////////////////////
//  MCU.cpp
//  Implementation of the Class CMCU
//  Created on:      14-���-2011 11:34:33
//  Original author: �����
///////////////////////////////////////////////////////////

#include "Defines.h"
#include "Configuration.h"
#include "Version.h"
#include "MCU.h"


// -=[ ���������������� ���� ]=-


// -=[ ������� ������ ]=-


// -=[ ���������� �� ����-������ ]=-


// -=[ ���������� � ��� ]=-


/***********************
*  � � � � � � � � � �
*  ~~~~~~~~~~~~~~~~~~~
************************/


/**
 * ������� (��������) ����� ���������
 */
HRESULT CMCU::MainThreadProcedure(){

    __enable_interrupt();

    do {


    } while ( true );

    // ��� �������� ������ �������, ������ � ������� ���������
    return NO_ERROR;

}


/**
 * ������������� ���� ���������
 */
void CMCU::Initialization(){

    // ��������� ������ � ������� SRAM [ATmega128]
    //ExternalSRAMInit();

    // ��������� �������/�������� 0 [ATmega128]
    //Timer0Init();

    // ��������� �������/�������� 1 [ATmega128]
    //Timer1Init();

    // ��������� ����������� ����������� ������� [ATmega128]
    //InternalWDTInit();

    // ����� ���������� (�������� �������) [ATmega128]
    //PortsInit();

    // ��������� ����������� USART [ATmega128]
    //USART0Init();

    // ��������� ����������������� ���������� SPI [ATmega128]
    //SPIInit();

    // ��������� ������ � �������� ������������ [ATmega128] 
    //ExternalInterruptsInit();

    // ��������� ����������� ��������� ����������� [ATmega128]
    //ControlRegistersInit();

}


/**
 * ��������� �������/�������� 1
 */
void CMCU::Timer1Init(){

    // [ATmega128] Table. Clock Select Bit Description
    // +----+----+----+-----------------------------------------------------------------+
    // |CSn2|CSn1|CSn0| Description                                                     �
    // +----+----+----+-----------------------------------------------------------------+
    // | 0  | 0  | 0  | No clock source. (������/������� ����������)                    |
    // | 0  | 0  | 1  | clkI/O/1    (No prescaling)                                     |
    // | 0  | 1  | 0  | clkI/O/8    (From prescaler)                                    |
    // | 0  | 1  | 1  | clkI/O/64   (From prescaler)                                    |
    // | 1  | 0  | 0  | clkI/O/256  (From prescaler)                                    |
    // | 1  | 0  | 1  | clkI/O/1024 (From prescaler)                                    |
    // | 1  | 1  | 0  | ����� �n, ���� �������������� �� ���������� ������ ���������    |
    // | 1  | 1  | 1  | ����� �n, ���� �������������� �� ������������ ������ ���������  |
    // +----+----+----+-----------------------------------------------------------------+

    // Timer/Counter1 Control Register B
    // [ ������� ���������� B ��������/��������� 1 ][ATmega128]
    //            00000000 - Initial Value
    //TCCR1B = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||		
    //            76543210
    //            |||||||+- 0, rw, CS10:  -+
    //            ||||||+-- 1, rw, CS11:   | - ���������� �������� ��������
    //            |||||+--- 2, rw, CS12:  _|
    //            ||||+---- 3, rw, WGM12: -+ - ����� ������ �������/��������
    //            |||+----- 4, rw, WGM13: _|
    //            ||+------ 5, r: 0          - ��������������, ������ ���� ���������� � 0 ��� ������
    //            |+------- 6, rw, ICES1:    - ����� ��������� ������ ������� �������
    //            +-------- 7, rw, ICNC1:    - ���������� ������ ���������� ����� ����� �������
    // ����������:

    // ������������� �������� ��� ������� ���������
    //TCNT1H = 0x00; // ( 0xFFFF - Delay * F_CPU / PrescaleValue ) >> 8
    //TCNT1L = 0x00; // ( 0xFFFF - Delay * F_CPU / PrescaleValue )
    /*
    OCR1AH = 0x00;
    OCR1AL = 0x39;

    OCR1BH = 0x00;
    OCR1BL = 0x39;

    OCR1CH = 0x00;
    OCR1CL = 0x39;

    ICR1H  = 0x00;
    ICR1L  = 0x39;
    */
    // Timer/Counter1 Control Register A
    // [ ������� ���������� A ��������/��������� 1 ][ATmega128]
    //            00000000 - Initial Value
    //TCCR1A = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||	
    //            76543210
    //            |||||||+- 0, rw, WGM10:  -+ - ����� ������ �������/��������
    //            ||||||+-- 1, rw, WGM11:  _|
    //            |||||+--- 2, rw, COM1C0: -+ - ����� ������ ������ ��������� C
    //            ||||+---- 3, rw, COM1C1: _|
    //            |||+----- 4, rw, COM1B0: -+ - ����� ������ ������ ��������� B
    //            ||+------ 5, rw, COM1B1: _|
    //            |+------- 6, rw, COM1A0: -+ - ����� ������ ������ ��������� A
    //            +-------- 7, rw, COM1A1: _|
    // ����������: ���������� ����� ������ ...


    //TCCR1B = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||	
    //            76543210
    //            |||||||+- 0, rw, CS10:  -+
    //            ||||||+-- 1, rw, CS11:   | - ���������� �������� ��������
    //            |||||+--- 2, rw, CS12:  _|
    //            ||||+---- 3, rw, WGM12: -+ - ����� ������ �������/��������
    //            |||+----- 4, rw, WGM13: _|
    //            ||+------ 5, r: 0          - ��������������, ������ ���� ���������� � 0 ��� ������
    //            |+------- 6, rw, ICES1:    - ����� ��������� ������ ������� �������
    //            +-------- 7, rw, ICNC1:    - ���������� ������ ���������� ����� ����� �������
    // ����������: ����������� ������� �������� ������� ���������� ������ ...
    // ����� ������: ...

}


/**
 * ��������� ����������������� ���������� SPI
 */
void CMCU::SPIInit(){

    // SPI Control Register
    // [ ������� ���������� SPI ][ATmega128]
    //          00000000 - Initial Value
    //SPCR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||	
    //          76543210
    //          |||||||+- 0, rw, SPR0: -+ - �������� ��������
    //          ||||||+-- 1, rw, SPR1: _|
    //          |||||+--- 2, rw, CPHA:    - ���� ��������� �������
    //          ||||+---- 3, rw, CPOL:    - ���������� ��������� �������
    //          |||+----- 4, rw, MSTR:    - ����� ������ ������ (Master/Slave)
    //          ||+------ 5, rw, DORD:    - ������� �������� ������
    //          |+------- 6, rw, SPE:     - ���������/���������� SPI
    //          +-------- 7, rw, SPIE:    - ���������� ���������� �� SPI
    // ����������:


    // SPI Status Register
    // [ ������� ������� SPI ][ATmega128]
    //          00000000 - Initial Value
    //SPSR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||	
    //          76543210
    //          |||||||+- 0, rw, SPI2X:    - Double SPI Speed Bit
    //          ||||||+-- 1, r, 0       -+
    //          |||||+--- 2, r, 0        |
    //          ||||+---- 3, r, 0        | - ���������������
    //          |||+----- 4, r, 0        |
    //          ||+------ 5, r, 0       _|
    //          |+------- 6, r, WCOL:      - Write COLlision flag
    //          +-------- 7, r, SPIF:      - SPI Interrupt Flag
    // ����������:

}


/**
 * ��������� ����������������� ���������� TWI
 */
void CMCU::TWIInit(){

    // TWI Bit Rate Register
    //TWBR = 0x00; // TODO: �������� ������� ��� ��������� ��������

    // TWI Control Register
    // [ ������� ���������� TWI ][ATmega128]
    //          00000000 - Initial Value
    //TWCR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||	
    //          76543210
    //          |||||||+- 0, rw, TWIE:  - TWI Interrupt Enable
    //          ||||||+-- 1, r:         - reserved (will always read as zero)
    //          |||||+--- 2, rw, TWEN:  - TWI Enable Bit
    //          ||||+---- 3, r,  TWWC:  - TWI Write Collision Flag
    //          |||+----- 4, rw, TWSTO: - TWI STOP Condition Bit
    //          ||+------ 5, rw, TWSTA: - TWI START Condition Bit
    //          |+------- 6, rw, TWEA:  - TWI Enable Acknowledge Bit
    //          +-------- 7, rw, TWINT: - TWI Interrupt Flag
    // ����������:


    // TWI Status Register
    // [ TWI ������ ������� ][ATmega128]
    //          11111000 - Initial Value
    //TWSR = BIN8(11111000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, TWPS0: -+ - TWI Prescaler Bits
    //          ||||||+-- 1, rw, TWPS1: _|
    //          |||||+--- 2, r:            - reserved (will always read as zero)
    //          ||||+---- 3, r, TWS3:   -+
    //          |||+----- 4, r, TWS4:    |
    //          ||+------ 5, r, TWS5:    | - TWI Status
    //          |+------- 6, r, TWS6:    |
    //          +-------- 7, r, TWS7:   _|
    // ����������:

    // TWI (Slave) Address Register
    // ����� � ����, ��� ������� �������� ��� TWGCE (TWI General Call Recognition Enable Bit)
    //TWAR = 0xFE;

}


/**
 * ��������� ����������� USART0
 */
void CMCU::USART0Init(){

    // USART0 Control and Status Register A
    // [ ������� ���������� USART0A ]
    //            00100000 - Initial Value
    //UCSR0A = BIN8(00100000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||		
    //            76543210
    //            |||||||+- 0, rw, MPCM0: - Multi-Processor Communication Mode
    //            ||||||+-- 1, rw, U2X0:  - Double the USART Transmission Speed
    //            |||||+--- 2, r,  UPE0:  - Parity Error
    //            ||||+---- 3, r,  DOR0:  - Data OverRun
    //            |||+----- 4, r,  FE0:   - Frame Error
    //            ||+------ 5, r,  UDRE0: - USART Data Register Empty
    //            |+------- 6, rw, TXC:   - USART Transmit Complete
    //            +-------- 7, r,  RXC0:  - USART Receive Complete
    // ����������:


    //UCSR0B = 0x00; // ���������, ���� ����������� ��������

    // ����������� BAUD ��. � �����: "Configuration.h"
    //UBRR0L = ( uint8_t ) ( F_CPU / ( 16UL * BAUD ) - 1UL ); // ������������� ��������
    //UBRR0H = ( uint8_t ) ( ( F_CPU / ( 16UL * BAUD ) - 1UL ) >> 8 );

    // USART0 Control and Status Register B
    //            00000000 - Initial Value
    //UCSR0B = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||		
    //            76543210
    //            |||||||+- 0, rw, TXB8:  - Transmit Data Bit 8
    //            ||||||+-- 1, r,  RXB8:  - Receive Data Bit 8
    //            |||||+--- 2, rw, UCSZ2: - Character Size
    //            ||||+---- 3, rw, TXEN:  - Transmitter Enable
    //            |||+----- 4, rw, XEN:   - Receiver Enable
    //            ||+------ 5, rw, UDRIE: - USART Data Register Empty Interrupt Enable
    //            |+------- 6, rw, TXCIE: - TX Complete Interrupt Enable
    //            +-------- 7, rw, RXCIE: - RX Complete Interrupt Enable
    // ����������:


    // USART0 Control and Status Register C
    //            00000110 - Initial Value
    //UCSR0C = BIN8(00000110); // BIN8() �� ������� �� ������ �����������
    //            ||||||||	
    //            76543210
    //            |||||||+- 0, rw, UCPOL0:    - Clock Polarity
    //            ||||||+-- 1, rw, UCSZ00: -+ - Character Size
    //            |||||+--- 2, rw, UCSZ01: _|
    //            ||||+---- 3, rw, USBS0:     - Stop Bit Select
    //            |||+----- 4, rw, UPM00:  -+ - Parity Mode
    //            ||+------ 5, rw, UPM01:  _|
    //            |+------- 6, rw, UMSEL0:    - USART Mode Select
    //            +-------- 7, rw:            - reserved (must be written to zero when UCSRnC is written)
    // ����������:

}


/**
 * -=[ ����� ���������� (�������� �������) MCU ATmega128 ]=-
 */
void CMCU::PortsInit(){

    // ��������: ����� �� ���� ������������� � �����������, ��� ���������
    // ������ ��������������� ���������� �����(��). ��� ����� �������
    // ��������� �������:
    // ��� �������: Example
    // ���� ����� (URI): file:///
    // ��� ����� ����� (MD5):
    // ���:
    // ����: 14.07.2011
    // ����������� �����: �������� ��������
    // ���������� ������������:
    //  mailto:unihomelab@ya.ru
    //  skype: viacheslavmezentsev

    // Table. Port Pin Configurations
    //+-----+------+----------+--------+---------+--------------------------------------------+
    //| DDxn|PORTxn|   PUD    |  I/O   | Pull-up |   Comment                                  |
    //|     |      |(in SFIOR)|        |         |                                            |
    //+-----+------+----------+--------+---------+--------------------------------------------+
    //|  0  |  0   |    X     | Input  |   No    | Tri-state (Hi-Z)                           |
    //|  0  |  1   |    0     | Input  |   Yes   | Pxn will source current if ext. pulled low.|
    //|  0  |  1   |    1     | Input  |   No    | Tri-state (Hi-Z)                           |
    //|  1  |  0   |    X     | Output |   No    | Output Low (Sink)                          |
    //|  1  |  1   |    X     | Output |   No    | Output High (Source)                       |
    //+-----+------+----------+--------+---------+--------------------------------------------+
    // ���� �� ��� PUD ���������� � 1, �������������
    // ��������� ����������� �� ���� ������� ����������������.

    //sbi( SFIOR, PUD );

    // ��������� ������ A-G. ��������� ������������� �������

    // Port A Data Direction Register
    // [ ������� ����������� ����� A ][ATmega128]
    //          00000000 - Initial Value
    DDRA = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDA0: -
    //          ||||||+-- 1, rw, DDA1: -
    //          |||||+--- 2, rw, DDA2: -
    //          ||||+---- 3, rw, DDA3: -
    //          |||+----- 4, rw, DDA4: -
    //          ||+------ 5, rw, DDA5: -
    //          |+------- 6, rw, DDA6: -
    //          +-------- 7, rw, DDA7: -
    // ����������:

    // Port B Data Direction Register
    // [ ������� ����������� ����� B ][ATmega128]
    //          00000000 - Initial Value
    DDRB = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDB0: -
    //          ||||||+-- 1, rw, DDB1: -
    //          |||||+--- 2, rw, DDB2: -
    //          ||||+---- 3, rw, DDB3: -
    //          |||+----- 4, rw, DDB4: -
    //          ||+------ 5, rw, DDB5: -
    //          |+------- 6, rw, DDB6: -
    //          +-------- 7, rw, DDB7: -
    // ����������:

    // Port C Data Direction Register
    // [ ������� ����������� ����� C ][ATmega128]
    //          00000000 - Initial Value
    DDRC = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDC0: -
    //          ||||||+-- 1, rw, DDC1: -
    //          |||||+--- 2, rw, DDC2: -
    //          ||||+---- 3, rw, DDC3: -
    //          |||+----- 4, rw, DDC4: -
    //          ||+------ 5, rw, DDC5: -
    //          |+------- 6, rw, DDC6: -
    //          +-------- 7, rw, DDC7: -
    // ����������:

    // Port D Data Direction Register
    // [ ������� ����������� ����� D ][ATmega128]
    //          00000000 - Initial Value
    DDRD = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDD0: -
    //          ||||||+-- 1, rw, DDD1: -
    //          |||||+--- 2, rw, DDD2: -
    //          ||||+---- 3, rw, DDD3: -
    //          |||+----- 4, rw, DDD4: -
    //          ||+------ 5, rw, DDD5: -
    //          |+------- 6, rw, DDD6: -
    //          +-------- 7, rw, DDD7: -
    // ����������:

    // Port E Data Direction Register
    // [ ������� ����������� ����� E ][ATmega128]
    //          00000000 - Initial Value
    DDRE = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDE0: -
    //          ||||||+-- 1, rw, DDE1: -
    //          |||||+--- 2, rw, DDE2: -
    //          ||||+---- 3, rw, DDE3: -
    //          |||+----- 4, rw, DDE4: -
    //          ||+------ 5, rw, DDE5: -
    //          |+------- 6, rw, DDE6: -
    //          +-------- 7, rw, DDE7: -
    // ����������:

    // Port F Data Direction Register
    // [ ������� ����������� ����� F ][ATmega128]
    //          00000000 - Initial Value
    DDRF = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDF0: -
    //          ||||||+-- 1, rw, DDF1: -
    //          |||||+--- 2, rw, DDF2: -
    //          ||||+---- 3, rw, DDF3: -
    //          |||+----- 4, rw, DDF4: -
    //          ||+------ 5, rw, DDF5: -
    //          |+------- 6, rw, DDF6: -
    //          +-------- 7, rw, DDF7: -
    // ����������:

    // Port G Data Direction Register
    // [ ������� ����������� ����� G ][ATmega128]
    //          00000000 - Initial Value
    DDRG = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||
    //          76543210
    //          |||||||+- 0, rw, DDG0: -
    //          ||||||+-- 1, rw, DDG1: -
    //          |||||+--- 2, rw, DDG2: -
    //          ||||+---- 3, rw, DDG3: -
    //          |||+----- 4, rw, DDG4: -
    //          ||+------ 5, r: 0
    //          |+------- 6, r: 0
    //          +-------- 7, r: 0
    // ����������:

    // Port A Data Register
    // [ ������� ������ ����� A ][ATmega128]
    //           00000000 - Initial Value
    PORTA = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTA0: (AD0) -
    //           ||||||+-- 1, rw, PORTA1: (AD1) -
    //           |||||+--- 2, rw, PORTA2: (AD2) -
    //           ||||+---- 3, rw, PORTA3: (AD3) -
    //           |||+----- 4, rw, PORTA4: (AD4) -
    //           ||+------ 5, rw, PORTA5: (AD5) -
    //           |+------- 6, rw, PORTA6: (AD6) -
    //           +-------- 7, rw, PORTA7: (AD7) -
    // ����������:

    // Port B Data Register
    // [ ������� ������ ����� B ][ATmega128]
    //           00000000 - Initial Value
    PORTB = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTB0: (~SS)      -
    //           ||||||+-- 1, rw, PORTB1: (SCK)      -
    //           |||||+--- 2, rw, PORTB2: (MOSI)     -
    //           ||||+---- 3, rw, PORTB3: (MISO)     -
    //           |||+----- 4, rw, PORTB4: (OC0)      -
    //           ||+------ 5, rw, PORTB5: (OC1A)     -
    //           |+------- 6, rw, PORTB6: (OC1B)     -
    //           +-------- 7, rw, PORTB7: (OC2/OC1C) -
    // ����������:

    // Port C Data Register
    // [ ������� ������ ����� C ][ATmega128]
    //           00000000 - Initial Value
    PORTC = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTC0: -
    //           ||||||+-- 1, rw, PORTC1: -
    //           |||||+--- 2, rw, PORTC2: -
    //           ||||+---- 3, rw, PORTC3: -
    //           |||+----- 4, rw, PORTC4: -
    //           ||+------ 5, rw, PORTC5: -
    //           |+------- 6, rw, PORTC6: -
    //           +-------- 7, rw, PORTC7: -
    // ����������:

    // Port D Data Register
    // [ ������� ������ ����� D ][ATmega128]
    //           00000000 - Initial Value
    PORTD = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTD0: (SCL/INT0)  -
    //           ||||||+-- 1, rw, PORTD1: (SDA/INT1)  -
    //           |||||+--- 2, rw, PORTD2: (RXD1/INT2) -
    //           ||||+---- 3, rw, PORTD3: (TXD1/INT3) -
    //           |||+----- 4, rw, PORTD4: (ICP1)      -
    //           ||+------ 5, rw, PORTD5: ((XCK1)     -
    //           |+------- 6, rw, PORTD6: (T1)        -
    //           +-------- 7, rw, PORTD7: (T2)        -
    // ����������:

    // Port E Data Register
    // [ ������� ������ ����� E ][ATmega128]
    //           00000000 - Initial Value
    PORTE = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTE0: (RXD0/(PDI))  -
    //           ||||||+-- 1, rw, PORTE1: (TXD0/PDO)    -
    //           |||||+--- 2, rw, PORTE2: (XCK0/AIN0)   -
    //           ||||+---- 3, rw, PORTE3: (OC3A/AIN1)   -
    //           |||+----- 4, rw, PORTE4: (OC3B/INT4)   -
    //           ||+------ 5, rw, PORTE5: (OC3C/INT5)   -
    //           |+------- 6, rw, PORTE6: (T3/INT6)     -
    //           +-------- 7, rw, PORTE7: (ICP3/INT7)   -
    // ����������:

    // Port F Data Register
    // [ ������� ������ ����� F ][ATmega128]
    //           00000000 - Initial Value
    PORTF = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTF0: (ADC0) -
    //           ||||||+-- 1, rw, PORTF1: (ADC1) -
    //           |||||+--- 2, rw, PORTF2: (ADC2) -
    //           ||||+---- 3, rw, PORTF3: (ADC3) -
    //           |||+----- 4, rw, PORTF4: (ADC4/TCK) -
    //           ||+------ 5, rw, PORTF5: (ADC5/TMS) -
    //           |+------- 6, rw, PORTF6: (ADC6/TDO) -
    //           +-------- 7, rw, PORTF7: (ADC7/TDI) -
    // ����������:

    // Port G Data Register
    // [ ������� ������ ����� G ][ATmega128]
    //           00000000 - Initial Value
    PORTG = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, PORTG0: (~WR)   -
    //           ||||||+-- 1, rw, PORTG1: (~RD)   -
    //           |||||+--- 2, rw, PORTG2: (ALE)   -
    //           ||||+---- 3, rw, PORTG3: (TOSC2) -
    //           |||+----- 4, rw, PORTG4: (TOSC1) -
    //           ||+------ 5, r: 0
    //           |+------- 6, r: 0
    //           +-------- 7, r: 0
    // ����������:

}


/**
 * ��������� ����������� ����������� �������
 */
void CMCU::InternalWDTInit(){

    // [ATmega128] Table. Watchdog Timer Prescale Select
    // +----+----+----+------------------+---------+---------+
    // |WDP2|WDP1|WDP0|OscCycles         | VCC3.0V | VCC5.0V |
    // +----+----+----+------------------+---------+---------+
    // | 0  | 0  | 0  |16K (16,384)      | 14.8 ms | 14.0 ms |
    // | 0  | 0  | 1  |32K (32,768)      | 29.6 ms | 28.1 ms |
    // | 0  | 1  | 0  |64K (65,536)      | 59.1 ms | 56.2 ms |
    // | 0  | 1  | 1  |128K (131,072)    | 0.12 s  | 0.11 s  |
    // | 1  | 0  | 0  |256K (262,144)    | 0.24 s  | 0.22 s  |
    // | 1  | 0  | 1  |512K (524,288)    | 0.47 s  | 0.45 s  |
    // | 1  | 1  | 0  |1,024K (1,048,576)| 0.95 s  | 0.9 s   |
    // | 1  | 1  | 1  |2,048K (2,097,152)| 1.9 s   | 1.8 s   |
    // +----+----+----+------------------+---------+---------+

    // Watchdog Timer ControlRegister
    // [ ������� ���������� ����������� ������� ][ATmega128]
    //           00000000 - Initial Value
    //WDTCR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, WDP0: -+
    //           ||||||+-- 1, rw, WDP1:  |- ����������� ������� ������������ ����������� �������
    //           |||||+--- 2, rw, WDP2: _|
    //           ||||+---- 3, rw, WDE:  ���������� ������ �� ����-���� ����������� �������
    //           |||+----- 4, rw, WDCE: ���������� ��������� ������������ ����������� �������
    //           ||+------ 5, r, -+
    //           |+------- 6, r,  |- Reserved Bits
    //           +-------- 7, r, _|
    // ����������:
    // ������� ���������� ������. ����� � ���� ��� ���������� ����������
    // ����� ���������� ������� ������� ������� ��� ���������� � ������
    // ������������� �������.

}


/**
 * ��������� ������ � �������� ������������
 */
void CMCU::ExternalInterruptsInit(){

    // Table. Interrupt Sense Control
    //+-----+------+--------------------------------------------------------------------------+
    //|ISCn1|ISCn0 | Description                                                              |
    //+-----+------+--------------------------------------------------------------------------+
    //|  0  |  0   | The low level of INTn generates an interrupt request.                    |
    //|  0  |  1   | Reserved                                                                 |
    //|  1  |  0   | The falling edge of INTn generates asynchronously an interrupt request.  |
    //|  1  |  1   | The rising edge of INTn generates asynchronously an interrupt request.   |
    //+-----+------+--------------------------------------------------------------------------+

    // External Interrupt Control Register A
    // [ ������� ���������� �������� ������������ ]
    //           00000000 - Initial Value
    //EICRA = BIN8(00000000);
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, ISC00: -+ - External Interrupt 0 Sense Control Bits
    //           ||||||+-- 1, rw, ISC01: _|
    //           |||||+--- 2, rw, ISC10: -+ - External Interrupt 1 Sense Control Bits
    //           ||||+---- 3, rw, ISC11: _|
    //           |||+----- 4, rw, ISC20: -+ - External Interrupt 2 Sense Control Bits
    //           ||+------ 5, rw, ISC21: _|
    //           |+------- 6, rw, ISC30: -+ - External Interrupt 3 Sense Control Bits
    //           +-------- 7, rw, ISC31: _|
    // When changing the ISCn1/ISCn0 bits, the interrupt must be disabled by clearing its
    // Interrupt Enable bit in the EIMSK Register. Otherwise an interrupt can occur when
    // the bits are changed.
    // ����������:


    // External Interrupt Control Register B
    // [ ������� ���������� �������� ������������ ]
    //           00000000 - Initial Value
    //EICRB = BIN8(00000000);
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, ISC40: -+ - External Interrupt 4 Sense Control Bits
    //           ||||||+-- 1, rw, ISC41: _|
    //           |||||+--- 2, rw, ISC50: -+ - External Interrupt 5 Sense Control Bits
    //           ||||+---- 3, rw, ISC51: _|
    //           |||+----- 4, rw, ISC60: -+ - External Interrupt 6 Sense Control Bits
    //           ||+------ 5, rw, ISC61: _|
    //           |+------- 6, rw, ISC70: -+ - External Interrupt 7 Sense Control Bits
    //           +-------- 7, rw, ISC71: _|
    // When changing the ISCn1/ISCn0 bits, the interrupt must be disabled by clearing its
    // Interrupt Enable bit in the EIMSK Register. Otherwise an interrupt can occur when
    // the bits are changed.
    // ����������:


    // External Interrupt Mask Register
    // [ ����� ������� ����������� ������������ ]
    //           00000000 - Initial Value
    //EIMSK = BIN8(00000000);
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, INT0: - External Interrupt Request 0 Enable
    //           ||||||+-- 1, rw, INT1: - External Interrupt Request 1 Enable
    //           |||||+--- 2, rw, INT2: - External Interrupt Request 2 Enable
    //           ||||+---- 3, rw, INT3: - External Interrupt Request 3 Enable
    //           |||+----- 4, rw, INT4: - External Interrupt Request 4 Enable
    //           ||+------ 5, rw, INT5: - External Interrupt Request 5 Enable
    //           |+------- 6, rw, INT6: - External Interrupt Request 6 Enable
    //           +-------- 7, rw, INT7: - External Interrupt Request 7 Enable
    // ����������:

}


/**
 * ��������� �������/�������� 0
 */
void CMCU::Timer0Init(){

    // [ATmega128] Table. Clock Select Bit Description
    // +----+----+----+------------------------------------------------+
    // |CSn2|CSn1|CSn0| Description                                    �
    // +----+----+----+------------------------------------------------+
    // | 0  | 0  | 0  | No clock source. (������/������� ����������)   |
    // | 0  | 0  | 1  | clkT0S/(No prescaling)                         |
    // | 0  | 1  | 0  | clkT0S/8    (From prescaler)                   |
    // | 0  | 1  | 1  | clkT0S/32   (From prescaler)                   |
    // | 1  | 0  | 0  | clkT0S/64   (From prescaler)                   |
    // | 1  | 0  | 1  | clkT0S/128  (From prescaler)                   |
    // | 1  | 1  | 0  | clkT0S/256  (From prescaler)                   |
    // | 1  | 1  | 1  | clkT0S/1024 (From prescaler)                   |
    // +----+----+----+------------------------------------------------+

    // Timer/Counter 0 Control Register
    // [ ������� ���������� ��������/��������� 0 ]
    //           00000000 - Initial Value
    //TCCR0 = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||	
    //           76543210
    //           |||||||+- 0, rw, CS00:  -+
    //           ||||||+-- 1, rw, CS01:   | - ���������� �������� ��������
    //           |||||+--- 2, rw, CS02:  _|
    //           ||||+---- 3, rw, WGM01: -+ - Waveform Generation Mode
    //           |||+----- 4, rw, COM00: -+ - Compare Match Output Mode
    //           ||+------ 5, rw: COM01  _|
    //           |+------- 6, rw, WGM00:    - Waveform Generation Mode
    //           +-------- 7, w, FOC0:      - Force Output Compare
    // ����������:


    // ������������� �������� ��� �������� ��������
    //TCNT0 = 0xFF - F_CPU / 1024000UL;

    // Timer/Counter0 Output Compare Register
    //OCR0 = 0x00;

    // Timer/Counter0 Asynchronous Status Register
    // [ ������� ... ][ATmega128]
    //          00000000 - Initial Value
    //ASSR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||	
    //          76543210
    //          |||||||+- 0, r, TCR0UB: - Timer/Counter Control Register0 Update Busy
    //          ||||||+-- 1, r, OCR0UB: - Output Compare Register0 Update Busy
    //          |||||+--- 2, r, TCN0UB: - Timer/Counter0 Update Busy
    //          ||||+---- 3, rw, AS0:   - Asynchronous Timer/Counter0
    //          |||+----- 4, r, -:
    //          ||+------ 5, r, -:
    //          |+------- 6, r, -:
    //          +-------- 7, r, -:
    // ����������: ���������� ����� ������ ...

}


/**
 * ��������� ������ � ������� ������� SRAM
 */
void CMCU::ExternalSRAMInit(){

    //  Table. Sector limits with different settings of SRL2..0
    // +-----+-----+-----+-------------------------------------------------------------------+
    // |SRL2 |SRL1 |SRL0 | Sector Limits                                                     |
    // +-----+-----+-----+-------------------------------------------------------------------+
    // |  0  |  0  |  0  | Lower sector = N/A.             Upper sector = 0x1100 - 0xFFFF    |
    // |  0  |  0  |  1  | Lower sector = 0x1100 - 0x1FFF. Upper sector = 0x2000 - 0xFFFF    |
    // |  0  |  1  |  0  | Lower sector = 0x1100 - 0x3FFF. Upper sector = 0x4000 - 0xFFFF    |
    // |  0  |  1  |  1  | Lower sector = 0x1100 - 0x5FFF. Upper sector = 0x6000 - 0xFFFF    |
    // |  1  |  0  |  0  | Lower sector = 0x1100 - 0x7FFF. Upper sector = 0x8000 - 0xFFFF    |
    // |  1  |  0  |  1  | Lower sector = 0x1100 - 0x9FFF. Upper sector = 0xA000 - 0xFFFF    |
    // |  1  |  1  |  0  | Lower sector = 0x1100 - 0xBFFF. Upper sector = 0xC000 - 0xFFFF    |
    // |  1  |  1  |  1  | Lower sector = 0x1100 - 0xDFFF. Upper sector = 0xE000 - 0xFFFF    |
    // +-----+-----+-----+-------------------------------------------------------------------+
    // The external memory address space can be divided in two sectors that have separate
    // wait-state bits. The SRL2, SRL1, and SRL0 bits select the split of the sectors, see Table
    // 3 and Figure 11. By default, the SRL2, SRL1, and SRL0 bits are set to zero and the
    // entire external memory address space is treated as one sector. When the entire SRAM
    // address space is configured as one sector, the wait-states are configured by the
    // SRW11 and SRW10 bits.

    // [ATmega128] Table. Wait States
    // +-----+-----+-------------------------------------------------------------------------+
    // |SRWn1|SRWn0| Wait States                                                             �
    // +-----+-----+-------------------------------------------------------------------------+
    // |  0  |  0  | No wait-states                                                          |
    // |  0  |  1  | Wait one cycle during read/write strobe                                 |
    // |  1  |  0  | Wait two cycles during read/write strobe                                |
    // |  1  |  1  | Wait two cycles during read/write and wait one cycle before driving out |
    // |     |     | new address                                                             |
    // +-----+-----+-------------------------------------------------------------------------+

    // External Memory Control Register A
    // [ ������� ���������� ������� ������� A ][ATmega128]
    //           00000000 - Initial Value
    //XMCRA = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||		
    //           76543210
    //           |||||||+- 0, r, Res:       - Reserved Bit
    //           |||||||(MCUCR:6) SRW10: -+ - Wait-state Select Bits for Upper Sector
    //           ||||||+-- 1, rw, SRW11: _|
    //           |||||+--- 2, rw, SRW00: -+ - Wait-state Select Bits for Lower Sector
    //           ||||+---- 3, rw, SRW01: _|
    //           |||+----- 4, rw, SRL0:  -+ - Wait-state Sector Limit
    //           ||+------ 5, rw, SRL1:   |
    //           |+------- 6, rw, SRL2:  _|
    //           +-------- 7, r, Res:       - Reserved Bit
    // ����������:


    //   Table. Port C Pins Released as Normal Port Pins when the External Memory is Enabled
    //  +-----+-----+-----+------------------------------------+-------------------------------+
    //  |XMM2 |XMM1 |XMM0 | # Bits for External Memory Address |  Released Port Pins           |
    //  +-----+-----+-----+------------------------------------+-------------------------------+
    //  |  0  |  0  |  0  | 8 (Full 60 KB space)               | None                          |
    //  |  0  |  0  |  1  | 7                                  | PC7                           |
    //  |  0  |  1  |  0  | 6                                  | PC7 - PC6                     |
    //  |  0  |  1  |  1  | 5                                  | PC7 - PC5                     |
    //  |  1  |  0  |  0  | 4                                  | PC7 - PC4                     |
    //  |  1  |  0  |  1  | 3                                  | PC7 - PC3                     |
    //  |  1  |  1  |  0  | 2                                  | PC7 - PC2                     |
    //  |  1  |  1  |  1  | No Address high bits               | Full Port C                   |
    //  +-----+-----+-----+------------------------------------+-------------------------------+

    // External Memory Control Register B
    // [ ������� ���������� ������� ������� B ][ATmega128]
    //           00000000 - Initial Value
    //XMCRB = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||		
    //           76543210
    //           |||||||+- 0, rw, XMM0: -+ - External Memory High Mask
    //           ||||||+-- 1, rw, XMM1:  |
    //           |||||+--- 2, rw, XMM2: _|
    //           ||||+---- 3, r, -:
    //           |||+----- 4, r, -: 
    //           ||+------ 5, r, -: 
    //           |+------- 6, r, -: 
    //           +-------- 7, rw, XMBK:    - XMBK: External Memory Bus-keeper Enable
    // ����������:

}


/**
 * ��������� ����������� ��������� �����������
 */
void CMCU::ControlRegistersInit(){

    // MCU Control Register
    // [ ������� ���������� ����������������� ]
    //           00000000 - Initial Value
    //MCUCR = BIN8(00000000);
    //           ||||||||
    //           76543210
    //           |||||||+- 0, rw, IVCE:   - Interrupt Vector Change Enable
    //           ||||||+-- 1, rw, IVSEL:  - Interrupt Vector Select
    //           |||||+--- 2, rw, SM2: -+ - Interrupt 1 Sense Control
    //           ||||+---- 3, rw, SM0: _|
    //           |||+----- 4, rw, SM1:    - ��� 1 ������ ������ ���
    //           ||+------ 5, rw, SE:     - ���������� ������ ���
    //           |+------- 6, rw, SRW10:  - ��� ������ ������ ��������
    //           +-------- 7, rw, SRE:    - ��������� ������� SRAM/XMEM
    // ����������:


    // Timer/Counter Interrupt Mask Register
    // [ ������� ����� ���������� �� ��������/��������� ][ATmega128]
    //           00000000 - Initial Value
    //TIMSK = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||		
    //           76543210
    //           |||||||+- 0, rw, TOIE0:  - Timer/Counter0 Overflow Interrupt Enable
    //           ||||||+-- 1, rw, OCIE0:  - OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
    //           |||||+--- 2, rw, TOIE1:  - Timer/Counter1, Overflow Interrupt Enable
    //           ||||+---- 3, rw, OCIE1B: - Timer/Counter1, Output Compare B Match Interrupt Enable
    //           |||+----- 4, rw, OCIE1A: - Timer/Counter1, Output Compare A Match Interrupt Enable
    //           ||+------ 5, rw, TICIE1: - Timer/Counter1, Input Capture Interrupt Enable
    //           |+------- 6, rw, TOIE2:  - Timer/Counter2 Overflow Interrupt Enable
    //           +-------- 7, rw, OCIE2:  - Timer/Counter2 Output Compare Match Interrupt Enable
    // ����������:


    // Timer/Counter Interrupt Flag Register
    // [ ������� ������ ���������� ��������/��������� ]
    //          00000000 - Initial Value
    //TIFR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //          ||||||||	
    //          76543210
    //          |||||||+- 0, rw, TOV0:  - Timer/Counter0 Overflow Flag
    //          ||||||+-- 1, rw, OCF0:  - Output Compare Flag 0
    //          |||||+--- 2, rw, TOV1:  - Timer/Counter1, Overflow Flag
    //          ||||+---- 3, rw, OCF1B: - Timer/Counter1, Output Compare B Match Flag
    //          |||+----- 4, rw, OCF1A: - Timer/Counter1, Output Compare A Match Flag
    //          ||+------ 5, rw, ICF1:  - Timer/Counter1, Input Capture Flag
    //          |+------- 6, rw, TOV2:  - Timer/Counter2 Overflow Flag
    //          +-------- 7, rw, OCF2:  - Output Compare Flag 2
    // ����������:

    // Special Function IO Register
    // [ ������� ����������� ������� �����/������ ]
    //           00000000 - Initial Value
    //SFIOR = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //           ||||||||		
    //           76543210
    //           |||||||+- 0, rw, PSR321: - Prescaler Reset Timer/Counter3,
    //           |||||||                  - Timer/Counter2, and Timer/Counter1
    //           ||||||+-- 1, rw, PSR0:   - Prescaler Reset Timer/Counter0
    //           |||||+--- 2, rw, PUD:    - Pull-up disable
    //           ||||+---- 3, rw, ACME:   - Analog Comparator Multiplexer Enable
    //           |||+----- 4, r: 0
    //           ||+------ 5, r: 0
    //           |+------- 6, r: 0
    //           +-------- 7, rw, TSM:    - Timer/Counter Synchronization Mode
    // ����������:


    // ADC Control and Status Register A � ADCSRA
    // [ ������� ���������� � ��������� A ]
    //            00000000 - Initial Value
    //ADCSRA = BIN8(00000000); // BIN8() �� ������� �� ������ �����������
    //            ||||||||		
    //            76543210
    //            |||||||+- 0, rw, ADPS0: -+ - ADC Prescaler Select Bits
    //            ||||||+-- 1, rw, ADPS1:  |
    //            |||||+--- 2, rw, ADPS2: _|
    //            ||||+---- 3, rw, ADIE:     - ADC Interrupt Enable
    //            |||+----- 4, rw, ADIF:     - ADC Interrupt Flag
    //            ||+------ 5, rw, ADFR:     - ADC Free Running Select
    //            |+------- 6, rw, ADSC:     - ADC Start Conversion
    //            +-------- 7, rw, ADEN:     - ADC Enable
    // ����������:

}


// -=[ ����������� ���������� ]=-

/**
 * External Interrupt Request 0
 */
void CMCU::OnExternalInterruptRequest0(){

}


/**
 * External Interrupt Request 1
 */
void CMCU::OnExternalInterruptRequest1(){

}


/**
 * External Interrupt Request 2
 */
void CMCU::OnExternalInterruptRequest2(){

}


/**
 * External Interrupt Request 3
 */
void CMCU::OnExternalInterruptRequest3(){

}


/**
 * External Interrupt Request 4
 */
void CMCU::OnExternalInterruptRequest4(){

}


/**
 * External Interrupt Request 5
 */
void CMCU::OnExternalInterruptRequest5(){

}


/**
 * External Interrupt Request 6
 */
void CMCU::OnExternalInterruptRequest6(){

}


/**
 * External Interrupt Request 7
 */
void CMCU::OnExternalInterruptRequest7(){

}


/**
 * Timer/Counter2 Compare Match
 */
void CMCU::OnTimerCounter2CompareMatch(){

}


/**
 * Timer/Counter2 Overflow
 */
void CMCU::OnTimerCounter2Overflow(){

}


/**
 * Timer/Counter1 Capture Event
 */
void CMCU::OnTimerCounter1CaptureEvent(){

}


/**
 * Timer/Counter1 Compare Match A
 */
void CMCU::OnTimerCounter1CompareMatchA(){

}


/**
 * Timer/Counter Compare Match B
 */
void CMCU::OnTimerCounter1CompareMatchB(){

}


/**
 * Timer/Counter1 Overflow
 */
void CMCU::OnTimerCounter1Overflow(){

}


/**
 * Timer/Counter0 Compare Match
 */
void CMCU::OnTimerCounter0CompareMatch(){

}


/**
 * Timer/Counter0 Overflow
 */
void CMCU::OnTimerCounter0Overflow(){

}


/**
 * SPI Serial Transfer Complete
 */
void CMCU::OnSPISerialTransferComplete(){

}


/**
 * USART0, Rx Complete
 */
void CMCU::OnUSART0RxComplete( uint8_t data ){

}


/**
 * USART0 Data Register Empty
 */
void CMCU::OnUSART0DataRegisterEmpty(){

}


/**
 * USART0, Tx Complete
 */
void CMCU::OnUSART0TxComplete(){

}


/**
 * ADC Conversion Complete
 */
void CMCU::OnADCConversionComplete( uint16_t value ) {

}


/**
 * EEPROM Ready
 */
void CMCU::OnEEPROMReady(){

}


/**
 * Analog Comparator
 */
void CMCU::OnAnalogComparator(){

}


/**
 * Timer/Counter1 Compare Match C
 */
void CMCU::OnTimerCounter1CompareMatchC(){

}


/**
 * Timer/Counter3 Capture Event
 */
void CMCU::OnTimerCounter3CaptureEvent(){

}


/**
 * Timer/Counter3 Compare Match A
 */
void CMCU::OnTimerCounter3CompareMatchA(){

}


/**
 * Timer/Counter3 Compare Match B
 */
void CMCU::OnTimerCounter3CompareMatchB(){

}


/**
 * Timer/Counter3 Compare Match C
 */
void CMCU::OnTimerCounter3CompareMatchC(){

}


/**
 * Timer/Counter3 Overflow
 */
void CMCU::TimerCounter3Overflow(){

}


/**
 * Timer/Counter3 Overflow
 */
void CMCU::OnTimerCounter3Overflow(){

}


/**
 * USART1, Rx Complete
 */
void CMCU::OnUSART1RxComplete( uint8_t data ){

}


/**
 * USART1, Data Register Empty
 */
void CMCU::OnUSART1DataRegisterEmpty(){

}


/**
 * USART1, Tx Complete
 */
void CMCU::OnUSART1TxComplete(){

}


/**
 * 2-wire Serial Interface
 */
void CMCU::OnTWISerialInterface(){

}


/**
 * Store Program Memory Read
 */
void CMCU::OnStoreProgramMemoryRead(){

}


/**
 * ��������� ������ � ������������ �� �������
 */
void CMCU::PinChangeInterruptsInit(){

}