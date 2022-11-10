#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

// The standards : c = EOF / a value that is representable in unsigned char
// c = an unsigned char or EOF, isascii undefined behavior for other values 
// If the argument c char, must be cast to unsigned char
// isalpha - макрокоманда
// определена только если isascii(c) равно true или c = EOF
// isalpha доступна в UNIX, поддерживается стандартом ANSI C
// почему ilsapha макрос
// print_test("isascii",'*',isascii,ft_isascii) ?
// Error: HEADER_PROT_ALL

void print_test_char(char *func_name, char c, int(*f1)(int), int(*f2)(int), char *comment)
{
	printf("%s(%c\t%d\t%32b\t%8x) \t%d  \t%d     %s\n",func_name,c,c,c,c,f1(c),f2(c),comment); 
}

void print_test_str(char *func_name, char* str, size_t(*f1)(const char *), int(*f2)(char *),char *comment)
{
	printf("%s(%s) \t%ld  \t%d     %s\n",func_name,str,f1(str),f2(str),comment); 
}

int main(void)
{
	printf("\t\t\t\t\t\t\t\t\t\tlibc\tmy_func\n");
	print_test_char("isalpha",'a',isalpha,ft_isalpha,"");
	print_test_char("isalpha",'b',isalpha,ft_isalpha,"");
	print_test_char("isalpha",'c',isalpha,ft_isalpha,"");
	print_test_char("isalpha",'A',isalpha,ft_isalpha,"");
	print_test_char("isalpha",'Z',isalpha,ft_isalpha,"");
	print_test_char("isalpha",'*',isalpha,ft_isalpha,"");
	printf("\n");
	print_test_char("isdigit",'*',isdigit,ft_isdigit,"");
	print_test_char("isdigit",'0',isdigit,ft_isdigit,"");
	printf("\n");
	print_test_char("isalnum",'0',isalnum,ft_isalnum,"");
	print_test_char("isalnum",'*',isalnum,ft_isalnum,"");
	printf("\n");

	print_test_char("isascii",0,isascii,ft_isascii,""); // 8 bits
	print_test_char("isascii",0x7E,isascii,ft_isascii,"0x7E = 126"); // 8 bits 
	print_test_char("isascii",0x7F,isascii,ft_isascii,"0x7F = 127"); // 8 bits
	print_test_char("isascii",128,isascii,ft_isascii,"0x80 = 128 non permis"); // 32 bits non permis
	print_test_char("isascii",0xF0,isascii,ft_isascii,"0xF0 = 256 non permis"); // 32 bits non permis
	print_test_char("isascii",0xF1,isascii,ft_isascii,"0xF1 = 257 non permis"); // 32 bits non permis
	print_test_char("isascii",EOF,isascii,ft_isascii,"EOF non permis"); // 32 bits non permis
	printf("\n");

	print_test_char("isprint",0,isprint,ft_isprint,"");
	print_test_char("isprint",1,isprint,ft_isprint,"");
	print_test_char("isprint",31,isprint,ft_isprint,"");
	print_test_char("isprint",32,isprint,ft_isprint,"");
	print_test_char("isprint",'*',isprint,ft_isprint,"");
	print_test_char("isprint",127,isprint,ft_isprint,"// 127");
	print_test_char("isprint",128,isprint,ft_isprint,"// 128 non permis");
	print_test_char("isprint",129,isprint,ft_isprint,"// 129 non permis");
	printf("\n");

	print_test_str("strlen","my str",strlen,ft_strlen,"");
	print_test_str("strlen","s",strlen,ft_strlen,"");
	print_test_str("strlen","",strlen,ft_strlen,"vide");
	print_test_str("strlen","\0",strlen,ft_strlen,"\\0");
	print_test_str("strlen","\n",strlen,ft_strlen,"\\n");
	printf("\n");

	void *s;
	ft_memset(s, 61, 1);

}