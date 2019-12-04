#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int adjecent(int i)
{
	int d1 = i / 100000;
	int d2 = i / 10000 - d1 * 10;
	int d3 = i / 1000 - d1 * 100 - d2 * 10;
	int d4 = i / 100 - d1 * 1000 - d2 * 100 - d3 * 10;
	int d5 = i / 10 - d1 * 10000 - d2 * 1000 - d3 * 100 - d4 * 10;
	int d6 = i / 1 - d1 * 100000 - d2* 10000 - d3 * 1000 - d4 * 100 - d5 * 10;


	if ((d1 == d2 && d2 != d3)
	   || (d2 == d3 && d1 != d2 && d3 != d4)
	   || (d3 == d4 && d2 != d3 && d4 != d5)
	   || (d4 == d5 && d3 != d4 && d5 != d6)
	   || (d5 == d6 && d4 != d5)) return 1;

	return 0;
}

int increases(int i)
{
	int d1 = i / 100000;
	int d2 = i / 10000 - d1 * 10;
	int d3 = i / 1000 - d1 * 100 - d2 * 10;
	int d4 = i / 100 - d1 * 1000 - d2 * 100 - d3 * 10;
	int d5 = i / 10 - d1 * 10000 - d2 * 1000 - d3 * 100 - d4 * 10;
	int d6 = i / 1 - d1 * 100000 - d2* 10000 - d3 * 1000 - d4 * 100 - d5 * 10;

	if (d1 <= d2 && d2 <= d3 && d3 <= d4 && d4 <= d5 && d5 <= d6) return 1;

	return 0;
}

int main()
{
	int possible = 0;
	for (int i = 248345; i <= 746315; i++) {
		if (!adjecent(i)) continue;
		if (!increases(i)) continue;
		possible++;
	}
	printf("possible: %d\n", possible);
}
