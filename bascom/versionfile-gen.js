/****************************************************
* ������������� ������������� ����� ������ CVersion.
*
* �����: �������� �. �.
* skype: viacheslavmezentsev
* �����: mailto:viacheslavmezentsev@gmail.com
*
* ����: �� 13.02.2015 �.
*
*****************************************************/

var fso, VersionFile, ForReading, TristateTrue, Text;
var Major, Minor, Build, Revision;

// ������ ������ �� ������ ���������� ��������� ������.
var objArgs = WScript.Arguments;

// TODO: ������� �������� �� ���������� ����������.

// ��������� ������ ���������� �� ���������.
var sSourceFile = objArgs(0);
var sVersionFile = objArgs(1);

// ������� ��������� ��������� ������.
WScript.StdOut.WriteLine( "Output file: " +  sSourceFile );
WScript.StdOut.WriteLine( "Version file: " +  sVersionFile );

fso = WScript.CreateObject( "Scripting.FileSystemObject" );

ForReading = 1; // ��� ������
TristateFalse = 0; // ������ ASCII

// ��������� ����� ������ �� �����.
VersionFile = fso.OpenTextFile( sVersionFile, ForReading, false, TristateFalse );

try {

    var version = VersionFile.ReadLine().split( "." );

    Major = version[0];
    Minor = version[1];
    Build = version[2];
    Revision = version[3];

} catch(e) {

} finally {

    VersionFile.Close();
}

var d = new Date();

if ( Build == "*" ) {

    // Build - ���������� ���� ����� 1 ������ 2000 ����.
    Build = Math.floor( ( d.getTime() - new Date( 2000, 0, 1 ).getTime() ) / ( 24 * 3600 * 1000 ) );

    // Revision - �������� ���������� ������ ����� �������� ������� �����.
    Revision = Math.floor( ( d.getTime() - new Date( d.getFullYear(),
        d.getMonth(), d.getDate() ).getTime() ) / ( 2 * 1000 ) );

}

// ��������� ������������ ���� ������.
var SourceFile;

SourceFile = fso.CreateTextFile( sSourceFile, true );

// ������� ����� ������.
SourceFile.Write(
"\
$nocompile\r\n\
\r\n\
' ������: Version_Header.bas\r\n\
' ������: " +
d.toLocaleDateString() + " " + d.toLocaleTimeString() +
"\r\n\
' �����: �������� �. �.\r\n\
'\r\n\
' ������ ��� ������������������ ������ � ������� ���������.\r\n\
'\r\n\
' ��������. ���� ���� ����������� �������������. ����� ��������\r\n\
' ����� ��������� �������� ����� �����������.\r\n\
\r\n\
'Const VERSION_ENABLED = 0 ' +/- ... ����(�)\r\n\
\r\n\
#if VERSION_ENABLED\r\n\
\r\n\
Declare Function Version_GetMajor() As DWORD\r\n\
Declare Function Version_GetMinor() As DWORD\r\n\
Declare Function Version_GetBuild() As DWORD\r\n\
Declare Function Version_GetRevision() As DWORD\r\n\
Declare Function Version_GetVersionString() As String\r\n\
Declare Function Version_GetBuildDateString() As String\r\n\
\r\n\
Function Version_GetMajor() As DWORD : Version_GetMajor = " + Major + " : End Function\r\n\
Function Version_GetMinor() As DWORD : Version_GetMinor = " + Minor + " : End Function\r\n\
Function Version_GetBuild() As DWORD : Version_GetBuild = " + Build + " : End Function\r\n\
Function Version_GetRevision() As DWORD : Version_GetRevision = " + Revision + " : End Function\r\n\
Function Version_GetVersionString() As String : Version_GetVersionString = \"" + Major + "." + Minor + "." + Build + "." + Revision + "\" : End Function\r\n\
Function Version_GetBuildDateString() As String : Version_GetBuildDateString = \"" + d.toLocaleDateString() + "\" : End Function\r\n\
\r\n\
#endif\r\n\
"
);

SourceFile.Close();
