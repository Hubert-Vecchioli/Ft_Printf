

SRCS	= ft_printf.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c libft_put.c 

OBJS	=  ${SRCS:.c=.o}

NAME = libftprintf.a

all : ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME} : $(OBJS)
	ar rc ${NAME} $(OBJS)

clean :
	rm -f ${OBJS} ${BNS_OBJS}

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY:	all clean fclean re