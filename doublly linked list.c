#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    float marks1, marks2, marks3;
    char usn[15], name[20], dept[20], phno[15];
    struct node *next;
    struct node *prev;
};

int count = 0;
struct node *first = NULL, *last = NULL, *temp = NULL;
void create() {
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("List is empty.\n");
        exit(1);
    }

    printf("Enter USN:");
    scanf("%s", temp->usn);

    printf("Enter Name:");
    scanf("%s", temp->name);

    printf("Enter Department:");
    scanf("%s", temp->dept);

    printf("Enter student marks in 3 subjects\n");
    printf("Enter the marks 1:");
    scanf("%f", &temp->marks1);
    printf("Enter the marks 2:");
    scanf("%f", &temp->marks2);
    printf("Enter the marks 3:");
    scanf("%f", &temp->marks3);


    printf("Enter student phone number:");
    scanf("%s", temp->phno);

    temp->next = NULL;
    temp->prev = NULL;

    count++;
}

void insert_Beg() {
    create();
    if (first == NULL) {
        first = temp;
        last = temp;
    } else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void insert_End() { 
    create();
    if (last == NULL) {
        first = temp;
        last = temp;
    } else {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void delete_Beg() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = first;

    if (temp->next == NULL) {
        first = last = NULL;
    } else {
        first = temp->next;
        first->prev = NULL;
    }

    free(temp);
    count--;
}

void delete_End() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = last;

    if (temp->prev == NULL) {
        first = last = NULL;
    } else {
        last = temp->prev;
        last->next = NULL;
    }

    free(temp);
    count--;
}

void total() {
    struct node *temp = first;

    while (temp != NULL) {
        float sum = temp->marks1 + temp->marks2 + temp->marks3;
        float average = sum / 3.0;

        printf("\nStudent total marks : %.2f", sum);
        printf("\nStudent average marks : %.2f", average);
        temp = temp->next;
    }
}

void display() {
    struct node *temp = first;
    if (first == NULL) {
        printf("List is empty.\n");
    } else {
        while (temp != NULL) {
            printf("Student Name: %s", temp->name,"\n");
            printf("\nStudent USN: %s", temp->usn,"\n");
            printf("\nStudent Department: %s", temp->dept,"\n");
            printf("\nStudent marks in 3 subjects:");
            printf("\nMarks 1: %.2f", temp->marks1);
            printf("\nMarks 2: %.2f", temp->marks2);
            printf("\nMarks 3: %.2f", temp->marks3);
            printf("\nStudent Phone No: %s", temp->phno "\n");
            printf("\n");

            temp = temp->next;
        }
    }
}

void displayCount() {
    printf("\nTotal number of students: %d\n", count);
}
int main() {
    int n;
    int choice;

    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 1; i <= n; i++) {
        insert_End();
        printf("\n");
    }

    while (1) {
        printf("\n");
        printf("1. INSERT BEGINING\n2. INSERT END\n3. DELETE BEGINING\n4. DELETE END\n5. DISPLAY\n6. TOTAL\n7. COUNT\n8. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_Beg();
                break;

            case 2:
                insert_End();
                break;

            case 3:
                delete_Beg();
                break;

            case 4:
                delete_End();
                break;

            case 5:
                display();
                break;

            case 6:
                total();
                break;

            case 7:
                displayCount();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}
