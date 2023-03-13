#include <stdio.h>

/* print fahrenheit-celsius table
 * for fahr = 1, .., 20, ..., 300*/

void calc_celsius() {
	int fahr, celsius;
	int lower, upper = 300, step;

	lower = 0;
	step = 20;

	fahr = lower;

	printf("\tFahrenheit\tCelsious\n");
	while (fahr <= upper ){

		celsius = 5 * (fahr - 32) / 9;
		printf("\t  %d\t\t  %d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

