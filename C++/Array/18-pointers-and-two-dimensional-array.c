#include <stdio.h>

int main(){
    
    int a[3][3] = {68, 25, 45, 54, 34, 48, 78, 89, 47};
    int *p;
    
    // p = a; is invalid

    // Below is valid
    // p = &a[0][0];
    p = a[0];
    
    // Below All Are Same
    printf("%p\n", p);
    printf("%p\n", a);
    printf("%p\n", &a[0][0]);
    printf("%p\n", &a);
    printf("%p\n", *a);
    printf("%p\n", a[0]);

    // Below All Are Same
    printf("%p\n", a + 1);
    printf("%p\n", &a[1]);
    printf("%p\n", *(a + 1));
    printf("%p\n", a[1]);
    
    // Note : a[i][j] = *(*(a + i) + j) = *(a[i] + j)
    // Below are same
    printf("%p\n", *(a+1) + 2);
    printf("%p\n", &a[1][2]);

    printf("%d\n", *(*(a+1) + 2));

    printf("%d\n", **a);
    printf("%p\n", *p);
    // Below is not valid because *p is integer dereferencing of integer not possible
    // printf("%p\n", **p); 
    
    // both are different
    printf("%p\n", a[1] + 1);
    printf("%p\n", &a[1] + 1);

    return 0;
}