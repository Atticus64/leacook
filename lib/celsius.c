#include <stdio.h>	

int calc_celsius(){
	int fahr, celsius;
	int lower, upper, step;

	upper = 300;
	lower = 0;
	step = 20;

	fahr = lower;

	printf("\tFahrenheit\tCelsious\n");
	while (fahr <= upper ){

		celsius = 5 * (fahr - 32) / 9;
		printf("\t  %d\t\t  %d\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
