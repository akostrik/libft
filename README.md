# libft
A project of 42 School, Solo, about 70 hours

How to run:
1) install bsd library
2) make 

if you do not have bsd library:
1) comment in main.c strlcpy, strlcat and strnstr and the line #include <bsd/string.h>
2) make

---------------------------------------------------
Tester: https://github.com/Tripouille/libftTester :

ft_memset	: 1.OK 2.OK 

ft_bzero	: 1.OK 2.OK 3.OK 

ft_memcpy	: 1.OK 2.OK 3.OK 

ft_memmove	: 1.OK 2.OK 3.OK 4.OK 

ft_memchr	: 1.OK 2.OK 3.OK 4.OK 5.OK 

ft_memcmp	: 1.OK 2.OK 3.OK 4.OK 5.OK 

ft_strlen	: 1.OK 2.OK 

ft_isalpha	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 

ft_isdigit	: 1.OK 2.OK 3.OK 4.OK 

ft_isalnum	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 

ft_isascii	: 1.OK 2.OK 3.OK 4.OK 

ft_isprint	: 1.OK 2.OK 3.OK 4.OK 

ft_toupper	: 1.OK 2.OK 3.OK 4.OK 

ft_tolower	: 1.OK 2.OK 3.OK 4.OK 

ft_strchr	: 1.OK 2.OK 3.OK 4.OK 5.OK 

ft_strrchr	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 

ft_strncmp	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 

ft_strlcpy	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 

ft_strlcat	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 

ft_strnstr	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 

ft_atoi		: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 

ft_calloc	: 1.OK 2.MOK 3.OK 

ft_strdup	: 1.OK 2.MOK 3.OK 4.MOK 

ft_substr	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 13.OK 14.MOK 15.OK 16.MOK 

ft_strjoin	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 

ft_strtrim	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 13.OK 14.MOK 15.OK 16.MOK 

ft_split	: 1.MOK 2.OK 3.MOK 4.OK 5.MOK 6.OK 7.OK 8.OK 9.OK 10.OK 11.MOK 12.OK 13.OK 14.MOK 15.OK 16.MOK 17.OK 18.OK 19.MOK 20.OK 21.OK 22.MOK 23.OK 
24.OK 25.MOK 26.OK 27.MOK 28.OK 29.MOK 30.OK 31.MOK 32.OK 33.MOK 34.OK 35.MOK 36.OK 37.MOK 38.OK 39.MOK 40.OK 41.MOK 42.OK 

ft_itoa		: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 

ft_strmapi	: 1.OK 2.MOK 3.OK 4.MOK 

ft_putchar_fd	: 1.OK 

ft_putstr_fd	: 1.OK 

ft_putendl_fd	: 1.OK 

ft_putnbr_fd	: 1.OK 2.OK 3.OK 4.OK 5.OK 

ft_striteri	: 1.OK 2.OK 3.OK 

-----------------------
Tester https://github.com/0x050f/libft-war-machine

FUNCTION              NORME          COMPIL.     FORBIDDEN FUNC.  TESTS               RESULT

ft_memset             ok             success     clean            ✓✓✓✓                OK

ft_bzero              ok             success     clean            ✓✓                  OK

ft_calloc             ok             success     clean            ✓                   OK

ft_memcpy             ok             success     clean            ✓✓✓                 OK

ft_memmove            ok             success     clean            ✓✓✓✓✓               OK

ft_memchr             ok             success     clean            ✓✓✓✓✓✓              OK

ft_memcmp             ok             success     clean            ✓✓✓✓✓✓✓✓✓           OK

ft_strlen             ok             success     clean            ✓✓✓✓✓✓              OK

ft_strdup             ok             success     clean           ✓                    OK

ft_strlcat            ok             success     clean            ✓✓✓✓✓✓✗✓✓           KO

ft_strlcpy            ok             success     clean            ✓✓✓✓✓               OK

ft_strchr             ok             success     clean            ✓✓✓✓✓✓              OK

ft_strrchr            ok             success     clean            ✓✓✓✓✓✓✓✓            OK

ft_strnstr            ok             success     clean            ✓✓✓✓✓✓✓✓✓✓          OK

ft_strncmp            ok             success     clean            ✓✓✓✓✓✓✓✓✓✓✓         OK

ft_atoi               ok             success     clean            ✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓ OK

ft_isalpha            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_isdigit            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_isalnum            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_isascii            ok             success     clean            ✓✓✓✓✓✓✓✓            OK

ft_isprint            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_toupper            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_tolower            ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_strmapi            ok             success     clean            ✓                   OK

ft_substr             ok             success     clean            ✓✓✓✓✓               OK

ft_strjoin            ok             success     clean            ✓✓✓✓                OK

ft_strtrim            ok             success     clean            ✓✓✓✓✓               OK

ft_split              ok             success     clean            ✓✓✓✓✓✓              OK

ft_itoa               ok             success     clean            ✓✓✓✓✓✓✓✓✓✓          OK

ft_striteri           ok             success     clean            ✓                   OK

ft_putchar_fd         ok             success     clean            ✓✓✓✓✓✓✓             OK

ft_putstr_fd          ok             success     clean            ✓✓✓✓                OK

ft_putendl_fd         ok             success     clean            ✓✓✓✓                OK

ft_putnbr_fd          ok             success     clean            ✓✓✓✓✓✓✓✓✓           OK

-------------------------------
Tester https://github.com/alelievr/libft-unit-test

ft_memset:     [OK] [OK] [OK] [NO CRASH] [OK] [OK] [OK] 

[no crash]: your memset does not segfault when null parameter is sent !

ft_bzero:      [OK] [OK] [OK] [OK] 

ft_memcpy:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] 

[crash]: your memcpy does not behave well with NULL as both params with size

ft_memmove:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] [OK] 

[crash]: your memmove does not well with NULL as both parameters and size

ft_memchr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_memcmp:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_strlen:     [OK] [OK] [OK] [OK] [NO CRASH] [OK] [OK] [OK] [OK] 

[no crash]: your strlen does not segv when null is sended

ft_isalpha:    [OK] 

ft_isdigit:    [OK] 

ft_isalnum:    [OK] 

ft_isascii:    [OK] 

ft_isprint:    [OK] 

ft_toupper:    [OK] 

ft_tolower:    [OK] 

ft_strchr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] 

[no crash]: your strchr does not segfault with NULL parameter

ft_strrchr:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] 

[no crash]: your strrchr does not segfault when a null parameter is sent

ft_strncmp:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_strlcpy:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_strlcat:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] [CRASH] 

[no crash]: your strlcat does not segfault when null parameter is sent

[crash]: your strlcat crush when null parameter is sent with a size of 0

ft_strnstr:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] [OK] 

[no crash]: your strnstr does not segfault when null parameter is sent

ft_atoi:       [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_calloc:     [OK] [OK] [OK] [OK] [OK] 

ft_strdup:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_substr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [🛡 ] [OK] 

ft_strjoin:    [OK] [OK] [OK] [OK] [OK] [🛡 ] 

ft_strtrim:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [💥 ] 

ft_split:      [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [💥 ] 

ft_itoa:       [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

ft_strmapi:    [OK] [OK] [OK] [OK] [OK] [💥 ] 

ft_putchar_fd: [OK] [OK] 

ft_putstr_fd:  [OK] [OK] [💥 ] 

ft_putendl_fd: [OK] [OK] [💥 ] 

ft_putnbr_fd:  [OK] [OK] [OK] [OK] [OK] 

You can choose to protect your function or not to,
a color code will tell you if your function is protected/not BUT stay coherent !
[🛡 ] --> protected
[💥 ] --> not protected

-------------------------------------------
Moulinette

test_ft_isalnum: OK

test_ft_isalpha: OK

test_ft_isascii: OK

test_ft_isdigit: OK

test_ft_isprint: OK

test_ft_atoi: OK

test_ft_bzero: OK

test_ft_calloc: OK

test_ft_itoa: OK

test_ft_memchr: O

test_ft_memcmp: OK

test_ft_memcpy: OK

test_ft_memmove: OK

test_ft_memset: OK

test_ft_putchar_fd: OK

test_ft_putendl_fd: OK

test_ft_putnbr_fd: OK

test_ft_putstr_fd: OK

test_ft_split: OK

test_ft_strchr: OK

test_ft_strdup: OK

test_ft_strjoin: OK

test_ft_strlcat: OK

test_ft_strlcpy: OK

test_ft_strlen: OK

test_ft_strmapi: OK

test_ft_striteri: OK

test_ft_strncmp: OK

test_ft_strnstr: OK

test_ft_strrchr: OK

test_ft_strtrim: OK

test_ft_substr: OK

test_ft_tolower: OK

test_ft_toupper: OK

bonus: KO (Does not compile)
