#include <stdio.h>
#include <string.h>
#include <ctype.h>

static inline int letterval(char c)
{
	c = toupper(c);
	return
		c == 'I' ? 1 :
		c == 'V' ? 5 :
		c == 'X' ? 10 :
		c == 'L' ? 50 :
		c == 'C' ? 100 :
		c == 'D' ? 500 :
		c == 'M' ? 1000 : 0;
}

static int roman(char *s)
{
	char *r = s + strlen(s);
	int v = 0, p = 0;

	while (--r >= s) {
		int d = letterval(*r);
		if (!d) {
			printf("%c not roman!\n", *r);
			return 0;
		}

		if (d < p)
			v -= d;
		else
			v += d, p = d;
	}
	return v;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("%10s = %d\n", *argv, roman(*argv));
	return 0;
}

