#          VARIABLES          #

#compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#sources and lib
NAME = libftprintf.a
SRCS = ft_func1.c ft_func2.c ft_ifs.c ft_printf.c

#objct files names
OBJS = $(SRCS:.c=.o)


#          RULES          #

#default target
all: $(NAME)

#creat library
$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

#compile no link
%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

#eraser
clean:
	rm -f $(OBJS)

#big eraser 
fclean: clean
	rm -f $(NAME)

#reset kolchi
re: fclean all

#fake file
.PHONY: clean