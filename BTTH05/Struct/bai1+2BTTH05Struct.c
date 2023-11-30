#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char id[30];
    int age;
    float gpa;
};

void initStudents(struct Student students[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        strcpy(students[i].name, "");
        students[i].age = 0;
        strcpy(students[i].id, "");
        students[i].gpa = 0.0;
    }
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents < 50) {
        printf("Nhap thong tin sinh vien moi:\n");
        printf("Ten: ");
        getchar();
        fgets(students[*numStudents].name, sizeof(students[*numStudents].name), stdin);
        printf("Ma sinh vien: ");
        fgets(students[*numStudents].id, sizeof(students[*numStudents].id), stdin);
        printf("Tuoi: ");
        scanf("%d", &students[*numStudents].age);
        printf("Diem trung binh: ");
        scanf("%f", &students[*numStudents].gpa);
        (*numStudents)++;
        printf("Them sinh vien moi thanh cong\n");
    } else {
        printf("Danh sach sinh vien da day\n");
    }
}

void editStudent(struct Student students[], int numStudents) {
    if (numStudents > 0) {
        int studentIndex;
        printf("Nhap vi tri sinh vien can sua: ");
        scanf("%d", &studentIndex);
        if (studentIndex >= 0 && studentIndex < numStudents) {
            printf("Nhap thong tin sinh vien moi:\n");
            printf("Ten: ");
            getchar();
            fgets(students[studentIndex].name, sizeof(students[studentIndex].name), stdin);
            printf("Ma sinh vien: ");
            fgets(students[studentIndex].id, sizeof(students[studentIndex].id), stdin);
            printf("Tuoi: ");
            scanf("%d", &students[studentIndex].age);
            printf("Diem trung binh: ");
            scanf("%f", &students[studentIndex].gpa);
            printf("Sua thong tin sinh vien thanh cong\n");
        } else {
            printf("Thong tin nhap khong hop le\n");
        }
    } else {
        printf("Khong tim duoc thong tin sinh vien\n");
    }
}

void sortStudents(struct Student students[], int numStudents) {
    int i,j;
	for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sinh vien sau khi sap xep:\n");
	for (i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("Ten: %s", students[i].name);
        printf("Ma sinh vien: %s", students[i].id);
        printf("Tuoi: %d\n", students[i].age);
        printf("Diem trung binh: %.2f\n", students[i].gpa);
    }
}

void searchStudent(struct Student students[], int numStudents, const char* searchName) {
    int i,found = 0;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Thong tin sinh vien:\n");
            printf("Ten: %s", students[i].name);
            printf("Ma sinh vien: %s",students[i].id);
            printf("Tuoi: %d\n", students[i].age);
            printf("Diem trung binh: %.2f\n", students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ten \"%s\"\n", searchName);
    }
}

int main() {
    struct Student students[50];
    int numStudents = 0;
    int choice;

    initStudents(students, 50);

    do {
        printf("\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Sap xep sinh vien theo diem trung binh\n");
        printf("4. Tim kiem sinh vien\n");
        printf("5. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                sortStudents(students, numStudents);
                break;
            case 4:
                printf("Nhap ten sinh vien can tim: ");
                getchar();
                char searchName[50];
                fgets(searchName, sizeof(searchName), stdin);
                searchStudent(students, numStudents, searchName);
                break;
            case 5:
                printf("Da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
