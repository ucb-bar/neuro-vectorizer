#include "header.h"

int   ia[1024] ALIGNED16;

__attribute__((noinline))
void example21(int *input, int n) {
  int i, mul = 1;

  for (i = n-1; i >= 0; i--)
    mul *= input[i];

  input[0] = mul;
}


int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[1024]);
  BENCH("Example21",  example21(ia, 1024), Mi/1024*512, digest_memory(&ia[0], &ia[1024]));
  return 0;
}
