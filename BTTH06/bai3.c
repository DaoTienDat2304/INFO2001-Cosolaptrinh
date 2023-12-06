#include <stdio.h>

struct Book {
    char title[500];
    char author[500];
    int price;
};

int main() {
    int size;
    printf("Nhap so luong sach: ");
    scanf("%d", &size);

    struct Book* bookList = (struct Book*)malloc(size * sizeof(struct Book));
    if (bookList == NULL) {
        printf("Khong the cap phat bo nho dong.\n");
        return 1;
    }

    printf("Nhap thong tin sach:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("Sach %d:\n", i + 1);
        printf("  - Ten sach: ");
        scanf("%s", bookList[i].title);
        printf("  - Tac gia: ");
        scanf("%s", bookList[i].author);
        printf("  - Gia: ");
        scanf("%d", &bookList[i].price);
    }

    printf("\nDanh sach sach:\n");
    for (i = 0; i < size; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach: %s\n", bookList[i].title);
        printf("Tac gia: %s\n", bookList[i].author);
        printf("Gia: %d VND\n", bookList[i].price);
    }

    free(bookList);
    printf("Da giai phong bo nho\n");

    return 0;
}
