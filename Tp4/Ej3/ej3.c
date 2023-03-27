#include <stdio.h>
#include <math.h>

#define PI 3.1415
#define vol(r) ((4.0/3.0)*(PI)*(pow(r, 3)))



int main(){

  int r;

  for (r=1; r<=10; r++){

    printf("r%d\tvol=%.4f\n", r, vol(r));
  }

}
