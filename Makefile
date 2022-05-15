$CC = g++
.SILENT:
install:
	echo Compiling cy...
	$C cy.cpp -o cy
	echo Moving cy to /usr/bin
	sudo mv cy /usr/bin
move :
	echo Moving cy to /usr/bin
	sudo mv cy /usr/bin
compile:
	echo Compiling cy...
	$C cy.cpp -o cy
