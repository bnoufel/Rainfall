#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int res;
	char *shell;
	int uid;
	int gid;

	res = atoi(argv[1]);
	if (res == 423)
	{
		shell = strdup("/bin/sh");
		uid = geteuid();
		gid = getegid();
		execv("/bin/sh", &shell);
	}
	else
	{
		fwrite("No !\n", 1, 5, (FILE *)stderr);
	}
	return 0;
}