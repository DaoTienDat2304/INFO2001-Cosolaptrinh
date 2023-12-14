#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

void writedatatobinaryfile(const char* ten_tep_tin) {
    FILE* file = fopen(ten_tep_tin, "wb");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi.\n");
        return;
    }

    Student students[] = {
        {1, "Dat", 8.5},
        {2, "Kien", 8.9},
        {3, "Dinh", 9.2}
    };
    int num_students = sizeof(students) / sizeof(Student);

    fwrite(students, sizeof(Student), num_students, file);

    fclose(file);
}

void readdatabinaryfile(const char* ten_tep_tin) {
    FILE* file = fopen(ten_tep_tin, "rb");
    if (file == NULL) {
        printf("Khong the mo tep tin de doc.\n");
        return;
    }

    Student student;


    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("ID: %d\n", student.id);
        printf("Name: %s\n", student.name);
        printf("Score: %.2f\n", student.score);
        printf("\n");
    }

    fclose(file);
}

int main() {
    const char* ten_tep_tin = "danhsachsv.txt";

    writedatatobinaryfile(ten_tep_tin);
    readdatabinaryfile(ten_tep_tin);

    return 0;
}
