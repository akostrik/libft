#include <stdio.h>
#include <ctype.h>
#include "libft.h"

// The standards : c = EOF / a value that is representable in unsigned char
// If the argument c is of type char, it must be cast to unsigned char
// res = toupper((unsigned char) c)
// определена только если isascii(c) равно true или c = EOF
// isalpha - это макрокоманда
// isalpha доступна в системах UNIX и поддерживается стандартом ANSI C
// аргумент имеет тип int, причем его значение должно принадлежать диапазону 
// значений типа unsigned char, или же быть равным значению макроконстанты 
// EOF. Если аргумент имеет любое другое значение, поведение функций не определено

/// почему макрос

int main(void)
{
	char c; // an unsigned char or EOF

	printf("           \tlibc\tmy_func\n");
	c = 'a';
	printf("isalpha(%c)\t%d  \t%d\n",c,isalpha(c),ft_isalpha(c));
	c = '*';
	printf("isalpha(%c)\t%d  \t%d\n",c,isalpha(c),ft_isalpha(c));
	c = '3';
	printf("isdigit(%c)\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
	c = '0';
	printf("isdigit(%c)\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
	c = 'a';
	printf("isdigit(%c)\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
}