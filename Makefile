$CC = g++
.SILENT:
install:
	echo Compiling cry...
	$C cry.cpp -o cry
	echo Moving cry to /usr/local/bin
	sudo mv cry /usr/local/bin
move :
	echo Moving cry to /usr/local/bin
	sudo mv cry /usr/local/bin
compile:
	echo Compiling cry...
	$C cry.cpp -o cry
