.SILENT:

compile:
	gcc -Wall -std=c99 -o diff2 diff.c

install: compile
	mv diff2 /usr/local/bin/

clean:
	rm -rf diff2
