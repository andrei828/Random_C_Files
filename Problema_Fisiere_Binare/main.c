#include <stdlib.h>
#include <stdio.h>

void readDataInFile(const char * file_name);
void splitDataInFiles(const char * file_name);

int main()
{
	// readDataInFile("input.txt");
	splitDataInFiles("input.txt");
}

void splitDataInFiles(const char * file_name)
{
	FILE *in, *out1, *out2;
	in = fopen(file_name, "r");
	out1 = fopen("output1.txt", "wb");
	out2 = fopen("output2.txt", "wb");

	if (in == NULL || out1 == NULL || out2 == NULL)
	{
		printf("File could not open");
		return;
	}

	int n, tmp;
	fscanf(in, "%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%d", &tmp);
		
		if (tmp < 0)
			fwrite(&tmp, sizeof(int), 1, out1);
		else
			fwrite(&tmp, sizeof(int), 1, out2);
	}
	
	fclose(in);
	fclose(out1);
	fclose(out2);
}

void readDataInFile(const char * file_name)
{
	int n, tmp;
	FILE * in = fopen(file_name, "w");
	
	if (in == NULL)
	{
		printf("File could not open");
		return;
	}

	scanf("%d", &n);
	fprintf(in, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		fprintf(in, "%d\n", tmp);
	}
	fclose(in);
}
