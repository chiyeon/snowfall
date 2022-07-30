echo Checking for previous versions

if [ -f /usr/bin/snowfall ]; then
	echo Uninstalling
	./uninstall.sh
fi

echo Compiling
gcc snowfall.c -o snowfall

echo Installing
sudo mv snowfall /usr/bin/ && echo Done
