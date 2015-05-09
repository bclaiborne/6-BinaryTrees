all: lab0a.c functions.c
	gcc -o lab0a lab0a.c functions.c -I .

run:
	./lab0a

clean:
	rm -f lab0a

test: test.c functions.c
	gcc -o t test.c functions.c -I .
	./t
	rm -f t