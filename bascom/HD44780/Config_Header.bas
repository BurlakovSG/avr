$nocompile

' /****************************
' *  � � � � � � � � � � � �
' *  ~~~~~~~~~~~~~~~~~~~~~~~
' ****************************/


Const Console_Cursor_Enabled = 1
Const Console_DrawFrame_Enabled = 1 ' +/- 752 �����
Const Console_Beep_Enabled = 0 ' +/- 284 �����

Const Version_Enabled = 0 ' +/- ... �����

' ������������ LCD �������

' ��������:
' �� �������� ��������� ������ � ������� ��� ���������� ���,
' � ���� ������ ���������� �� �����!

LCD_DDR_NAME_En     alias DDRB.0
LCD_PORT_NAME_En    alias PORTB.0

LCD_DDR_NAME_RS     alias DDRC.6
LCD_PORT_NAME_RS    alias PORTC.6

' ����������. ���� ������������ ������ ����� ������ � ����� RW ��� �������� � �����,
' �� ����� ����� ������ ��� �� ��� �����, ��� � ��� ������ LCD Enable. ��� �� �������
' ������ ������ ��������� � ���� ������.
LCD_DDR_NAME_RW     alias LCD_DDR_NAME_En
LCD_PORT_NAME_RW    alias LCD_PORT_NAME_En
'LCD_DDR_NAME_RW     alias DDRD.4
'LCD_PORT_NAME_RW    alias PORTD.4

LCD_DDR_NAME_D4     alias DDRC.1
LCD_PORT_NAME_D4    alias PORTC.1
LCD_PIN_NAME_D4     alias PINC.1

LCD_DDR_NAME_D5     alias DDRA.1
LCD_PORT_NAME_D5    alias PORTA.1
LCD_PIN_NAME_D5     alias PINA.1

LCD_DDR_NAME_D6     alias DDRA.6
LCD_PORT_NAME_D6    alias PORTA.6
LCD_PIN_NAME_D6     alias PINA.6

LCD_DDR_NAME_D7     alias DDRD.7
LCD_PORT_NAME_D7    alias PORTD.7
LCD_PIN_NAME_D7     alias PIND.7

' ���������.
Const LCD_DATA_LENGTH_4BIT = 1
