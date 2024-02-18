#include <stdio.h>

int main()
{
  int x = 10;
  
  // pointer store address in long hexadecimal
  // it called point to integer
  // we can not contain value in pointer it store only address
  int* y;
  
  // *y = value at y
  // & = address of operator
  // * = dereferencing operator 
  y = &x;
  
  //we can not write below code
  // y = x;
  
  int a[] = {25, 75, 53, 92, 35};
  int * q = a; // it is equal to &a[0]
  printf("%p\n", a);
  printf("%p\n", q);
  // q++; is valid
  // a++; is invalid
  // q = a[2] is invalid because its invalid
  printf("%p\n", &a);
  printf("%p\n", &q);
  // a = &a is valid
  // q = &q is not valid
  
  //excess any value using base address
  printf("%d\n", *a);
  
  // all has value is same
  printf("%d\n", *(a+2));
  printf("%d\n", *(q+2));
  printf("%d\n", *(2+q));
  printf("%d\n", 2[q]);
  printf("%d\n", *(2+a));
  printf("%d\n", 2[a]);
  
  // it is print second element address
  printf("%p\n", a + 1);
  printf("%p\n", &a[0] + 1);
  
  
  // it is print address of the box after whole array in linear array
  printf("%p\n", &a + 1);
  
  
  
  return 0;
}