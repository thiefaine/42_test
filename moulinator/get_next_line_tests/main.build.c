#include <testframework.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>
#include <regex.h>

#define RENDU_PATH "/nfs/zfs-student-2/users/2014_paris/mdubray/GNL_WOLF/"

#define FT_LS_PATH RENDU_PATH"/ft_ls"


UT_TEST(01_test_simple)
{
char 	*line;
int		out;
int		p[2];
int		fd;

fd = 1;
out = dup(fd);
pipe(p);

dup2(p[1], fd);
write(fd, "aaa\nbbb\nccc\nddd\n", 16);
dup2(out, fd);
close(p[1]);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "aaa"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "bbb"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ccc"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ddd"));

}

UT_TEST(02_test_eof_with_close)
{
char *line;
int		out;
int		p[2];
int		fd;
int		gnl_ret;

fd = 1;
out = dup(fd);
pipe(p);
dup2(p[1], fd);
write(fd, "aaa", 3);
close(p[1]);
dup2(out, fd);
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "aaa"));
UT_ASSERT(gnl_ret == 0 || gnl_ret == 1);

}

UT_TEST(03_test_medium_string)
{
char 	*line;
int		out;
int		p[2];
char 	*str;
int		gnl_ret;

str = (char *)malloc(1000 * 1000);
*str = '\0';
strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
out = dup(1);
pipe(p);
dup2(p[1], 1);

write(1, str, strlen(str));
close(p[1]);
dup2(out, 1);
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(strequ(line, str));
UT_ASSERT(gnl_ret == 0 || gnl_ret == 1);
}

UT_TEST(04_test_return_values)
{
/* Thank you bwyyoung for pointing out the problem. */

char 	*line;
int		out;
int		p[2];
int		fd;
int		gnl_ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abc\n\n", 5);
close(p[1]);
dup2(out, fd);

/* Read abc and new line */
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(gnl_ret == 1);
UT_ASSERT(strequ(line, "abc"));

/* Read new line */
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(gnl_ret == 1);
UT_ASSERT(line == NULL || *line == '\0');

/* Read again, but meet EOF */
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(gnl_ret == 0);
UT_ASSERT(line == NULL || *line == '\0');

/* Let's do it once again */
gnl_ret = get_next_line(p[0], &line);
UT_ASSERT(gnl_ret == 0);
UT_ASSERT(line == NULL || *line == '\0');

}

UT_TEST(05_test_error_handling)
{
UT_ASSERT_EQ(get_next_line(-99, NULL), -1);
UT_ASSERT_EQ(get_next_line(-1, NULL), -1);
UT_ASSERT_EQ(get_next_line(1, NULL), -1);
UT_ASSERT_EQ(get_next_line(99, NULL), -1);

char 	*line;
UT_ASSERT_EQ(get_next_line(-99, &line), -1);
UT_ASSERT_EQ(get_next_line(-1, &line), -1);

/* Not opened fd */
UT_ASSERT_EQ(get_next_line(42, &line), -1);

}

UT_TEST(06_test_line_of_08)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "oiuytrew\n", 9);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "oiuytrew"));
}

UT_TEST(07_test_two_lines_of_08)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefgh\n", 9);
write(fd, "ijklmnop\n", 9);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcdefgh"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ijklmnop"));
}

UT_TEST(08_test_few_lines_of_08)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefgh\n", 9);
write(fd, "ijklmnop\n", 9);
write(fd, "qrstuvwx\n", 9);
write(fd, "yzabcdef\n", 9);
write(fd, "ghijklmn\n", 9);
write(fd, "opqrstuv\n", 9);
write(fd, "wxyzabcd\n", 9);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcdefgh"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ijklmnop"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "qrstuvwx"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "yzabcdef"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ghijklmn"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "opqrstuv"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "wxyzabcd"));
}

UT_TEST(09_test_line_of_16)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefghijklmnop\n", 17);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcdefghijklmnop"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(10_test_two_lines_of_16)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefghijklmnop\n", 17);
write(fd, "qrstuvwxyzabcdef\n", 17);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcdefghijklmnop"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "qrstuvwxyzabcdef"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(11_test_few_lines_of_16)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcdefghijklmnop\n", 17);
write(fd, "qrstuvwxyzabcdef\n", 17);
write(fd, "ghijklmnopqrstuv\n", 17);
write(fd, "wxyzabcdefghijkl\n", 17);
write(fd, "mnopqrstuvwxyzab\n", 17);
write(fd, "cdefghijklmnopqr\n", 17);
write(fd, "stuvwxzabcdefghi\n", 17);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcdefghijklmnop"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "qrstuvwxyzabcdef"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ghijklmnopqrstuv"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "wxyzabcdefghijkl"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "mnopqrstuvwxyzab"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "cdefghijklmnopqr"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "stuvwxzabcdefghi"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(12_test_line_of_4)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcd\n", 5);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcd"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(13_test_two_lines_of_4)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcd\n", 5);
write(fd, "efgh\n", 5);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcd"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "efgh"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(14_test_few_lines_of_4)
{
char 	*line;
int		out;
int		p[2];
int		fd;
int		ret;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcd\n", 5);
write(fd, "efgh\n", 5);
write(fd, "ijkl\n", 5);
write(fd, "mnop\n", 5);
write(fd, "qrst\n", 5);
write(fd, "uvwx\n", 5);
write(fd, "yzab\n", 5);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcd"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "efgh"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "ijkl"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "mnop"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "qrst"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "uvwx"));
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "yzab"));
ret = get_next_line(p[0], &line);
UT_ASSERT(ret == 0);
}

UT_TEST(15_test_line_without_nl)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "abcd", 4);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "abcd"));

}

UT_TEST(16_test_line_of_8_without_nl)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "efghijkl", 8);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "efghijkl"));

}

UT_TEST(17_test_line_of_16_without_nl)
{
char 	*line;
int		out;
int		p[2];
int		fd;

out = dup(1);
pipe(p);

fd = 1;
dup2(p[1], fd);
write(fd, "mnopqrstuvwxyzab", 16);
close(p[1]);
dup2(out, fd);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, "mnopqrstuvwxyzab"));

}

UT_TEST(30_bonus_multiple_fd)
{
char 	*line0;
int		p0[2];
int		fd0 = 0;
int		out0 = dup(fd0);
pipe(p0);
dup2(p0[1], fd0);
write(fd0, "aaa\nbbb\n", 12);
dup2(out0, fd0);

char 	*line_fd1;
int		p_fd1[2];
int		fd1 = 1;
int		out_fd1 = dup(fd1);
pipe(p_fd1);
dup2(p_fd1[1], fd1);
write(fd1, "111\n222\n", 12);
dup2(out_fd1, fd1);

char 	*line_fd2;
int		p_fd2[2];
int		fd2 = 2;
int		out_fd2 = dup(fd2);
pipe(p_fd2);
dup2(p_fd2[1], fd2);
write(fd2, "www\nzzz\n", 12);
dup2(out_fd2, fd2);

char 	*line_fd3;
int		p_fd3[2];
int		fd3 = 3;
int		out_fd3 = dup(fd3);
pipe(p_fd3);
dup2(p_fd3[1], fd3);
write(fd3, "888\n999\n", 12);
dup2(out_fd3, fd3);

get_next_line(p0[0], &line0);
UT_ASSERT(strequ(line0, "aaa"));

get_next_line(p_fd1[0], &line_fd1);
UT_ASSERT(strequ(line_fd1, "111"));

get_next_line(p_fd2[0], &line_fd2);
UT_ASSERT(strequ(line_fd2, "www"));

get_next_line(p_fd3[0], &line_fd3);
UT_ASSERT(strequ(line_fd3, "888"));

get_next_line(p0[0], &line0);
UT_ASSERT(strequ(line0, "bbb"));

get_next_line(p_fd1[0], &line_fd1);
UT_ASSERT(strequ(line_fd1, "222"));

get_next_line(p_fd2[0], &line_fd2);
UT_ASSERT(strequ(line_fd2, "zzz"));

get_next_line(p_fd3[0], &line_fd3);
UT_ASSERT(strequ(line_fd3, "999"));

}

UT_TEST(31_bonus_one_static_var)
{
char		path[10000];
FILE		*file;
char		*line = NULL;
size_t		len = 0;
ssize_t		read;
int			static_files_count = 0;
regex_t		regex;
int			reti;

strcpy(path, RENDU_PATH);
strcat(path, "/get_next_line.c");
file = fopen(path, "r");

regcomp(&regex, "static[ \t].*;", 0);

while ((read = getline(&line, &len, file)) != -1) {
	reti = regexec(&regex, line, 0, NULL, 0);
	if (!reti) {
		static_files_count++;
	}
}

UT_ASSERT(static_files_count <= 1);

}

UT_TEST(40_hard_test_medium_string)
{
char 	*line;
int		out;
int		p[2];
char 	*str;
int		len = 50;

str = (char *)malloc(1000 * 1000);
*str = '\0';
while (len--)
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
out = dup(1);
pipe(p);
dup2(p[1], 1);

write(1, str, strlen(str));
close(p[1]);
dup2(out, 1);
get_next_line(p[0], &line);
UT_ASSERT(strequ(line, str));

}

UT_TEST(41_hard_test_large_file)
{
system("mkdir -p sandbox");
system("openssl rand -out sandbox/large_file.txt -base64 $((2**19 * 3/4))");

char *line;
int fd;
int fd2;


fd = open("sandbox/large_file.txt", O_RDONLY);
fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

while (get_next_line(fd, &line) == 1)
{
    write(fd2, line, strlen(line));
    write(fd2, "\n", 1);
}
write(fd2, line, strlen(line));
close(fd);
close(fd2);

int fd3;
int	diff_file_size;
system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
fd3 = open("sandbox/large_file.diff", O_RDONLY);
diff_file_size = read(fd3, NULL, 10);
close(fd3);

UT_ASSERT(diff_file_size == 0);

}

UT_TEST(42_hard_test_one_big_fat_line)
{
system("mkdir -p sandbox");
system("openssl rand -base64 $((2**15 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
system("echo '\n' >> sandbox/one_big_fat_line.txt");

char *line;
int fd;
int fd2;


fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

while (get_next_line(fd, &line) == 1)
{
    write(fd2, line, strlen(line));
    write(fd2, "\n", 1);
}
write(fd2, line, strlen(line));
close(fd);
close(fd2);

int fd3;
int	diff_file_size;
system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
diff_file_size = read(fd3, NULL, 10);
close(fd3);

UT_ASSERT(diff_file_size == 0);

}


int	main(void)
{

UT_ADD_TEST(01_test_simple);

UT_ADD_TEST(02_test_eof_with_close);

UT_ADD_TEST(03_test_medium_string);

UT_ADD_TEST(04_test_return_values);

UT_ADD_TEST(05_test_error_handling);

UT_ADD_TEST(06_test_line_of_08);

UT_ADD_TEST(07_test_two_lines_of_08);

UT_ADD_TEST(08_test_few_lines_of_08);

UT_ADD_TEST(09_test_line_of_16);

UT_ADD_TEST(10_test_two_lines_of_16);

UT_ADD_TEST(11_test_few_lines_of_16);

UT_ADD_TEST(12_test_line_of_4);

UT_ADD_TEST(13_test_two_lines_of_4);

UT_ADD_TEST(14_test_few_lines_of_4);

UT_ADD_TEST(15_test_line_without_nl);

UT_ADD_TEST(16_test_line_of_8_without_nl);

UT_ADD_TEST(17_test_line_of_16_without_nl);

UT_ADD_TEST(30_bonus_multiple_fd);

UT_ADD_TEST(31_bonus_one_static_var);

UT_ADD_TEST(40_hard_test_medium_string);

UT_ADD_TEST(41_hard_test_large_file);

UT_ADD_TEST(42_hard_test_one_big_fat_line);


	UT_RUN_ALL_TESTS();
	return (0);
}
