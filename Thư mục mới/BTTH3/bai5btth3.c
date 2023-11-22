#include <stdio.h>

	int isPrime(int N) {
    int i;
    if (N < 2) {
        return 0;
    } else {
    for (i = 2; i <= N / 2; i++) {
    if (N % i == 0) {
return 0;
            }
        }
return 1;
    }
}

int main() {
    int N;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &N);
    if (isPrime(N)) {
    printf("So vua nhap la so nguyen to");
    } else {
    printf("So vua nhap khong phai so nguyen to");
    }
return 0;
}
