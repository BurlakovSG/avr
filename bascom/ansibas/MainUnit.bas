'*******************************************************************************
'* �����: �������� ��������
'* ����:  26.10.2013 �.
'* CPU:  ATmega16
'* �������� �������:  8000000  Hz
'* ����������: BASCOM-AVR 2.0.7.5
'*
'* �����������: �������� ������ ��������� - ������ � ANSI ����������
'*
'*******************************************************************************

$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 64
'$sim

' �������� ������ ����������� USART
' 9600, 19200, 38400, 57600, 115200
$baud = 57600


' -=[ ���������� � ��� ]=-

Dim Key As Byte
Dim Text As String * 32
Dim CurrTime(7) As Byte


' ����� ����� � �������� ���������.
Declare Sub Main : Main : End


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ***********************/

' ���������� ������������ ����� �������.
$include "Config_Header.bas"
$include "Version_Header.bas"
$include "..\base\Delays_Header.bas"
$include "..\base\Console_Header.bas"
$include "..\base\CommandShell_Header.bas"
$include "..\base\RTC_Header.bas"
$include "..\base\MemoryViewer_Header.bas"
$include "..\base\M16_Header.bas"


' ���������������� �������.
Declare Sub ShowPinStates


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ************************/

' ���������� ������.
$include "..\base\Delays.bas"
$include "..\base\Console.bas"
$include "..\base\CommandShell.bas"
$include "..\base\RTC.bas"
$include "..\base\MemoryViewer.bas"
$include "..\base\M16.bas"


Sub Main

    ' ������������� ���� ��������� ����������������.
    M16_Initialization

    ' ��������� RTC.
    RTC_Initialization RTC_DS1307

    ' ��������� ��������������.
    CommandShell_Initialization

    'TODO: ��� �������� ����� > 255?
    'Console_Beep 255, 1

    'Console_SetColor clLightGray, clBlack
    'Console_ClearScreen cmAll

    ' ����� ��� ���������.
    'Caption = ""
    'Console_DrawFrame 1, 2, 80, 23, clLightGray, clBlue, Caption

    ' ���� ���� � �������.
    'Console_DrawFrame 25, 10, 20, 4, clBlack, clWhite, Caption

    'Caption = LookupStr( 0, TimeStr )
    'Console_MoveTo 27, 11
    'Console_WriteString Caption, cp1251

    'Caption = LookupStr( 0, DateStr )
    'Console_MoveTo 27, 12
    'Console_WriteString Caption, cp1251

    CommandShell_Info

    Do

        ' ����� ����������� ��������� ������.
        CommandShell_Prompt

        Input Text

        RTC_GetDatetime CurrTime(1)

        if Text = "time" then

            RTC_ShowTime CurrTime(1)


        elseif Text = "date" then

            RTC_ShowDate CurrTime(1)


        elseif Text = "ram" then

            MemoryViewer_FormActivate

            Do

                Key = Inkey()

            Loop Until Key = &H1B

            CommandShell_Info


        elseif Text = "mcu" then

            DDRA = &HFF
            PORTA = &HAA

            DDRB = &HFF
            PORTB = &H0F

            Console_CursorOff
            Console_ClearScreen cmAll
            ShowPinStates

            Do

                Key = Inkey()

            Loop Until Key = &H1B

            CommandShell_Info

        end if

    Loop

End Sub


Sub ShowPinStates

    Local I As Byte, Top As Byte, Temp As Byte
    Local Ptr As Word

    ' ������� ����������� ����������������.
    Ptr = LoadLabel( MCUViewData )
    
    For Top = 0 To 22

        Temp = Top + 2
        Console_MoveTo 1, Temp
        
        Temp = CPeek( Ptr )
        
        While Temp > 0
            
            PrintBin Temp
            Incr Ptr
            Temp = CPeek( Ptr )
            
        WEnd
        
        ' ������������ ����� ������.
        Incr Ptr
        
    Next
    
    ' ��������� ����� B.
    For I = 0 To 7

        Top = 4 + I
        Console_MoveTo 16, Top

        Temp = PINB
        Shift Temp, Right, I
        Temp = Temp and &H01

        if Temp = 0 then

            Console_SetForegroundColor clBlue

        else

            Console_SetForegroundColor clRed
        end if

        PrintBin &HFE

    Next

    ' ��������� ����� D.
    For I = 0 To 7

        if I = 7 then

            Console_MoveTo 35, 23

        else

            Top = 17 + I
            Console_MoveTo 16, Top
        end if

        Temp = PIND
        Shift Temp, Right, I
        Temp = Temp and &H01

        if Temp = 0 then

            Console_SetForegroundColor clBlue

        else

            Console_SetForegroundColor clRed
        end if

        PrintBin &HFE

    Next

    ' ��������� ����� A.
    For I = 0 To 7

        Top = 4 + I
        Console_MoveTo 35, Top

        Temp = PINA
        Shift Temp, Right, I
        Temp = Temp and &H01

        if Temp = 0 then

            Console_SetForegroundColor clBlue

        else

            Console_SetForegroundColor clRed
        end if

        PrintBin &HFE

    Next

    ' ��������� ����� C.
    For I = 0 To 7

        Top = 22 - I
        Console_MoveTo 35, Top

        Temp = PINC
        Shift Temp, Right, I
        Temp = Temp and &H01

        if Temp = 0 then

            Console_SetForegroundColor clBlue

        else

            Console_SetForegroundColor clRed
        end if

        PrintBin &HFE

    Next

End Sub


' /****************
' *  � � � � � �
' *  ~~~~~~~~~~~
' ****************/

CommandShellInfo:
    Data "��������� �������� (Bascom AVR), ������ "

Prompt:
    Data "[ATmega16]$ "

ViewMemoryData:
    Data "�������� ������: ��� (CP1251)"

TimeStr:
    Data "Time: "

DateStr:
    Data "Date: "

TitleDS:
    Data "DS1307"

MCUViewData:
    Data "                  ATmega16 - PDIP             ", _
       "                 +--------------+             ", _
       "   (XCK/T0) PB0 -|  1        40 |- PA0 (ADC0) ", _
       "       (T1) PB1 -|  2        39 |- PA1 (ADC1) ", _
       "(INT2/AIN0) PB2 -|  3        38 |- PA2 (ADC2) ", _
       " (OC0/AIN1) PB3 -|  4        37 |- PA3 (ADC3) ", _
       "      (~SS) PB4 -|  5        36 |- PA4 (ADC4) ", _
       "     (MOSI) PB5 -|  6        35 |- PA5 (ADC5) ", _
       "     (MISO) PB6 -|  7        34 |- PA6 (ADC6) ", _
       "      (SCK) PB7 -|  8        33 |- PA7 (ADC7) ", _
       "         ~RESET -|  9        32 |- AREF       ", _
       "            VCC -| 10        31 |- GND        ", _
       "            GND -| 11        30 |- AVCC       ", _
       "          XTAL2 -| 12        29 |- PC7 (TOSC2)", _
       "          XTAL1 -| 13        28 |- PC6 (TOSC1)", _
       "      (RXD) PD0 -| 14        27 |- PC5 (TDI)  ", _
       "      (TXD) PD1 -| 15        26 |- PC4 (TDO)  ", _
       "     (INT0) PD2 -| 16        25 |- PC3 (TMS)  ", _
       "     (INT1) PD3 -| 17        24 |- PC2 (TCK)  ", _
       "     (OC1B) PD4 -| 18        23 |- PC1 (SDA)  ", _
       "     (OC1A) PD5 -| 19        22 |- PC0 (SCL)  ", _
       "     (ICP1) PD6 -| 20        21 |- PD7 (OC2)  ", _
       "                 +--------------+             "