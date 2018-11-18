#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * sterg(char * p, int poz, int cate)
{
	//strcpy(p + poz, p + poz + cate);
	return p;
}

int main()
{
	char * test = "Ana are mere";
	char * x = sterg(test, 3, 3);
	printf("%s\n", x);
}
