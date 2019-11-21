#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char			*c;

typedef struct	stru
{
	int			nb;
	void		*ptr;
}				t_stru;

void	m(void)
{
	printf("%s - %d\n", c, time(NULL));
	return ;
}

int main(int ac, char **av)
{
	FILE	*fd;
	t_stru	*p1 = malloc(sizeof(t_stru));
	p1->nb = 1;
	p1->ptr = malloc(8);
	
	t_stru	*p2 = malloc(sizeof(t_stru));
	p2->nb = 2;
	p2->ptr = malloc(8);

	strcpy(p1->ptr, av[1]);
	strcpy(p2->ptr, av[2]);
	fd = fopen("/home/user/level8/.pass", "r");
	fgets(c, 68, fd);
	puts("~~");
	return (0);
}
