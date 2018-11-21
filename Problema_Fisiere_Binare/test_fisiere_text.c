#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Client {
	int IBAN;
	char nume[30];
	unsigned char stare_civila : 1;
	unsigned char bit_paritate : 1;
} Client;

void Problema1();
int Problema2(int IBAN);
void Problema3();
void Problema4(const char * nume_fisier);

int main()
{
	Problema1();
}

void Problema1()
{
	FILE * out = fopen("baza_de_date.txt", "w");
	
	if (out == NULL)
	{
		printf("Fisierul nu s-a putut deschide");
		return;
	}

	int n;
	scanf("%d", &n);

	Client * tmp = (Client *) malloc(sizeof(Client));
	unsigned char bit_paritate, stare_civila; // 'char' pentru alocare eficienta a memoriei

	for (int i = 0; i < n; i++)
	{
		scanf("%30s", tmp -> nume);
		scanf("%d", &(tmp -> IBAN));
		scanf("%c", &stare_civila);

		tmp -> stare_civila = stare_civila;
		bit_paritate = Problema2(tmp -> IBAN);

		fprintf(out, "%s ", tmp -> nume);
		fprintf(out, "%d ", tmp -> IBAN);
		fprintf(out, "%d\n", tmp -> stare_civila);
	}

	free(tmp);
	fclose(out);
}

int Problema2(int IBAN)
{
	int k = 0;
	while (IBAN)
	{
		if ((IBAN & 1) == 1)
			k = ~k;
		IBAN >>= 1;
	}
	return abs(k);
}


void Problema3()
{
	// citire fisier
	FILE * in = fopen("baza_de_date.txt", "r");
	
	if (in == NULL)
	{
		printf("Fisierul nu s-a putut deschide");
		return;
	}	

	Client * clients = (Client *) malloc(10 * sizeof(Client));
	unsigned int stare_civila;
	int k = 0;

	while (!feof(in))
	{
		fscanf(in, "%30s", clients[k].nume);
		fscanf(in, "%d", &(clients[k].IBAN));
		fscanf(in, "%u\n", &stare_civila);
		clients[k++].stare_civila = stare_civila;
	}

	fclose(in);

	// sortare baza de date
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (clients[i].stare_civila > clients[j].stare_civila)
			{
				Client tmp;
				tmp = clients[i];
				clients[i] = clients[j];
				clients[j] = tmp;
			}

	// scriere fisier
	FILE * out = fopen("baza_de_date.txt", "w");

	if (out == NULL)
	{
		printf("Fisierul nu s-a putut deschide");
		return;
	}

	for (int i = 0; i < k; i++)
		fprintf(out, "%s %d %d\n", clients[i].nume, clients[i].IBAN, clients[i].stare_civila);

	free(clients);
	fclose(out);
}

void Problema4(const char * nume_fisier)
{
	FILE * in = fopen(nume_fisier, "r");
	
	if (in == NULL)
	{
		printf("Fisierul nu s-a putut deschide");
		return;
	}


	char * nume = (char *) malloc(30 * sizeof(char));
	char * stare_civila = (char *) malloc(11 * sizeof(char));
	int * IBAN = (int *) malloc(sizeof(int));

	while (!feof(in))
	{
		fscanf(in, "%30s", nume);
		fscanf(in, "%d", IBAN);
		fscanf(in, "%11s\n", stare_civila);  // '\n' folosit pe post de cin.ignore()
		
		if (strchr("AEIOU", *nume) && *stare_civila == 'n')
			printf("%s  %d  %s\n", nume, *IBAN, stare_civila);
	}
	
	free(nume);
	free(IBAN);
	free(stare_civila);
	fclose(in);
}
