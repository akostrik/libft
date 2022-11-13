// везде проверить MAXINT NULL 0 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
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
	printf("%s(%c\t%d\t%32b\t%8x) \t%d  \t%d     %s\n",func_name,c,c,c,c,f1(c),f2(c),comment); 
}

void mem_to_str(void* mem, size_t nb_bytes, char* res_str) // проверить memset etc
{
	int i = 0;
	if (mem != NULL)
		for(; i < (int)nb_bytes; i++)
			res_str[i] = ((char*)mem)[i];
	res_str[i] = '\0';
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
	printf("isascii(0 \t%d\t%32b\t\t\t\t%8x) \t%d  \t%d \n",0,0,0,isascii(0),ft_isascii(0)); 
	print_test_char("isascii",0x7E,isascii,ft_isascii,"0x7E = 126"); // 8 bits 
	printf("isascii(' ' \t%d\t%32b\t%8x) \t\t\t%d  \t%d     espace\n",' ',' ',' ',isascii(' '),ft_isascii(' ')); 
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

	printf("strlen(\"my str\") \t\t\t\t\t\t\t\t%ld  \t%d\n",strlen("my str"),ft_strlen("my str")); 
	printf("strlen(\"s\") \t\t\t\t\t\t\t\t\t%ld  \t%d\n",strlen("s"),ft_strlen("s")); 
	printf("strlen(\"\") \t\t\t\t\t\t\t\t\t%ld  \t%d\n",strlen(""),ft_strlen("0")); 
	printf("strlen(\"\\0\") \t\t\t\t\t\t\t\t\t%ld  \t%d\n",strlen("\0"),ft_strlen("\0")); 
	printf("strlen(\"\\n\") \t\t\t\t\t\t\t\t\t%ld  \t%d\n",strlen("\n"),ft_strlen("\n")); 
	printf("\n");

	char s1[4] = { 'A', 'B', 'C', '\0'};
	printf("memset(%s,'D')\t\t\t\t\t\t\t\t\t",s1);
	printf("[%s]\t",(char *)memset(s1, 'D', 3));
	printf("[%s]\n",(char *)ft_memset(s1, 'D', 3));

	char s2[4] = { 'A', 'B', 'C', '\0'};
	printf("bzero(%s)\t\t\t\t\t\t\t\t\t",s2);
	bzero(s2, 3);
	printf("[%s]\t",s2);
	char s3[4] = { 'A', 'B', 'C', '\0'};
	ft_bzero(s3, 3);
	printf("[%s]\n",s3);

	char s4[4] = { 'A', 'B', 'C', '\0'};
	char s5[4] = { 'D', 'E', 'F', '\0'};
	printf("memcpy(%s,%s)\t\t\t\t\t\t\t\t\t",s5,s4);
	printf("[%s]\t",(char *)memcpy(s5,s4,4));
	char s6[4] = { 'A', 'B', 'C', '\0'};
	char s7[4] = { 'D', 'E', 'F', '\0'};
	printf("[%s]\n",(char *)ft_memcpy(s7,s6,4));

	char s8[4] = { 'A', 'B', 'C', '\0'};  // разной длины?
	char s9[4] = { 'D', 'E', 'F', '\0'};
	printf("memmove(%s,%s)\t\t\t\t\t\t\t\t",s9,s8);
	printf("%s\t",(char *)memmove(s9,s8,4));
	char s10[4] = { 'A', 'B', 'C', '\0'};
	char s11[4] = { 'D', 'E', 'F', '\0'};
	printf("[%s]\n",(char *)ft_memmove(s11,s10,4));
	printf("\n");

	printf("strlcpy returns the total length of the string it tried to create = the length of src\n");
	// poprobovqt korotkie stroki
	/*
	char *src = "ABC";
	char dst01[3];
	char dst02[3];
	printf("strlcpy(\"%s\" \"%s\" %d)\t\t\t",dst01,src,0); // dst01
	size_t ret = strlcpy(dst01, src, 0);
	printf("dst=\"%s\" ret=%ld\t\t\t",dst01,ret); 
	ret = ft_strlcpy(dst02, src, 0); 
	printf("dst=\"%s\" ret=%ld\n",dst02,ret); 
	
	char dst03[3];
	char dst04[3];
	printf("strlcpy(\"%s\" \"%s\" 1)\t\t\t",dst03,src);
	ret = strlcpy(dst03, src, 1); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst03,ret); 
	ret = ft_strlcpy(dst04, src, 1); 
	printf("dst=\"%s\" ret=%ld\n",dst04,ret); 

	char dst05[3];
	char dst06[3];
	printf("strlcpy(\"%s\" \"%s\" 2)\t\t\t",dst05,src);
	ret = strlcpy(dst05, src, 2); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst05,ret); 
	ret = ft_strlcpy(dst06, src, 2); 
	printf("dst=\"%s\" ret=%ld\n",dst06,ret); 

	char dst07[3];
	char dst08[3];
	printf("strlcpy(\"%s\" \"%s\" 3)\t\t\t",dst07,src);
	ret = strlcpy(dst07, src, 3); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst07,ret); 
	ret = ft_strlcpy(dst08, src, 3); 
	printf("dst=\"%s\" ret=%ld\n",dst08,ret); 

	char dst09[3];
	char dst10[3];
	printf("strlcpy(\"%s\" \"%s\" 4)\t\t\t",dst09,src);
	ret = strlcpy(dst09, src, 4); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst09,ret); 
	ret = ft_strlcpy(dst10, src, 4); 
	printf("dst=\"%s\" ret=%ld\n",dst10,ret); 

	char dst11[3];
	char dst12[3];
	printf("strlcpy(\"%s\" \"%s\" 5)\t\t\t",dst11,src);
	ret = strlcpy(dst11, src, 5); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst11,ret); 
	ret = ft_strlcpy(dst12, src, 5); 
	printf("dst=\"%s\" ret=%ld\n",dst12,ret); 
	printf("\n"); 

	printf("strlcat returns the total length of the string they tried to create = the initial length of dst + the length of src\n");
	char dst13[8]; dst13[0]='D'; dst13[1]='E'; dst13[2]='F'; dst13[3]='\0';
	char dst14[8]; dst14[0]='D'; dst14[1]='E'; dst14[2]='F'; dst14[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst13,src,0);
	ret = strlcat(dst13, src, 0); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst13,ret); 
	ret = ft_strlcat(dst14, src, 0); 
	printf("dst=\"%s\" ret=%ld\n",dst14,ret); 

	char dst15[8]; dst15[0]='D'; dst15[1]='E'; dst15[2]='F'; dst15[3]='\0';
	char dst16[8]; dst16[0]='D'; dst16[1]='E'; dst16[2]='F'; dst16[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst15,src,1);
	ret = strlcat(dst15, src, 1); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst15,ret); 
	ret = ft_strlcat(dst16, src, 1); 
	printf("dst=\"%s\" ret=%ld\n",dst16,ret); 

	char dst17[8]; dst17[0]='D'; dst17[1]='E'; dst17[2]='F'; dst17[3]='\0';
	char dst18[8]; dst18[0]='D'; dst18[1]='E'; dst18[2]='F'; dst18[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst17,src,2);
	ret = strlcat(dst17, src, 2); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst17,ret); 
	ret = ft_strlcat(dst18, src, 2); 
	printf("dst=\"%s\" ret=%ld\n",dst18,ret); 

	char dst19[8]; dst19[0]='D'; dst19[1]='E'; dst19[2]='F'; dst19[3]='\0';
	char dst20[8]; dst20[0]='D'; dst20[1]='E'; dst20[2]='F'; dst20[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst19,src,3);
	ret = strlcat(dst19, src, 3); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst19,ret); 
	ret = ft_strlcat(dst20, src, 3); 
	printf("dst=\"%s\" ret=%ld\n",dst20,ret); 
	
	char dst21[8]; dst21[0]='D'; dst21[1]='E'; dst21[2]='F'; dst21[3]='\0';
	char dst22[8]; dst22[0]='D'; dst22[1]='E'; dst22[2]='F'; dst22[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst21,src,4);
	ret = strlcat(dst21, src, 4); 
	printf("dst=\"%s\" ret=%ld\t\t\t",dst21,ret);
	ret = ft_strlcat(dst22, src, 4); 
	printf("dst=\"%s\" ret=%ld\n",dst22,ret);

	char dst23[8]; dst23[0]='D'; dst23[1]='E'; dst23[2]='F'; dst23[3]='\0';
	char dst24[8]; dst24[0]='D'; dst24[1]='E'; dst24[2]='F'; dst24[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst23,src,5);
	ret = strlcat(dst23, src, 5); 
	printf("dst=\"%s\" ret=%ld\t\t",dst23,ret); 
	ret = ft_strlcat(dst24, src, 5); 
	printf("dst=\"%s\" ret=%ld\n",dst24,ret); 

	char dst25[8]; dst25[0]='D'; dst25[1]='E'; dst25[2]='F'; dst25[3]='\0';
	char dst26[8]; dst26[0]='D'; dst26[1]='E'; dst26[2]='F'; dst26[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst25,src,6);
	ret = strlcat(dst25, src, 6); 
	printf("dst=\"%s\" ret=%ld\t\t",dst25,ret); 
	ret = ft_strlcat(dst26, src, 6); 
	printf("dst=\"%s\" ret=%ld\n",dst26,ret); 

	char dst27[8]; dst27[0]='D'; dst27[1]='E'; dst27[2]='F'; dst27[3]='\0';
	char dst28[8]; dst28[0]='D'; dst28[1]='E'; dst28[2]='F'; dst28[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst27,src,7);
	ret = strlcat(dst27, src, 7); 
	printf("dst=\"%s\" ret=%ld\t\t",dst27,ret); 
	ret = ft_strlcat(dst28, src, 7); 
	printf("dst=\"%s\" ret=%ld\n",dst28,ret); 

	char dst29[8]; dst29[0]='D'; dst29[1]='E'; dst29[2]='F'; dst29[3]='\0';
	char dst30[8]; dst30[0]='D'; dst30[1]='E'; dst30[2]='F'; dst30[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst29,src,8);
	ret = strlcat(dst29, src, 8); 
	printf("dst=\"%s\" ret=%ld\t\t",dst29,ret); 
	ret = ft_strlcat(dst30, src, 8); 
	printf("dst=\"%s\" ret=%ld\n",dst30,ret); 

	char dst31[8]; dst31[0]='D'; dst31[1]='E'; dst31[2]='F'; dst31[3]='\0';
	char dst32[8]; dst32[0]='D'; dst32[1]='E'; dst32[2]='F'; dst32[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst31,src,9);
	ret = strlcat(dst31, src, 9); 
	printf("dst=\"%s\" ret=%ld\t\t",dst31,ret); 
	ret = ft_strlcat(dst32, src, 9); 
	printf("dst=\"%s\" ret=%ld\n",dst32,ret); 

	char dst33[8]; dst33[0]='D'; dst33[1]='E'; dst33[2]='F'; dst33[3]='\0';
	char dst34[8]; dst34[0]='D'; dst34[1]='E'; dst34[2]='F'; dst34[3]='\0';
	printf("strlcat(\"%s\" \"%s\" %d)\t\t\t",dst33,src,10);
	ret = strlcat(dst33, src, 10); 
	printf("dst=\"%s\" ret=%ld\t\t",dst33,ret); 
	ret = ft_strlcat(dst34, src, 10); 
	printf("dst=\"%s\" ret=%ld\n",dst34,ret); 
	*/
	printf("\n");

	printf("toupper('a')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'a'),ft_toupper((unsigned char)'a'));
	printf("toupper('A')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'A'),ft_toupper((unsigned char)'A'));
	printf("toupper('*')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'*'),ft_toupper((unsigned char)'*'));
	printf("tolower('A')\t\t\t\t%c\t\t\t\t%c\n",tolower((unsigned char)'A'),ft_tolower((unsigned char)'A'));

	printf("\n");
	printf("strchr(\"ABC\",'B')\t\t\t[%s]\t\t\t\t[%s]\n",strchr("ABC",'B'),ft_strchr("ABC",'B'));
	printf("strchr(\"ABC\",'C')\t\t\t[%s]\t\t\t\t[%s]\n",strchr("ABC",'C'),ft_strchr("ABC",'C'));
	printf("strchr(\"ABC\",'\\0')\t\t\t[%s]\t\t\t\t[%s]\n",strchr("ABC",'\0'),ft_strchr("ABC",'\0'));
	printf("strchr(\"ABC\",'D')\t\t\t%s\t\t\t\t%s\n",strchr("ABC",'D'),ft_strchr("ABC",'D'));

	printf("\n");
	printf("strrchr(\"ABC\",'A')\t\t\t[%s]\t\t\t\t[%s]\n",strrchr("ABC",'A'),ft_strrchr("ABC",'A'));
	printf("strrchr(\"AAC\",'A')\t\t\t[%s]\t\t\t\t[%s]\n",strrchr("AAC",'A'),ft_strrchr("AAC",'A'));
	printf("strrchr(\"AAA\",'A')\t\t\t[%s]\t\t\t\t[%s]\n",strrchr("AAA",'A'),ft_strrchr("AAA",'A'));
	printf("strrchr(\"AAA\",'\\0')\t\t\t[%s]\t\t\t\t[%s]\n",strrchr("AAA",'\0'),ft_strrchr("AAA",'\0'));
	printf("strrchr(\"ABC\",'D')\t\t\t%s\t\t\t\t%s\n",strrchr("ABC",'D'),ft_strrchr("ABC",'D'));

	printf("\n");
	printf("strncmp(\"ABE\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABE","ABC",3),ft_strncmp("ABE","ABC",3));
	printf("strncmp(\"ABD\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABD","ABC",3),ft_strncmp("ABD","ABC",3));
	printf("strncmp(\"ABC\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABC",3),ft_strncmp("ABC","ABC",3));
	printf("strncmp(\"ABC\",\"ABD\",3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABD",3),ft_strncmp("ABC","ABD",3));
	printf("strncmp(\"ABE\",\"ABC\",2)\t\t\t%d\t\t\t\t%d\n",strncmp("ABE","ABC",2),ft_strncmp("ABE","ABC",2));
	printf("strncmp(\"ABC\",\"BCD\",0)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","BCD",0),ft_strncmp("ABC","BCD",0));
	printf("strncmp(\"\\0\",\"\\0\",1)\t\t\t%d\t\t\t\t%d\n",strncmp("\0","\0",1),ft_strncmp("\0","\0",1));
	printf("strncmp(\"A\",\"ABD\",1)\t\t\t%d\t\t\t\t%d\n",strncmp("A","ABD",1),ft_strncmp("A","ABD",1));
	printf("strncmp(\"A\",\"ABD\",2)\t\t\t%d\t\t\t\t%d\n",strncmp("A","ABD",2),ft_strncmp("A","ABD",2));
	printf("strncmp(\"ABC\",\"ABC\",10)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABC",10),ft_strncmp("ABC","ABC",10));
	printf("\n");

	char* mem = "ABC";
	printf("memchr(\"ABC\",'B',0)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',0),(char*)ft_memchr(mem,'B',0));
	printf("memchr(\"ABC\",'B',1)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',1),(char*)ft_memchr(mem,'B',1));
	printf("memchr(\"ABC\",'B',2)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',2),(char*)ft_memchr(mem,'B',2));
	printf("memchr(\"ABC\",'B',5)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',5),(char*)ft_memchr(mem,'B',5));
	printf("memchr(\"ABC\",'D',5)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'D',5),(char*)ft_memchr(mem,'D',5));
	printf("\n");

	printf("memcmp(\"ABC\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","ABC",3),ft_memcmp("ABC","ABC",3));
	printf("memcmp(\"ABC\",\"ABD\",3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","ABD",3),ft_memcmp("ABC","ABD",3));
	printf("memcmp(\"ABD\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",3),ft_memcmp("ABD","ABC",3));
	printf("memcmp(\"ABE\",\"ABC\",3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",3),ft_memcmp("ABE","ABC",3));
	printf("memcmp(\"ABE\",\"ABC\",4)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",4),ft_memcmp("ABE","ABC",4));
	printf("memcmp(\"ABE\",\"ABC\",5)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",5),ft_memcmp("ABE","ABC",5));
	printf("memcmp(\"ABD\",\"ABC\",2)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",2),ft_memcmp("ABD","ABC",2));
	printf("memcmp(\"ABD\",\"ABC\",1)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",1),ft_memcmp("ABD","ABC",1));
	printf("memcmp(\"ABD\",\"ABC\",0)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",0),ft_memcmp("ABD","ABC",0));
	printf("memcmp(\"\\0\",\"\\0\",2)\t\t\t%d\t\t\t\t%d\n",memcmp("\\0","\\0",2),ft_memcmp("\\0","\\0",2));
	printf("memcmp(\"ABC\",\"\\0\",1)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","\\0",1),ft_memcmp("ABC","\\0",1));
	printf("\n");

	// попробовать больше maxint
	char* str1 = "42";	
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str1,atoi(str1),ft_atoi(str1));
	char* str2 = "-42";	
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str2,atoi(str2),ft_atoi(str2));
	char* str3 = "--42";	
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str3,atoi(str3),ft_atoi(str3));
	char* str4 = " -42";	
	printf("atoi(\"[%s]\")\t\t\t\t%d\t\t\t\t%d\n",str4,atoi(str4),ft_atoi(str4));
	char* str5 = "a42";	
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str5,atoi(str5),ft_atoi(str5));
	char* str6 = "42a b";	
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str6,atoi(str6),ft_atoi(str6));
	char* str7 = "   42";	
	printf("atoi(\"[%s]\")\t\t\t\t%d\t\t\t\t%d\n",str7,atoi(str7),ft_atoi(str7));
	char* str8 = "2147483647";	
	printf("atoi(\"%s\")\t\t\t%d\t\t\t%d\n",str8,atoi(str8),ft_atoi(str8));
	char* str9 = "2147483648";	
	printf("atoi(\"%s\")\t\t\t%d\t\t\t%d\n",str9,atoi(str9),ft_atoi(str9));
	char* str10 = "-2147483648";	
	printf("atoi(\"%s\")\t\t\t%d\t\t\t%d\n",str10,atoi(str10),ft_atoi(str10));
	char* str11 = "-2147483649";	
	printf("atoi(\"%s\")\t\t\t%d\t\t\t%d\n",str11,atoi(str11),ft_atoi(str11));
	printf("\n");

	// ft_calloc попробовать огромные оба параметра
	void* mem01, *mem02;
	size_t nmemb = 5;
	size_t size = 1; // 1 byte
	char* res_str[100]; // 	
	printf("calloc(%ld,%ld)\t\t\t\t",nmemb,size);
	mem01 = calloc(nmemb,size);
	mem_to_str(mem01,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem02 = ft_calloc(nmemb,size);
	mem_to_str(mem02,nmemb,res_str);
	printf("[%s]\n",res_str);

	void* mem03, *mem04;
	nmemb = 5;
	size = 2; 
	printf("calloc(%ld,%ld)\t\t\t\t",nmemb,size);
	mem03 = calloc(nmemb,size);
	mem_to_str(mem03,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem04 = ft_calloc(nmemb,size);
	mem_to_str(mem04,nmemb,res_str);
	printf("[%s]                 // wait .....\n",res_str);

	/*
	void* mem05, *mem06;
	nmemb = 1; 
	size = INT_MAX; 
	printf("calloc(%ld,%ld)\t\t\t",nmemb,size);
	mem05 = calloc(nmemb,size);
	mem_to_str(mem05,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem06 = ft_calloc(nmemb,size);
	mem_to_str(mem06,nmemb,res_str);
	printf("[%s] \n",res_str);
	*/

	void* mem07, *mem08;
	nmemb = 2;   
	size = INT_MAX; 
	printf("calloc(%ld,%ld)\t\t\t",nmemb,size);
	mem07 = calloc(nmemb,size);
	mem_to_str(mem07,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem08 = ft_calloc(nmemb,size);
	mem_to_str(mem08,nmemb,res_str);
	printf("[%s]                 // quickly, calloc returns NULL\n",res_str);
	printf("\n");

	char *str12 = "abc";
	printf("strdup(%s)\t\t\t\t%s\t\t\t\t%s\n",str12,strdup(str12),ft_strdup(str12));
	char *str13 = "";
	printf("strdup(%s)\t\t\t\t[%s]\t\t\t\t[%s]\n",str13,strdup(str13),ft_strdup(str13));

}
