#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"
#include <limits.h>
#include <math.h>

/**
 * main - fonction give pq of n
 * @file: file with n numbers
 * Return: 0 if succed or 1 if fail.
 */

int main(int argc, char *argv[])
{
	FILE* fichier = NULL;
	unsigned long long int ktab[45], tab[45], tab2[45];
	unsigned long long int i = 0, n = 2, j = 0, p, t = 0, a;
	int chiffre_actuel = 0;

	(void)argc;

	fichier = fopen(argv[1], "r");
	if (fichier != NULL)
	{
		do
		{
			chiffre_actuel = fgetc(fichier);
			if (chiffre_actuel == '\n'|| chiffre_actuel == EOF)
			{
				printtab(tab, i);
				n = 2, t = 0, j = 0, p = 0, a = 1;
				while (p < 44)
				{
					tab2[p] = tab[p];
					p++;
				}
				for (int m = 0; m < 44; m++)
					ktab[m] = 0;
				while ((tab2[i-1] != 0 || j != i-1) || a == 1)
				{
					a = 0;
					if (tab2[j] >= n)
					{
					        tab2[j] -=n;
						ktab[j] += 1;
						continue;
					}
					else if (tab2[j] == 0)
					{
						j++;
						continue;
					}
					else if (tab2[j] < n && j < i-1)
					{
						tab2[j+1] = tab2[j]*10 + tab2[j+1], tab2[j] = 0;
						t++;
						j++;
						continue;
					}
					p = 0;
					while (p < 44)
					{
						tab2[p] = tab[p];
						p++;
					}
					n++, j = 0;
					for (int m = 0; m < 44; m++)
						ktab[m] = 0;
					}
				printf("=");
				printtab(ktab, i);
				printf("*%lld\n", n);
				i = 0;
				for (int m = 0; m < 44; m++)
					tab[m] = 0;
				for (int m = 0; m < 44; m++)
					tab2[m] = 0;
			}
			else
			{
				tab[i] = chiffre_actuel - 48;
				i++;
			}
		}while (chiffre_actuel != EOF);
		fclose(fichier);
	}
	return (0);
}
void printtab(unsigned long long int tab[],unsigned long long int t)
{
	int i = 0, a = 0;

	while (t > 0)
	{
		if (a == 1)
		{
		        printf("%lld", tab[i]);
		}
		else if (tab[i] != 0 || a == 1)
		{
			a = 1;
			printf("%lld", tab[i]);
		}
		t--;
		i++;
	}
}
