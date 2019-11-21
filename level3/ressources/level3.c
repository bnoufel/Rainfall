#include <stdio.h>
#include <stdlib.h>

int	m = 0;

void		v()
{
	char	buff[512];
	fgets(&(buff[0]), 512, (FILE *)stdin);
	printf(buff);
	if (m == 64) {
		fwrite("Wait what?!\n", 1, 13, (FILE *)stdin);
		system("/bin/sh");
	}
}

int main()
{
	v();
	return 0;
}
