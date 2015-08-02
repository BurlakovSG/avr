///////////////////////////////////////////////////////////
//  MCU.h
//  Implementation of the Class CMCU
//  Created on:      14-���-2011 11:34:33
//  Original author: �����
///////////////////////////////////////////////////////////

#if !defined(EA_65BAC4E6_2352_4d1c_A473_BA968DAA6985__INCLUDED_)
#define EA_65BAC4E6_2352_4d1c_A473_BA968DAA6985__INCLUDED_

/**
 * ����� CMCU
 * ~~~~~~~~~~
 * 
 * ����������:
 * ������ ��� ������ � ����������������� ATmega128.
 * 
 * �����: �������� ��������
 * 
 * �����: mailto:unihomelab@ya.ru
 * 
 * ��������:
 * ���� ���� ����������� ������������� � ����� EA.
 * ���� �� ���-�� �������� �����, �� ��������������� ��������� � EA.
 */
class CMCU
{

public:

    static void Initialization();
    static HRESULT MainThreadProcedure();

	static void OnExternalInterruptRequest0();
	static void OnExternalInterruptRequest1();
	static void OnExternalInterruptRequest2();
	static void OnExternalInterruptRequest3();
	static void OnExternalInterruptRequest4();
	static void OnExternalInterruptRequest5();
	static void OnExternalInterruptRequest6();
	static void OnExternalInterruptRequest7();
	static void OnTimerCounter2CompareMatch();
	static void OnTimerCounter2Overflow();
	static void OnTimerCounter1CaptureEvent();
	static void OnTimerCounter1CompareMatchA();
	static void OnTimerCounter1CompareMatchB();
	static void OnTimerCounter1Overflow();
	static void OnTimerCounter0CompareMatch();
	static void OnTimerCounter0Overflow();
	static void OnSPISerialTransferComplete();
	static void OnUSART0RxComplete( uint8_t data );
	static void OnUSART0DataRegisterEmpty();
	static void OnUSART0TxComplete();
	static void OnADCConversionComplete( uint16_t );
	static void OnEEPROMReady();
	static void OnAnalogComparator();
	static void OnTimerCounter1CompareMatchC();
	static void OnTimerCounter3CaptureEvent();
	static void OnTimerCounter3CompareMatchA();
	static void OnTimerCounter3CompareMatchB();
	static void OnTimerCounter3CompareMatchC();
	static void TimerCounter3Overflow();
	static void OnTimerCounter3Overflow();
	static void OnUSART1RxComplete( uint8_t data );
	static void OnUSART1DataRegisterEmpty();
	static void OnUSART1TxComplete();
	static void OnTWISerialInterface();
	static void OnStoreProgramMemoryRead();
	
private:
	static void Timer1Init();
	static void SPIInit();
	static void TWIInit();
	static void USART0Init();
	static void PortsInit();
	static void InternalWDTInit();
	static void ExternalInterruptsInit();
	static void Timer0Init();
	static void ExternalSRAMInit();
	static void ControlRegistersInit();
	static void PinChangeInterruptsInit();

};
#endif // !defined(EA_65BAC4E6_2352_4d1c_A473_BA968DAA6985__INCLUDED_)
