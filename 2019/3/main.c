#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUFFLEN 19096
//#define BUFFLEN 20

size_t calc_md(int x, int y)
{
	size_t orig_x = BUFFLEN / 2;
	size_t orig_y = BUFFLEN / 2;
	size_t x_diff, y_diff;
	if (orig_x > x) x_diff = orig_x - x;	
	else x_diff = x - orig_x;;

	if (orig_y > y) y_diff = orig_y - y;
	else y_diff = y - orig_y;
	size_t res = x_diff + y_diff;
	printf("calc_md : %lu\n", res);
	return res;
}

int main()
{
	FILE * inf;
	char * line = NULL;
	size_t len = 0;
	long long * buff = malloc(sizeof(long long) * BUFFLEN * BUFFLEN);
	for (size_t i = 0; i < BUFFLEN; i++)
		for (size_t j = 0; j < BUFFLEN; j++)
			*(buff + i * BUFFLEN + j) = 0;

	inf = fopen("input.txt", "r");
	int reset = 0;
	size_t min_dist = INT_MAX;
	size_t min_steps = INT_MAX;
	int line_nbr = 1;
	int l = 0;
	while (getline(&line, &len, inf) > 0) {

		char * token;
		token = strtok(line, ",");
		size_t x = BUFFLEN / 2;
		size_t y = BUFFLEN / 2;
		*(buff + x * BUFFLEN + y) = 'o';
		while (token != NULL) {
			size_t toklen = strlen(token);
			if (token[toklen - 1] == '\n') {
				token[toklen - 1] = '\0';
				reset = 1;
			}
			printf("token: |%s|\n", token);
			size_t dist = 0;
			printf("x: %lu, y: %lu \n", x, y);
			switch(token[0]) {
				case 'R':
					if (*(buff + x * BUFFLEN + y) != 'o') *(buff + x * BUFFLEN + y) = l;
					dist = atoi(++token);
					for (int i = x + 1; i <= x + dist; i++) {
						l++;
						if (*(buff + i * BUFFLEN + y) > 0 && *(buff + i * BUFFLEN + y) != 'o') {
							*(buff + i * BUFFLEN + y) += l;
							size_t md = calc_md(i, y);
							if (md < min_dist) min_dist = md;
							if (*(buff + i * BUFFLEN + y) < min_steps) min_steps = *(buff + i * BUFFLEN + y);
						} else if (*(buff + i * BUFFLEN + y) != 'o')
							if (line_nbr == 1) *(buff + i * BUFFLEN + y) = l * -1;;
					}
					x = x + dist;
				break;
				case 'L':
					if (*(buff + x * BUFFLEN + y) != 'o') *(buff + x * BUFFLEN + y) = l;
					dist = atoi(++token);
					for (int i = x - 1; i >= x - dist; i--) {
						l++;
						if (*(buff + i * BUFFLEN + y) > 0 && *(buff + BUFFLEN * i + y) != 'o') {
							*(buff + i * BUFFLEN + y) += l;
							size_t md = calc_md(i, y);
							if (md < min_dist) min_dist = md;
							if (*(buff + i * BUFFLEN + y) < min_steps) min_steps = *(buff + i * BUFFLEN + y);
						} else if (*(buff + i * BUFFLEN + y) != 'o')
							if (line_nbr == 1) *(buff + i * BUFFLEN + y) = l * -1;
					}
					x = x - dist;
				break;
				case 'U':
					if (*(buff + x * BUFFLEN + y) != 'o') *(buff + x * BUFFLEN + y) = l;
					dist = atoi(++token);
					for (int i = y - 1; i >= y - dist; i--) {
						l++;
						if (*(buff + x * BUFFLEN + i) > 0 && *(buff + x * BUFFLEN + i) != 'o') {
							*(buff + x * BUFFLEN + i) += l;
							size_t md = calc_md(x, i);
							if (md < min_dist) min_dist = md;
							if (*(buff + x * BUFFLEN + i) < min_steps) min_steps = *(buff + x * BUFFLEN + i);
						} else if (*(buff + x * BUFFLEN + i) != 'o')
							if (line_nbr == 1) *(buff + x * BUFFLEN + i) = l * -1;
					}
					y = y - dist;
				break;
				case 'D':
					if (*(buff + x * BUFFLEN + y) != 'o') *(buff + x * BUFFLEN + y) = l;
					dist = atoi(++token);
					for (int i = y + 1; i <= y + dist; i++) {
						l++;
						if (*(buff + x * BUFFLEN + i) > 0 && *(buff + x * BUFFLEN + i) != 'o') {
							*(buff + x * BUFFLEN + i) += l;
							size_t md = calc_md(x, i);
							if (md < min_dist) min_dist = md;
							if (*(buff + x * BUFFLEN + i) < min_steps) min_steps = *(buff + x * BUFFLEN + i);
						} else if (*(buff + x * BUFFLEN + i) != 'o')
							if (line_nbr == 1) *(buff + x * BUFFLEN + i) = l * -1;
					}
					y = y + dist;
				break;
			}
			if (reset) {
				printf("==================\n");
				reset = 0;
				l = 0;
				line_nbr++;
				for (size_t i = 0; i < BUFFLEN; i++)
					for (size_t j = 0; j < BUFFLEN; j++)
						if (*(buff + i * BUFFLEN + j) < 0)
							*(buff + i * BUFFLEN + j) *= -1;
			}
			token = strtok(NULL, ",");
		}
	} 
	/*
	for (int y = 0; y < BUFFLEN; y++) {
		for (int x = 0; x < BUFFLEN; x++) {
			if (*(buff + x * BUFFLEN + y) == 0)
				printf(" .  ");
			else {
				if (*(buff + x * BUFFLEN + y) < 10)
					printf("%03lu ", *(buff + x * BUFFLEN + y));
				else
					printf("%03lu ", *(buff + x * BUFFLEN + y));
			}
		}
		printf("\n");
	}
	*/

	printf("Min dist: %lu\n", min_dist);
	printf("Min steps: %lu\n", min_steps);
	fclose(inf);

	return 0;
}
