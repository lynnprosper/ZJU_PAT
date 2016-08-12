#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void earthTomars(char *s);
void marsToearth(char *s);
typedef char string[10];											//define the type 'string' , so that we can use it conveniently.
char *base[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };	//global variable
char *carry[13] = { "\0", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int main()
{
	
	int n, i;
	scanf("%d", &n);
	string *test = (string *) malloc(sizeof(string) * n);
	getchar();												// to filter the key 'Enter';
	for (i = 0; i < n; i++)
		gets(test[i]);

	for (i = 0; i < n; i++)
	{
		if (test[i][0] >= '0' && test[i][0] <= '9')
			earthTomars(test[i]);
		else
			marsToearth(test[i]);
	}

	return 0;
}

void earthTomars(char *s)
{
	int a, m;
	sscanf(s, "%d", &a);
	if (a < 13)
		printf("%s\n", base[a]);
	else
	{
		m = a / 13;
		printf("%s", carry[m]);
		a %= 13;
		if (a != 0)
			printf(" %s", base[a]);
		printf("\n");
	}
}

void marsToearth(char *s)
{
	int i, flag = 0;
	for (i = 0; i < 13; i++)
	{
		if (strcmp(s, base[i]) == 0)
		{
			printf("%d\n", i);
			flag = 1;
			break;
		}
			
	}
	int sum;
	if (flag == 0)
	{
		for (i = 1; i < 13; i++)
		{
			if (strncmp(s, carry[i], 3) == 0)
				sum = i * 13;		
		}

		if (*(s + 3) != '\0')
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp(s + 4, base[i]) == 0)
					sum += i;
			}
		}
		printf("%d\n", sum);
	}
}
