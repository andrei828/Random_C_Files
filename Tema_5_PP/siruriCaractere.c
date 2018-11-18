#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * sterg(const char * p, int poz, int cate)
{
	char * result = (char *) malloc(strlen(p) - cate + 1);
	strncpy(result, p, poz + 1);
	strcat(result, p + poz + cate + 1);
	return result;
}

char * inserez(char * p, char * s, int poz)
{
	char * result = (char *) malloc(strlen(s) - poz + 1);
	strncpy(result, p, poz + 1);
	strcat(result, s);
	return result;
}

char * replace(char * a, char * b, char * text)
{
	char * result = (char *) malloc(sizeof(strlen(text)) + strlen(b) + 1);
	char * tmp, * buffer;

	while ((tmp = strstr(text, a)))
	{
		strncat(result, text, tmp - text);
		strcat(result, b);
		text = tmp + strlen(a);
	}
	strcat(result, text);
	
	return result;
}

void fraza_pe_rand(char text[])
{
	char * word = strtok(text, " ,");

	while (word)
	{
		printf("%s\n", word);
		word = strtok(NULL, " ,");
	}
}

int main()
{
	char * test = "Ana are mere are pere";
	char * insert = "testing";
	char * tmp = "are";
	char test_strtok[] = "Acesta este doar un, test";
	
	//char * x = replace(tmp, insert, test);
	//char * x = inserez(test, insert, 4);
	//char * x = sterg(test, 3, 3);
	fraza_pe_rand(test_strtok);

	return 0;
}
