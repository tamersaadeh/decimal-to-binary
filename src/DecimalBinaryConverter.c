/*
 ============================================================================
 Name        : DecimalBinaryConverter.c
 Author      : Tamer Saadeh
 Version     : 0.0.1
 Copyright   : 
 Description : Decimal-Binary Converter in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

char* toBinary(long decimal) {
	// variables
	static char binary[1000];
	int k = 0, n = 0;
	int negative = 0;
	int remain;
	char temp[strlen(binary)];

	// take care of negative input
	if (decimal < 0) {
		decimal = -decimal;
		negative = 1;
	}

	while (decimal > 0) {
		remain = decimal % 2;
		decimal = decimal / 2;
		temp[k++] = remain + '0';
	}

	//using sign and magnitude

	if (negative)
		temp[k++] = '1';
	else
		temp[k++] = '0';

	// reverse the spelling
	while (k >= 0)
		binary[n++] = temp[--k];

	binary[n - 1] = 0;
	return binary;
}

int main() {
	long decimal;
	char *binary;

	printf("Enter an integer value: ");
	scanf("%ld", &decimal);
	binary = toBinary(decimal);
	printf("\nThe binary value of %ld is %s (using sign and magnitude for negative numbers).\n", decimal, binary);

	return 0;
}
