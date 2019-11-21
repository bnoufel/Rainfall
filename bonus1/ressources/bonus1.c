int main(int ac. char **av)
{
	char str[40];
	int ret;

	ret = atoi(av[1]);
	if (ret <= 9)
	{
		ret = ret * 4 + 0;
		memcpy(str, av[2], ret)
		if (ret == 0x574f4c46)
			execl("/bin/sh", "sh");
		return 0;
	}
	return 1;
}
