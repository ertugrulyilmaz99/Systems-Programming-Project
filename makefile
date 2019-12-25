
terminal :terminal.o primes.o upper.o
	gcc -o terminal terminal.o primes.o upper.o

terminal.o :  terminal.c primes.h upper.h
	cc -c terminal.c
		
primes.o : primes.c primes.h
	cc -c primes.c

upper.o : upper.c upper.h
	cc -c upper.c
 
clean: 
	rm -f terminal.o primes.o upper.o
