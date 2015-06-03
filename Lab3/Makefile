all:
	gcc client.c -o client
	gcc -lpthread server.c  -o server
threads:
	gcc client.c -o client
	gcc -lpthread server.c -DTHREAD -o server
clean:
	rm -f client
	rm -f server