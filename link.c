#include <stdio.h>
#include <stdlib.h>

struct StudentData {
    char name[30];
    int vize;
    int final;
    int id;
    struct StudentData *next;
};

typedef struct StudentData node;
node *head;

void CreatingList() {
    int n;
    int i;
    node *p;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        node *newStudent = (node *)malloc(sizeof(node));
        newStudent->next = NULL;

        printf("Enter name: ");
        scanf("%s", newStudent->name);
        printf("Enter vize: ");
        scanf("%d", &newStudent->vize);
        printf("Enter final: ");
        scanf("%d", &newStudent->final);
        printf("Enter ID: ");
        scanf("%d", &newStudent->id);

        if (i == 0) {
            head = newStudent;
            p = head;
        } else {
            p->next = newStudent;
            p = p->next;
        }
    }
}

node *AddingList() {
    int stdno;
    node *q, *p;
    node *newStudent = (node *)malloc(sizeof(node));

    printf("Enter name: ");
    scanf("%s", newStudent->name);
    printf("Enter vize: ");
    scanf("%d", &newStudent->vize);
    printf("Enter final: ");
    scanf("%d", &newStudent->final);
    printf("Enter ID: ");
    scanf("%d", &newStudent->id);

    printf("Choose a place to add to the list: ");
    scanf("%d", &stdno);
    p = head;

    if (stdno == p->id) {
        newStudent->next = p;
        head = newStudent;
    } else {
        while (p->next != NULL && p->id != stdno) {
            q = p;
            p = p->next;
        }
        if (p->id == stdno) {
            q->next = newStudent;
            newStudent->next = p;
        } else if (p->next == NULL) {
            p->next = newStudent;
            newStudent->next = NULL;
        }
    }
    return head;
}

node *DeletingList() {
    int stdno;
    node *p, *q;

    p = head;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &stdno);

    if (stdno == p->id) {
        head = p->next;
        free(p);
    } else {
        while (p->next != NULL && p->id != stdno) {
            q = p;
            p = p->next;
        }
        if (p->id == stdno) {
            q->next = p->next;
            free(p);
        } else if (p->next == NULL) {
            printf("There is no student with the given ID.\n");
        }
    }
    return head;
}

double CalculateOfSuccess(int vize, int final) {
    return 0.4 * vize + 0.6 * final;
}

void CalculateOfSucceeded() {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    double maxSuccess = CalculateOfSuccess(head->vize, head->final);
    node *p = head;

    while (p != NULL) {
        double success = CalculateOfSuccess(p->vize, p->final);
        if (success > maxSuccess) {
            maxSuccess = success;
        }
        p = p->next;
    }

    printf("Highest success: %.2f\n", maxSuccess);
}

int main() {
    printf("Welcome to the Student linked list\n");

    int islem;

    printf("Enter a number to choose what you want to do in the system: ");
    scanf("%d", &islem);

    switch (islem) {
        case 1:
            CreatingList();
            break;

        case 2:
            DeletingList();
            break;

        case 3:
            AddingList();
            break;

        case 4:
            CalculateOfSucceeded();
            break;

        default:
            printf("Please enter a valid number between 1 and 4.\n");
            break;
    }

    return 0;
}
