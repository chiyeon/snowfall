#!/usr/bin/env bash

if [ "$1" == "-l" ]; then
	echo "Uninstalling locally"
	rm $HOME/.local/share/snowfall
	rm snowfall
else
	echo "Uninstalling globally"
	sudo rm /usr/local/bin/snowfall
	rm snowfall
fi

echo "Done."

done