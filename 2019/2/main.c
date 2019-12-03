#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFLEN 256

int main()
{
	FILE * inf;
	char * line = NULL;
	size_t len = 0;
	int buff[BUFFLEN];


	int j = 0; 
	int k = 0;
	while (buff[0] != 19690720) {
		for (int i = 0; i < BUFFLEN; i++) { buff[i] = 0; }

		inf = fopen("input.txt", "r");
		getline(&line, &len, inf);
		fclose(inf);

		char* token;
		int var;
		token = strtok(line, ",");
		int i = 0;
		while (token != NULL) {
			sscanf(token, "%d", &var);
			token = strtok(NULL, ",");
			buff[i] = var;
			i++;
		}

		buff[1] = j;
		buff[2] = k;

		for (int i = 0; i < BUFFLEN; i += 4) {
			if (buff[i] == 99) break;

			int p1 = buff[i + 1], p2 = buff[i + 2], p3 = buff[i + 3];
			if (p1 > BUFFLEN - 1 || p2 > BUFFLEN - 1|| p3 > BUFFLEN - 1) break;

			if (buff[i] == 1) {
				buff[p3] = buff[p1] + buff[p2];
			} else if (buff[i] == 2) {
				buff[p3] = buff[p1] * buff[p2];
			}

		}
		printf("value: %d, buff[0]: %d j: %d, k: %d\n", buff[1] * 100 + buff[2], buff[0], j, k);
		if (j > 99) {
			j = 0;
			k++;
		} else {
			j++;
		}
		if (j > 99 && k > 99) {
			printf("FAIL\n");
			break;
		}
	} 

	return 0;
}
