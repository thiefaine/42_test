#define TEST_ft_strrev
#define TEST_ft_islower
#define TEST_ft_isupper
#define PART1
#define PART2
#define BONUS
#include <testframework.h>
#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>

#ifdef PART1

#define	TEST_ft_memset
#define	TEST_ft_bzero
#define	TEST_ft_memcpy
#define	TEST_ft_memccpy
#define	TEST_ft_memmove
#define	TEST_ft_memchr
#define	TEST_ft_memcmp
#define	TEST_ft_strlen
#define	TEST_ft_strdup
#define	TEST_ft_strcpy
#define	TEST_ft_strncpy
#define	TEST_ft_strcat
#define	TEST_ft_strncat
#define	TEST_ft_strlcat
#define	TEST_ft_strchr
#define	TEST_ft_strrchr
#define	TEST_ft_strstr
#define	TEST_ft_strnstr
#define	TEST_ft_strcmp
#define	TEST_ft_strncmp
#define	TEST_ft_atoi
#define	TEST_ft_isalpha
#define	TEST_ft_isdigit
#define	TEST_ft_isalnum
#define	TEST_ft_isascii
#define	TEST_ft_isprint
#define	TEST_ft_toupper
#define	TEST_ft_tolower

#endif

#ifdef PART2

void	it_test(char *c)
{
	*c = *c + 1;
}

void	iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

char	map_test(char c)
{
	return (c + 1);
}

char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

#define TEST_ft_memalloc
#define TEST_ft_memdel
#define TEST_ft_strnew
#define TEST_ft_strdel
#define TEST_ft_strclr
#define TEST_ft_striter
#define TEST_ft_striteri
#define TEST_ft_strmap
#define TEST_ft_strmapi
#define TEST_ft_strequ
#define TEST_ft_strnequ
#define TEST_ft_strsub
#define TEST_ft_strjoin
#define TEST_ft_strtrim
#define TEST_ft_strsplit
#define TEST_ft_itoa
#define TEST_ft_putchar
#define TEST_ft_putstr
#define TEST_ft_putendl
#define TEST_ft_putnbr
#define TEST_ft_putchar_fd
#define TEST_ft_putstr_fd
#define TEST_ft_putendl_fd
#define TEST_ft_putnbr_fd

#endif

#ifdef BONUS

int		____diddel;

void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

t_list	*lstmap_test(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

#define TEST_ft_lstnew
#define TEST_ft_lstdelone
#define TEST_ft_lstdel
#define TEST_ft_lstadd
#define TEST_ft_lstiter
#define TEST_ft_lstmap
#endif


#ifdef TEST_ft_abs
UT_TEST(ft_abs)
{
UT_ASSERT_EQ(ft_abs(12), abs(12));
UT_ASSERT_EQ(ft_abs(-12), abs(-12));
UT_ASSERT_EQ(ft_abs(28), abs(28));
UT_ASSERT_EQ(ft_abs(0), abs(0));
}
#endif

#ifdef TEST_ft_atoi
UT_TEST(ft_atoi)
{
UT_ASSERT_EQ(ft_atoi(" -sfecf"), atoi(" -sfecf"));
UT_ASSERT_EQ(ft_atoi(""), atoi(""));
UT_ASSERT_EQ(ft_atoi("+2798"), atoi("+2798"));
UT_ASSERT_EQ(ft_atoi("  \t\n  \r\r\v\f-899"), atoi("  \t\n  \r\r\v\f-899"));
UT_ASSERT_EQ(ft_atoi("+0089"), atoi("+0089"));
UT_ASSERT_EQ(ft_atoi("a56"), atoi("a56"));
UT_ASSERT_EQ(ft_atoi("      --s8"), atoi("      --s8"));
UT_ASSERT_EQ(ft_atoi("0001020304"), atoi("0001020304"));
UT_ASSERT_EQ(ft_atoi("000000000000000110"), atoi("000000000000000110"));
UT_ASSERT_EQ(ft_atoi("-153"), atoi("-153"));
UT_ASSERT_EQ(ft_atoi("+132"), atoi("+132"));
UT_ASSERT_EQ(ft_atoi("++876"), atoi("++876"));
UT_ASSERT_EQ(ft_atoi("--132"), atoi("--132"));
UT_ASSERT_EQ(ft_atoi("dwbk "), atoi("dwbk "));
UT_ASSERT_EQ(ft_atoi(" 1"), atoi(" 1"));
UT_ASSERT_EQ(ft_atoi("42jk "), atoi("42jk "));
UT_ASSERT_EQ(ft_atoi(" 21"), atoi(" 21"));
UT_ASSERT_EQ(ft_atoi("     32 "), atoi("     32 "));
UT_ASSERT_EQ(ft_atoi("\n          42 24"), atoi("\n          42 24"));
UT_ASSERT_EQ(ft_atoi("1-2"), atoi("1-2"));
UT_ASSERT_EQ(ft_atoi("4+2"), atoi("4+2"));
UT_ASSERT_EQ(ft_atoi("  +442"), atoi("  +442"));
UT_ASSERT_EQ(ft_atoi("  -4232"), atoi("  -4232"));
UT_ASSERT_EQ(ft_atoi("4,5"), atoi("4,5"));
UT_ASSERT_EQ(ft_atoi("+"), atoi("+"));
UT_ASSERT_EQ(ft_atoi("-"), atoi("-"));
UT_ASSERT_EQ(ft_atoi("-+1"), atoi("-+1"));
UT_ASSERT_EQ(ft_atoi("+-1"), atoi("+-1"));
UT_ASSERT_EQ(ft_atoi("\200123"), atoi("\200123"));
UT_ASSERT_EQ(ft_atoi("123\200"), atoi("123\200"));

UT_ASSERT_EQ(ft_atoi("-2147483648"), atoi("-2147483648"));
UT_ASSERT_EQ(ft_atoi("2147483647"), atoi("2147483647"));

UT_ASSERT_W(ft_atoi("2147483648") == atoi("2147483648"));
UT_ASSERT_W(ft_atoi("9223372036854775807") == atoi("9223372036854775807"));
UT_ASSERT_W(ft_atoi("9223372036854775806") == atoi("9223372036854775806"));
UT_ASSERT_W(ft_atoi("9223372036854775808") == atoi("9223372036854775808"));
UT_ASSERT_W(ft_atoi("-9223372036854775807") == atoi("-9223372036854775807"));
UT_ASSERT_W(ft_atoi("-9223372036854775806") == atoi("-9223372036854775806"));
UT_ASSERT_W(ft_atoi("-9223372036854775808") == atoi("-9223372036854775808"));
UT_ASSERT_W(ft_atoi("    555 5555555555555555") == atoi("    555 5555555555555555"));
UT_ASSERT_W(ft_atoi("2398472983749236582739823758723469826928374") == atoi("2398472983749236582739823758723469826928374"));
UT_ASSERT_W(ft_atoi("-2398472983749236582739823758723469826928374") == atoi("-2398472983749236582739823758723469826928374"));


/* The original atoi segfault in this case

	atoi(NULL);

*/
}
#endif

#ifdef TEST_ft_bzero
UT_TEST(ft_bzero)
{
char	b1[10], b2[10];

bzero(b1, 10);
ft_bzero(b2, 10);
UT_ASSERT_EQ(memcmp(b1, b2, 10), 0);
b1[0] = 1;
ft_bzero(b1, 0);
UT_ASSERT_EQ(b1[0], 1);

/* test edge cases */
bzero(NULL, 0);
ft_bzero(NULL, 0);

}
#endif

#ifdef TEST_ft_factorial
UT_TEST(ft_factorial)
{
UT_ASSERT_EQ(ft_factorial(0), 1);
UT_ASSERT_EQ(ft_factorial(1), 1);
UT_ASSERT_EQ(ft_factorial(3), 6);
UT_ASSERT_EQ(ft_factorial(5), 120);
UT_ASSERT_EQ(ft_factorial(8), 40320);
UT_ASSERT_EQ(ft_factorial(20), 2432902008176640000);
}
#endif

#ifdef TEST_ft_isalnum
UT_TEST(ft_isalnum)
{
UT_ASSERT_EQ(ft_isalnum('a'), isalnum('a'));
UT_ASSERT_EQ(ft_isalnum('a' + 0x100), isalnum('a' + 0x100));
UT_ASSERT_EQ(ft_isalnum('2'), isalnum('2'));
UT_ASSERT_EQ(ft_isalnum('Z'), isalnum('Z'));
UT_ASSERT_EQ(ft_isalnum('t'), isalnum('t'));
UT_ASSERT_EQ(ft_isalnum(0), isalnum(0));
UT_ASSERT_EQ(ft_isalnum(1), isalnum(1));
UT_ASSERT_EQ(ft_isalnum(9999), isalnum(9999));
UT_ASSERT_EQ(ft_isalnum('1'), isalnum('1'));
UT_ASSERT_EQ(ft_isalnum('2'), isalnum('2'));
UT_ASSERT_EQ(ft_isalnum('A'), isalnum('A'));
UT_ASSERT_EQ(ft_isalnum('Z'), isalnum('Z'));
UT_ASSERT_EQ(ft_isalnum(' '), isalnum(' '));
UT_ASSERT_EQ(ft_isalnum('%'), isalnum('%'));
UT_ASSERT_EQ(ft_isalnum('\t'), isalnum('\t'));
UT_ASSERT_EQ(ft_isalnum('\n'), isalnum('\n'));
UT_ASSERT_EQ(ft_isalnum('\v'), isalnum('\v'));
UT_ASSERT_EQ(ft_isalnum('\b'), isalnum('\b'));
UT_ASSERT_EQ(ft_isalnum(7), isalnum(7));

}
#endif

#ifdef TEST_ft_isalpha
UT_TEST(ft_isalpha)
{
UT_ASSERT_EQ(ft_isalpha('a'), isalpha('a'));
UT_ASSERT_EQ(ft_isalpha('a' + 0x100), isalpha('a' + 0x100));
UT_ASSERT_EQ(ft_isalpha('2'), isalpha('2'));
UT_ASSERT_EQ(ft_isalpha('Z'), isalpha('Z'));
UT_ASSERT_EQ(ft_isalpha('t'), isalpha('t'));
UT_ASSERT_EQ(ft_isalpha(0), isalpha(0));
UT_ASSERT_EQ(ft_isalpha(1), isalpha(1));
UT_ASSERT_EQ(ft_isalpha(9999), isalpha(9999));
UT_ASSERT_EQ(ft_isalpha('1'), isalpha('1'));
UT_ASSERT_EQ(ft_isalpha('2'), isalpha('2'));
UT_ASSERT_EQ(ft_isalpha('A'), isalpha('A'));
UT_ASSERT_EQ(ft_isalpha('Z'), isalpha('Z'));
UT_ASSERT_EQ(ft_isalpha(' '), isalpha(' '));
UT_ASSERT_EQ(ft_isalpha('%'), isalpha('%'));
UT_ASSERT_EQ(ft_isalpha('\t'), isalpha('\t'));
UT_ASSERT_EQ(ft_isalpha('\n'), isalpha('\n'));
UT_ASSERT_EQ(ft_isalpha('\v'), isalpha('\v'));
UT_ASSERT_EQ(ft_isalpha('\b'), isalpha('\b'));
UT_ASSERT_EQ(ft_isalpha(7), isalpha(7));

}
#endif

#ifdef TEST_ft_isascii
UT_TEST(ft_isascii)
{
UT_ASSERT_EQ(ft_isascii('a'), isascii('a'));
UT_ASSERT_EQ(ft_isascii('a' + 0x100), isascii('a' + 0x100));
UT_ASSERT_EQ(ft_isascii('2'), isascii('2'));
UT_ASSERT_EQ(ft_isascii('Z'), isascii('Z'));
UT_ASSERT_EQ(ft_isascii('t'), isascii('t'));
UT_ASSERT_EQ(ft_isascii(0), isascii(0));
UT_ASSERT_EQ(ft_isascii(1), isascii(1));
UT_ASSERT_EQ(ft_isascii(9999), isascii(9999));
UT_ASSERT_EQ(ft_isascii('1'), isascii('1'));
UT_ASSERT_EQ(ft_isascii('2'), isascii('2'));
UT_ASSERT_EQ(ft_isascii('A'), isascii('A'));
UT_ASSERT_EQ(ft_isascii('Z'), isascii('Z'));
UT_ASSERT_EQ(ft_isascii(' '), isascii(' '));
UT_ASSERT_EQ(ft_isascii('%'), isascii('%'));
UT_ASSERT_EQ(ft_isascii('\t'), isascii('\t'));
UT_ASSERT_EQ(ft_isascii('\n'), isascii('\n'));
UT_ASSERT_EQ(ft_isascii('\v'), isascii('\v'));
UT_ASSERT_EQ(ft_isascii('\b'), isascii('\b'));
UT_ASSERT_EQ(ft_isascii(7), isascii(7));

}
#endif

#ifdef TEST_ft_isblank
UT_TEST(ft_isblank)
{
UT_ASSERT_EQ(ft_isblank('a'), isblank('a'));
UT_ASSERT_EQ(ft_isblank('a' + 0x100), isblank('a' + 0x100));
UT_ASSERT_EQ(ft_isblank('2'), isblank('2'));
UT_ASSERT_EQ(ft_isblank('Z'), isblank('Z'));
UT_ASSERT_EQ(ft_isblank('t'), isblank('t'));
UT_ASSERT_EQ(ft_isblank(0), isblank(0));
UT_ASSERT_EQ(ft_isblank(1), isblank(1));
UT_ASSERT_EQ(ft_isblank(9999), isblank(9999));
UT_ASSERT_EQ(ft_isblank('1'), isblank('1'));
UT_ASSERT_EQ(ft_isblank('2'), isblank('2'));
UT_ASSERT_EQ(ft_isblank('A'), isblank('A'));
UT_ASSERT_EQ(ft_isblank('Z'), isblank('Z'));
UT_ASSERT_EQ(ft_isblank(' '), isblank(' '));
UT_ASSERT_EQ(ft_isblank('%'), isblank('%'));
UT_ASSERT_EQ(ft_isblank('\t'), isblank('\t'));
UT_ASSERT_EQ(ft_isblank('\n'), isblank('\n'));
UT_ASSERT_EQ(ft_isblank('\v'), isblank('\v'));
UT_ASSERT_EQ(ft_isblank('\b'), isblank('\b'));
UT_ASSERT_EQ(ft_isblank(7), isblank(7));

}
#endif

#ifdef TEST_ft_isdigit
UT_TEST(ft_isdigit)
{
UT_ASSERT_EQ(ft_isdigit('a'), isdigit('a'));
UT_ASSERT_EQ(ft_isdigit('a' + 0x100), isdigit('a' + 0x100));
UT_ASSERT_EQ(ft_isdigit('2'), isdigit('2'));
UT_ASSERT_EQ(ft_isdigit('Z'), isdigit('Z'));
UT_ASSERT_EQ(ft_isdigit('t'), isdigit('t'));
UT_ASSERT_EQ(ft_isdigit(0), isdigit(0));
UT_ASSERT_EQ(ft_isdigit(1), isdigit(1));
UT_ASSERT_EQ(ft_isdigit(9999), isdigit(9999));
UT_ASSERT_EQ(ft_isdigit('1'), isdigit('1'));
UT_ASSERT_EQ(ft_isdigit('2'), isdigit('2'));
UT_ASSERT_EQ(ft_isdigit('A'), isdigit('A'));
UT_ASSERT_EQ(ft_isdigit('Z'), isdigit('Z'));
UT_ASSERT_EQ(ft_isdigit(' '), isdigit(' '));
UT_ASSERT_EQ(ft_isdigit('%'), isdigit('%'));
UT_ASSERT_EQ(ft_isdigit('\t'), isdigit('\t'));
UT_ASSERT_EQ(ft_isdigit('\n'), isdigit('\n'));
UT_ASSERT_EQ(ft_isdigit('\v'), isdigit('\v'));
UT_ASSERT_EQ(ft_isdigit('\b'), isdigit('\b'));
UT_ASSERT_EQ(ft_isdigit(7), isdigit(7));

}
#endif

#ifdef TEST_ft_islower
UT_TEST(ft_islower)
{
UT_ASSERT_EQ(ft_isprint('a'), isprint('a'));
UT_ASSERT_EQ(ft_isprint('a' + 0x100), isprint('a' + 0x100));
UT_ASSERT_EQ(ft_isprint('2'), isprint('2'));
UT_ASSERT_EQ(ft_isprint('Z'), isprint('Z'));
UT_ASSERT_EQ(ft_isprint('t'), isprint('t'));
UT_ASSERT_EQ(ft_isprint(0), isprint(0));
UT_ASSERT_EQ(ft_isprint(1), isprint(1));
UT_ASSERT_EQ(ft_isprint(9999), isprint(9999));
UT_ASSERT_EQ(ft_isprint('1'), isprint('1'));
UT_ASSERT_EQ(ft_isprint('2'), isprint('2'));
UT_ASSERT_EQ(ft_isprint('A'), isprint('A'));
UT_ASSERT_EQ(ft_isprint('Z'), isprint('Z'));
UT_ASSERT_EQ(ft_isprint(' '), isprint(' '));
UT_ASSERT_EQ(ft_isprint('%'), isprint('%'));
UT_ASSERT_EQ(ft_isprint('\t'), isprint('\t'));
UT_ASSERT_EQ(ft_isprint('\n'), isprint('\n'));
UT_ASSERT_EQ(ft_isprint('\v'), isprint('\v'));
UT_ASSERT_EQ(ft_isprint('\b'), isprint('\b'));
UT_ASSERT_EQ(ft_isprint(7), isprint(7));

}
#endif

#ifdef TEST_ft_isprint
UT_TEST(ft_isprint)
{
UT_ASSERT_EQ(ft_isprint('a'), isprint('a'));
UT_ASSERT_EQ(ft_isprint('a' + 0x100), isprint('a' + 0x100));
UT_ASSERT_EQ(ft_isprint('2'), isprint('2'));
UT_ASSERT_EQ(ft_isprint('Z'), isprint('Z'));
UT_ASSERT_EQ(ft_isprint('t'), isprint('t'));
UT_ASSERT_EQ(ft_isprint(0), isprint(0));
UT_ASSERT_EQ(ft_isprint(1), isprint(1));
UT_ASSERT_EQ(ft_isprint(9999), isprint(9999));
UT_ASSERT_EQ(ft_isprint('1'), isprint('1'));
UT_ASSERT_EQ(ft_isprint('2'), isprint('2'));
UT_ASSERT_EQ(ft_isprint('A'), isprint('A'));
UT_ASSERT_EQ(ft_isprint('Z'), isprint('Z'));
UT_ASSERT_EQ(ft_isprint(' '), isprint(' '));
UT_ASSERT_EQ(ft_isprint('%'), isprint('%'));
UT_ASSERT_EQ(ft_isprint('\t'), isprint('\t'));
UT_ASSERT_EQ(ft_isprint('\n'), isprint('\n'));
UT_ASSERT_EQ(ft_isprint('\v'), isprint('\v'));
UT_ASSERT_EQ(ft_isprint('\b'), isprint('\b'));
UT_ASSERT_EQ(ft_isprint(7), isprint(7));

}
#endif

#ifdef TEST_ft_ispunct
UT_TEST(ft_ispunct)
{
UT_ASSERT_EQ(ft_ispunct('a'), ispunct('a'));
UT_ASSERT_EQ(ft_ispunct('a' + 0x100), ispunct('a' + 0x100));
UT_ASSERT_EQ(ft_ispunct('2'), ispunct('2'));
UT_ASSERT_EQ(ft_ispunct('Z'), ispunct('Z'));
UT_ASSERT_EQ(ft_ispunct('t'), ispunct('t'));
UT_ASSERT_EQ(ft_ispunct(0), ispunct(0));
UT_ASSERT_EQ(ft_ispunct(1), ispunct(1));
UT_ASSERT_EQ(ft_ispunct(9999), ispunct(9999));
UT_ASSERT_EQ(ft_ispunct('1'), ispunct('1'));
UT_ASSERT_EQ(ft_ispunct('2'), ispunct('2'));
UT_ASSERT_EQ(ft_ispunct('A'), ispunct('A'));
UT_ASSERT_EQ(ft_ispunct('Z'), ispunct('Z'));
UT_ASSERT_EQ(ft_ispunct(' '), ispunct(' '));
UT_ASSERT_EQ(ft_ispunct('%'), ispunct('%'));
UT_ASSERT_EQ(ft_ispunct('\t'), ispunct('\t'));
UT_ASSERT_EQ(ft_ispunct('\n'), ispunct('\n'));
UT_ASSERT_EQ(ft_ispunct('\v'), ispunct('\v'));
UT_ASSERT_EQ(ft_ispunct('\b'), ispunct('\b'));
UT_ASSERT_EQ(ft_ispunct(7), ispunct(7));

}
#endif

#ifdef TEST_ft_isspace
UT_TEST(ft_isspace)
{
UT_ASSERT_EQ(ft_isspace('a'), isspace('a'));
UT_ASSERT_EQ(ft_isspace('a' + 0x100), isspace('a' + 0x100));
UT_ASSERT_EQ(ft_isspace('2'), isspace('2'));
UT_ASSERT_EQ(ft_isspace('Z'), isspace('Z'));
UT_ASSERT_EQ(ft_isspace('t'), isspace('t'));
UT_ASSERT_EQ(ft_isspace(0), isspace(0));
UT_ASSERT_EQ(ft_isspace(1), isspace(1));
UT_ASSERT_EQ(ft_isspace(9999), isspace(9999));
UT_ASSERT_EQ(ft_isspace('1'), isspace('1'));
UT_ASSERT_EQ(ft_isspace('2'), isspace('2'));
UT_ASSERT_EQ(ft_isspace('A'), isspace('A'));
UT_ASSERT_EQ(ft_isspace('Z'), isspace('Z'));
UT_ASSERT_EQ(ft_isspace(' '), isspace(' '));
UT_ASSERT_EQ(ft_isspace('%'), isspace('%'));
UT_ASSERT_EQ(ft_isspace('\t'), isspace('\t'));
UT_ASSERT_EQ(ft_isspace('\n'), isspace('\n'));
UT_ASSERT_EQ(ft_isspace('\v'), isspace('\v'));
UT_ASSERT_EQ(ft_isspace('\b'), isspace('\b'));
UT_ASSERT_EQ(ft_isspace(7), isspace(7));

}
#endif

#ifdef TEST_ft_isupper
UT_TEST(ft_isupper)
{
UT_ASSERT_EQ(ft_isupper('a'), isupper('a'));
UT_ASSERT_EQ(ft_isupper('a' + 0x100), isupper('a' + 0x100));
UT_ASSERT_EQ(ft_isupper('2'), isupper('2'));
UT_ASSERT_EQ(ft_isupper('Z'), isupper('Z'));
UT_ASSERT_EQ(ft_isupper('t'), isupper('t'));
UT_ASSERT_EQ(ft_isupper(0), isupper(0));
UT_ASSERT_EQ(ft_isupper(1), isupper(1));
UT_ASSERT_EQ(ft_isupper(9999), isupper(9999));
UT_ASSERT_EQ(ft_isupper('1'), isupper('1'));
UT_ASSERT_EQ(ft_isupper('2'), isupper('2'));
UT_ASSERT_EQ(ft_isupper('A'), isupper('A'));
UT_ASSERT_EQ(ft_isupper('Z'), isupper('Z'));
UT_ASSERT_EQ(ft_isupper(' '), isupper(' '));
UT_ASSERT_EQ(ft_isupper('%'), isupper('%'));
UT_ASSERT_EQ(ft_isupper('\t'), isupper('\t'));
UT_ASSERT_EQ(ft_isupper('\n'), isupper('\n'));
UT_ASSERT_EQ(ft_isupper('\v'), isupper('\v'));
UT_ASSERT_EQ(ft_isupper('\b'), isupper('\b'));
UT_ASSERT_EQ(ft_isupper(7), isupper(7));

}
#endif

#ifdef TEST_ft_itoa
UT_TEST(ft_itoa)
{
UT_ASSERT_EQ(strcmp(ft_itoa(0), "0"), 0);
UT_ASSERT_EQ(strcmp(ft_itoa(-1234), "-1234"), 0);
UT_ASSERT_EQ(strcmp(ft_itoa(123456000), "123456000"), 0);
UT_ASSERT_EQ(strcmp(ft_itoa(-2147483648), "-2147483648"), 0);

}
#endif

#ifdef TEST_ft_lstadd
UT_TEST(ft_lstadd)
{
t_list	*list;
t_list	*list2;

list = malloc(sizeof(t_list));
list2 = malloc(sizeof(t_list));
bzero(list, sizeof(t_list));
bzero(list2, sizeof(t_list));
ft_lstadd(&list2, list);
UT_ASSERT_EQ(list, list2);
UT_ASSERT_NEQ(list->next, NULL);

/* test edge cases */
ft_lstadd(NULL, NULL);

}
#endif

#ifdef TEST_ft_lstdel
UT_TEST(ft_lstdel)
{
t_list	*list;
int		ft;

ft = 42;
____diddel = 0;
list = malloc(sizeof(t_list));
bzero(list, sizeof(t_list));
list->next = malloc(sizeof(t_list));
bzero(list->next, sizeof(t_list));
list->content = &ft;
list->next->content = (&ft) + 1;
ft_lstdel(&list, del_test);
UT_ASSERT_EQ(list, NULL);
UT_ASSERT_EQ(____diddel, 2);

/* test edge cases */
ft_lstdel(NULL, NULL);

}
#endif

#ifdef TEST_ft_lstdelone
UT_TEST(ft_lstdelone)
{
t_list	*list;
int		ft;

____diddel = 0;
ft = 42;
list = (t_list *)malloc(sizeof(t_list));
list->content = &ft;
list->content_size = sizeof(int);
ft_lstdelone(&list, del_test);
UT_ASSERT_EQ(list, NULL);
UT_ASSERT_EQ(____diddel, 1);

/* test edge cases */
ft_lstdelone(NULL, NULL);
}
#endif

#ifdef TEST_ft_lstiter
UT_TEST(ft_lstiter)
{
t_list	*list;

bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
ft_lstiter(list, lstiter_test);
UT_ASSERT_EQ(list->content_size, 42);
UT_ASSERT_EQ(list->next->content_size, 42);

}
#endif

#ifdef TEST_ft_lstmap
UT_TEST(ft_lstmap)
{
t_list	*list;
t_list	*list2;
t_list	*map;

bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
list->content_size = 21;
list->content = strdup("abc");
list->next->content_size = 100;
list->next->content = strdup("abc");
map = ft_lstmap(list, lstmap_test);
UT_ASSERT_EQ(list->content_size, 21);
UT_ASSERT_EQ(list->next->content_size, 100);
UT_ASSERT_EQ(map->content_size, 42);
UT_ASSERT_EQ(map->next->content_size, 200);

/* NE PAS TENIR COMPTE

bzero((list2 = malloc(sizeof(t_list))), sizeof(t_list)); list2->content_size = 10; map = ft_lstmap(list2, lstmap_test); UT_ASSERT_EQ(map->content_size, 0);

*/

}
#endif

#ifdef TEST_ft_lstnew
UT_TEST(ft_lstnew)
{
t_list	*list;
int		ft;

ft = 42;
list = ft_lstnew(&ft, sizeof(int));
UT_ASSERT_EQ((*(int*)(list->content)), 42);
list = ft_lstnew(NULL, 386);
UT_ASSERT_EQ((list->content_size), 0);

/* NE PAS TENIR COMPTE
list = ft_lstnew(strdup("abc"), 0); UT_ASSERT(list->content == NULL); UT_ASSERT(list->content_size ==  0);
*/
}
#endif

#ifdef TEST_ft_memalloc
UT_TEST(ft_memalloc)
{
void	*mem1, *mem2;

mem1 = malloc(100);
bzero(mem1, 100);
mem2 = ft_memalloc(100);

UT_ASSERT(memcmp(mem1, mem2, 100) == 0);
UT_ASSERT(ft_memalloc((size_t)-1) == NULL);

UT_ASSERT_W(ft_memalloc(0) != NULL);

}
#endif

#ifdef TEST_ft_memccpy
UT_TEST(ft_memccpy)
{
char	buf1[] = "Ceci est un test.";
char	buf2[200];
void	*p1, *p2;

p1 = memccpy(buf2, buf1, 'i', 10);
p2 = ft_memccpy(buf2, buf1, 'i', 10);
UT_ASSERT_EQ(p1, p2);
UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'k', 5), 0);
UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, 0), memccpy(buf2, buf1, 0, 0));
UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, sizeof(buf1)), memccpy(buf2, buf1, 0, sizeof(buf1)));
UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'C', 10), buf2 + 1);

char dest[] = "abcdefghijklmnopqrstuvwxyz";
UT_ASSERT_EQ(ft_memccpy(dest, strdup("test\200string"), '\200', 12),
	memccpy(dest, strdup("test\200string"), '\200', 12));

}
#endif

#ifdef TEST_ft_memchr
UT_TEST(ft_memchr)
{
UT_ASSERT_EQ(ft_memchr("abcdef", 'a', 5), memchr("abcdef", 'a', 5));
UT_ASSERT_EQ(ft_memchr("abcdef", 'c', 5), memchr("abcdef", 'c', 5));
UT_ASSERT_EQ(ft_memchr("abcdef", '\0', 7), memchr("abcdef", '\0', 7));
UT_ASSERT_EQ(ft_memchr("abcdef", 'z', 6), memchr("abcdef", 'z', 6));
UT_ASSERT_EQ(ft_memchr("abcdef", 999, 6), memchr("abcdef", 999, 6));

/* Barbarian test from Qperez !! */
char			ctab[11];
int				itab[11];
unsigned long	ltab[11];
size_t			j;
int				i;

i = -300;
memchr(NULL, 0, 0);
ft_memchr(NULL, 0, 0);
while (i < 300)
{
	j = 0;
	while (j < 11)
	{
		ctab[j] = (char)rand();
		itab[j] = rand();
		ltab[j] = (unsigned long)rand() * 10000;
		j++;
	}
	if ((memchr(ctab, i, sizeof(ctab)) != ft_memchr(ctab, i, sizeof(ctab)))
		|| ((memchr(itab, i, sizeof(itab)) != ft_memchr(itab, i, sizeof(itab))))
		|| (memchr(ltab, i, sizeof(ltab)) != ft_memchr(ltab, i, sizeof(ltab))))
	{
		UT_ASSERT(!"Unsigned char problem?");
		break;
	}
	++i;
}

UT_ASSERT(memchr(NULL, 0, 0) == ft_memchr(NULL, 0, 0));

memchr(NULL, 0, 10);
ft_memchr(NULL, 0, 10);

memchr(NULL, -10, 10);
ft_memchr(NULL, -10, 10);

}
#endif

#ifdef TEST_ft_memcmp
UT_TEST(ft_memcmp)
{
char	*t = "ab\0ab";


UT_ASSERT_EQ(ft_memcmp(t, t, 5), 0);
UT_ASSERT_NEQ(ft_memcmp(t, "abcab", 5) ,0);
UT_ASSERT(ft_memcmp("aaa", "aab", 4) < 0);
UT_ASSERT_EQ(ft_memcmp("aab", "aac", 2), 0);
UT_ASSERT_EQ(ft_memcmp("aww", "bpp", 0), 0);
UT_ASSERT(ft_memcmp("\200", "\0", 1) > 0);

/* test edge cases */
// UT_ASSERT_W(memcmp(NULL, NULL, 0) == ft_memcmp(NULL, NULL, 0));
// UT_ASSERT_W(memcmp(NULL, NULL, 10) == ft_memcmp(NULL, NULL, 10));

/* should not crash in those cases */
// memcmp(NULL, t, 10);
// ft_memcmp(NULL, t, 10);
// memcmp(t, NULL, 10);
// ft_memcmp(t, NULL, 10);

}
#endif

#ifdef TEST_ft_memcpy
UT_TEST(ft_memcpy)
{
char	b1[100], b2[100];

memset(b1, 33, 100);
memset(b2, 63, 100);

ft_memcpy(b1, b2, 100);
UT_ASSERT(memcmp(b1, b2, 100) == 0);
UT_ASSERT(ft_memcpy(b1, b2, 0) == b1);

/* test edge cases */
memcpy(NULL, NULL, 0); /* The original memcpy does not segfault. */
UT_ASSERT(ft_memcpy(NULL, NULL, 0) == memcpy(NULL, NULL, 0));

}
#endif

#ifdef TEST_ft_memdel
UT_TEST(ft_memdel)
{
void	*mem;

mem = malloc(2000);
ft_memdel(&mem);
UT_ASSERT_W(mem == NULL);

/* test edge cases */
void	*mem2;
mem2 = NULL;
// ft_memdel(NULL);
// ft_memdel(&mem2);

}
#endif

#ifdef TEST_ft_memdup
UT_TEST(ft_memdup)
{
char	*c;

c = "AbC";
UT_ASSERT_EQ(strcmp(ft_memdup("aaaaa", 6), "aaaaa"), 0);
UT_ASSERT_EQ(strcmp(ft_memdup("", 1), ""), 0);
UT_ASSERT_NEQ(c, ft_memdup(c, 4));

/* test edge cases */
UT_ASSERT(ft_memdup(NULL, 0) == NULL);

}
#endif

#ifdef TEST_ft_memmove
UT_TEST(ft_memmove)
{
char	testA1[] = "abcdef";
char	testA2[] = "abcdef";

ft_memmove(testA1 + 1, testA1, 5);
ft_memmove(testA1 + 1, testA1, 0);
memmove(testA2 + 1, testA2, 5);
memmove(testA2 + 1, testA2, 0);
UT_ASSERT(strcmp(testA1, "aabcde") == 0);
UT_ASSERT(strcmp(testA1, testA2) == 0);

char	testB1[] = "abcdef";
char	testB2[] = "abcdef";

ft_memmove(testB1, testB1 + 1, 5);
ft_memmove(testB1, testB1 + 1, 0);
memmove(testB2, testB2 + 1, 5);
memmove(testB2, testB2 + 1, 0);
UT_ASSERT(strcmp(testB1, "bcdeff") == 0);
UT_ASSERT(strcmp(testB1, testB2) == 0);

/* test edge cases */
// char	test[] = "aaa";
// UT_ASSERT_W(ft_memmove(NULL, test, 0) == memmove(NULL, test, 0));
// UT_ASSERT_W(strcmp(memmove(test, NULL, 0), ft_memmove(test, NULL, 0)) == 0);
// UT_ASSERT_W(ft_memmove(NULL, NULL, 0) == memmove(NULL, NULL, 0));
// UT_ASSERT_W(ft_memmove(NULL, NULL, 100) == memmove(NULL, NULL, 100));
// UT_ASSERT_W(ft_memmove(NULL, NULL, -100) == memmove(NULL, NULL, -100));

/* The original memmove segfault or stops on those cases;

	memmove(NULL, test, 100);
	memmove(test, NULL, 100);
	memmove(NULL, test, -100);
	memmove(test, NULL, -100);
*/

}
#endif

#ifdef TEST_ft_memset
UT_TEST(ft_memset)
{
char	b1[100], b2[100];

ft_memset(b1, 42, 100);
memset(b2, 42, 100);
UT_ASSERT_EQ(memset(b1, 99, 0), ft_memset(b1, 99, 0));
UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
b1[0] = 1;
ft_memset(b1, 0, 0);
UT_ASSERT_EQ(b1[0], 1);

UT_ASSERT(memcmp(memset(strdup("abcd"), 'A', 5), ft_memset(strdup("abcd"), 'A', 5), 5) == 0);

/* test edge cases */
UT_ASSERT(memset(0, 0, 0) == ft_memset(0, 0, 0));
UT_ASSERT(memset(0, 'A', 0) == ft_memset(0, 'A', 0));
UT_ASSERT(memcmp(memset(strdup("abcd"), 0, 0), ft_memset(strdup("abcd"), 0, 0), 5) == 0);

}
#endif

#ifdef TEST_ft_memswap
UT_TEST(ft_memswap)
{
 /* Two contributor for this test */
char	was_a = 'a';
char	was_b = 'b';
int		was_1 = 1;
int		was_2 = 2;
char	was_toto[] = "toto";
char	was_tata[] = "tata";

char test_swap_str_1[] = "coucou les filles";
char test_swap_str_2[] = "bonjour jambon po";
int test_swap_int_1 = 24;
int test_swap_int_2 = 42;

ft_memswap(&was_a, &was_b, sizeof(char));
UT_ASSERT(was_a == 'b');
UT_ASSERT(was_b == 'a');
ft_memswap(&was_1, &was_2, sizeof(int));
UT_ASSERT(was_1 == 2);
UT_ASSERT(was_2 == 1);
ft_memswap(&was_1, &was_2, 0);
UT_ASSERT(was_1 == 2);
UT_ASSERT(was_2 == 1);
ft_memswap(was_toto, was_tata, sizeof(char) * 2);
UT_ASSERT_EQ(strcmp(was_toto, "tato"), 0);
UT_ASSERT_EQ(strcmp(was_tata, "tota"), 0);

ft_memswap(&test_swap_str_1, &test_swap_str_2, ft_strlen(test_swap_str_2));
ft_memswap(&test_swap_int_1, &test_swap_int_2, 2);
UT_ASSERT_EQ(strcmp(test_swap_str_1, "bonjour jambon po"), 0);
UT_ASSERT_EQ(strcmp(test_swap_str_2, "coucou les filles"), 0);
UT_ASSERT_EQ(test_swap_int_1, 42);
UT_ASSERT_EQ(test_swap_int_2, 24);

}
#endif

#ifdef TEST_ft_nrot
UT_TEST(ft_nrot)
{
UT_ASSERT_EQ(strcmp(ft_nrot(strdup("a"), 1), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 5), "F"), 0);
UT_ASSERT_EQ(strcmp(ft_nrot(strdup("A"), 22), "W"), 0);
}
#endif

#ifdef TEST_ft_power
UT_TEST(ft_power)
{
UT_ASSERT_EQ(ft_power(2, 3), pow(2, 3));
UT_ASSERT_EQ(ft_power(10, 9), pow(10, 9));
UT_ASSERT_EQ(ft_power(50, 0), pow(50, 0));
UT_ASSERT_EQ(ft_power(0, 10), pow(0, 10));
UT_ASSERT_EQ(ft_power(25, 13), pow(25,13));
}
#endif

#ifdef TEST_ft_printable_rotone
UT_TEST(ft_printable_rotone)
{
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("a")), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("z")), "{"), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("~")), " "), 0);
UT_ASSERT_EQ(strcmp(ft_printable_rotone(strdup("7")), "8"), 0);
}
#endif

#ifdef TEST_ft_ptrswap
UT_TEST(ft_ptrswap)
{
int		was_1 = 1;
int		was_2 = 2;
char	was_a = 'a';
char	was_b = 'b';
int		*ptr_1 = &was_1;
int		*ptr_2 = &was_2;
char	*ptr_a = &was_a;
char	*ptr_b = &was_b;

ft_ptrswap(&ptr_1, &ptr_2);
ft_ptrswap(&ptr_a, &ptr_b);
UT_ASSERT(*ptr_1 == 2);
UT_ASSERT(*ptr_2 == 1);
UT_ASSERT(*ptr_a == 'b');
UT_ASSERT(*ptr_b == 'a');
}
#endif

#ifdef TEST_ft_putchar
UT_TEST(ft_putchar)
{
int		out;
int		p[2];
char	buf[4];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putchar('a');
ft_putchar('b');
ft_putchar('c');
dup2(out, 1);
read(p[0], buf, 3);
buf[3] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "abc"), 0);
}
#endif

#ifdef TEST_ft_putchar_fd
UT_TEST(ft_putchar_fd)
{
int		p[2];
char	buf[100];

pipe(p);
ft_putchar_fd('a', p[1]);
ft_putchar_fd('b', p[1]);
buf[read(p[0], buf, 100)] = 0;
close(p[0]);
close(p[1]);
UT_ASSERT_EQ(strcmp(buf, "ab"), 0);
}
#endif

#ifdef TEST_ft_putendl
UT_TEST(ft_putendl)
{
int		out;
int		p[2];
char	buf[4];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putendl("aa");
dup2(out, 1);
read(p[0], buf, 3);
buf[3] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "aa\n"), 0);
}
#endif

#ifdef TEST_ft_putendl_fd
UT_TEST(ft_putendl_fd)
{
int		p[2];
char	buf[100];

pipe(p);
ft_putendl_fd("A QUE KOUKOU", p[1]);
buf[read(p[0], buf, 100)] = 0;
close(p[0]);
close(p[1]);
UT_ASSERT_EQ(strcmp(buf, "A QUE KOUKOU\n"), 0);
}
#endif

#ifdef TEST_ft_putnbr
UT_TEST(ft_putnbr)
{
int		out;
int		p[2];
char	buf[100];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putnbr(0);
ft_putnbr(1);
ft_putnbr(-1);
ft_putnbr(12300);
ft_putnbr(10203);
ft_putnbr(-56);
ft_putnbr(2147483647);
ft_putnbr(-2147483648);
dup2(out, 1);
buf[read(p[0], buf, 100)] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "01-11230010203-562147483647-2147483648"), 0);
}
#endif

#ifdef TEST_ft_putnbr_fd
UT_TEST(ft_putnbr_fd)
{
int		p[2];
char	buf[100];

pipe(p);
ft_putnbr_fd(0, p[1]);
ft_putnbr_fd(1, p[1]);
ft_putnbr_fd(-1, p[1]);
ft_putnbr_fd(56, p[1]);
ft_putnbr_fd(-1230, p[1]);
ft_putnbr_fd(10203, p[1]);
ft_putnbr_fd(2147483647, p[1]);
ft_putnbr_fd(-2147483648, p[1]);
buf[read(p[0], buf, 100)] = 0;
close(p[0]);
close(p[1]);
UT_ASSERT_EQ(strcmp(buf, "01-156-1230102032147483647-2147483648"), 0);
}
#endif

#ifdef TEST_ft_putnendl
UT_TEST(ft_putnendl)
{
int		out;
int		p[2];
char	buf[5];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putnendl("Bonjour", 4);
dup2(out, 1);
read(p[0], buf, 5);
buf[5] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "Bonj\n"), 0);
}
#endif

#ifdef TEST_ft_putnstr
UT_TEST(ft_putnstr)
{
int		out;
int		p[2];
char	buf[5];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putnstr("Bonjour", 4);
dup2(out, 1);
read(p[0], buf, 4);
buf[4] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "Bonj"), 0);
}
#endif

#ifdef TEST_ft_putstr
UT_TEST(ft_putstr)
{
int		out;
int		p[2];
char	buf[4];

out = dup(1);
pipe(p);
dup2(p[1], 1);
ft_putstr("aaa");
dup2(out, 1);
read(p[0], buf, 3);
buf[3] = 0;
close(p[0]);
close(p[1]);
close(out);
UT_ASSERT_EQ(strcmp(buf, "aaa"), 0);
}
#endif

#ifdef TEST_ft_putstr_fd
UT_TEST(ft_putstr_fd)
{
int		p[2];
char	buf[100];

pipe(p);
ft_putstr_fd("A QUE KOUKOU", p[1]);
buf[read(p[0], buf, 100)] = 0;
close(p[0]);
close(p[1]);
UT_ASSERT_EQ(strcmp(buf, "A QUE KOUKOU"), 0);
}
#endif

#ifdef TEST_ft_replace_char
UT_TEST(ft_replace_char)
{
char test_change[] = "Coucou les filles";
char *return_test_change;

return_test_change = (char *)malloc(strlen(test_change) + 1);

return_test_change = ft_replace_char(test_change, 'o', 'r');
UT_ASSERT_EQ(strcmp(return_test_change, "Crucru les filles"), 0);
}
#endif

#ifdef TEST_ft_rotone
UT_TEST(ft_rotone)
{
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("a")), "b"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("A")), "B"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("z")), "a"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("Z")), "A"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("6")), "6"), 0);
UT_ASSERT_EQ(strcmp(ft_rotone(strdup("[")), "["), 0);
}
#endif

#ifdef TEST_ft_sort_int_table
UT_TEST(ft_sort_int_table)
{
int test_ft_sort[7] = {42,4,98,9,12,68,21};

ft_sort_int_table(test_ft_sort, 7);
UT_ASSERT_EQ(test_ft_sort[0], 4);
UT_ASSERT_EQ(test_ft_sort[1], 9);
UT_ASSERT_EQ(test_ft_sort[2], 12);
UT_ASSERT_EQ(test_ft_sort[3], 21);
UT_ASSERT_EQ(test_ft_sort[4], 42);
UT_ASSERT_EQ(test_ft_sort[5], 68);
UT_ASSERT_EQ(test_ft_sort[6], 98);
}
#endif

#ifdef TEST_ft_sqrt
UT_TEST(ft_sqrt)
{
UT_ASSERT_EQ(ft_sqrt(25), 5);
UT_ASSERT_EQ(ft_sqrt(100), 10);
UT_ASSERT_EQ(ft_sqrt(18), 0);
UT_ASSERT_EQ(ft_sqrt(0), 0);
}
#endif

#ifdef TEST_ft_strcapitalize
UT_TEST(ft_strcapitalize)
{
ft_strcapitalize(NULL);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("bonjour les filles")), "Bonjour Les Filles"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello")), "Hello"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("hello2world")), "Hello2world"), 0);
UT_ASSERT_EQ(strcmp(ft_strcapitalize(strdup("   je mange des pommes.  ")), "   Je Mange Des Pommes.  "), 0);
}
#endif

#ifdef TEST_ft_strcat
UT_TEST(ft_strcat)
{
char	buf[9];

bzero(buf, 9);
ft_strcat(buf, "");
ft_strcat(buf, "Bon");
ft_strcat(buf, "j");
ft_strcat(buf, "our.");
ft_strcat(buf, "");
UT_ASSERT_EQ(strcmp(buf, "Bonjour."), 0);
UT_ASSERT_EQ(buf, ft_strcat(buf, ""));
}
#endif

#ifdef TEST_ft_strchr
UT_TEST(ft_strchr)
{
char	buf[] = "Je suis un poisson.";

UT_ASSERT_EQ(strchr(buf, 'p'), ft_strchr(buf, 'p'));
UT_ASSERT_EQ(strchr(buf, 0), ft_strchr(buf, 0));
UT_ASSERT_EQ(ft_strchr(buf, 'J'), buf);
UT_ASSERT_EQ(ft_strchr(buf, 'z'), 0);
}
#endif

#ifdef TEST_ft_strclr
UT_TEST(ft_strclr)
{
char	str[] = "tttttt";

ft_strclr(str);
UT_ASSERT_EQ(memcmp(str, "\0\0\0\0\0\0", 7), 0);
}
#endif

#ifdef TEST_ft_strcmp
UT_TEST(ft_strcmp)
{
	/* No need to test for NULL value
	**
	** ft_strcmp(NULL, NULL)
	**
	** The standard strcmp function return this error:
	** error: null argument where non-null required
	*/
	UT_ASSERT_EQ(ft_strcmp("abc", "abc"), 0);
	UT_ASSERT(ft_strcmp("abc", "abd") < 0);
	UT_ASSERT(ft_strcmp("\200", "\0") > 0);
	UT_ASSERT_NEQ(ft_strcmp("a", "abcde"), 0);
}
#endif

#ifdef TEST_ft_strcpy
UT_TEST(ft_strcpy)
{
char	buf1[6], buf2[6];

bzero(buf1, 6);
bzero(buf2, 6);

UT_ASSERT_EQ(strcmp(ft_strcpy(buf1, "abcde"), strcpy(buf1, "abcde")), 0);
UT_ASSERT_EQ(strcmp(ft_strcpy(buf1, "abc"), strcpy(buf1, "abc")), 0);

// strcpy(NULL, NULL);
// ft_strcpy(NULL, NULL);

}
#endif

#ifdef TEST_ft_strdel
UT_TEST(ft_strdel)
{
char	*str;

str = malloc(123);
ft_strdel(&str);
UT_ASSERT_EQ(str, NULL);
}
#endif

#ifdef TEST_ft_strdup
UT_TEST(ft_strdup)
{
char	*c;

c = "AbC";
UT_ASSERT_EQ(strcmp(ft_strdup("aaaaa"), "aaaaa"), 0);
UT_ASSERT_EQ(strcmp(ft_strdup(""), ""), 0);
UT_ASSERT_NEQ(c, ft_strdup(c));
}
#endif

#ifdef TEST_ft_strequ
UT_TEST(ft_strequ)
{
UT_ASSERT_EQ(ft_strequ("", ""), 1);
UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEF"), 1);
UT_ASSERT_EQ(ft_strequ("abcDEF", "abcDEf"), 0);

}
#endif

#ifdef TEST_ft_striter
UT_TEST(ft_striter)
{
char	str[] = "aBcDeF";

ft_striter(str, it_test);
UT_ASSERT_EQ(strcmp(str, "bCdEfG"), 0);
}
#endif

#ifdef TEST_ft_striteri
UT_TEST(ft_striteri)
{
char	str[] = "aBcDeF";

ft_striteri(str, iti_test);
UT_ASSERT_EQ(strcmp(str, "aCeGiK"), 0);
}
#endif

#ifdef TEST_ft_strjoin
UT_TEST(ft_strjoin)
{
UT_ASSERT_EQ(strcmp(ft_strjoin("abc", "def"), "abcdef"), 0);
UT_ASSERT_EQ(strcmp(ft_strjoin("", ""), ""), 0);

ft_strjoin("", NULL);
ft_strjoin(NULL, "");
ft_strjoin(NULL, NULL);

}
#endif

#ifdef TEST_ft_strlcat
UT_TEST(ft_strlcat)
{
char	buf[10];
bzero(buf, 10);
strcpy(buf, "abc");
ft_strlcat(buf, "abcdefghijklmnop", 10);
UT_ASSERT_EQ(strcmp(buf, "abcabcdef"), 0);
UT_ASSERT_EQ(ft_strlcat(buf, "abcd", 2), 6);
bzero(buf, 10);
UT_ASSERT_EQ(ft_strlcat(buf, "abc", 10), 3);
UT_ASSERT_EQ(ft_strlcat(buf, "def", 10), 6);
bzero(buf, 10);
memset(buf, 'a', 10);
UT_ASSERT_EQ(ft_strlcat(buf, "ccc", 10), 13);

UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 0), strlcat(strdup("abc\0\0\0"), "ccc", 0));
UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 1), strlcat(strdup("abc\0\0\0"), "ccc", 1));
UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 6), strlcat(strdup("abc\0\0\0"), "ccc", 6));
UT_ASSERT_EQ(ft_strlcat(strdup("abc\0\0\0"), "ccc", 10), strlcat(strdup("abc\0\0\0"), "ccc", 10));

}
#endif

#ifdef TEST_ft_strlen
UT_TEST(ft_strlen)
{
UT_ASSERT_EQ(ft_strlen("chat"), strlen("chat"));
UT_ASSERT_EQ(ft_strlen(""), strlen(""));
UT_ASSERT_EQ(ft_strlen("aaa\0aaa"), strlen("aaa\0aaa"));
}
#endif

#ifdef TEST_ft_strlowcase
UT_TEST(ft_strlowcase)
{
ft_strlowcase(NULL);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("")), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("aaa")), "aaa"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("zzz")), "zzz"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("AAA")), "aaa"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("ZZZ")), "zzz"), 0);
UT_ASSERT_EQ(strcmp(ft_strlowcase(strdup("aBcDeé9123'47289")), "abcdeé9123'47289"), 0);
}
#endif

#ifdef TEST_ft_strmap
UT_TEST(ft_strmap)
{
char	*src;
char	*dst;

src = strdup("abcde");
dst = ft_strmap(src, map_test);

free(src); src = NULL;

UT_ASSERT_EQ(strcmp(dst, "bcdef"), 0);

}
#endif

#ifdef TEST_ft_strmapi
UT_TEST(ft_strmapi)
{
char	*src;
char	*dst;

src = strdup("abcde");
dst = ft_strmapi(src, mapi_test);

free(src); src = NULL;

UT_ASSERT_EQ(strcmp(dst, "acegi"), 0);

}
#endif

#ifdef TEST_ft_strncat
UT_TEST(ft_strncat)
{
char	buf[20];

strcpy(buf, "To be ");
ft_strncat(buf, "or not to be", 6);
UT_ASSERT_EQ(strcmp(buf, "To be or not"), 0);
ft_strncat(buf, "efefef", 0);
UT_ASSERT_EQ(strcmp(buf, "To be or not"), 0);
UT_ASSERT_EQ(buf, ft_strncat(buf, "", 0));
}
#endif

#ifdef TEST_ft_strncmp
UT_TEST(ft_strncmp)
{
UT_ASSERT(ft_strncmp("\200", "\0", 1) > 0);
UT_ASSERT_EQ(ft_strncmp("abc", "abcde", 3), 0);
UT_ASSERT_EQ(ft_strncmp("abc", "abc\0defg", 100), 0);
UT_ASSERT_NEQ(ft_strncmp("ab\0cde", "abcc\0e", 20), 0);
UT_ASSERT_EQ(ft_strncmp("q", "a", 0), strncmp("q", "a", 0));

}
#endif

#ifdef TEST_ft_strncpy
UT_TEST(ft_strncpy)
{
char	buf[6];

memset(buf, 33, 6);
ft_strncpy(buf, "abc", 6);
UT_ASSERT_EQ(memcmp(buf, "abc\0\0", 6), 0);
ft_strncpy(buf, "abcdefghi", 6);
UT_ASSERT_EQ(memcmp(buf, "abcdefghi", 6), 0);


strncpy(NULL, NULL, 0);
ft_strncpy(NULL, NULL, 0);

}
#endif

#ifdef TEST_ft_strnequ
UT_TEST(ft_strnequ)
{
UT_ASSERT_EQ(ft_strnequ("ededeqdf", "", 0), 1);
UT_ASSERT_EQ(ft_strnequ("abcde", "abdfe", 2), 1);
UT_ASSERT_EQ(ft_strnequ("abc", "abc", 100), 1);
UT_ASSERT_EQ(ft_strnequ("abcde", "abdde", 5), 0);
}
#endif

#ifdef TEST_ft_strnew
UT_TEST(ft_strnew)
{
char	*str;
char	*t;

str = ft_strnew(0);
UT_ASSERT_NEQ(str, NULL);
str = ft_strnew(100);
t = malloc(101);
bzero(t, 101);
UT_ASSERT_EQ(memcmp(str, t, 101), 0);
UT_ASSERT_NEQ(ft_strnew(0), 0);
UT_ASSERT_EQ(ft_strnew((size_t)-10), 0);
}
#endif

#ifdef TEST_ft_strnstr
UT_TEST(ft_strnstr)
{
char	buf[10];

bzero(buf, 10);
strcpy(buf, "un deux 9");
UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
UT_ASSERT_EQ(strnstr(buf, "9", 3), ft_strnstr(buf, "9", 3));
UT_ASSERT_EQ(ft_strnstr(buf, "", 6), buf);
UT_ASSERT_EQ(ft_strnstr(buf, "deux", 5), strnstr(buf, "deux", 5));
UT_ASSERT_EQ(ft_strnstr(buf, "9", 10), strnstr(buf, "9", 10));
UT_ASSERT_EQ(ft_strnstr(buf, "9", 8), strnstr(buf, "9", 8));
buf[9] = '6';
UT_ASSERT_EQ(strnstr(buf, "cinq", 10), ft_strnstr(buf, "cinq", 10));
UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
UT_ASSERT_EQ(strnstr(buf, "9682", 10), ft_strnstr(buf, "9682", 10));
UT_ASSERT_EQ(strnstr(buf, "6", 10), ft_strnstr(buf, "6", 10));
buf[1] = 0;
UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
}
#endif

#ifdef TEST_ft_strrchr
UT_TEST(ft_strrchr)
{
char	buf[] = "abcdedcba";

UT_ASSERT_EQ(strrchr(buf, 'a'), ft_strrchr(buf, 'a'));
UT_ASSERT_EQ(strrchr(buf, 0), ft_strrchr(buf, 0));
UT_ASSERT_EQ(ft_strrchr(buf, 'z'), 0);
buf[5] = 0;
UT_ASSERT_EQ(ft_strrchr(buf, 'a'), buf);
}
#endif

#ifdef TEST_ft_strrev
UT_TEST(ft_strrev)
{
char	buf1[] = "123456";
char	buf2[] = "12345";
char	buf3[] = "1";
char	buf4[] = "";

UT_ASSERT_EQ(strcmp(ft_strrev(buf1), "654321"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf2), "54321"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf3), "1"), 0);
UT_ASSERT_EQ(strcmp(ft_strrev(buf4), ""), 0);
}
#endif

#ifdef TEST_ft_strsplit
UT_TEST(ft_strsplit)
{
char	**tt;

tt = ft_strsplit("***salut****!**", '*');
UT_ASSERT_EQ(strcmp(tt[0], "salut"), 0);
UT_ASSERT_EQ(strcmp(tt[1], "!"), 0);
UT_ASSERT_EQ(tt[2], NULL);

tt = ft_strsplit("*****", '*');
UT_ASSERT_EQ(tt[0], NULL);

tt = ft_strsplit("coucou", '*');
UT_ASSERT_EQ(strcmp(tt[0], "coucou"), 0);
UT_ASSERT_EQ(tt[1], NULL);

tt = ft_strsplit("", '*');
UT_ASSERT(tt &&  tt[0] == NULL);

ft_strsplit(NULL, 0);

}
#endif

#ifdef TEST_ft_strstr
UT_TEST(ft_strstr)
{
char	buf[] = "Ceci n'est pas une pipe.";
char	buf2[] = "ozarabozaraboze";

UT_ASSERT_EQ(strstr(buf, "une"), ft_strstr(buf, "une"));
UT_ASSERT_EQ(strstr(buf, "C"), ft_strstr(buf, "C"));
UT_ASSERT_EQ(strstr(buf, "."), ft_strstr(buf, "."));
UT_ASSERT_EQ(strstr(buf, ""), ft_strstr(buf, ""));
UT_ASSERT_EQ(strstr(buf, "aaaaa"), ft_strstr(buf, "aaaaa"));
UT_ASSERT_EQ(strstr(buf2, "ozaraboze"), ft_strstr(buf2, "ozaraboze"));
UT_ASSERT_EQ(ft_strstr(buf, "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"), NULL);
UT_ASSERT(strstr("", "") == ft_strstr("", ""));

}
#endif

#ifdef TEST_ft_strsub
UT_TEST(ft_strsub)
{
char	*str;

str = "Un jour je serai, le meilleur dresseur !";
UT_ASSERT_EQ(ft_strsub(str, 0, (size_t)-10), NULL);
UT_ASSERT_EQ(strcmp(ft_strsub(str, 8, 8), "je serai"), 0);
UT_ASSERT_EQ(strcmp(ft_strsub(str, 0, 0), ""), 0);
}
#endif

#ifdef TEST_ft_strtrim
UT_TEST(ft_strtrim)
{
UT_ASSERT_EQ(strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB"), 0);
UT_ASSERT_EQ(strcmp(ft_strtrim("\t\t\n\t\t   "), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrim(""), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrim("abc"), "abc"), 0);

ft_strtrim(NULL);

}
#endif

#ifdef TEST_ft_strtrimc
UT_TEST(ft_strtrimc)
{
UT_ASSERT_EQ(strcmp(ft_strtrimc("*****AAA*****BBB*****", '*'), "AAA*****BBB"), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("**********", '*'), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("", '*'), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strtrimc("abc", '*'), "abc"), 0);
}
#endif

#ifdef TEST_ft_strupcase
UT_TEST(ft_strupcase)
{
ft_strupcase(NULL);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("")), ""), 0);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("aaa")), "AAA"), 0);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("zzz")), "ZZZ"), 0);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("AAA")), "AAA"), 0);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("ZZZ")), "ZZZ"), 0);
UT_ASSERT_EQ(strcmp(ft_strupcase(strdup("aBcDeé9123'47289")), "ABCDEé9123'47289"), 0);
}
#endif

#ifdef TEST_ft_swap
UT_TEST(ft_swap)
{
int test_swap1 = 24;
int test_swap2 = 42;
ft_swap(&test_swap1, &test_swap2);
UT_ASSERT_EQ(test_swap1, 42);
UT_ASSERT_EQ(test_swap2, 24);
}
#endif

#ifdef TEST_ft_tolower
UT_TEST(ft_tolower)
{
UT_ASSERT_EQ(ft_tolower('T'), 't');
UT_ASSERT_EQ(ft_tolower(99999), 99999);
UT_ASSERT_EQ(ft_tolower('e'), 'e');
}
#endif

#ifdef TEST_ft_toupper
UT_TEST(ft_toupper)
{
UT_ASSERT_EQ(ft_toupper('a'), 'A');
UT_ASSERT_EQ(ft_toupper(12345), 12345);
UT_ASSERT_EQ(ft_toupper(' '), ' ');
UT_ASSERT_EQ(ft_toupper('Z'), 'Z');
}
#endif


int	main(void)
{

#ifdef TEST_ft_abs
	UT_ADD_TEST(ft_abs);
#endif

#ifdef TEST_ft_atoi
	UT_ADD_TEST(ft_atoi);
#endif

#ifdef TEST_ft_bzero
	UT_ADD_TEST(ft_bzero);
#endif

#ifdef TEST_ft_factorial
	UT_ADD_TEST(ft_factorial);
#endif

#ifdef TEST_ft_isalnum
	UT_ADD_TEST(ft_isalnum);
#endif

#ifdef TEST_ft_isalpha
	UT_ADD_TEST(ft_isalpha);
#endif

#ifdef TEST_ft_isascii
	UT_ADD_TEST(ft_isascii);
#endif

#ifdef TEST_ft_isblank
	UT_ADD_TEST(ft_isblank);
#endif

#ifdef TEST_ft_isdigit
	UT_ADD_TEST(ft_isdigit);
#endif

#ifdef TEST_ft_islower
	UT_ADD_TEST(ft_islower);
#endif

#ifdef TEST_ft_isprint
	UT_ADD_TEST(ft_isprint);
#endif

#ifdef TEST_ft_ispunct
	UT_ADD_TEST(ft_ispunct);
#endif

#ifdef TEST_ft_isspace
	UT_ADD_TEST(ft_isspace);
#endif

#ifdef TEST_ft_isupper
	UT_ADD_TEST(ft_isupper);
#endif

#ifdef TEST_ft_itoa
	UT_ADD_TEST(ft_itoa);
#endif

#ifdef TEST_ft_lstadd
	UT_ADD_TEST(ft_lstadd);
#endif

#ifdef TEST_ft_lstdel
	UT_ADD_TEST(ft_lstdel);
#endif

#ifdef TEST_ft_lstdelone
	UT_ADD_TEST(ft_lstdelone);
#endif

#ifdef TEST_ft_lstiter
	UT_ADD_TEST(ft_lstiter);
#endif

#ifdef TEST_ft_lstmap
	UT_ADD_TEST(ft_lstmap);
#endif

#ifdef TEST_ft_lstnew
	UT_ADD_TEST(ft_lstnew);
#endif

#ifdef TEST_ft_memalloc
	UT_ADD_TEST(ft_memalloc);
#endif

#ifdef TEST_ft_memccpy
	UT_ADD_TEST(ft_memccpy);
#endif

#ifdef TEST_ft_memchr
	UT_ADD_TEST(ft_memchr);
#endif

#ifdef TEST_ft_memcmp
	UT_ADD_TEST(ft_memcmp);
#endif

#ifdef TEST_ft_memcpy
	UT_ADD_TEST(ft_memcpy);
#endif

#ifdef TEST_ft_memdel
	UT_ADD_TEST(ft_memdel);
#endif

#ifdef TEST_ft_memdup
	UT_ADD_TEST(ft_memdup);
#endif

#ifdef TEST_ft_memmove
	UT_ADD_TEST(ft_memmove);
#endif

#ifdef TEST_ft_memset
	UT_ADD_TEST(ft_memset);
#endif

#ifdef TEST_ft_memswap
	UT_ADD_TEST(ft_memswap);
#endif

#ifdef TEST_ft_nrot
	UT_ADD_TEST(ft_nrot);
#endif

#ifdef TEST_ft_power
	UT_ADD_TEST(ft_power);
#endif

#ifdef TEST_ft_printable_rotone
	UT_ADD_TEST(ft_printable_rotone);
#endif

#ifdef TEST_ft_ptrswap
	UT_ADD_TEST(ft_ptrswap);
#endif

#ifdef TEST_ft_putchar
	UT_ADD_TEST(ft_putchar);
#endif

#ifdef TEST_ft_putchar_fd
	UT_ADD_TEST(ft_putchar_fd);
#endif

#ifdef TEST_ft_putendl
	UT_ADD_TEST(ft_putendl);
#endif

#ifdef TEST_ft_putendl_fd
	UT_ADD_TEST(ft_putendl_fd);
#endif

#ifdef TEST_ft_putnbr
	UT_ADD_TEST(ft_putnbr);
#endif

#ifdef TEST_ft_putnbr_fd
	UT_ADD_TEST(ft_putnbr_fd);
#endif

#ifdef TEST_ft_putnendl
	UT_ADD_TEST(ft_putnendl);
#endif

#ifdef TEST_ft_putnstr
	UT_ADD_TEST(ft_putnstr);
#endif

#ifdef TEST_ft_putstr
	UT_ADD_TEST(ft_putstr);
#endif

#ifdef TEST_ft_putstr_fd
	UT_ADD_TEST(ft_putstr_fd);
#endif

#ifdef TEST_ft_replace_char
	UT_ADD_TEST(ft_replace_char);
#endif

#ifdef TEST_ft_rotone
	UT_ADD_TEST(ft_rotone);
#endif

#ifdef TEST_ft_sort_int_table
	UT_ADD_TEST(ft_sort_int_table);
#endif

#ifdef TEST_ft_sqrt
	UT_ADD_TEST(ft_sqrt);
#endif

#ifdef TEST_ft_strcapitalize
	UT_ADD_TEST(ft_strcapitalize);
#endif

#ifdef TEST_ft_strcat
	UT_ADD_TEST(ft_strcat);
#endif

#ifdef TEST_ft_strchr
	UT_ADD_TEST(ft_strchr);
#endif

#ifdef TEST_ft_strclr
	UT_ADD_TEST(ft_strclr);
#endif

#ifdef TEST_ft_strcmp
	UT_ADD_TEST(ft_strcmp);
#endif

#ifdef TEST_ft_strcpy
	UT_ADD_TEST(ft_strcpy);
#endif

#ifdef TEST_ft_strdel
	UT_ADD_TEST(ft_strdel);
#endif

#ifdef TEST_ft_strdup
	UT_ADD_TEST(ft_strdup);
#endif

#ifdef TEST_ft_strequ
	UT_ADD_TEST(ft_strequ);
#endif

#ifdef TEST_ft_striter
	UT_ADD_TEST(ft_striter);
#endif

#ifdef TEST_ft_striteri
	UT_ADD_TEST(ft_striteri);
#endif

#ifdef TEST_ft_strjoin
	UT_ADD_TEST(ft_strjoin);
#endif

#ifdef TEST_ft_strlcat
	UT_ADD_TEST(ft_strlcat);
#endif

#ifdef TEST_ft_strlen
	UT_ADD_TEST(ft_strlen);
#endif

#ifdef TEST_ft_strlowcase
	UT_ADD_TEST(ft_strlowcase);
#endif

#ifdef TEST_ft_strmap
	UT_ADD_TEST(ft_strmap);
#endif

#ifdef TEST_ft_strmapi
	UT_ADD_TEST(ft_strmapi);
#endif

#ifdef TEST_ft_strncat
	UT_ADD_TEST(ft_strncat);
#endif

#ifdef TEST_ft_strncmp
	UT_ADD_TEST(ft_strncmp);
#endif

#ifdef TEST_ft_strncpy
	UT_ADD_TEST(ft_strncpy);
#endif

#ifdef TEST_ft_strnequ
	UT_ADD_TEST(ft_strnequ);
#endif

#ifdef TEST_ft_strnew
	UT_ADD_TEST(ft_strnew);
#endif

#ifdef TEST_ft_strnstr
	UT_ADD_TEST(ft_strnstr);
#endif

#ifdef TEST_ft_strrchr
	UT_ADD_TEST(ft_strrchr);
#endif

#ifdef TEST_ft_strrev
	UT_ADD_TEST(ft_strrev);
#endif

#ifdef TEST_ft_strsplit
	UT_ADD_TEST(ft_strsplit);
#endif

#ifdef TEST_ft_strstr
	UT_ADD_TEST(ft_strstr);
#endif

#ifdef TEST_ft_strsub
	UT_ADD_TEST(ft_strsub);
#endif

#ifdef TEST_ft_strtrim
	UT_ADD_TEST(ft_strtrim);
#endif

#ifdef TEST_ft_strtrimc
	UT_ADD_TEST(ft_strtrimc);
#endif

#ifdef TEST_ft_strupcase
	UT_ADD_TEST(ft_strupcase);
#endif

#ifdef TEST_ft_swap
	UT_ADD_TEST(ft_swap);
#endif

#ifdef TEST_ft_tolower
	UT_ADD_TEST(ft_tolower);
#endif

#ifdef TEST_ft_toupper
	UT_ADD_TEST(ft_toupper);
#endif

	UT_RUN_ALL_TESTS();
	return (0);
}
