#include <stdio.h>

#define CUBO(x)  ((x) * (x) * (x))


int cubo (int num);


int
main(void)						
{
	int a=3, b, c, d, e, f;


	b = CUBO( ++a );
c = CUBO( a++ );
d = 3;
	e = cubo ( ++d );
	d = 3;
	f = cubo ( d++ );

  printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\n", a, b, c, d, e, f);

	return 0;
}


int 
cubo ( int num )
{
	return num * num * num;
}

