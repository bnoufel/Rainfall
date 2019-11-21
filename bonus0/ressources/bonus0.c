#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *p(char *param1, char *param2)
{
	char tab[4096];

	puts(param2);
	read(0 , &(tab[0]), 4096);
	*strchr(&(tab[0]), '\n') = '\0';
	return (strncpy(param1, &(tab[0]), 20));
}

int pp(char *arg)
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;
	char	var1[20];
	char	var2[16];

	p(&(var1[0]), " - ");
	p(&(var2[0]), " - ");
	strcpy(arg, &(var1[0]));
	strcat(arg, &(var2[0]));
	return (0);
}

int main(int argc, char **argv)
{
	char	param[42];

	pp(&(param[0]));
	puts(&(param[0]));
	return (0);
}
