# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_CLIENT = client.c $(SRC_COMMON)
SRC_SERVER = server.c $(SRC_COMMON)

# Headers
HEADERS = ft_printf/ft_printf.h Libft/libft.h

# Printf Library
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

# Libft Library
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# Objects
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Executables
NAME_CLIENT = client
NAME_SERVER = server

# Rules
all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_SERVER)

# Rule to compile .c files into .o files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build Printf Library
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Build Libft Library
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re