#include <stdio.h>
 
int main(void) {
  int x = 10; 
  int *p;
  p = &x; 
  printf("pointer p address: %p\n", (void *)p);
 
  return 0;
}