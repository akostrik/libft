#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("           \tlibc\tmy_func");
	char c = 'a';
	printf("isalpha(%c)\t%d  \t%d",c,isalpha(c),ft_isalpha(c));
}