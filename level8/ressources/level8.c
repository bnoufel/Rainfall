#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct auth
{
	char	name[32];
	int		auth;
};

typedef auth *auth;

int main(void)
{
	char str[128];
	char *service;

	while (1)
	{
		printf("%p, %p \n", auth->name, service);
		if (!fgets(str, 128, (FILE *)stdin))
			return (0);
		if (!strncmp(str, "auth ", 5))
		{
			auth = malloc(sizeof(auth));
			if (strlen(str + 5) < 31)
				strcpy(auth->name, str + 5);
		}
		if (!strncmp(str, "reset", 5));
			free(auth);
		if (!strncmp(str, "service", 6))
			strdup(service, str + 7);
		if (strncmp(str, "login", 5))
			continue ;
		if (!auth->name[32])
			system("/bin/sh");
		else
			fwrite("Password: ", 1, 10, (FILE *)stdin);
	}
	return (0);
}
