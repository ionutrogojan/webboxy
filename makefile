default : main.c
	gcc main.c -o webboxy

dev : main.c
	-gcc main.c -o webboxy-dev.o
	-./webboxy-dev.o

clean :
	-rm -f webboxy.o
	-rm -f webboxy
	-rm -f webboxy-dev.o
	-rm -f webboxy-dev
	-clear