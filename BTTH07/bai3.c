#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    struct Contact* next;
} Contact;

void addContact(Contact** head, const char* name, const char* phone, const char* email) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return;
    }

    strncpy(newContact->name, name, sizeof(newContact->name) - 1);
    strncpy(newContact->phone, phone, sizeof(newContact->phone) - 1);
    strncpy(newContact->email, email, sizeof(newContact->email) - 1);
    newContact->next = *head;
    *head = newContact;

    printf("Da them nguoi lien lac: %s\n", name);
}

void getStringInput(char* dest, size_t destSize, const char* prompt) {
    printf("%s", prompt);
    fgets(dest, destSize, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

void printContacts(const Contact* head) {
    const Contact* current = head;

    if (current == NULL) {
        printf("Danh sach lien lac rong.\n");
        return;
    }

    printf("Danh sach lien lac:\n");
    while (current != NULL) {
        printf("Ten: %s\n", current->name);
        printf("Dien thoai: %s\n", current->phone);
        printf("Email: %s\n", current->email);
        printf("\n");

        current = current->next;
    }
}

void searchContact(const Contact* head, const char* name) {
    const Contact* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Da tim thay nguoi lien lac:\n");
            printf("Ten: %s\n", current->name);
            printf("Dien thoai: %s\n", current->phone);
            printf("Email: %s\n", current->email);
            printf("\n");
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay nguoi lien lac voi ten: %s\n", name);
    }
}

void deleteContact(Contact** head, const char* name) {
    Contact* current = *head;
    Contact* prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Da xoa nguoi lien lac: %s\n", name);
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay nguoi lien lac voi ten: %s\n", name);
    }
}

void saveToFile(const Contact* head, const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi.\n");
        return;
    }

    const Contact* current = head;
    while (current != NULL) {
        fwrite(current, sizeof(Contact), 1, file);
        current = current->next;
    }

    fclose(file);
}

void loadFromFile(Contact** head, const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Khong the mo tep tin de doc.\n");
        return;
    }

    Contact buffer;
    while (fread(&buffer, sizeof(Contact), 1, file) == 1) {
        addContact(head, buffer.name, buffer.phone, buffer.email);
    }

    fclose(file);
}

void freeContacts(Contact* head) {
    Contact* current = head;
    Contact* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Contact* head = NULL;
    loadFromFile(&head, "solienlac.txt");
    int choice;
    char name[50];
    char phone[15];
    char email[50];

    do {
        printf("Chon mot lua chon:\n");
        printf("1. Them nguoi lien lac\n");
        printf("2. In danh sach lien lac\n");
        printf("3. Tim kiem nguoi lien lac\n");
        printf("4. Xoa nguoi lien lac\n");
        printf("5. Luu vao tep tin\n");
        printf("0. Thoat\n");

        char choiceStr[5];
        getStringInput(choiceStr, sizeof(choiceStr), "");
        choice = atoi(choiceStr);

        switch (choice) {
            case 1:
                getStringInput(name, sizeof(name), "Nhap ten: ");
                getStringInput(phone, sizeof(phone), "Nhap dien thoai: ");
                getStringInput(email, sizeof(email), "Nhap email: ");
                addContact(&head, name, phone, email);
                break;
            case 2:
                printContacts(head);
                break;
            case 3:
                getStringInput(name, sizeof(name), "Nhap ten can tim kiem: ");
                searchContact(head, name);
                break;
            case 4:
                getStringInput(name, sizeof(name), "Nhap ten can xoa: ");
                deleteContact(&head, name);
                break;
            case 5:
                saveToFile(head, "solienlac.txt");
                printf("Du lieu da duoc luu vao tep tin.\n");
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    freeContacts(head);

    return 0;
}

