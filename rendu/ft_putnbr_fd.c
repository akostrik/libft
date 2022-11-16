// n: L’entier à écrire.
// fd: Le descripteur de fichier sur lequel écrire
// fonctions autoirisées : write
// Écrit l’entier ’n’ sur le descripteur de fichier donné

#include <stdio.h>
#include <unistd.h>

static void	ft_put_positiv_nbr_fd(int n, int fd)
{
	char c;

	if (n == 0)
		return ;
	ft_put_positiv_nbr_fd(n/10, fd);
	c = n - (n / 10) * 10 + '0';
	write(fd,&c,1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0) 
	{
		write(fd,"0",1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd,"-2147483648",11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd,"-",1);
	}
	ft_put_positiv_nbr_fd(n, fd);
}