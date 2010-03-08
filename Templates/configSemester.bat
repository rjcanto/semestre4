REM Builder para constru��o autom�tica das cadeiras dos semestres
REM Nuno Cancelo
REM Vers�o 0.1
REM Mar�o/2010
@echo off
cls
REM Defini��o da Raiz da Locali��o das Pastas/Ficheiros
set "ISEL_PATH=d:\ESCOLA\ISEL\Semestre4"
REM Defini��o das Cadeiras a serem realizadas
set "CADEIRAS=REDES LS EGP PSC POO"
REM Defini��o das SubPastas
set "PASTAS=SERIES TRABALHOS DOCS"

:MAIN
IF NOT EXIST %ISEL_PATH% mkdir %ISEL_PATH%


:FOR
	SET CADEIRA_PATH=""	
for %%i in (%CADEIRAS%) DO (
	IF NOT EXIST %ISEL_PATH%\%%i (
		echo Build %ISEL_PATH%\%%i
		MKDIR %ISEL_PATH%\%%i
	)
	for %%j in (%PASTAS%) do (
		IF NOT EXIST %ISEL_PATH%\%%i\%%j (
			echo Build %ISEL_PATH%\%%i\%%j
			MKDIR %ISEL_PATH%\%%i\%%j
		)
	)
)
GOTO END
	

:END
ECHO Finnish!

		
	

