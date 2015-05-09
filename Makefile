all: lab6.c liststyle.c
	gcc -o lab6 lab6.c liststyle.c -I .

run:
	./lab6

clean:
	rm -f lab6

test: test.c liststyle.c
	gcc -o t test.c liststyle.c -I .
	./t
	rm -f t