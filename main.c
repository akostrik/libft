// calloc, strdup, substr, strjoin, strtrim, split, itoa, strmapi

// возвращаемые значения у меня и у libc не совпадают
// The standards : c = EOF / a value that is representable in unsigned char
// If the argument c char, must be cast to unsigned char

/*
size_t
Used for a count of bytes
The result of the sizeof()
C standard: an unsigned integer [0, SIZE_MAX]
POSIX: the implementation shall support one or more programming environments
where the width of size_t is no greater than the width of the type long
Printf(3), scanf(3) : %zu or %zx
Размер типа выбирается таким образом, чтобы в него можно было записать максимальный размер
теоретически возможного массива любого типа. Например, на 32-битной системе size_t
будет занимать 32-бита, на 64-битной - 64-бита. В переменную типа size_t может
быть безопасно помещен указатель. Исключение составляют указатели на функции
классов, но это особый случай.
Гарантированно может использоваться для адресной арифметики.
Позволяет писать переносимый код.
Проблемы адресной арифметики стали активно проявлять себя с началом освоения 64-битных систем.
size_t следует использовать в качестве индексов больших массивов, для хранения указателей и арифметики с указателями.
Тип long в рамках 32-битных и 64-битных моделей данных, принятых в Linux, тоже работает.
Размер типа long совпадает с размером указателя. Но такой код несовместим с Windows.
Хотя в size_t можно помещать указатель, для этих целей лучше подходит uintptr_t.
size_t обычно применяется для счетчиков циклов, индексации массивов,
хранения размеров, адресной арифметики.
Максимально допустимое значение size_t = SIZE_MAX.
*/

#include "submit/libft.h"

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
	printf("******************************************************************************* LIBC ** MY FUNCTION ***\n");
	char c = 'a';
	[[fallthrough]]
	printf("isalpha(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalpha(c),ft_isalpha(c));
	c = 'A';
	printf("isalpha(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalpha(c),ft_isalpha(c));
	c = '#';
	printf("isalpha(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalpha(c),ft_isalpha(c));
	c = EOF;
	printf("isalpha(EOF\t%d\t%32b\t%8x)\t%d\t%d\t\n",c,c,c,c,isalpha(c),ft_isalpha(c));
	printf("\n");

	c = '0';
	printf("isdigit(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isdigit(c),ft_isdigit(c));
	c = '#';
	printf("isdigit(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isdigit(c),ft_isdigit(c));
	c = EOF;
	printf("isdigit(EOF\t%d\t%32b\t%8x)\t%d\t%d\t\n",c,c,c,c,isdigit(c),ft_isdigit(c));
	printf("\n");

	c = '0';
	printf("isalnum(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalnum(c),ft_isalnum(c));
	c = 'a';
	printf("isalnum(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalnum(c),ft_isalnum(c));
	c = '#';
	printf("isalnum(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalnum(c),ft_isalnum(c));
	c = EOF;
	printf("isalnum(EOF\t%d\t%32b\t%8x)\t%d\t%d\t\n",c,c,c,c,isalnum(c),ft_isalnum(c));
	printf("\n");

	c = 0;
	printf("isascii([%c]\t%d\t%32b\t%8x)\t%d\t%d \n",c,c,c,c,isascii(c),ft_isascii(c));
	c = ' ';
	printf("isascii(' '\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 'a';
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d \n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 126;
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d \n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 127;
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d\t\n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 128;
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d\t// 0x80 = 128 no ascii\n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 0xF0;
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d\t// 0xF0 = 256 no ascii\n",c,c,c,c,isascii(c),ft_isascii(c));
	c = 0xF1;
	printf("isascii(%c\t%d\t%32b\t%8x)\t%d\t%d\t// 0xF1 = 257 no ascii\n",c,c,c,c,isascii(c),ft_isascii(c));
	c = EOF;
	printf("isascii(EOF\t%d\t%32b\t%8x)\t%d\t%d\t// no ascii\n",c,c,c,c,isascii(c),ft_isascii(c));
	printf("\n");

	c = 0;
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 1;
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 31;
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 32;
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = '#';
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 127;
	printf("isprint(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 128;
	printf("isprint(128\t%d\t%32b\t%8x)\t%d\t%d\t// no permitted\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = 129;
	printf("isprint(129\t%d\t%32b\t%8x)\t%d\t%d\t// no permitted\n",c,c,c,c,isprint(c),ft_isprint(c));
	c = EOF;
	printf("isprint(EOF\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isprint(c),ft_isprint(c));
	printf("\n");

	printf("*************************************** LIBC ************************** MY FUNCTION ***\n");
	printf("strlen(\"my str\")\t\t\t%ld\t\t\t\t%d\n",strlen("my str"),ft_strlen("my str"));
	printf("strlen(\"s\")\t\t\t\t%ld\t\t\t\t%d\n",strlen("s"),ft_strlen("s"));
	printf("strlen(\"\")\t\t\t\t%ld\t\t\t\t%d\n",strlen(""),ft_strlen(""));
	printf("strlen(\"\\0\")\t\t\t\t%ld\t\t\t\t%d\n",strlen("\0"),ft_strlen("\0"));
	printf("strlen(\"\\n\")\t\t\t\t%ld\t\t\t\t%d\n",strlen("\n"),ft_strlen("\n"));
	printf("strlen(NULL)\t\t\t\tsegmentation fault\t\t%d\n",ft_strlen(NULL));
	printf("\n");

	char s1[4] = { 'A', 'A', 'A', '\0'};
	char s16[4] = { 'A', 'A', 'A', '\0'};
	int n = 3;
	printf("memset(%s,'a',%d)\t\t\t",s1,n);
	printf("[%s]\t\t\t\t",(char *)memset(s1, 'a', n));
	printf("[%s]\n",(char *)ft_memset(s16, 'a', n));

	char s12[4] = { 'A', 'A', 'A', '\0'};
	char s17[4] = { 'A', 'A', 'A', '\0'};
	n = 2;
	printf("memset(%s,'a',%d)\t\t\t",s12,n);
	printf("[%s]\t\t\t\t",(char *)memset(s12, 'a', n));
	printf("[%s]\n",(char *)ft_memset(s17, 'a', n));

	char s13[4] = { 'A', 'A', 'A', '\0'};
	char s18[4] = { 'A', 'A', 'A', '\0'};
	n = 1;
	printf("memset(%s,'a',%d)\t\t\t",s13,n);
	printf("[%s]\t\t\t\t",(char *)memset(s13, 'a', n));
	printf("[%s]\n",(char *)ft_memset(s18, 'a', n));

	char s14[4] = { 'A', 'A', 'A', '\0'};
	char s19[4] = { 'A', 'A', 'A', '\0'};
	n = 0;
	printf("memset(%s,'a',%d)\t\t\t",s14,n);
	printf("[%s]\t\t\t\t",(char *)memset(s14, 'a', n));
	printf("[%s]\n",(char *)ft_memset(s19,'a', n));

	char *s21 = NULL;
	n = 3;
	printf("memset(NULL,'a',%d)\t\t\t",n);
	printf("segmentation fault\t\t");
	printf("%d\t\t\t// returns NULL\n",(int)ft_memset(s21,'a', n));
	printf("\n");

	char s2[4] = { 'A', 'A', 'A', '\0'};
	printf("bzero(%s)\t\t\t\t",s2);
	bzero(s2, 3);
	printf("[%s]\t\t\t\t",s2);
	char s3[4] = { 'A', 'A', 'A', '\0'};
	ft_bzero(s3, 3);
	printf("[%s]\n",s3);
	printf("\n");

	char s4[4] = { 'A', 'B', 'C', '\0'};
	char s5[4] = { 'D', 'E', 'F', '\0'};
	n = 4;
	printf("memcpy(%s,%s,%d)\t\t\t",s4,s5,n);
	printf("[%s]\t\t\t\t",(char *)memcpy(s4,s5,n));
	char s6[4] = { 'A', 'B', 'C', '\0'};
	char s7[4] = { 'D', 'E', 'F', '\0'};
	printf("[%s]\n",(char *)ft_memcpy(s6,s7,n));

	char s48[4] = {'A','B','C','\0'};
	char s49[4] = {'D','E','F','\0'};
	n = 2;
	printf("memcpy(%s,%s,%d)\t\t\t",s48,s49,n);
	printf("[%s]\t\t\t\t",(char *)memcpy(s48,s49,n));
	char s50[4] = {'A','B','C','\0'};
	char s51[4] = {'D','E','F','\0'};
	printf("[%s]\n",(char *)ft_memcpy(s50,s51,n));

	char s52[4] = {'A','B','C','\0'};
	char s53[4] = {'D','E','F','\0'};
	n = 1;
	printf("memcpy(%s,%s,%d)\t\t\t",s52,s53,n);
	printf("[%s]\t\t\t\t",(char *)memcpy(s52,s53,n));
	char s54[4] = {'A','B','C','\0'};
	char s55[4] = {'D','E','F','\0'};
	printf("[%s]\n",(char *)ft_memcpy(s54,s55,n));

	char s56[4] = {'A','B','C','\0'};
	char s57[4] = {'D','E','F','\0'};
	n = 0;
	printf("memcpy(%s,%s,%d)\t\t\t",s56,s57,n);
	printf("[%s]\t\t\t\t",(char *)memcpy(s56,s57,n));
	char s58[4] = {'A','B','C','\0'};
	char s59[4] = {'D','E','F','\0'};
	printf("[%s]\n",(char *)ft_memcpy(s58,s59,n));

	char s44[4] = { 'A', 'B', 'C', '\0'};
	char s45[4] = { 'D', 'E', '\0'};
	n = 4;
	printf("memcpy(%s,%s,%d)\t\t\t",s44,s45,n);
	printf("[%s]\t\t\t\t",(char *)memcpy(s44,s45,n));
	char s46[4] = { 'A', 'B', 'C', '\0'};
	char s47[4] = { 'D', 'E', '\0'};
	printf("[%s]\n",(char *)ft_memcpy(s46,s47,n));
	printf("\n");

	char s8[4] = { 'A', 'B', 'C', '\0'};
	char s9[4] = { 'D', 'E', 'F', '\0'};
	n = 4;
	printf("memmove(%s,%s,%d)\t\t\t",s8,s9,n);
	printf("[%s]\t\t\t\t",(char *)memmove(s8,s9,n));
	char s10[4] = { 'A', 'B', 'C', '\0'};
	char s11[4] = { 'D', 'E', 'F', '\0'};
	printf("[%s]\n",(char *)ft_memmove(s10,s11,n));

	char s68[4] = { 'A', 'B', 'C', '\0'};
	char s69[4] = { 'D', 'E', '\0'};
	n = 4;
	printf("memmove(%s,%s,%d)\t\t\t",s68,s69,n);
	printf("[%s]\t\t\t\t",(char *)memmove(s68,s69,n));
	char s70[4] = { 'A', 'B', 'C', '\0'};
	char s71[4] = { 'D', 'E', '\0'};
	printf("[%s]\n",(char *)ft_memmove(s70,s71,n));

	char s72[4] = { 'A', 'B', 'C', '\0'};
	char s73[4] = { 'D', 'E', '\0'};
	n = 2;
	printf("memmove(%s,%s,%d)\t\t\t",s72,s73,n);
	printf("[%s]\t\t\t\t",(char *)memmove(s72,s73,n));
	char s74[4] = { 'A', 'B', 'C', '\0'};
	char s75[4] = { 'D', 'E', '\0'};
	printf("[%s]\n",(char *)ft_memmove(s74,s75,n));

	char s76[4] = { 'A', 'B', 'C', '\0'};
	char s77[4] = { 'D', 'E', '\0'};
	n = 1;
	printf("memmove(%s,%s,%d)\t\t\t",s76,s77,n);
	printf("[%s]\t\t\t\t",(char *)memmove(s76,s77,n));
	char s78[4] = { 'A', 'B', 'C', '\0'};
	char s79[4] = { 'D', 'E', '\0'};
	printf("[%s]\n",(char *)ft_memmove(s78,s79,n));

	char s96[4] = { 'A', 'B', 'C', '\0'};
	n = 3;
	printf("memmove(%s,%s,%d)\t\t\t",s96,s96,n);
	printf("[%s]\t\t\t\t",(char *)memmove(s96,s96,n));
	char s97[4] = { 'A', 'B', 'C', '\0'};
	printf("[%s]\t\t// dest = src\n",(char *)ft_memmove(s97,s97,n));

	char dest1[5] = { 'A', 'B', 'C', 'D','\0'};
	n = 3;
	printf("memmove(%s,%s,%d)\t\t\t",dest1,&dest1[2],n);
	printf("[%s]\t\t\t\t",(char *)memmove(dest1,&dest1[2],n));
	char dest2[5] = { 'A', 'B', 'C', 'D','\0'};
	printf("[%s]\t\t// src0 inside dest, direct ordre\n",(char *)ft_memmove(dest2,&dest2[2],n));

	char src1[5] = { 'A', 'B', 'C', 'D','\0'};
	n = 3;
	printf("memmove(%s,%s,%d)\t\t\t",&src1[2],src1,n);
	printf("[%s]\t\t\t\t",(char *)memmove(&src1[2],src1,n));
	char src2[5] = { 'A', 'B', 'C', 'D','\0'};
	printf("[%s]\t\t// dest0 inside src, inverse ordre\n",(char *)ft_memmove(&src2[2],src2,n));
	printf("\n");

	printf("strlcpy copies up to n - 1 characters from the NUL-terminated src to dst\n");
	printf("strlcpy returns the total length of the string it tried to create = the length of src\n");
	// poprobovqt korotkie stroki
	char *src = "ABC";
	char dst01[1] = {'\0'};
	printf("strlcpy(\"%s\",\"%s\",%d)\t\t\t",dst01,src,0);
	size_t ret = strlcpy(dst01, src, 0);
	printf("dst=\"%s\"\t\tret=%ld\t\t",dst01,ret);
	char dst02[1] = {'\0'};
	ret = ft_strlcpy(dst02, src, 0);
	printf("dst=\"%s\"\t\tret=%ld\n",dst02,ret);

	char dst03[1] = {'\0'};
	printf("strlcpy(\"%s\",\"%s\",1)\t\t\t",dst03,src);
	ret = strlcpy(dst03, src, 1);
	printf("dst=\"%s\"\t\tret=%ld\t\t",dst03,ret);
	char dst04[1] = {'\0'};
	ret = ft_strlcpy(dst04, src, 1);
	printf("dst=\"%s\"\t\tret=%ld\n",dst04,ret);

	char dst05[2] = {'\0','\0'};
	char dst06[2] = {'\0','\0'};
	printf("strlcpy(\"%s\",\"%s\",2)\t\t\t",dst05,src);
	ret = strlcpy(dst05, src, 2);
	printf("dst=\"%s\"\t\tret=%ld\t\t",dst05,ret);
	ret = ft_strlcpy(dst06, src, 2);
	printf("dst=\"%s\"\t\tret=%ld\n",dst06,ret);

	char dst07[] = {'\0','\0','\0'};
	char dst08[] = {'\0','\0','\0'};
	printf("strlcpy(\"%s\",\"%s\",3)\t\t\t",dst07,src);
	ret = strlcpy(dst07, src, 3);
	printf("dst=\"%s\"\tret=%ld\t\t",dst07,ret);
	ret = ft_strlcpy(dst08, src, 3);
	printf("dst=\"%s\"\tret=%ld\n",dst08,ret);

	char dst09[] = {'\0','\0','\0','\0'};
	char dst10[] = {'\0','\0','\0','\0'};;
	printf("strlcpy(\"%s\",\"%s\",4)\t\t\t",dst09,src);
	ret = strlcpy(dst09, src, 4);
	printf("dst=\"%s\"\tret=%ld\t\t",dst09,ret);
	ret = ft_strlcpy(dst10, src, 4);
	printf("dst=\"%s\"\tret=%ld\n",dst10,ret);

	char dst11[] = {'\0','\0','\0','\0','\0'};
	char dst12[] = {'\0','\0','\0','\0','\0'};
	printf("strlcpy(\"%s\",\"%s\",5)\t\t\t",dst11,src);
	ret = strlcpy(dst11, src, 5);
	printf("dst=\"%s\"\tret=%ld\t\t",dst11,ret);
	ret = ft_strlcpy(dst12, src, 5);
	printf("dst=\"%s\"\tret=%ld\n",dst12,ret);

	char dst111[10] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char dst112[10] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char src100[] = "coucou";
	n = -1;
	printf("strlcpy(\"%s\",\"%s\",%d)\t\t\t",dst111,src100,n);
	ret = strlcpy(dst111, src100, n);
	printf("dst=\"%s\"\tret=%ld\t\t",dst111,ret);
	ret = ft_strlcpy(dst112, src100, n);
	printf("dst=\"%s\"\tret=%ld\n",dst112,ret);
	printf("\n");

	printf("strlcat concatenate dst + src, appends at most n-strlen(dst)-1 bytes\n");
	printf("returns the total length of the string they tried to create = the initial length of dst + the length of src\n");
	// char *src = "ABC";
	char dst13[9]; memset(dst13, 0, 9); dst13[0] = 'D'; dst13[1] = 'D';
	char dst14[9]; memset(dst14, 0, 9); dst14[0] = 'D'; dst14[1] = 'D';
	n = 0;
	printf("strlcat(%s,%s,%d)\t\t\t",dst13,src,n);
	ret = strlcat(dst13, src, n);
	printf("dst=\"%s\"\tret=%ld\t\t",dst13,ret);
	ret = ft_strlcat(dst14, src, n);
	printf("dst=\"%s\"\tret=%ld\n",dst14,ret);

	char dst15[9]; memset(dst15, 0, 9); dst15[0] = 'D'; dst15[1] = 'D';
	char dst16[9]; memset(dst16, 0, 9); dst16[0] = 'D'; dst16[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst15,src,1);
	ret = strlcat(dst15, src, 1);
	printf("dst=\"%s\"\tret=%ld\t\t",dst15,ret);
	ret = ft_strlcat(dst16, src, 1);
	printf("dst=\"%s\"\tret=%ld\n",dst16,ret);

	char dst17[9]; memset(dst17, 0, 9); dst17[0] = 'D'; dst17[1] = 'D';
	char dst18[9]; memset(dst18, 0, 9); dst18[0] = 'D'; dst18[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst17,src,2);
	ret = strlcat(dst17, src, 2);
	printf("dst=\"%s\"\tret=%ld\t\t",dst17,ret);
	ret = ft_strlcat(dst18, src, 2);
	printf("dst=\"%s\"\tret=%ld\n",dst18,ret);

	char dst19[9]; memset(dst19, 0, 9); dst19[0] = 'D'; dst19[1] = 'D';
	char dst20[9]; memset(dst20, 0, 9); dst20[0] = 'D'; dst20[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst19,src,3);
	ret = strlcat(dst19, src, 3);
	printf("dst=\"%s\"\tret=%ld\t\t",dst19,ret);
	ret = ft_strlcat(dst20, src, 3);
	printf("dst=\"%s\"\tret=%ld\n",dst20,ret);

	char dst21[9]; memset(dst21, 0, 9); dst21[0] = 'D'; dst21[1] = 'D';
	char dst22[9]; memset(dst22, 0, 9); dst22[0] = 'D'; dst22[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst21,src,4);
	ret = strlcat(dst21, src, 4);
	printf("dst=\"%s\"\tret=%ld\t\t",dst21,ret);
	ret = ft_strlcat(dst22, src, 4);
	printf("dst=\"%s\"\tret=%ld\n",dst22,ret);

	char dst23[9]; memset(dst23, 0, 9); dst23[0] = 'D'; dst23[1] = 'D';
	char dst24[9]; memset(dst24, 0, 9); dst24[0] = 'D'; dst24[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst23,src,5);
	ret = strlcat(dst23, src, 5);
	printf("dst=\"%s\"\tret=%ld\t\t",dst23,ret);
	ret = ft_strlcat(dst24, src, 5);
	printf("dst=\"%s\"\tret=%ld\n",dst24,ret);

	char dst25[9]; memset(dst25, 0, 9); dst25[0] = 'D'; dst25[1] = 'D';
	char dst26[9]; memset(dst26, 0, 9); dst26[0] = 'D'; dst26[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst25,src,6);
	ret = strlcat(dst25, src, 6);
	printf("dst=\"%s\"\tret=%ld\t\t",dst25,ret);
	ret = ft_strlcat(dst26, src, 6);
	printf("dst=\"%s\"\tret=%ld\n",dst26,ret);

	char dst27[9]; memset(dst27, 0, 9); dst27[0] = 'D'; dst27[1] = 'D';
	char dst28[9]; memset(dst28, 0, 9); dst28[0] = 'D'; dst28[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst27,src,7);
	ret = strlcat(dst27, src, 7);
	printf("dst=\"%s\"\tret=%ld\t\t",dst27,ret);
	ret = ft_strlcat(dst28, src, 7);
	printf("dst=\"%s\"\tret=%ld\n",dst28,ret);

	char dst29[9]; memset(dst29, 0, 9); dst29[0] = 'D'; dst29[1] = 'D';
	char dst30[9]; memset(dst30, 0, 9); dst30[0] = 'D'; dst30[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst29,src,8);
	ret = strlcat(dst29, src, 8);
	printf("dst=\"%s\"\tret=%ld\t\t",dst29,ret);
	ret = ft_strlcat(dst30, src, 8);
	printf("dst=\"%s\"\tret=%ld\n",dst30,ret);

	char dst31[9]; memset(dst31, 0, 9); dst31[0] = 'D'; dst31[1] = 'D';
	char dst32[9]; memset(dst32, 0, 9); dst32[0] = 'D'; dst32[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst31,src,9);
	ret = strlcat(dst31, src, 9);
	printf("dst=\"%s\"\tret=%ld\t\t",dst31,ret);
	ret = ft_strlcat(dst32, src, 9);
	printf("dst=\"%s\"\tret=%ld\n",dst32,ret);

	char dst33[9]; memset(dst33, 0, 9); dst33[0] = 'D'; dst33[1] = 'D';
	char dst34[9]; memset(dst34, 0, 9); dst34[0] = 'D'; dst34[1] = 'D';
	printf("strlcat(%s,%s,%d)\t\t\t",dst33,src,10);
	ret = strlcat(dst33, src, 10);
	printf("dst=\"%s\"\tret=%ld\t\t",dst33,ret);
	ret = ft_strlcat(dst34, src, 10);
	printf("dst=\"%s\"\tret=%ld\n",dst34,ret);
	printf("\n");

	printf("toupper('a')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'a'),ft_toupper((unsigned char)'a'));
	printf("toupper('A')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'A'),ft_toupper((unsigned char)'A'));
	printf("toupper('*')\t\t\t\t%c\t\t\t\t%c\n",toupper((unsigned char)'*'),ft_toupper((unsigned char)'*'));
	printf("tolower('A')\t\t\t\t%c\t\t\t\t%c\n",tolower((unsigned char)'A'),ft_tolower((unsigned char)'A'));
	printf("\n");

	printf("\n");
	printf("strchr(ABC,'A')\t\t\t\t%s\t\t\t\t%s\n",       strchr("ABC",'A'),     ft_strchr("ABC",'A'));
	printf("strchr(ABC,'A'+256)\t\t\t%s\t\t\t\t%s\n",     strchr("ABC",'A'+256), ft_strchr("ABC",'A'+256));
	printf("strchr(ABC,'A'+128)\t\t\t%s\t\t\t\t%s\n",     strchr("ABC",'A'+128), ft_strchr("ABC",'A'+128));
	printf("strchr(ABC,'B')\t\t\t\t%s\t\t\t\t%s\n",       strchr("ABC",'B'),     ft_strchr("ABC",'B'));
	printf("strchr(ABC,'B'+256)\t\t\t%s\t\t\t\t%s\n",     strchr("ABC",'B'+256), ft_strchr("ABC",'B'+256));
	printf("strchr(ABC,'C')\t\t\t\t%s\t\t\t\t%s\n",       strchr("ABC",'C'),     ft_strchr("ABC",'C'));
	printf("strchr(ABC,'D')\t\t\t\t%s\t\t\t\t%s\n",       strchr("ABC",'D'),     ft_strchr("ABC",'D'));
	printf("strchr(ABC,'\\0')\t\t\t[%s]\t\t\t\t[%s]\n",   strchr("ABC",'\0'),    ft_strchr("ABC",'\0'));

	printf("\n");
	printf("strrchr(ABC,'A')\t\t\t%s\t\t\t\t%s\n",        strrchr("ABC",'A'),    ft_strrchr("ABC",'A'));
	printf("strrchr(ABC,'A'+256)\t\t\t%s\t\t\t\t%s\n",    strrchr("ABC",'A'+256),ft_strrchr("ABC",'A'+256));
	printf("strrchr(ABC,'B')\t\t\t%s\t\t\t\t%s\n",        strrchr("ABC",'B'),    ft_strrchr("ABC",'B'));
	printf("strrchr(ABC,'B'+256)\t\t\t%s\t\t\t\t%s\n",    strrchr("ABC",'B'+256),ft_strrchr("ABC",'B'+256));
	printf("strrchr(ABC,'C')\t\t\t%s\t\t\t\t%s\n",        strrchr("ABC",'C'),    ft_strrchr("ABC",'C'));
	printf("strrchr(ABC,'D')\t\t\t%s\t\t\t\t%s\n",        strrchr("ABC",'D'),    ft_strrchr("ABC",'D'));
	printf("strrchr(ABC,'\\0')\t\t\t[%s]\t\t\t\t[%s]\n",  strrchr("ABC",'\0'),   ft_strrchr("ABC",'\0'));
	printf("strrchr(AAA,'A')\t\t\t%s\t\t\t\t%s\n",        strrchr("AAA",'A'),    ft_strrchr("AAA",'A'));
	printf("strrchr(AAC,'A')\t\t\t%s\t\t\t\t%s\n",        strrchr("AAC",'A'+256),ft_strrchr("AAC",'A'+256));

	printf("\n");
	printf("strncmp(ABE,ABC,3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABE","ABC",3),ft_strncmp("ABE","ABC",3));
	printf("strncmp(ABD,ABC,3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABD","ABC",3),ft_strncmp("ABD","ABC",3));
	printf("strncmp(ABC,ABC,3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABC",3),ft_strncmp("ABC","ABC",3));
	printf("strncmp(ABC,ABD,3)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABD",3),ft_strncmp("ABC","ABD",3));
	printf("strncmp(ABE,ABC,2)\t\t\t%d\t\t\t\t%d\n",strncmp("ABE","ABC",2),ft_strncmp("ABE","ABC",2));
	printf("strncmp(ABC,BCD,0)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","BCD",0),ft_strncmp("ABC","BCD",0));
	printf("strncmp(\"\\0\",\"\\0\",1)\t\t\t%d\t\t\t\t%d\n",strncmp("\0","\0",1),ft_strncmp("\0","\0",1));
	printf("strncmp(\"A\",ABD,1)\t\t\t%d\t\t\t\t%d\n",strncmp("A","ABD",1),ft_strncmp("A","ABD",1));
	printf("strncmp(\"A\",ABD,2)\t\t\t%d\t\t\t\t%d\n",strncmp("A","ABD",2),ft_strncmp("A","ABD",2));
	printf("strncmp(ABC,ABC,10)\t\t\t%d\t\t\t\t%d\n",strncmp("ABC","ABC",10),ft_strncmp("ABC","ABC",10));
	printf("\n");

	char* mem = "ABC";
	printf("memchr(ABC,'B',0)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',0),(char*)ft_memchr(mem,'B',0));
	printf("memchr(ABC,'B',1)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',1),(char*)ft_memchr(mem,'B',1));
	printf("memchr(ABC,'B',2)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',2),(char*)ft_memchr(mem,'B',2));
	printf("memchr(ABC,'B',5)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'B',5),(char*)ft_memchr(mem,'B',5));
	printf("memchr(ABC,'D',5)\t\t\t%s\t\t\t\t%s\n",(char*)memchr(mem,'D',5),(char*)ft_memchr(mem,'D',5));
	printf("\n");

	printf("memcmp(ABC,ABC,3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","ABC",3),ft_memcmp("ABC","ABC",3));
	printf("memcmp(ABC,ABD,3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","ABD",3),ft_memcmp("ABC","ABD",3));
	printf("memcmp(ABD,ABC,3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",3),ft_memcmp("ABD","ABC",3));
	printf("memcmp(ABE,ABC,3)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",3),ft_memcmp("ABE","ABC",3));
	printf("memcmp(ABE,ABC,4)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",4),ft_memcmp("ABE","ABC",4));
	printf("memcmp(ABE,ABC,5)\t\t\t%d\t\t\t\t%d\n",memcmp("ABE","ABC",5),ft_memcmp("ABE","ABC",5));
	printf("memcmp(ABD,ABC,2)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",2),ft_memcmp("ABD","ABC",2));
	printf("memcmp(ABD,ABC,1)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",1),ft_memcmp("ABD","ABC",1));
	printf("memcmp(ABD,ABC,0)\t\t\t%d\t\t\t\t%d\n",memcmp("ABD","ABC",0),ft_memcmp("ABD","ABC",0));
	printf("memcmp(\"\\0\",\"\\0\",2)\t\t\t%d\t\t\t\t%d\n",memcmp("\\0","\\0",2),ft_memcmp("\\0","\\0",2));
	printf("memcmp(ABC,\"\\0\",1)\t\t\t%d\t\t\t\t%d\n",memcmp("ABC","\\0",1),ft_memcmp("ABC","\\0",1));
	printf("\n");

	char*	big = "ABCDE";
	char*	little = "CD";
	n = 5;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	big = "";
	little = "CD";
	n = 5;
	printf("strnstr(%s,%s,%d)\t\t\t\t%p\t\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	big = "";
	little = "CD";
	n = -1;
	printf("strnstr(%s,%s,%d)\t\t\t\t%p\t\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	big = "ABCDE";
	little = "DE";
	n = 5;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	little = "";
	n = 5;
	printf("strnstr(%s,\"%s\",%d)\t\t\t%p\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	little = "AB";
	n = 5;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	little = "BC";
	n = 3;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	little = "BC";
	n = 2;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));

	little = "ZW";
	n = 5;
	printf("strnstr(%s,%s,%d)\t\t\t%p\t\t\t\t%p\n",big,little,n,strnstr(big,little,n),ft_strnstr(big,little,n));
	printf("\n");

	char* str32 = "0";
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t\t%d\n",str32,atoi(str32),ft_atoi(str32));
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
	str11 = "-+42";
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t%d\n",str11,atoi(str11),ft_atoi(str11));
	str11 = "-++42";
	printf("atoi(\"%s\")\t\t\t\t%d\t\t\t%d\n",str11,atoi(str11),ft_atoi(str11));
	printf("\n");

	// ft_calloc попробовать огромные оба параметра
	void* mem01, *mem02;
	size_t nmemb = 2;
	size_t size = 2; // 2 byte
	char res_str[100]; // 100 !
	printf("calloc(%ld,%ld)\t\t\t\t",nmemb,size);
	mem01 = calloc(nmemb,size);
	mem_to_str(mem01,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem02 = ft_calloc(nmemb,size);
	mem_to_str(mem02,nmemb,res_str);
	printf("[%s]\n",res_str);
	free (mem01);
	printf("mem01 free\n");
	free (mem02);
	printf("mem02 free\n");
	char* mem100 = (char*)malloc(0);
	printf("\nsizeof = %zu\n",sizeof(mem100)/sizeof(mem100[0]));
	mem100 = (char*)malloc(2);
	printf("\nsizeof = %zu\n",sizeof(mem100)/sizeof(mem100[0]));
	mem100 = (char*)malloc(50);
	printf("sizeof = %zu\n",sizeof(mem100)/sizeof(mem100[0]));
	char mem101[50];
	printf("sizeof = %zu\n",sizeof(mem101)/sizeof(mem101[0]));

	void* mem03, *mem04;
	nmemb = 5;
	size = 2;
	printf("calloc(%ld,%ld)\t\t\t\t",nmemb,size);
	mem03 = calloc(nmemb,size);
	mem_to_str(mem03,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem04 = ft_calloc(nmemb,size);
	mem_to_str(mem04,nmemb,res_str);
	printf("[%s]\t\t\t// wait .....\n",res_str);
	free (mem03);
	printf("mem03 free\n");
	free (mem04);
	printf("mem04 free\n");

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
	free (mem05);
	printf("mem05 free\n");
	free (mem06);
	printf("mem06 free\n");

	void* mem07, *mem08;
	nmemb = 2;
	size = INT_MAX;
	printf("calloc(%ld,%ld)\t\t\t",nmemb,size);
	mem07 = calloc(nmemb,size);
	mem_to_str(mem07,nmemb,res_str);
	printf("[%s]\t\t\t\t",res_str);
  mem08 = ft_calloc(nmemb,size);
	mem_to_str(mem08,nmemb,res_str);
	printf("[%s]\t\t\t// calloc returns NULL\n",res_str);
	free (mem07);
	printf("mem07 free\n");
	free (mem08);
	printf("mem08 free\n");
	printf("\n");

	char *str12 = "coucou";
	printf("strdup(%s)\t\t\t\t%s\t\t\t\t%s\t\t\terrno = %s\n",str12,strdup(str12),ft_strdup(str12),errno);
	char *str13 = "";
	printf("strdup(%s)\t\t\t\t[%s]\t\t\t\t[%s]\t\t\terrno = %s\n",str13,strdup(str13),ft_strdup(str13),errno);
	printf("\n");

	printf("strjoin(ABC,DE)\t\t\t\t%s\n",ft_strjoin("ABC", "DE"));
	printf("strjoin(\"\",DE)\t\t\t\t%s\n",ft_strjoin("", "DE"));
	printf("strjoin(ABC,\"\")\t\t\t\t%s\n",ft_strjoin("ABC", ""));
	printf("strjoin(\"\",\"\")\t\t\t\t[%s]\n",ft_strjoin("", ""));
	printf("\n");

	char *ss1 = ft_substr("ABCDE",0,2);
	printf("substr(ABCDE,0,2)\t\t\t%s\n",ss1);
	free (ss1);
	char *ss2 = ft_substr("ABCDE",10,1);
	printf("substr(ABCDE,0,2)\t\t\t%s\n",ss2);
	free (ss2);
	printf("substr(ABCDE,1,3)\t\t\t%s\n",ft_substr("ABCDE",1,3));
	printf("substr(ABCDE,2,3)\t\t\t%s\n",ft_substr("ABCDE",2,3));
	printf("substr(ABCDE,3,3)\t\t\t%s\n",ft_substr("ABCDE",3,3));
	printf("substr(ABCDE,4,3)\t\t\t%s\n",ft_substr("ABCDE",4,3));
	printf("substr(ABCDE,5,3)\t\t\t%s\n",ft_substr("ABCDE",5,3));
	printf("substr(ABCDE,0,5)\t\t\t%s\n",ft_substr("ABCDE",0,5));
	printf("substr(ABCDE,0,10)\t\t\t%s\n",ft_substr("ABCDE",0,10));
	printf("substr(\"\",0,10)\t\t\t\t%s\n",ft_substr("",0,10));
	printf("substr(ABCDE,1,1)\t\t\t[%s]\n",ft_substr("ABCDE",1,1));
	printf("substr(ABCDE,0,0)\t\t\t[%s]\n",ft_substr("ABCDE",0,0));
	printf("\n");

	printf("strtrim({(ABCDE)},\"_(){}\")\t\t%s\n",ft_strtrim("{(ABCDE)}","_(){}"));
	printf("strtrim({(___)},\"_(){}\")\t\t[%s]\n",ft_strtrim("{(___)}","_(){}"));
	printf("strtrim(A{(___)},\"_(){}\")\t\t%s\n",ft_strtrim("A{(___)}","_(){}"));
	printf("strtrim({(___)}A,\"_(){}\")\t\t%s\n",ft_strtrim("{(___)}A","_(){}"));
	printf("strtrim({(___)}A_,\"_(){}\")\t\t%s\n",ft_strtrim("{(___)}A_","_(){}"));
	printf("strtrim({(ABCDE)},\"\")\t\t\t%s\n",ft_strtrim("{(ABCDE)}",""));
	printf("strtrim(\"\",\"_()}\")\t\t\t[%s]\n",ft_strtrim("","_()}"));
	printf("strtrim(\"\",\"\")\t\t\t\t[%s]\n",ft_strtrim("",""));
	printf("strtrim(\"   xxx   xxx\",\" x\")\t\t[%s]\n",ft_strtrim("   xxx   xxx"," x"));
	printf("\n");
*/
	char *str;
	char	separator;
	char	**tab;
	int i;
/*
	str = "_A__B__CD";
	separator = '_';
	tab = ft_split(str, separator);
	printf("split(%s,'%c')\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "A__B__C";
	separator = '_';
	tab = ft_split(str, separator);
	printf("slit(%s,'%c')\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "ABC";
	separator = '_';
	tab = ft_split(str, separator);
	printf("split(%s,'%c')\t\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "";
	separator = '_';
	tab = ft_split(str, separator);
	printf("split(\"%s\",'%c')\t\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "  ";
	separator = ' ';
	tab = ft_split(str, separator);
	printf("split(\"[%s]\",'%c')\t\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "  tripouille  42  ";
	separator = ' ';
	tab = ft_split(str, separator);
	printf("split(\"%s\",'%c')\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");

	str = "A";
	separator = ' ';
	tab = ft_split(str, separator);
	printf("split(\"%s\",'%c')\t\t\t\t",str,separator);
	for (i = 0; tab[i] != NULL; i++)
		printf("[%s] ", tab[i]);
	if (tab[i] == NULL)
		printf("NULL\n");
	printf("\n");

	int n = 10;
	printf("itoa(%d)\t\t\t\t%s\n",n,ft_itoa(n));
	n = -10;
	printf("itoa(%d)\t\t\t\t%s\n",n,ft_itoa(n));
	n = 1000;
	printf("itoa(%d)\t\t\t\t%s\n",n,ft_itoa(n));
	n = INT_MAX;
	printf("itoa(%d)\t\t\t%s\n",n,ft_itoa(n));
	n = INT_MIN;
	printf("itoa(%d)\t\t\t%s\n",n,ft_itoa(n));
	n = 0;
	printf("itoa(%d)\t\t\t\t\t%s\n",n,ft_itoa(n));
	n = 1;
	printf("itoa(%d)\t\t\t\t\t%s\n",n,ft_itoa(n));
	n = -1;
	printf("itoa(%d)\t\t\t\t%s\n",n,ft_itoa(n));
	printf("\n");

	char *func(unsigned int n, char c)
	{
		return (c+n);
	}
	char *s = "ABC";
	printf("strmapi(%s,c->c+2)\t\t\t%s\n",s,ft_strmapi(s,func));

	s = "";
	printf("strmapi(\"\",c->c+2)\t\t\t[%s]\n",ft_strmapi(s,func));
	printf("\n");

	char *func2(unsigned int n, char *c)
	{
		*c += n;
	}
	char s42[4] = {'A','B','C','\0'};
	printf("striteri(%s,c->c+index)\t\t",s42);
	ft_striteri(s42,func2);
	printf("%s\n",s42);

	char s43[4] = {'\0'};
	printf("striteri(\"%s\",c->c+index)\t\t\t",s43);
	ft_striteri(s43,func2);
	printf("[%s]\n",s43);

	printf("\n putchar_fd(A,1)\t\t\t\t\t\t\t\t// stdout 1\t\t\t\t");
	ft_putchar_fd('A',1);
	printf("\n putchar_fd(B,2)\t\t\t\t\t\t\t\t// stderr 2\t\t\t\t");
	ft_putchar_fd('B',2);
	printf("\n putchar_fd(C,0)\t\t\t\t\t\t\t\t// stdin 0\t\t\t\t");
	ft_putchar_fd('C',0);
	printf("\n  putchar_fd(D,3)");
	ft_putchar_fd('D',3);
	printf("\n\n");

	printf("\n putstr_fd(ABC,1)");
	ft_putstr_fd("ABC",1);
	printf("\n\n");

	printf("\nputendl_fd(ABC,1)");
	ft_putendl_fd("ABC",1);
	printf("\n\n");

	printf("\n putnbr_fd(0,1)");
	ft_putnbr_fd(0,1);
	printf("\n");
	printf("\n putnbr_fd(1234,1)");
	ft_putnbr_fd(1234,1);
	printf("\n");
	printf("\n putnbr_fd(-1234,1)");
	ft_putnbr_fd(-1234,1);
	printf("\n");
	printf("\n putnbr_fd(INT_MAX,1)");
	ft_putnbr_fd(INT_MAX,1);
	printf("\n");
	printf("\n putnbr_fd(INT_MIN,1)");
	ft_putnbr_fd(INT_MIN,1);
	printf("\n");
}
