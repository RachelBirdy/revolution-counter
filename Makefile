revcount:
	mkdir bin
	cc RevsPerSec.c -o bin/revolution-counter -lpthread

install: revcount
	echo "Figure this out!"

clean:
	rm -r bin
