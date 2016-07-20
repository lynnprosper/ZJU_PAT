#include <stdio.h>
#include <string.h>
//core key: naPnbTnc, na * nb = nc.(na means the counts of 'A')

int main()
{
	int n,i, j, lp, lt, cntp, cntt, other, len;
	i = j = 0;
	char s[9][102];

	scanf("%d\n", &n);
	for (i = 0; i < n; i++)		// input strings;
		gets(s[i]);

	for (i = 0; i < n; i++)		// judge yes or no;
	{
		len = strlen(s[i]);
		lp = lt = cntp = cntt = other = 0;
		for (j = 0; j < len; j++)
		{
			if (s[i][j] == 'P')		
			{						//cntp: 'p' counts;
				lp = j;				//lp: the location of 'P';
				cntp++;
			}
			else if (s[i][j] == 'T')
			{
				lt = j;
				cntt++;
			}
			else if (s[i][j] != 'A')
				other++;			//ohter: other character's counts;
		}

		if (other > 0 || cntp != 1 || cntt != 1 || lt - lp < 2)
			printf("NO\n");
		else if (lp * (lt - lp - 1) != (len-lt-1))
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
