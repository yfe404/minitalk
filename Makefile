NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): server.c $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) server.c -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

$(NAME_CLIENT): client.c $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) client.c -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f *.o
	rm -rf *.dSYM

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
