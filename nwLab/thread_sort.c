#include <pthread.h>
#include <stdio.h>
#include "stuff.h"

struct data {
    int *arr;
    int n;
};

void *sort(void *ptr) {
    struct data *d = (struct data *)ptr;
    int *arr = d->arr;
    int n = d->n;
    qsort(arr, n, sizeof(int), cmpfunc);
}

int main() {
    srand(time(NULL));
    
    int arr_size;
    printf("Enter array size: ");
    scanf("%d", &arr_size);
    int mid = arr_size / 2;
    int *arr1 = array(mid);
    int *arr2 = array(arr_size - mid);

    printf("\nBefore sorting...\n");
    disp(arr1, mid);
    disp(arr2, arr_size - mid);

    struct data a1, a2;
    a1.arr = arr1;
    a1.n = mid;
    a2.arr = arr2;
    a2.n = arr_size - mid;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, sort, &a1);
    pthread_create(&t2, NULL, sort, &a2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int sorted[arr_size];
    merge(arr1,mid,arr2,arr_size-mid,sorted);

    printf("\nAfter sorting...\n");
    disp(sorted,arr_size);
    printf("\n");
    return 0;
}