NAME    = libft.a
SRCS1   = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 
SRCS2   = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c
SRCS3   = ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c 
SRCS4   = ft_memchr.c ft_memcmp.c
SRCS    = ${SRCS1} ${SRCS2} ${SRCS3} ${SRCS4} 
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
