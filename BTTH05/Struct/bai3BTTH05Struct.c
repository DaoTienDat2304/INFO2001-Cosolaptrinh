#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeID;
    char name[50];
    char position[50];
    float salary;
};

void initEmployees(struct Employee employees[], int size) {
    int i; 
	for (i = 0; i < size; i++) {
        employees[i].employeeID = 0;
        strcpy(employees[i].name, "");
        strcpy(employees[i].position, "");
        employees[i].salary = 0.0;
    }
}

void addEmployee(struct Employee employees[], int *numEmployees) {
    if (*numEmployees < 50) {
        printf("Nhap thong tin nhan vien moi:\n");
        printf("Ma nhan vien: ");
        scanf("%d", &employees[*numEmployees].employeeID);
        printf("Ho va ten nhan vien: ");
        getchar();
        fgets(employees[*numEmployees].name, sizeof(employees[*numEmployees].name), stdin);
        printf("Chuc vu: ");
        fgets(employees[*numEmployees].position, sizeof(employees[*numEmployees].position), stdin);
        printf("Luong: ");
        scanf("%f", &employees[*numEmployees].salary);
        (*numEmployees)++;
        printf("Them nhan vien thanh cong\n");
    } else {
        printf("Danh sach nhan vien da day\n");
    }
}

void removeEmployee(struct Employee employees[], int *numEmployees, int employeeID) {
    int i, j, found = 0;
    for (i = 0; i < *numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            found = 1;
            for (j = i; j < (*numEmployees) - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*numEmployees)--;
            printf("Da xoa nhan vien.\n", employeeID);
            break;
        }
    }
    if (!found) {
        printf("Khong the tim thay thong tin nhan vien.\n", employeeID);
    }
}

void displayEmployees(struct Employee employees[], int numEmployees) {
    printf("Danh sach nhan vien:\n");
    int i; 
    for (i = 0; i < numEmployees; i++) {
        printf("Nhan vien %d:\n", i + 1);
        printf("Ma nhan vien: %d\n", employees[i].employeeID);
        printf("Ten nhan vien: %s", employees[i].name);
        printf("Chuc vu: %s", employees[i].position);
        printf("Luong: %.2f\n", employees[i].salary);
        printf("--------------------\n");
    }
}

void sortEmployees(struct Employee employees[], int numEmployees) {
    int i,j; 
	for (i = 0; i < numEmployees - 1; i++) {
        for (j = 0; j < numEmployees - i - 1; j++) {
            if (employees[j].salary < employees[j + 1].salary) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sinh vien sau khi sap xep:\n");
    displayEmployees(employees, numEmployees);
}

int main() {
    struct Employee employees[50];
    int numEmployees = 0;
    int choice;

    initEmployees(employees, 50);

    do {
        printf("\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Thong tin nhan vien\n");
        printf("4.Sap xep nhan vien theo muc luong\n");
        printf("5. Thoat chuong trinh\n");
        printf("Hay nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                if (numEmployees > 0) {
                    int employeeID;
                    printf("Nhap ID nhan vien can xoa: ");
                    scanf("%d", &employeeID);
                    removeEmployee(employees, &numEmployees, employeeID);
                } else {
                    printf("ID nhan vien khong ton tai.\n");
                }
                break;
            case 3:
                if (numEmployees > 0) {
                    displayEmployees(employees, numEmployees);
                } else {
                    printf("Thong tin nhan vien khong ton tai.\n");
                }
                break;
            case 4:
                if (numEmployees > 0) {
                    sortEmployees(employees, numEmployees);
                } else {
                    printf("Thong tin nhan vien khong ton tai.\n");
                }
                break;
            case 5:
                printf("Da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
        } while (choice != 5);
        return 0;
}
