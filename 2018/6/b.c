#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

struct point {
	int x;
	int y;
};

#define LEN 50
struct point coords[LEN] = {
	{174, 356},
	{350, 245},
	{149, 291},
	{243, 328},
	{312, 70},
	{327, 317},
	{46, 189},
	{56, 209},
	{84, 60},
	{308, 202},
	{289, 331},
	{201, 139},
	{354, 201},
	{283, 130},
	{173, 144},
	{110, 280},
	{242, 250},
	{196, 163},
	{217, 300},
	{346, 188},
	{329, 225},
	{112, 275},
	{180, 190},
	{255, 151},
	{107, 123},
	{86, 304},
	{236, 88},
	{313, 124},
	{297, 187},
	{203, 289},
	{104, 71},
	{100, 151},
	{227, 47},
	{318, 293},
	{268, 225},
	{116, 49},
	{222, 125},
	{261, 146},
	{47, 117},
	{119, 214},
	{183, 242},
	{136, 210},
	{91, 300},
	{326, 237},
	{144, 273},
	{300, 249},
	{200, 312},
	{305, 50},
	{235, 265},
	{322, 291}
};
#define COLS 400

/*
#define LEN 6
struct point coords[LEN] = {
	{1, 1},
	{1, 6},
	{8, 3},
	{3, 4},
	{5, 5},
	{8, 9}
};


#define COLS 10
*/

int cdist(int x1, int y1, int x2, int y2)
{
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return x + y;
}

int main()
{
	int size = 0;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < COLS; j++) {
			int dist = 0;
			for (int k = 0; k < LEN; k++) {
				dist += cdist(j, i, coords[k].x, coords[k].y);
			}
			int val = '.' - 97;
			if (dist < 10000) {
				val = '#' - 97;
				size++;
			}
			//printf("%c", val + 97);
		}
		//printf("\n");
	}
	printf("size: %d\n", size);
	return 0;
}
