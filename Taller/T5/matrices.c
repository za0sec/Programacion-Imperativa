#define R 0.2989
#define G 0.5870
#define B 0.1140
 
#define N 3
#define M 5
#define RGB_M (3 * M)
 
#include <stdio.h>
#include <assert.h>
 
void rgbToGray(const unsigned char (rgb[])[RGB_M], unsigned char grayscale[][M]);

static void print(const unsigned char m[][M]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      printf("%d ", m[i][j]);
    }
    putchar('\n');
  }
}


// Solo para testing
static void assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols);
 
int
main(void) {
    const unsigned char rgbMatrix[][RGB_M] = {
            {100,200,100,100,180,100,200,100,120,110,123,122,100,120,122},
            {101,200,105,99,200,100,201,102,118,110,120,120,100,121,122},
            {100,200,100,100,210,105,200,100,100,120,120,100,100,122,121}
    };
    unsigned char grayscaleMatrix[N][M];
    rgbToGray(rgbMatrix, grayscaleMatrix);
    unsigned char expectedGrayscaleMatrix[][M] = {
            {158,146,132,118,114},
            {159,158,133,116,114},
            {158,165,129,117,115}
    };
    print(grayscaleMatrix);
    puts("");
    print(expectedGrayscaleMatrix);

    assertMatrixEquals(expectedGrayscaleMatrix, grayscaleMatrix, N, M);
 
    puts("OK!\n");
    return 0;
}
 
/**
 * Tester
 */
static void
assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols) {
    for (int i = 0; i < fils; i++) {
        for (int j = 0; j < cols; j++) {
            assert(expected[i][j] == actual[i][j]);
        }
    }
}
 


void rgbToGray(const unsigned char rgb[][RGB_M], unsigned char grayscale[][M]){

  float num = 0;


  for ( int i=0; i<N; i++ ){

    for (int j=0; j<RGB_M; j++){

      if ( j%3 == 1 ){
        num += rgb[i][j] * G;

      }else if ( j%3 == 2 ){

        num += rgb[i][j] * B;
        grayscale[i][j/3] = num;
        num = 0;

      }else{
        num += rgb[i][j] * R;

      }

    }

  }
}
