#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Problema1()
{
        FILE * out = fopen("output.out", "w");
	
	if (out == NULL)
	{
		printf("File could not open\n");
		return;
	}

        int n;
        char buffer[256];

        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
        {       
                fgets(buffer, 256, stdin);
                fprintf(out, "%s", buffer);
        }

        fclose(out);
}

void Problema2()
{
	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");
	char buffer[256];

	if (in == NULL || out == NULL)
	{
		printf("File could not open\n");
		return;
	}
	
	
	while (fgets(buffer, 256, in))
		fprintf(out, "%s", buffer);

	fclose(in);
	fclose(out);
}

void Problema3()
{
	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");

	if (in == NULL || out == NULL)
	{
		printf("Files could not open\n");
		return;
	}

	char buffer[256], k = 0;
	while (fgets(buffer, 256, in))
		k++;
	
	fseek(in, 0, SEEK_SET);
	fflush(in);

	char full_file[k][256];
	for (int i = 0; i < k; i++)
		fgets(full_file[i], 256, in);

	for (int i = k - 1; i >= 0; i--)
		fprintf(out, "%s", full_file[i]);
	
	printf("Fisierul are %d linii\n", k);
	fclose(in);
	fclose(out);
}

int main()
{
	// Problema1();
	// Problema2();
	Problema3();

	return 0;
}
