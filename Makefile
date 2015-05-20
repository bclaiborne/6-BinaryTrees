all: lab6.c liststyle.c
	gcc -o lab6 lab6.c liststyle.c arraystyle.c -I .

run:
	./lab6

clean:
	rm -f lab6

test: test.c liststyle.c
	gcc -o t test.c liststyle.c arraystyle.c -I .
	./t
	rm -f t