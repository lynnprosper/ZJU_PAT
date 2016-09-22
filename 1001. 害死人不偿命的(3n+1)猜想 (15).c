#include <stdio.h>

int main()
{
	int n;
	int cnt = 0;

	scanf("%d", &n);
	if (n > 0 && n <= 1000)
	{
		while (n != 1)				// while loop, count the times.
		{
			if (n % 2 == 0)
				n = n / 2;
			else
				n = (n * 3 + 1) / 2;
			cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
