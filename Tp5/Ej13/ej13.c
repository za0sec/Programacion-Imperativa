#include <stdio.h>

void redHost(unsigned long ip[], unsigned char bitsNet){

  printf("\t\tRed\t\tHost\n\n\t\t");
  
  if (bitsNet == 16 ){


    for ( int i = 0; i<4; i++ )
      printf("%ld%s",ip[i], i<2 ? "." : ".0.0\t");

    for ( int i = 0; i<2; i++ ) 
      printf("0.0.%ld",ip[i+2]);
      
    

  }else if ( bitsNet > 16  ){

    for ( int i = 0; i<4; i++ )
      printf("%ld%s", ip[i], i<3 ? "." : " " );

  }

}


int main(){


  unsigned long ip[4] = {192,168,1,1};
  
  unsigned char bitsNet = 16;

  redHost(ip, bitsNet);

}
