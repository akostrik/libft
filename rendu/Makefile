NAME    = libft.a
SRCS    = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: clean ${OBJS} 
	gcc -c ${OBJS} -o ${NAME}
	ar rc libft.a ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
