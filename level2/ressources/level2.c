void	p()
{
	char	tab[64];
	int	EIP;

	fflush(stdout);
	gets(&(tab[0]));
	EIP = *((int*)(&tab + 80));
	if ((EIP & 0xb0000000) == 0xb0000000)
	{
		printf("(%p)\n", (void*)EIP);
		exit(1);
	}
	else
	{
		puts(&(tab[0]));
		strdup(&(tab[0]));
	}
	return ;
}

int	main()
{
	p();
	return (0);
}
