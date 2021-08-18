revcount:
	cc interface.c draw_interface.c create_window.c -o interface -lncurses

install: revcount
	echo "Figure this out!"

clean:
	rm interface
