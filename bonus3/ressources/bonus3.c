int	main(int ac, char **av)
{
	char	buf[128]		// esp + 18 -> esp + 98
	int	fd;			// esp + 9c

	fd = fopen("/home/user/end/.pass", "r");
	bzero(&(buf[0]), 128);		// fake
	if (!fd || ac != 2)
		return (-1);
	fread(&(buf[0]), 1, 66, fd);
	buf[65] = '\0';
	buf[atoi(av[1])] = 0;		// really 4 bytes
	fread(&(buf[66]), 1, 65, fd);
	fclose(fd);
	if (!strcmp(buf, av[1]))
		execl("/bin/sh", "sh", NULL);
	return (puts(&(buf[66])));
}
