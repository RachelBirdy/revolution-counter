revcount:
	cc interface.c -o interface -lncurses

install: revcount
	echo "Figure this out!"

clean:
	rm interface
