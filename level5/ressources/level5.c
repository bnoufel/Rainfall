#include <stdlib.h>
#include <stdio.h>

void	o()
{
	system("/bin/sh");
}

void	n()
{
	char	buff[512];

	fgets(&(buff[0]), 512, (FILE*)stdin);
	printf(buff);
	exit(1);
}

int	main(void)
{
	n();
	return 0;
}
