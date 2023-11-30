#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
	int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 3, 4, 10, 16, 1, 9, 32, 39, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;

    int result = linearSearch(arr, n, x);

    if (result != -1) {
        printf("%d duoc tim thay o vi tri %d trong mang.\n", x, result);
    } else {
        printf("%d so can tim khong ton tai trong mang\n", x);
    }

    return 0;
}
