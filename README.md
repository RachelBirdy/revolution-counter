*Rachel's Amazing Revolution Counter For Inductor Winding And Other Rotary Endeavours!*
=======================================================================================
This is a piece of software I wrote to count how many times an inductor being wound on the end of a drill spins. It relies on a photodiode with a laser pointing at it connected to a gpio pin. It increments a counter every 2 times the laser is interupted.

Requirements
------------
This is currently written exclusive for a Raspberry Pi 4 and needs modification for compatibility with other systems.
This branch requires ncurses! On debian based systems, run
`sudo apt install libncurses-dev`

On other systems you're on your own

Installation
------------
Run `make` to get the binary in the /bin folder. There is no install yet.
