#include <stdio.h>

void bubbleSort(int arr[], int n) {
    
	int i,j; 
	for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[] = {5, 0, 2, 8, 1};
    int length = 5;
	int i; 
    printf("Mang truoc khi sap xep:\n");
    for ( i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    bubbleSort(a, length);

    printf("Mang sau khi sap xep:\n");
    for ( i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
