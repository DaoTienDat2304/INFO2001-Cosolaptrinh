#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char id[30];
    int age;
    float gpa;
};


void saveStudentsToFile(struct Student students[], int numStudents, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file\n");
        return;
    }



    fprintf(file, "%d\n", numStudents);
	int i; 
    for (i = 0; i < numStudents; i++) {
        fprintf(file, "%s", students[i].name);
        fprintf(file, "%s", students[i].id);
        fprintf(file, "%d\n", students[i].age);
        fprintf(file, "%f\n", students[i].gpa);
    }

    fclose(file);
    printf("Danh sach sinh vien duoc luu vao file thanh cong\n");
}




void loadStudentsFromFile(struct Student students[], int* numStudents, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file\n");
        return;
    }

    fscanf(file, "%d\n", numStudents); // ??c s? l??ng sinh viên t? t?p tin
	int i; 
    for (i = 0; i < *numStudents; i++) {
        fgets(students[i].name, sizeof(students[i].name), file); 
        fgets(students[i].id, sizeof(students[i].id), file);
        fscanf(file, "%d\n", &students[i].age);
        fscanf(file, "%f\n", &students[i].gpa);
    }

    fclose(file);
    printf("Danh sach sinh vien da duoc tai tu file\n");
}
void addStudent(struct Student students[], int* numStudents) {
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





void deleteStudent(struct Student students[], int* numStudents, const char* searchName) {
    int found = 0;
    int i; 
	for (i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            int j; 
			for (j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Da xoa sinh vien co ten \"%s\"\n", searchName);
    } else {
        printf("Khong tim thay sinh vien co ten \"%s\"\n", searchName);
    }
}


void updateStudent(struct Student students[], int numStudents, const char* searchName) {
    int found = 0;
    int i; 
	for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Nhap thong tin sinh vien moi:\n");
            printf("Ten: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            printf("Ma sinh vien: ");
            fgets(students[i].id, sizeof(students[i].id), stdin);
            printf("Tuoi: ");
            scanf("%d", &students[i].age);
            printf("Diem trung binh: ");
            scanf("%f", &students[i].gpa);
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Cap nhat thong tin sinh vien thanh cong\n");
    } else {
        printf("Khong tim thay sinh vien co ten \"%s\"\n", searchName);
    }
}



void printStudent(struct Student student) {
    printf("Ten: %s", student.name);
    printf("Ma sinh vien: %s", student.id);
    printf("Tuoi: %d\n", student.age);
    printf("Diem trung binh: %.2f\n", student.gpa);
}

void printAllStudents(struct Student students[], int numStudents) {
    printf("Danh sach sinh vien:\n");
    int i; 
	for (i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printStudent(students[i]);
    }
}



int main() {
    struct Student students[50];
    int numStudents = 0;
    int choice;

    loadStudentsFromFile(students, &numStudents, "students.txt");
     do {
        printf("\n");
        printf("1. Them sinh vien\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                printf("Nhap ten sinh vien can xoa: ");
                getchar();
                char deleteName[50];
                fgets(deleteName, sizeof(deleteName), stdin);
                deleteStudent(students, &numStudents, deleteName);
                break;
            case 3:
                printf("Nhap ten sinh vien can cap nhat: ");
                getchar();
                char updateName[50];
                fgets(updateName, sizeof(updateName), stdin);
                updateStudent(students, numStudents, updateName);
                break;
            case 4:
                printAllStudents(students, numStudents);
                break;
            case 5:
                saveStudentsToFile(students, numStudents, "students.txt");
                break;
            case 6:
                printf("Da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
                
        }
    } while (choice != 6);

    return 0;
}
