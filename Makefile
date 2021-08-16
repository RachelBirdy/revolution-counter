revcount:
	mkdir bin
	cc -c pollRateCalculator.c
	cc interface.c -o bin/interface

install: revcount
	echo "Figure this out!"

clean:
	rm pollRateCalculator.o
	rm -r bin
