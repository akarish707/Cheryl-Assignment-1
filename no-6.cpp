#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

static void swap(struct Node** headr)
{
	struct Node* prev = NULL;
	struct Node* curr = *headr;
	struct Node* next = NULL;
	while (curr != NULL) {
		//next
		next = curr->next;

		// nuker 
		curr->next = prev;

        //pindah
		prev = curr;
		curr = next;
	}
	*headr = prev;
}


void push(struct Node** headr, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*headr);
	(*headr) = new_node;
}


void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
    puts("NULL");
}

int main()
{
	struct Node* head = NULL;

	push(&head, 100);
	push(&head, 98);
	push(&head, 95);
	push(&head, 92);

	printf("Ascending Linked List :\n");
	printList(head);
	swap(&head);
	printf("\nDescending Linked List : \n");
	printList(head);
	getchar();
}
