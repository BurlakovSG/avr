$nocompile

'$include "CommandShell_Header.bas"


Sub CommandShell_Initialization

End Sub


Sub CommandShell_Info

    Local Ptr As Word
    
    Console_SetColor clLightGray, clBlack
    Console_ClearScreen cmAll
    Console_MoveTo 1, 25

    Ptr = LoadLabel( CommandShellInfo )
    Console_WriteFlashString Ptr, cp1251

#if Version_Enabled
    ' ����� ������ ������.
    'Text = Version(2)
    Text = Version_GetVersionString()
    Console_WriteString Text, cp1251

    Print " (";

    ' ����� ���� ������.
    'Text = Version(1)
    Text = Version_GetBuildDateString()
    Console_WriteString Text, cp1251

    Print ")"
#endif

    Exit Sub

'CommandShellInfo:
'    'DATA "��������� �������� (Bascom AVR), ������ "
'$ASM
'    .DB "��������� �������� (Bascom AVR), ������ "
'$END ASM

End Sub


Sub CommandShell_Prompt

    Local Ptr As Word

    Console_NewLine

    Console_SetForegroundColor clLightGreen
    Ptr = LoadLabel( Prompt )    
    Console_WriteFlashString Ptr, cp1251

    Console_SetForegroundColor clLightGray
    Console_ClearLine cmFromCursorToEnd
    Console_CursorOn

    Exit Sub

'Prompt:
'$ASM
'    .DB "[ATmega16]$ "
'$END ASM

End Sub


'CommandShellInfo:
'    Data "��������� �������� (Bascom AVR), ������ "

'Prompt:
'    Data "[ATmega16]$ "