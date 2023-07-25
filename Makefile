CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = shell.c lists.c getfile.c main.c builtins.c
OBJS = $(SRCS:.c=.o)

simple_shell: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o simple_shell

shell.o: shell.c shell.h main.h
	$(CC) $(CFLAGS) -c shell.c -o shell.o

lists.o: linkedlists.c lists.h
	$(CC) $(CFLAGS) -c linkedlists.c -o lists.o

getfile.o: getfile.c main.h
	$(CC) $(CFLAGS) -c getfile.c -o getfile.o

builtins.o: builtins.c shell.h lists.h main.h
	$(CC) $(CFLAGS) -c builtins.c -o builtins.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f simple_shell

re: fclean all

.PHONY: clean fclean all re
