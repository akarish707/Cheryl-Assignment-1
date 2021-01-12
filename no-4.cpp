#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int data;
	struct Node* next;
};

void rmvDuplicates(struct Node* head)
{
	struct Node* curr = head;
	struct Node* next_s; 

	if (curr == NULL){
	  return; 
    }
	while (curr->next != NULL) {
	if (curr->data == curr->next->data) {	
        next_s = curr->next->next;
		free(curr->next);
		curr->next = next_s; 
	}
	else{
		curr = curr->next; 
	}
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
			
	new_node->data = new_data;
	new_node->next = (*head_ref);	 
	(*head_ref) = new_node;
}

void printList(struct Node *node)
{
	while (node!=NULL)
	{
	printf("%d ->", node->data);
	node = node->next;
	}
    puts("NULL");
} 

int main()
{
	struct Node* head = NULL;
	push(&head, 100);
	push(&head, 100);
	push(&head, 90); 
	push(&head, 95);
	push(&head, 95);
	push(&head, 95);
    push(&head, 88);
    push(&head, 82);
    push(&head, 80);								 

	printf("\n Before Remove : ");
	printList(head);
	rmvDuplicates(head); 
	printf("\n After Remove :  ");		 
	printList(head);		 

	return 0;
}
