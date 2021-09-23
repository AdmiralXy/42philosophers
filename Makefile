CC = gcc
RM = rm -f
INC = includes
INCLUDES = ft_philosophers.h
CFLAGS = -Wall -Wextra -Werror -pthread -I$(INC)

NAME = philo

SRCS = srcs/ft_main.c \
		srcs/ft_atoi.c \
		srcs/ft_init.c \
		srcs/ft_utils.c \
		srcs/ft_threads.c

OBJS = $(SRCS:%.c=%.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "Building: \033[0;34m$<\033[0m"

$(NAME): $(INC)/$(INCLUDES) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Binary \033[0;32m$(NAME)\033[0m successfully linked!"

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

norminette:
	norminette $(SRCS)
	norminette $(INC)/$(INCLUDES)
	@echo "\033[0;35mAll files in accordance with norminette!\033[0m"