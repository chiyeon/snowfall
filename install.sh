echo "Checking for previous versions"

echo "Compiling snowfall.c"
gcc snowfall.c -o snowfall

if [ "$1" == "-g" ]; then
	echo "Installing globally"

	if [ -f /usr/local/bin/snowfall ]; then
		echo "Uninstalling existing version"
		./uninstall.sh
	fi

	echo "Installing to /usr/local/bin"
	{
		sudo mv snowfall /usr/local/bin/ && echo "Done. Run 'snowfall' to begin, or add '-h' to see more!"
	} || {
		echo "Unable to move to /usr/local/bin. Try installing without '-g'."
	}
else
	echo "Installing locally (Want to install globally? Run with '-g')"

	if [ -f $HOME/.local/share/snowfall ]; then
		echo "Uninstalling existing version"
		./uninstall.sh
	fi

	echo "Installing to $HOME/.local/share"
	{
		sudo mv snowfall $HOME/.local/share/ && echo "Done. Run 'snowfall' to begin, and add '-h' to see more!"
	} || {
		echo "Unable to move to $HOME/.local/share. Run locally with './snowfall', and add '-h' to see more!"
	}
fi
