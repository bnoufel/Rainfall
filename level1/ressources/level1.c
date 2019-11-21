#include <stdio.h>
#include <stdlib.h>
void run()
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

int main()
{
	char tmp[64];
	gets(tmp);
	return 0;
}
