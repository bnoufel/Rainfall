#include <iostream>
#include <cstring>
#include <unistd.h>

class N
{
        public:
			N(int x) : nb(x)
			{
			}
			void setAnnotation(char *a)
			{
				memcpy(annotation, a, strlen(a));
			}
			virtual int operator+(N &r)
			{
				return nb + r.nb;
			}
			virtual int operator-(N &r)
			{
				return nb - r.nb
			}
        private:
			char annotation[100];
			int nb;
};

int main(int ac, char **av)
{
	if (ac > 2) exit(1);
	N *var1 = new N(5);
	N *var2 = new N(6);
	N &var3 = *var1, &var4 = *var2;

	var3.setAnnotation(argv[1]);

	return var3 + var4;
}
