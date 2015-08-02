'*******************************************************************************
'* �����: �������� ��������
'* ����:  31.10.2013 �.
'* CPU:  ATmega16
'* �������� �������:  8000000 ��
'* ����������: BASCOM-AVR 2.0.7.5
'*
'* �����������: ������ � ��� (������� HD44780).
'*
'*******************************************************************************

$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 32
$framesize = 64
'$sim

' �������� ������ ����������� USART
' 9600, 19200, 38400, 57600, 115200
$baud = 57600


' -=[ ���������� � ��� ]=-

Dim Key As Byte
Dim Text As String * 32


' ����� ����� � �������� ���������.
Declare Sub Main : Main : End


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ***********************/


' ���������� ������������ ����� �������.
$include "Config_Header.bas"
$include "../base/Delays_Header.bas"
$include "../base/Console_Header.bas"
$include "../base/LCD_Header.bas"


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ************************/

' ���������� ������.
$include "../base/Delays.bas"
$include "../base/Console.bas"
$include "../base/LCD.bas"


Sub Main

    Local Ptr As Word

    Console_CursorOff
    Console_SetBackgroundColor clBlack
    Console_ClearScreen cmAll
    
    Text = "���������"
    Console_DrawFrame 12, 9, 22, 6, clWhite, clGreen, Text
    
    Console_MoveTo 13, 10
    Console_CursorOn
    
    ' ������������� ����������.
    LCD_Initialization LCD_DRIVER_HD44780

    Ptr = LoadLabel( TextPinboardDemo )
    LCD_WriteFlashString Ptr

    LCD_MoveTo 0, 2

    'Ptr = LoadLabel( RussiaForever )
    'LCD_WriteFlashString Ptr
    
    LCD_ShowCursor 0
    
    Do

        Do : Key = Inkey() : Loop Until Key > &H30 Or Key = 13
        
        LCD_PutChar Key

    Loop

End Sub


' /****************
' *  � � � � � �
' *  ~~~~~~~~~~~
' ****************/


TextPinboardDemo:
    Data "Pinboard II ����{013}Bascom AVR"

' ����� �� ��������� ����� �����:
'
' +----------------+
' |Pinboard II ����|
' |Bascom AVR      |
' +----------------+


RussiaForever:
    Data "������ ��������!{013}���, ������!"

' ����� �� ��������� ����� �����:
'
' +----------------+
' |������ ��������!|
' |���, ������!    |
' +----------------+