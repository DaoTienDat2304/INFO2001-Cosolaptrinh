#include <stdio.h>

int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Bo nho da day khong the chay bo nho dong.\n");
        return 1;
    }
    printf("Nhap cac phan tu:");
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Tat ca cac phan tu la: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    printf("Bo nho da duoc giai phong\n");
    return 0;
}
