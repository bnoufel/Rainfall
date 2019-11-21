#include <stdio.h>
#include <stdlib.h>

int m = 0;

void p(char *str) {
	printf(str);
}

void n() {
	char	buff[512];

	fgets(&(buff[0]), 512, (FILE *)stdin);
	p(buff);
	if (m == 16930116)
		system("/bin/cat /home/user/level5/.pass");
}

int main() {
	n();
	return (0);
}
