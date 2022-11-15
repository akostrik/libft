
// c: Le caractère à écrire
// fd: Le descripteur de fichier sur lequel écrire
// fonctions autorisées : write
// Écrit le caractère ’c’ sur le descripteur de fichier donné

#include <stdio.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
  write(fd,&c,1);  
}
