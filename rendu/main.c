#include <stdio.h>
#include <ctype.h>
#include <string.h>
//#include <bsd/string.h>
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
	printf("%s(%c\t%d\t%clear32b\t%8x) \t%d  \t%d     %s\n",func_name,c,c,c,c,f1(c),f2(c),comment); 
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

	// returns the total length of the string it tried to create = the length of src
	char *src = "ABC";
	char dst01[3];
	char dst02[3];
	printf("strlcpy(\"%s\" \"%s\" %d)\t\t\t",dst02,src,0); // dst01
	//size_t ret = strlcpy(dst01, src, 0);
	//printf("dst=%s, ret=%ld\t\t)",dst01,ret); 
	size_t ret = ft_strlcpy(dst02, src, 0); 
	printf("dst=\"%s\" ret=%ld\n",dst02,ret); 
	
	char dst03[3];
	printf("strlcpy(\"%s\" \"%s\" 1)\t\t\t",dst03,src);
	ret = ft_strlcpy(dst03, src, 1); 
	printf("dst=\"%s\" ret=%ld\n",dst03,ret); 

	char dst05[3];
	printf("strlcpy(\"%s\" \"%s\" 2)\t\t\t",dst05,src);
	ret = ft_strlcpy(dst05, src, 2); 
	printf("dst=\"%s\" ret=%ld\n",dst05,ret); 

	char dst07[3];
	printf("strlcpy(\"%s\" \"%s\" 3)\t\t\t",dst07,src);
	ret = ft_strlcpy(dst07, src, 3); 
	printf("dst=\"%s\" ret=%ld\n",dst07,ret); 

	char dst09[3];
	printf("strlcpy(\"%s\" \"%s\" 4)\t\t\t",dst09,src);
	ret = ft_strlcpy(dst09, src, 4); 
	printf("dst=\"%s\" ret=%ld\n",dst09,ret); 

	char dst11[3];
	printf("strlcpy(\"%s\" \"%s\" 5)\t\t\t",dst11,src);
	ret = ft_strlcpy(dst11, src, 5); 
	printf("dst=\"%s\" ret=%ld\n",dst11,ret); 

	printf("\n"); ///////////////////
	char dst13[8]; dst13[0]='D'; dst13[1]='E'; dst13[2]='F'; dst13[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst13,src,0);
	ret = ft_strlcat(dst13, src, 0); 
	printf("dst=\"%s\" ret=%ld\n",dst13,ret); 

	char dst15[8]; dst15[0]='D'; dst15[1]='E'; dst15[2]='F'; dst15[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst15,src,1);
	ret = ft_strlcat(dst15, src, 1); 
	printf("dst=\"%s\" ret=%ld\n",dst15,ret); 

	char dst17[8]; dst17[0]='D'; dst17[1]='E'; dst17[2]='F'; dst17[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst17,src,2);
	ret = ft_strlcat(dst17, src, 2); 
	printf("dst=\"%s\" ret=%ld\n",dst17,ret); 

	char dst19[8]; dst19[0]='D'; dst19[1]='E'; dst19[2]='F'; dst19[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst19,src,3);
	ret = ft_strlcat(dst19, src, 3); 
	printf("dst=\"%s\" ret=%ld\n",dst19,ret); 
	
	char dst21[8]; dst21[0]='D'; dst21[1]='E'; dst21[2]='F'; dst21[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst21,src,4);
	ret = ft_strlcat(dst21, src, 4); 
	printf("dst=\"%s\" ret=%ld\n",dst21,ret);

	char dst23[8]; dst23[0]='D'; dst23[1]='E'; dst23[2]='F'; dst23[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst23,src,5);
	ret = ft_strlcat(dst23, src, 5); 
	printf("dst=\"%s\" ret=%ld\n",dst23,ret); 

	char dst25[8]; dst25[0]='D'; dst25[1]='E'; dst25[2]='F'; dst25[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst25,src,6);
	ret = ft_strlcat(dst25, src, 6); 
	printf("dst=\"%s\" ret=%ld\n",dst25,ret); 

	char dst27[8]; dst27[0]='D'; dst27[1]='E'; dst27[2]='F'; dst27[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst27,src,7);
	ret = ft_strlcat(dst27, src, 7); 
	printf("dst=\"%s\" ret=%ld\n",dst27,ret); 

	char dst29[8]; dst29[0]='D'; dst29[1]='E'; dst29[2]='F'; dst29[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst29,src,8);
	ret = ft_strlcat(dst29, src, 8); 
	printf("dst=\"%s\" ret=%ld\n",dst29,ret); 

	char dst31[8]; dst31[0]='D'; dst31[1]='E'; dst31[2]='F'; dst31[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst31,src,9);
	ret = ft_strlcat(dst31, src, 9); 
	printf("dst=\"%s\" ret=%ld\n",dst31,ret); 

	char dst33[8]; dst33[0]='D'; dst33[1]='E'; dst33[2]='F'; dst33[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst33,src,10);
	ret = ft_strlcat(dst33, src, 10); 
	printf("dst=\"%s\" ret=%ld\n",dst33,ret); 

	char dst35[4]; dst35[0]='D'; dst35[1]='E'; dst35[2]='F'; dst35[3]='\0'; // dst size = 4
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst35,src,10);
	ret = ft_strlcat(dst35, src, 10); 
	printf("dst=\"%s\" ret=%ld\n",dst35,ret); 

	printf("\n");
	printf("toupper('a')\t\t\t\t\t%c\t%c\n",toupper((unsigned char)'a'),ft_toupper((unsigned char)'a'));
	printf("toupper('A')\t\t\t\t\t%c\t%c\n",toupper((unsigned char)'A'),ft_toupper((unsigned char)'A'));
	printf("toupper('*')\t\t\t\t\t%c\t%c\n",toupper((unsigned char)'*'),ft_toupper((unsigned char)'*'));
	printf("tolower('A')\t\t\t\t\t%c\t%c\n",tolower((unsigned char)'A'),ft_tolower((unsigned char)'A'));

	printf("\n");
	printf("strchr(\"ABC\",'B')\t\t\t\t\t[%s]\t[%s]\n",strchr("ABC",'B'),ft_strchr("ABC",'B'));
	printf("strchr(\"ABC\",'C')\t\t\t\t\t[%s]\t[%s]\n",strchr("ABC",'C'),ft_strchr("ABC",'C'));
	printf("strchr(\"ABC\",'\\0')\t\t\t\t\t[%s]\t[%s]\n",strchr("ABC",'\0'),ft_strchr("ABC",'\0'));
	printf("strchr(\"ABC\",'D')\t\t\t\t\t%s\t%s\n",strchr("ABC",'D'),ft_strchr("ABC",'D'));

	printf("\n");
	printf("strrchr(\"ABC\",'A')\t\t\t\t\t[%s]\t[%s]\n",strrchr("ABC",'A'),ft_strrchr("ABC",'A'));
	printf("strrchr(\"AAC\",'A')\t\t\t\t\t[%s]\t[%s]\n",strrchr("AAC",'A'),ft_strrchr("AAC",'A'));
	printf("strrchr(\"AAA\",'A')\t\t\t\t\t[%s]\t[%s]\n",strrchr("AAA",'A'),ft_strrchr("AAA",'A'));
	printf("strrchr(\"AAA\",'\\0')\t\t\t\t\t[%s]\t[%s]\n",strrchr("AAA",'\0'),ft_strrchr("AAA",'\0'));
	printf("strrchr(\"ABC\",'D')\t\t\t\t\t%s\t%s\n",strrchr("ABC",'D'),ft_strrchr("ABC",'D'));

	printf("\n");
	printf("strncmp(\"ABE\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",strncmp("ABE","ABC",3),ft_strncmp("ABE","ABC",3));
	printf("strncmp(\"ABD\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",strncmp("ABD","ABC",3),ft_strncmp("ABD","ABC",3));
	printf("strncmp(\"ABC\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",strncmp("ABC","ABC",3),ft_strncmp("ABC","ABC",3));
	printf("strncmp(\"ABC\",\"ABD\",3)\t\t\t\t\t%d\t%d\n",strncmp("ABC","ABD",3),ft_strncmp("ABC","ABD",3));
	printf("strncmp(\"ABE\",\"ABC\",2)\t\t\t\t\t%d\t%d\n",strncmp("ABE","ABC",2),ft_strncmp("ABE","ABC",2));
	printf("strncmp(\"ABC\",\"BCD\",0)\t\t\t\t\t%d\t%d\n",strncmp("ABC","BCD",0),ft_strncmp("ABC","BCD",0));
	printf("strncmp(\"\\0\",\"\\0\",1)\t\t\t\t\t%d\t%d\n",strncmp("\0","\0",1),ft_strncmp("\0","\0",1));
	printf("strncmp(\"A\",\"ABD\",1)\t\t\t\t\t%d\t%d\n",strncmp("A","ABD",1),ft_strncmp("A","ABD",1));
	printf("strncmp(\"A\",\"ABD\",2)\t\t\t\t\t%d\t%d\n",strncmp("A","ABD",2),ft_strncmp("A","ABD",2));
	printf("strncmp(\"ABC\",\"ABC\",10)\t\t\t\t\t%d\t%d\n",strncmp("ABC","ABC",10),ft_strncmp("ABC","ABC",10));

	printf("\n");
	char* mem = "ABC";
	printf("memchr(\"ABC\",'B',0)\t\t\t\t\t%s\t%s\n",(char*)memchr(mem,'B',0),(char*)ft_memchr(mem,'B',0));
	printf("memchr(\"ABC\",'B',1)\t\t\t\t\t%s\t%s\n",(char*)memchr(mem,'B',1),(char*)ft_memchr(mem,'B',1));
	printf("memchr(\"ABC\",'B',2)\t\t\t\t\t%s\t%s\n",(char*)memchr(mem,'B',2),(char*)ft_memchr(mem,'B',2));
	printf("memchr(\"ABC\",'B',5)\t\t\t\t\t%s\t%s\n",(char*)memchr(mem,'B',5),(char*)ft_memchr(mem,'B',5));
	printf("memchr(\"ABC\",'D',5)\t\t\t\t\t%s\t%s\n",(char*)memchr(mem,'D',5),(char*)ft_memchr(mem,'D',5));

	printf("\n");
	printf("memcmp(\"ABC\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",memcmp("ABC","ABC",3),ft_memcmp("ABC","ABC",3));
	printf("memcmp(\"ABC\",\"ABD\",3)\t\t\t\t\t%d\t%d\n",memcmp("ABC","ABD",3),ft_memcmp("ABC","ABD",3));
	printf("memcmp(\"ABD\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",memcmp("ABD","ABC",3),ft_memcmp("ABD","ABC",3));
	printf("memcmp(\"ABE\",\"ABC\",3)\t\t\t\t\t%d\t%d\n",memcmp("ABE","ABC",3),ft_memcmp("ABE","ABC",3));
	printf("memcmp(\"ABE\",\"ABC\",4)\t\t\t\t\t%d\t%d\n",memcmp("ABE","ABC",4),ft_memcmp("ABE","ABC",4));
	printf("memcmp(\"ABE\",\"ABC\",5)\t\t\t\t\t%d\t%d\n",memcmp("ABE","ABC",5),ft_memcmp("ABE","ABC",5));
	printf("memcmp(\"ABD\",\"ABC\",2)\t\t\t\t\t%d\t%d\n",memcmp("ABD","ABC",2),ft_memcmp("ABD","ABC",2));
	printf("memcmp(\"ABD\",\"ABC\",1)\t\t\t\t\t%d\t%d\n",memcmp("ABD","ABC",1),ft_memcmp("ABD","ABC",1));
	printf("memcmp(\"ABD\",\"ABC\",0)\t\t\t\t\t%d\t%d\n",memcmp("ABD","ABC",0),ft_memcmp("ABD","ABC",0));
	printf("memcmp(\"\\0\",\"\\0\",2)\t\t\t\t\t%d\t%d\n",memcmp("\\0","\\0",2),ft_memcmp("\\0","\\0",2));
	printf("memcmp(\"ABC\",\"\\0\",1)\t\t\t\t\t%d\t%d\n",memcmp("ABC","\\0",1),ft_memcmp("ABC","\\0",1));
}