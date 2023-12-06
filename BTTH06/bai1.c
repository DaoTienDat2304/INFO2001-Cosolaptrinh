#include <stdio.h>

void nhapMang(int* arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }
}
void inMang(int* arr, int size) {
    printf("Cac phan tu da nhap la: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("n");
}
int timKiem(int* arr, int size, int A) {
    int i;
    for (i = 0; i < size; i++) {
        if (*(arr + i) == A) {
            return i;
        }
    }
    return -1;
}
int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    nhapMang(arr, size);
    inMang(arr, size);

    int A;
    printf("Nhap phan tu muon tim kiem: ");
    scanf("%d", &A);
    int index = timKiem(arr, size, A);
    if (index != -1) {
        printf("Phan tu %d nam o vi tri thu %d trong mang.\n", A, index);
    } else {
        printf("Phan tu %d khong co trong mang.\n", A);
    }
    free(arr);

    return 0;
}
