#include <stdio.h>
int main() {
    int number;
	printf("Nhap so nguyen : ");
    scanf("%d", &number);
    if (number <0) {
    printf("So am khong phai so chan cung khong phai so le\n");
    }
    else if (number ==0) {
    printf("So 0 khong phai so chan cung khong phai so le");
    }
    else if (number % 2 ==0) {
    printf("%d la so chan\n", number);
    }
    else {
    printf("%d la so le \n", number);
    }
    return 0;
}
