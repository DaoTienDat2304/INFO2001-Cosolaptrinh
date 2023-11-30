#include <stdio.h>
int binarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}
int main() {
    int arr[] = {2, 3, 4, 7, 9, 14, 15, 32, 39, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    int result = binarySearch(arr, 0, size - 1, x);
    if (result == -1)
        printf("%d khong co trong mang\n", x);
    else
        printf("%d xuat hien tai vi tri %d trong mang\n", x, result);

    return 0;
}
