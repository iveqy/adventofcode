#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * inf;
	inf = fopen("input.txt", "r");
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	int total = 0;
	while ((read = getline(&line, &len, inf)) != -1) {
		int nbr = atoi(line);
		nbr = nbr / 3;
		nbr -= 2;
		// Calc fuel
		int fuel = nbr;
		while (fuel) {
			fuel /= 3;
			fuel -= 2;
			if (fuel < 0) break;
			nbr += fuel;
		}
		total += nbr;
	}
	printf("total: %d\n", total);


	fclose(inf);
	return 0;
}
