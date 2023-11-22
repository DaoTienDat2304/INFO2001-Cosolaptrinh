#include <stdio.h>

int main() {
    float point;
	printf("Nhap diem so: ");
    scanf("%f", &point);
	if (point >=9 && point <= 10) {
    printf("Xuat sac\n");
    }
    else if (point >=8 && point < 9) {
    printf("Gioi\n");
    }
    else if (point >=6.5 && point < 8){
    printf("Kha\n");
    }
    else if (point >=5 && point < 6.5) {
    printf("Trung binh\n");
    }
    else if (point >=0 && point < 5) {
    printf("Yeu\n");
    }
    else {
    printf("Nhap sai diem\n");
    }
    return 0;
}
