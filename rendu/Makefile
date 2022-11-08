NAME    = libft.a
SRCS    = ft_isalpha.c ft_isdigit.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .

all: ${NAME}

${NAME}: clean
	gcc -I ${HDRS} -c ft_isalpha.c
	gcc -I ${HDRS} -c ft_isdigit.c
#	gcc -I ${HDRS} -c $< -o ${<:.c=.o}
	ar rc libft.a ${OBJS}
 
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
#CFLAGS  = -Wall -Wextra -Werror
