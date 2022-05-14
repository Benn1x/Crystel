$CC = g++
.SILENT:
install:
	echo Compiling cry...
	$C cry.cpp -o cry
	echo Moving cry to /usr/bin
	sudo mv cry /usr/bin
move :
	echo Moving cry to /usr/bin
	sudo mv cry /usr/bin
compile:
	echo Compiling cry...
	$C cry.cpp -o cry
