$nocompile


' ������������� ��������.
Sub LCD_Initialization( ByVal ADriver As Byte )

    LDriver = ADriver
    
    Select Case ADriver
    
        Case LCD_DRIVER_HD44780: LCD_Init_HD44780
        
    End Select

End Sub


' ��������� HD44780 �������� LCD �������.
Sub LCD_Init_HD44780

    ' �������� ����� 40 ��, ���� �� ���������� ����������
    ' �������� �� ����� �������.
    _delay_ms 40

    ' ������������� ������ ������� ����� LCD_RS (�������).
    Set LCD_DDR_NAME_RS
    Reset LCD_PORT_NAME_RS

    ' ������������� ������ ������� ����� LCD_RW (������).
    Set LCD_DDR_NAME_RW
    Reset LCD_PORT_NAME_RW

    LCD_WriteLow4bits &H03
    LCD_Writestrobe 5          ' -> 0x03
    LCD_Writestrobe 5          ' -> 0x03

    LCD_WriteLow4bits &H02
    LCD_Writestrobe 5          ' -> 0x02
    LCD_Writestrobe 5          ' -> 0x02

    LCD_WriteLow4bits &H2C
    LCD_Writestrobe 5          ' -> 0x0C

    LCD_WriteData TYPE_COMMAND, &H06     ' -> 1, I/D, SH

    LCD_Clear ' -> 0x01

    LCD_WriteData TYPE_COMMAND, &H0C     ' -> 1, D, C, B

    LCD_Home ' -> 0x02

End Sub


' ������� �������.
Sub LCD_Clear

    LCD_WriteData TYPE_COMMAND, LCD_HD44780_CMD_CLEAR

    _delay_ms LCD_DELAYS_CLEAR_MS

End Sub


' ����������� ������ � ������.
Sub LCD_Home

    LCD_WriteData TYPE_COMMAND, LCD_HD44780_CMD_RETURN_HOME

    _delay_ms LCD_DELAYS_CLEAR_MS

End Sub


' ����������� ������ �� �����������.
Sub LCD_MoveTo( ByVal ALeft As Byte, ByVal ATop As Byte )

    Local DDRAMAddr As Byte

    Select Case ATop

        Case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR

        Case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR

        Case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR

        Case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR

    End Select

    DDRAMAddr = DDRAMAddr + ALeft
    
    Set DDRAMAddr.7

    LCD_WriteData TYPE_COMMAND, DDRAMAddr

End Sub


' ����� ������� �� ���.
Sub LCD_PutChar( ByVal AChar As Byte )    

    Local Ptr As Word
            
    ' ��������, ���� ������� �� ������.
    if LDriver = LCD_DRIVER_NONE then Exit Sub

    ' ���� ���� ������� ������, �� ��������� �� ��������� ������.
    If AChar = Asc( "{013}" ) Then

        ' TODO: �������� ������� �� ����� ������ � ����������� �� ��������
        ' ���������.
        LCD_MoveTo 0, 1
        ' ��������� ��������� �������'
        'AChar = LCD_ReadAddress()
        'AChar = MakeBCD( AChar )
        'Print Str( AChar )
        
        'if AChar < LCD_LINE2_DDRAMADDR then 
        '    
        '    LCD_MoveTo 0, 1
        '    
        'elseif AChar < LCD_LINE1_DDRAMADDR then 
        ' 
        '    LCD_MoveTo 0, 3 
        '
        'elseif AChar < LCD_LINE3_DDRAMADDR then 
        ' 
        '    LCD_MoveTo 0, 2
        '            
        'else 
        '
        '    LCD_MoveTo 0, 0
        '    
        'end if

    Else      
        
        if AChar.7 = 1 then 
                   
            AChar = AChar And &h7F        
            Ptr = LoadLabel( CP1251_TO_CPHD44780 )
            Ptr = Ptr + AChar
            AChar = CPeek( Ptr )
            
         end if

        ' ������� ������, ������� ������������� ������� ����������.
        LCD_WriteData TYPE_DATA, AChar

    End If
    
    Exit Sub

    ' TODO: 5C -> 20, 7C -> 20, 7B -> 5B, 7D -> 5D, 7E -> E9
CP1251_TO_CPHD44780:

$asm
                                                             
    .DB &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20
    .DB &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20, &H20
    .DB &HCB, &H20, &H49, &H69, &H04, &H20, &HFE, &HEF, &HA2, &HCC, &H00, &HC9, &H20, &H20, &H20, &H02
    .DB &H00, &H00, &H00, &H00, &H00, &H00, &H00, &H00, &HB5, &H4E, &H00, &H00, &H00, &H00, &H00, &H00
    .DB &H41, &HA0, &H42, &HA1, &HE0, &H45, &HA3, &HA4, &HA5, &HA6, &H4B, &HA7, &H4D, &H48, &H4F, &HA8
    .DB &H50, &H43, &H54, &HA9, &HAA, &H58, &HE1, &HAB, &HAC, &HE2, &HAD, &HAE, &H62, &HAF, &HB0, &HB1
    .DB &H61, &HB2, &HB3, &HB4, &HE3, &H65, &HB6, &HB7, &HB8, &HB9, &HBA, &HBB, &HBC, &HBD, &H6F, &HBE
    .DB &H70, &H63, &HBF, &H79, &HE4, &H78, &HE5, &HC0, &HC1, &HE6, &HC2, &HC3, &HC4, &HC5, &HC6, &HC7
    
$end asm
    
End Sub


' ������� ������ �� ���.
Sub LCD_WriteString( AText As String )

    Local Temp As Byte
    Local Ptr As Word

    ' ��������, ���� ������� �� ������.
    if LDriver = LCD_DRIVER_NONE then Exit Sub
    
    Ptr = VarPtr( AText )
    Temp = Inp( Ptr )

    While Temp > 0

        LCD_PutChar Temp
        Incr Ptr
        Temp = Inp( Ptr )

    WEnd

End Sub


' ������� ������ �� Flash.
Sub LCD_WriteFlashString( ByVal APtr As Word )

    Local Temp As Byte

    ' ��������, ���� ������� �� ������.
    if LDriver = LCD_DRIVER_NONE then Exit Sub
    
    Temp = CPeek( APtr )

    While Temp > 0

        LCD_PutChar Temp
        Incr APtr
        Temp = CPeek( APtr )

    WEnd
    
End Sub


' �������� ������.
Sub LCD_HideCursor( ByVal ABlinking As Byte )

    Local Value As Byte
    
    ' ��������, ���� ������� �� ������.
    if LDriver = LCD_DRIVER_NONE then Exit Sub

    Set Value.LCD_HD44780_CMD_ON_CTRL
    Set Value.LCD_HD44780_CMD_ON_DISPLAY
    
    Value.LCD_HD44780_CMD_ON_BLINK = ABlinking
    
    LCD_WriteData TYPE_COMMAND, Value

End Sub


' ���������� ������.
Sub LCD_ShowCursor( ByVal ABlinking As Byte )

    Local Value As Byte
    
    ' ��������, ���� ������� �� ������.
    if LDriver = LCD_DRIVER_NONE then Exit Sub

    Set Value.LCD_HD44780_CMD_ON_CTRL
    Set Value.LCD_HD44780_CMD_ON_DISPLAY
    Set Value.LCD_HD44780_CMD_ON_CURSOR
    
    Value.LCD_HD44780_CMD_ON_BLINK = ABlinking
    
    LCD_WriteData TYPE_COMMAND, Value

End Sub


' �������� ������ �� �����������.
Sub LCD_ShowCursorAt( ByVal ABlinking As Byte, ByVal ALeft As Byte, ByVal ATop As Byte )

    ' ���������� ������ �� �������.
    LCD_MoveTo ALeft, ATop

    ' ��������� ������������.
    LCD_ShowCursor ABlinking

End Sub


' ��������� ������� ������.
Function LCD_ReadAddress() As Byte
         
    Local Addr As Byte
    
    ' �������, ���� ������� ����� ���������� ���������� �������.
    'Do 
    '    Addr = IsBusy()
    '    
    'Loop Until Addr = 0
         
    #if LCD_DATA_LENGTH_4BIT = 1
             
        ' ������������� ������ ������� ����� LCD_RS (�������).
        Set LCD_DDR_NAME_RS
        Reset LCD_PORT_NAME_RS

        ' ������������� ������� ������� ����� LCD_RW (������).
        Set LCD_DDR_NAME_RW
        Set LCD_PORT_NAME_RW

        ' ��������� ����� �� ����� LCD E.
        LCD_WriteStrobe 5
        
        ' ��������� ������� �������.
        Addr = LCD_ReadLow4bits()
        Shift Addr, Left, 4
        Addr = Addr And &H7F
        
        ' ��������� ����� �� ����� LCD E.
        LCD_WriteStrobe 5

        ' ��������� � ��� ������� ��� ����� ��������� (BF).
        LCD_ReadAddress = LCD_ReadLow4bits()              
        LCD_ReadAddress = LCD_ReadAddress Or Addr
             
     #endif
   
    Reset LCD_PORT_NAME_RW
    
End Function


' �������, ���� �� ����� ������� ���� ��������� � LCD.
Function LCD_IsBusy() As Byte

    ' When the busy flag is 1, the controller LSI is in the internal operation mode, and the next
    ' instruction will not be accepted. When RS=0 and R/W=1, the busy flag is output to DB7. The
    ' next instruction must be written after ensuring that the busy flag is 0.
    '
    ' +----+----+-------------------------------------------------------------+
    ' | RS |R/W |                 Operation                                   �
    ' +----+----+-------------------------------------------------------------+
    ' | 0  | 0  | IR write as an internal operation (display clear, etc.)     |
    ' | 0  | 1  | Read busy flag (DB7) and address counter (DB0 to DB7)       |
    ' | 1  | 0  | Write data to DDRAM or CGRAM (DR to DDRAM or CGRAM)         |
    ' | 1  | 1  | Read data from DDRAM or CGRAM (DDRAM or CGRAM to DR)        |
    ' +----+----+-------------------------------------------------------------+
    
    Local Busy As Byte
    
    Busy = 0
    
    ' ���� ������������� ��������� ���������, �� ���������� ��.
    if SFIOR.PUD = 1 then Reset SFIOR.PUD
    
    ' ������������� ������ ������� ����� LCD_RS (�������).
    Set LCD_DDR_NAME_RS
    Reset LCD_PORT_NAME_RS
    
    ' ������������� ������� ������� ����� LCD_RW (������).
    Set LCD_DDR_NAME_RW
    Set LCD_PORT_NAME_RW

    ' ������ ���� ���������, ���������� ����� �� ���� ;)         
    Reset LCD_DDR_NAME_D7
    Set LCD_PORT_NAME_D7
    
    ' ������ ��������� ����� LCD DB7.
    Busy = LCD_PIN_NAME_D7
    
    Reset LCD_PORT_NAME_RW

    LCD_IsBusy = Busy
    
End Function


' ����� ������ �� ����� E.
Sub LCD_WriteStrobe( ByVal usec As DWORD )

   ' ��������� �������� ����� ������.
    Set LCD_DDR_NAME_En
    Set LCD_PORT_NAME_En

    $asm
        NOP
    $end asm

    Reset LCD_PORT_NAME_En

    ' �������� �� ���������� �������� ������ �� ����� 1,2 ���.
    _delay_us 2

    ' ���������������� ��������.
    _delay_us usec

End Sub


' ������ �������� ��������� ������.
Sub LCD_WriteLow4bits( ByVal AValue As Byte )

    Set LCD_DDR_NAME_D4 : LCD_PORT_NAME_D4 = AValue.0
    Set LCD_DDR_NAME_D5 : LCD_PORT_NAME_D5 = AValue.1
    Set LCD_DDR_NAME_D6 : LCD_PORT_NAME_D6 = AValue.2
    Set LCD_DDR_NAME_D7 : LCD_PORT_NAME_D7 = AValue.3

End Sub


' ������ ��������� ������.
Function LCD_ReadLow4bits() As Byte
   
    Local Value As Byte

    Value = 0
    
    ' ���� ������������� ��������� ���������, �� ���������� ��.
    if SFIOR.PUD = 1 then Reset SFIOR.PUD
    
    ' ����������� ����� �� ����.
    Reset LCD_DDR_NAME_D4 : Set LCD_PORT_NAME_D4
    Reset LCD_DDR_NAME_D5 : Set LCD_PORT_NAME_D5
    Reset LCD_DDR_NAME_D6 : Set LCD_PORT_NAME_D6
    Reset LCD_DDR_NAME_D7 : Set LCD_PORT_NAME_D7

    _delay_us 1

    Value.0 = LCD_PIN_NAME_D4
    Value.1 = LCD_PIN_NAME_D5
    Value.2 = LCD_PIN_NAME_D6
    Value.3 = LCD_PIN_NAME_D7
            
    LCD_ReadLow4bits = Value
    
End Function


' ����� ������ �� �������.
Sub LCD_WriteData( ByVal ACmdType As Byte, ByVal AValue As Byte )

    Local Temp As Byte

    Temp = AValue
    Shift Temp, Right, 4

    ' ������� �������� ����� ������ �� ����.

    Set LCD_DDR_NAME_RS

    Select Case ACmdType

        ' ������������� ������ ������� ����� LCD_RS.
        Case TYPE_COMMAND: Reset LCD_PORT_NAME_RS

        ' ������������� ������� ������� ����� LCD_RS.
        case TYPE_DATA: Set LCD_PORT_NAME_RS

    End Select

    ' ������������� ������ ������� ����� LCD_RW.
    Set LCD_DDR_NAME_RW
    Reset LCD_PORT_NAME_RW

    ' ������� ������� 4 ���� ������.
    LCD_WriteLow4bits Temp

    ' ��������� ����� ������ �� ����� LCD_E.
    Select Case ACmdType

        Case TYPE_COMMAND: LCD_Writestrobe LCD_DELAYS_COMMAND_US

        Case TYPE_DATA: LCD_Writestrobe LCD_DELAYS_DATA_US

    End Select

    ' ������� ������� 4 ���� ������.
    LCD_WriteLow4bits AValue

    ' ��������� ����� ������ �� ����� LCD_E.
    Select Case ACmdType

        Case TYPE_COMMAND: LCD_Writestrobe LCD_DELAYS_COMMAND_US

        Case TYPE_DATA: LCD_Writestrobe LCD_DELAYS_DATA_US

    End Select

    ' ��������� ������ ������� �� ���� ������ ��� ������ �� ������.
    LCD_WriteLow4bits 0

    If ACmdType = TYPE_DATA Then Reset LCD_PORT_NAME_RS

End Sub
