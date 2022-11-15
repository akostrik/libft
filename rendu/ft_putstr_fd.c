// s: La chaîne de caractères à écrire.
// fd: Le descripteur de fichier sur lequel écrire.
// fonctions autorisées : write
// Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.

#include <stdio.h>
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd,s,i);
}