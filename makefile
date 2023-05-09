default : main.c
	gcc -std=gnu99 main.c lib/weblink.c -o webboxy.o

dev : main.c
	gcc -std=gnu99 main.c lib/weblink.c -o webboxy-dev.o

clean :
	-rm -f webboxy.o
	-rm -f webboxy
	-rm -f webboxy-dev.o
	-rm -f webboxy-dev
	-clear