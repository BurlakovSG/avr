'*******************************************************************************
'* �����: �������� ��������
'* ����:  28.10.2013 �.
'* MCU:  ATtiny2313
'* �������� �������:  8000000 ��
'* ����������: BASCOM-AVR 2.0.7.5
'*
'* �����������: �������� ������ ��������� - ������ � ANSI ����������.
'*
'*******************************************************************************

$regfile = "attiny2313.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
'$map
'$sim

' �������� ������ ����������� USART
' 9600, 19200, 38400, 57600, 115200
$baud = 57600


' -=[ ���������� � ��� ]=-

Dim Text As String * 16


' ����� ����� � �������� ���������.
Declare Sub Main : Main : End


' /***********************  
' *  � � � � � � � � � �    
' *  ~~~~~~~~~~~~~~~~~~~    
' ***********************/  

' ���������� ������������ ����� �������.

$include "Config_Header.bas"
$include "Version_Header.bas"
$include "../base/Console_Header.bas"
$include "../base/CommandShell_Header.bas"


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ************************/

' ���������� ������.
$include "../base/Console.bas"
$include "../base/CommandShell.bas"


Sub Main

    ' USART Control and Status Register C
    ' [ ������� ���������� UCSRC ][ATtiny2313]
    '         00000110 - Initial Value
    UCSRC = &B00000110
    '         ||||||||
    '         |||||||+- 0, rw, UCPOL:    - Clock Polarity
    '         ||||||+-- 1, rw, UCSZ0: -+ - Character Size
    '         |||||+--- 2, rw, UCSZ1: _|
    '         ||||+---- 3, rw, USBS:     - Stop Bit Select
    '         |||+----- 4, rw, UPM0:  -+ - Parity Mode
    '         ||+------ 5, rw, UPM1:  _|
    '         |+------- 6, rw, UMSEL:    - USART Mode Select
    '         +-------- 7, r: 0
    '  ����������:

    CommandShell_Info

    Do

        ' ����� ����������� ��������� ������.
        CommandShell_Prompt

        Input Text
        
        ' ������� ������ ���������.
        'if Text = "cls" then Console_ClearScreen cmAll : Console_MoveTo 1, 25

    Loop

End Sub


Prompt:
    Data "[ATtiny2313]$ "

CommandShellInfo:
    Data "Command shell{013}{010}"
