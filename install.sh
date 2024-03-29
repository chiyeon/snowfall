#!/usr/bin/env bash

echo "Compiling snowfall.c"
gcc snowfall.c -o snowfall

if [ "$1" == "-l" ]; then
	echo "Installing locally"

	echo "Checking for previous versions"
	if [ -f $HOME/.local/share/snowfall ]; then
		echo "Uninstalling existing version"
		./uninstall.sh "-l"
	fi

	echo "Installing to $HOME/.local/share"
	{
		cp snowfall $HOME/.local/share/ && echo "Done. Run 'snowfall' to begin, and add '-H' to see more!"
	} || {
		echo "Unable to move to $HOME/.local/share. Run locally with './snowfall', and add '-H' to see more!"
	}
else
	echo "Installing globally"
	echo "Want to install locally, without sudo? Run with '-l'."

	echo "Checking for previous versions"
	if [ -f /usr/local/bin/snowfall ]; then
		echo "Uninstalling existing version"
		./uninstall.sh
	fi

	echo "Installing to /usr/local/bin"
	{
		sudo cp snowfall /usr/local/bin/ && echo "Done. Run 'snowfall' to begin, or add '-H' to see more!"
	} || {
		echo "Unable to move to /usr/local/bin. Try installing with '-l'."
	}
fi
