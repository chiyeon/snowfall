if [ "$1" == "-g" ]; then
	echo "Uninstalling globally"
	sudo rm /usr/bin/snowfall
else
	echo "Uninstalling locally"
	rm $HOME/.local/share/snowfall
fi

echo "Done."
