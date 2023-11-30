#include <stdio.h>

float calculate_average(float arr[], int a) {
    float sum = 0.0;
    int i;
    for (i = 0; i < a; i++) {
        sum += arr[i];
    }
    float average = sum / a;
    return average;
}
int main() {
    int a;
    printf("Tong so luong sinh vien: ");
    scanf("%d", &a);
    if (a <= 0) {
        printf("Nhap sai so luong sinh vien.\n");
        return 0;
    }
    float gpa[a];
    printf("Nhap diem cua sinh vien:\n");
    int i;
    for (i = 0; i < a; i++) {
        printf("Sinh vien %d: ", i + 1);
        scanf("%f", &gpa[i]);
    }
    float average = calculate_average(gpa, a);
    printf("Tong diem trung binh cua ca lop la: %.2f\n", average);

    return 0;
}
