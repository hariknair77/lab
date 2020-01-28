#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER 0
#define UPPER 100

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int randint() {
    return rand() % (UPPER - LOWER + 1) + LOWER;
}
int *array(int size) {
    int *a = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        a[i] = randint();
    return a;
}
void disp(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void merge(int a[], int m, int b[], int n, int sorted[]) {
    int i, j, k;
    j = k = 0;
    for (i = 0; i < m + n;) {
        if (j < m && k < n) {
            if (a[j] < b[k]) {
                sorted[i] = a[j];
                j++;
            } else {
                sorted[i] = b[k];
                k++;
            }
            i++;
        } else if (j == m)
            for (; i < m + n;) {
                sorted[i] = b[k];
                k++;
                i++;
            }
        else
            for (; i < m + n;) {
                sorted[i] = a[j];
                j++;
                i++;
            }
    }
}
// int main(){
//     srand(time(NULL));
//     int n;
//     printf("Enter array size: ");
//     scanf("%d",&n);

//     int *a = array(n);
//     disp(a,n);

//     return 0;
// }