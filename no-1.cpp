#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int nilai;
    node *next;
} *head; 
node *tail;

node *createnode(int value) {
    node *temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
}

void push(int value, node** current) {
    node *temp = createnode(value);
    temp->next = *current;
    *current = temp;
}

void pushtail(int value) {
    node *temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}
void swap(node* node1, node* node2) {
    if (head) {
        node* hapus = head;
        while (hapus) {
            hapus = head->next;
            head->next = NULL;
            free(head);
            head = hapus;
        }
    }
    node* temp1 = node1, *temp2 = node2;
    while (temp1 && temp2) {
        if (temp1->nilai > temp2->nilai) {
            pushtail(temp2->nilai);
            temp2 = temp2->next;
        }
        else {
            pushtail(temp1->nilai);
            temp1 = temp1->next;
        }
    }
    while (temp1) {
        pushtail(temp1->nilai);
        temp1 = temp1->next;
    }
    while (temp2) {
        pushtail(temp2->nilai);
        temp2 = temp2->next;
    }
}

void print(node *current) {
    while (current) {
        if (current->next == NULL) {
            printf("%d\n", current->nilai);
            current = current->next;
        }
        else {
            printf("%d -> ", current->nilai);
            current = current->next;
        }
    }
}

int main() {
    node *a = NULL;
    node *b = NULL;
    int n, m, num;
    printf("Tulis banyak elemen dan Input data dari besar ke kecil : ");
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &num);
        push(num, &a);
    }
    print(a);
    printf("Tulis banyak elemen dan Input data dari besar ke kecil: ");
    scanf("%d", &m);
    for (int i = 0;i < n;i++) {
        scanf("%d", &num);
        push(num, &b);
    }
    swap(b, a);
    print(head);

    return 0;
}