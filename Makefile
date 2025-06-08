all: client server

server: server.c libft/libft.a
	gcc -I./libft server.c -L./libft -lft -o server

client: client.c libft/libft.a
re: clean
	make all


clean:
	rm -f client server
	rm -rf *.dSYM
	rm -rf *.o
	rm -rf libft/*.o
	rm -rf libft/*.dSYM

.PHONY: all clean
