// s1: La chaîne de caractères à trimmer.
// set: Le set de référence de caractères à trimmer.
// Retourns La chaîne de caractères trimmée, NULL si l’allocation échoue
// fonc. authorisées : malloc
// Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de caractères

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int  is_char_to_trim(char c, char const *set)
{
  size_t  i;

  if (c == '\0')
    return (1);
  i = 0;
  while (set[i] != '\0')
  {
    if (c == set[i])
      return (1);
    i++;
  }
  return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
  size_t  i;
  char    *new_string;
  size_t  new_string_start;
  size_t  new_string_end;

  new_string_start = 0;
  while (is_char_to_trim(s1[new_string_start], set) == 1 && s1[new_string_start] != '\0')
    new_string_start++;
  new_string_end = 0;
  while (s1[new_string_end] != '\0')
    new_string_end++;
  while (is_char_to_trim(s1[new_string_end], set) == 1 && new_string_end > 0)
    new_string_end--;
  if (new_string_start > new_string_end)
    return ("");
  new_string = (char *)malloc(new_string_end - new_string_start + 2);
  if (new_string == NULL)
    return (NULL);  
  i = 0;
  while (i < new_string_end - new_string_start + 1)
  {
    new_string[i] = s1[new_string_start + i];
    i++;
  }
  new_string[i] = '\0';    
  return (new_string);
}