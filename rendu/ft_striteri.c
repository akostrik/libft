// s: La chaîne de caractères sur laquelle itérer
// f: La fonction à appliquer à chaque caractère
// Aucune fonctions externe
// Applique f à chaque caractère de s et en passant son index comme premier argument
// Chaque caractère est transmis par adresse à ’f’ afin d’être modifié si nécessaire

#include <stddef.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
  size_t  i;

  i = 0;
  while (s[i] != '\0')
  {
    f((unsigned int)i,s + i);
    i++;
  }
}