/**
 * @file Pascal_triangle.c
 * @brief This program generates Pascal's triangle up to a given number of rows.
 * @author Ratul Hasan (RaSan147)
 * @date December 1, 2023
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


char* centerString(char* s, int width){
	int len = strlen(s);
	if (len > width){
		width = len;
	}
	int i;
	char* result = malloc(sizeof(char) * (width + 1));
	int left = (width - len) / 2;
	int right = width - len - left;

	// printf("%d %d %d %d\n", left, len, right, width);


	for(i = 0; i < left; i++){
		result[i] = ' ';
	}
	for(i = 0; i < len; i++){
		result[left + i] = s[i];
	}
	for(i = 0; i < right; i++){
		result[left + len + i] = ' ';
	}
	result[width] = '\0';

	return result;
}

int fancyTriangle(){
	int lines = 13;

	for(int i=1; i<lines; i+=2){
		char* s = malloc(sizeof(char) * (i + 2));
		for(int j=0; j<i; j++){
			s[j] = '*';
		}
		s[i] = '\0';
		printf("%s\n", centerString(s, lines+1));
	}

	return 0;
}

unsigned int intLen(unsigned long long int v)
{
	unsigned long long int limit = ULLONG_MAX/10;
    unsigned long long int u = 1;
	unsigned int i = 0;
	while (u <= v && u <= limit) {
		u *= 10;
		i++;
	}
	if (u > limit) {
		if (v > limit) {
			printf("Overflow\n");
			i++;
		}
	}
	return i;
}

int printLine(unsigned long long int* line, int len, int width){
	char* str = malloc(sizeof(char) * (width + 1));
	str[0] = '\0';
	unsigned int highest = 0;

	for (int i=1; i<len-1; i++){

		unsigned int digits = intLen(line[i]);
		if (digits > highest){
			highest = digits;
		}


		char* s = malloc(sizeof(char) * (1 + 6)); // 6 is max digits, 1 is for null terminator

		if (digits>5 && i!=1){
			s[0] = '|';
			s[1] = '\0';
		} else {
			free(s);
			s = centerString(" ", 6-digits); // generate string of spaces
		}

		char num[40];
		// printf("hello %d\n", digits);
		sprintf(num, "%llu", line[i]);
		// printf("===== %d\n", i);

		strcat(str, num);
		strcat(str, s);

		free(s);
	}

	printf("%s\n", centerString(str, width));

	// printf(">> HIGHEST %u\n", highest);

	free(str);
	return 0;
}


int pascalTriangle(int lines){
	if (lines < 1){
		printf("Invalid number of lines\n");
		return 0;
	}

	unsigned long long int* pastLine;
	pastLine = malloc(sizeof(unsigned long long int) * 3);
	pastLine[0] = 0;
	pastLine[1] = 1;
	pastLine[2] = 0;

	int pastLen = 3;
	int distance = lines + 10*(lines - 1);
	// print first line
	printLine(pastLine, pastLen, distance);


	for (int i=1; i<lines; i++){
		// printf("i = %d\n", i);
		int newLen = pastLen + 1;

		unsigned long long int* line = malloc(sizeof(unsigned long long int) * newLen);
		line[0] = 0;


		for (int x=1; x<pastLen; x++){
			line[x] = pastLine[x-1] + pastLine[x];
		}



		line[pastLen] = 0;

		// print line like python list

		// printf("[");
		// for (int x=0; x<newLen; x++){
		// 	printf("%llu", line[x]);
		// 	if (x != newLen-1){
		// 		printf(", ");
		// 	}
		// }
		// printf("]\n");

		free(pastLine);
		pastLine = malloc(sizeof(unsigned long long int) * newLen);

		memcpy(pastLine, line, sizeof(unsigned long long int) * newLen);
		pastLen = newLen;
		
		printLine(line, newLen, distance);

		free(line);


		

	}

	free(pastLine);
	return 0;
}


int main(){
	fancyTriangle();

	printf("Max value for unsigned long long int: %llu\n", ULLONG_MAX);
    printf("Max digits for unsigned long long int: %u\n", intLen(ULLONG_MAX));

	printf("Enter number of lines: ");
	int lines = 0;
	scanf("%d", &lines);

	pascalTriangle(lines);

	return 0;
}