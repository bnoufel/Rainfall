int language = 0;

int greetuser(char *param1)
{
	char tmp[72];

	if (language == 1)
		memcpy(tmp, "Hyvää päivää ", 19);	// fake
	else if (language == 2)
		memcpy(tmp, "Goedemiddag! ", 14);	// fake
	else if (language == 0)
		memcpy(&(tmp[0]), "Hello ", 7)		// fake
	strcat(tmp, param1);
	puts(tmp);
}

int main(int ac, char **av)
{
	char	buf2[72];				// esp + 0  -> esp + 48
	char	buf[72];				// esp + 50 -> esp + 98
	char	envvar;					// esp + 9c -> esp + a0

	if (ac != 3)
		return (1);
	bzero(&(buf2[0]), 72);				// fake
	strncpy(&(buf[0]), av[1], 40);
	strncpy(&(buf[40]), av[2], 32);
	envvar = getenv("LANG");
	if (*envvar != '\0')
	{
		if (!memcmp(envvar, "fi", 2))
			language = 1;
		else if (!memcmp(envvar, "nl", 2))
			language = 2;
	}
	i = 0;
	memcpy(&(buf2[0]), &(buf[0]));			// fake
	return (greetuser(&(buf2[0])));
}
