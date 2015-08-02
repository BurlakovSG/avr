'*******************************************************************************
'* �����: �������� �������� ����������
'* ������������: viacheslavmezentsev@gmail.com
'* skype: viacheslavmezentsev
'* icq: 10333578
'*
'* ������: EEPROM File System.
'* ����:  08.11.2013 �.
'* ����������: BASCOM-AVR 2.0.7.5
'* MCU:  ATmega16
'* �������� �������:  8000000  Hz
'*******************************************************************************

' ��������� �����������.

$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 64
$framesize = 24
'$map
'$sim
'$noinit

' �������� ������ ����������� USART
' 9600, 19200, 38400, 57600, 115200
'$baud = 38400


' -=[ ���������� � ��� ]=-

Dim Result As Byte
Dim AFile(4) As Byte
Dim szName As String * 13
Dim pData(12) As Byte At szName Overlay


' ����� ����� � �������� ���������.
Declare Sub Main : Main : End


' /***********************  
' *  � � � � � � � � � �    
' *  ~~~~~~~~~~~~~~~~~~~    
' ***********************/  

' ���������� ������������ ����� �������.

$include "..\base\EFS_Header.bas"


' /***********************
' *  � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~
' ************************/

' ���������� ������.

$include "..\base\EFS.bas"


Sub Main

    Local n As Byte, Temp As Byte

    ' ��������� ����� EEPROM ������.
    For n = 0 To 239
    
        Temp = &H00
        WriteEeprom Temp, n
        
    Next       
    
    EFS_Initialization
    
    szName = "MyFile"    
    Result = EFS_CreateFile( AFile(1), &HCF, szName )
    
    szName = "-123456-"
    Result = EFS_WriteFile( AFile(1), pData(1), 0, 8 )
    
    Do : Loop

End Sub

