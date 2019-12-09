#include "header.h"

int   ia[8192] ALIGNED16;

__attribute__((noinline))
void example21(int *in_array, int n) {
  int i, sum = 0;

  for (i = n-1; i >= 0; i--)
    sum += in_array[i];

  in_array[0] = sum;
}


int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[8192]);
  BENCH("Example21",  example21(ia, 8192), Mi*4/8192*512, digest_memory(&ia[0], &ia[8192]));
  return 0;
}
