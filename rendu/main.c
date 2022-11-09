#include <stdio.h>
#include <ctype.h>
#include "libft.h"

// The standards : c = EOF / a value that is representable in unsigned char
// If the argument c is of type char, it must be cast to unsigned char
// res = toupper((unsigned char) c)
// определена только если isascii(c) равно true или c = EOF
// isalpha - макрокоманда
// isalpha доступна в UNIX, поддерживается стандартом ANSI C
// аргумент int, его значение должно принадлежать диапазону 
// значений типа unsigned char, или же быть равным значению макроконстанты 
// EOF. Если аргумент имеет любое другое значение, поведение функций не определено

/// почему ilsapha макрос

void print_test(char c, int(*f1)(int), int(*f2)(int))
{
	printf("? %s\n",int(*f1));
	printf("isascii(%c %d %x)\t%d  \t%d\n",c,c,c,f1(c),f2(c)); //
}

int main(void)
{
	int c; // an unsigned char or EOF

	printf("           \t\tlibc\tmy_func !\n");
	printf("isalpha(%c)\t\t%d  \t%d\n",c,isalpha(c),ft_isalpha(c));
	print_test('a',isalpha,ft_isalpha);
	c = '*';
	printf("isalpha(%c)\t\t%d  \t%d\n",c,isalpha(c),ft_isalpha(c));
	c = '3';
	printf("isdigit(%c)\t\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
	c = '0';
	printf("isdigit(%c)\t\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
	c = 'a';
	printf("isdigit(%c)\t\t%d  \t%d\n",c,isdigit(c),ft_isdigit(c));
	c = 'a';
	printf("isalnum(%c)\t\t%d  \t%d\n",c,isalnum(c),ft_isalnum(c));
	c = '0';
	printf("isalnum(%c)\t\t%d  \t%d\n",c,isalnum(c),ft_isalnum(c));
	c = '0';
	printf("isascii(%c %d %x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = '#';
	printf("isascii(%c %d %x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = EOF;
	printf("isascii(%c %d %x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = NULL;
	printf("isascii(NULL %d %x)\t%d  \t%d\n",c,c,isascii(c),ft_isascii(c));

}
