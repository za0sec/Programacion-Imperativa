#include <stdio.h>
#include <assert.h>
#include "complexADT.h" 

#define EPS 0.01

int main(void) {
  complexADT comp1 = newComplex( 1, 2 ); // comp1 = 1 + 2i
	complexADT comp2 = newComplex( 2, -3 ); // comp2 = 2 - 3i
	complexADT ans;

	ans = addComplex( comp1, comp2 );
	assert( getReal(ans) - 3 < EPS && getImaginary(ans) + 1 < EPS );

	freeComplex( comp1 );
	freeComplex( comp2 );
	freeComplex( ans );

	printf("OK!\n");
}
