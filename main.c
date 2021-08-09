/*
 *  This is a Algorithm Visualization tool for: Bubble Sort, Insertion Sort, Selection Sort, and Combination Sort.
 *
 *  Created on: Jul 02, 2021
 *      Author: Andrew Herbert
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define downTime 150
#define bufferSize 5000
#define dataSize 25
#define combinationShrinkSize 1.3

int data[dataSize];

int main(int f, char** args) {
	int pick;
	f = 2;
	printf("Enter choice.");
	scanf("%d", &pick);
	int temp = dataSize;
	if (f != 2) {
		help();
		return 0;
	}
	else if (pick < 1 || pick > 4) {
		help();
		return 0;
	}
	for (int i = 0; i < temp + 2; i++) {
		printf("\n");
	}
	generateDataBlocks(data, temp);
	drawDataBlocks(data, temp, -1, -1, 0);
	switch (pick) {
	case 1:
		bubbleSort(data, temp);
		break;
	case 2:
		selectionSort(data, temp);
		break;
	case 3:
		insertionSort(data, temp);
		break;
	case 4:
		comboSort(data, temp, combinationShrinkSize);
	}
}

void help() {
	printf("   -- HELP --\n");
	printf("1.  Bubble sort\n");
	printf("2.  Selection Sort\n");
	printf("3.  Insertion Sort\n");
	printf("4.  Combo Sort\n");
}

void bubbleSort(int *g, int foo) {
	int r = 0;
	int c = 0;
	while (r != foo - 1) {
		r = 0;
	    for (int i = 1; i < foo; i++) {
	    	if (g[i] > g[i -1]) {
	    		swap(g, i, i -1);
	    	}
	        else {
	        	r++;
	        }
	    	c++;
	    	drawDataBlocks(g, foo, i, i - 1, c);
	    	usleep(downTime * 1000);
	    }
	}
}

void selectionSort(int *g, int foo) {
	int max, temp = 0;
	for (int i = 0; i < foo; i++) {
		max = i;
		for (int j = i; j < foo; j++) {
			if (g[j] > g[max]) {
				max = j;
			}
			temp++;
			drawDataBlocks(g, foo, j, max, temp);
			usleep(downTime * 1000);
		}
		if(max != i) {
			swap(g, i, max);
			temp++;
			drawDataBlocks(g, foo, i, max, temp);
			usleep(downTime * 1000);
		}
	}
}

void insertionSort(int *g, int foo) {
	int temp = 0;
	for (int i = 1; i < foo; i++) {
		if (g[i - 1] < g[i]) {
			swap(g, i, i - 1);
			(i != 1) ? (i -= 2) : (0);
		}
		temp++;
		drawDataBlocks(g, foo, i - 1, i, temp);
		usleep(downTime * 1000);
	}
}

void comboSort(int *g, int foo, float s) {
	int a = foo - 1;
	int b, c = 0;
	while(!b) {
		a = a / s;
		if (a <= 1) {
			b = 1;
		}
		for (int i = 0; i + a < foo; i++) {
			if (g[i] < g[i + a]) {
				swap(g, i, i + a);
				b = 0;
			}
			c++;
			drawDataBlocks(g, foo, i, i + a, c);
			usleep(downTime * 1000);
		}
	}
}

void swap(int *g, int foo, int foo2) {
	int temp = g[foo];
	g[foo] = g[foo2];
	g[foo2] = temp;
}

void generateDataBlocks(int *g, int foo) {
	srand(time(0));
	for (int i = 0; i < foo; i++) {
		g[i] = i + 1;
	}
	if (foo > 1) {
		for (int j = 0; j < foo; j++) {
			int k = j + rand() / (RAND_MAX / (foo - 1) + 1);
			swap(g,k,j);
		}
	}
}

void drawDataBlocks(int *g, int foo, int p1, int p2, int c) {
	char buffer[bufferSize];
	for (int i = 0; i < foo + 2; i++) {
		printf("e[1A");
	}
	sprintf(buffer, "Cycles: %d\n", c);
	for (int y = 0; y <= foo; y++) {
	        for (int x = 0; x < foo; x++) {
	            if (g[x] <= y) {
	                if (x == p1 +1 || x == p2 +1) {
	                    strcat(buffer, "\e[31m[]\e[0m");
	                }
	                else {
	                    strcat(buffer, "[]");
	                }
	            }
	            else {
	                strcat(buffer, "  ");
	            }
	        }
	        strcat(buffer, "\n");
	    }
	    printf(buffer);
}
