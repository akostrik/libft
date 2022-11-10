#include <stdio.h>
#include <ctype.h>
#include "libft.h"

// The standards : c = EOF / a value that is representable in unsigned char
// c = an unsigned char or EOF, isascii undefined behavior for other values 
// If the argument c is of type char, it must be cast to unsigned char
// isalpha - макрокоманда
// определена только если isascii(c) равно true или c = EOF
// isalpha доступна в UNIX, поддерживается стандартом ANSI C



// почему ilsapha макрос
// 	print_test("isascii",'*',isascii,ft_isascii) ?

void print_test(char *func_name, char c, int(*f1)(int), int(*f2)(int))
{
	//printf("? %s\n",int(*f1));
	printf("%s(%1c %2d %2x)\t%d  \t%d\n",func_name,c,c,c,f1(c),f2(c)); //
}

int main(void)
{
	printf("           \t\tlibc\tmy_func !\n");
	print_test("isalpha",'a',isalpha,ft_isalpha);
	print_test("isalpha",'*',isalpha,ft_isalpha);
	print_test("isdigit",'*',isdigit,ft_isdigit);
	print_test("isdigit",'0',isdigit,ft_isdigit);
	print_test("isalnum",'0',isalnum,ft_isalnum);
	print_test("isalnum",'*',isalnum,ft_isalnum);

	//print_test("isascii",'*',isascii,ft_isascii); ?
	int c = '#';
	printf("isascii(%1c %2d %2x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = EOF;
	printf("isascii(%1c %2d %2x)\t%d  \t%d   // EOF\n",c,c,c,isascii(c),ft_isascii(c));
	c = NULL;
	printf("isascii(%2c %2d %2x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = 0x7F;
	printf("isascii(%2c %2d %2x)\t%d  \t%d\n",c,c,c,isascii(c),ft_isascii(c));
	c = 0xF0;
	printf("isascii(%c %2d %2x)\t%d  \t%d   // 0xF0 = 256\n",c,c,c,isascii(c),ft_isascii(c));
}
