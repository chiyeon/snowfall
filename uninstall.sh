if [ "$1" == "-l" ]; then
	echo "Uninstalling locally"
	rm $HOME/.local/share/snowfall
else
	echo "Uninstalling globally"
	sudo rm /usr/local/bin/snowfall
fi

echo "Done."
