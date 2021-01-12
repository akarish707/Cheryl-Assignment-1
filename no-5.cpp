#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node { 
int data; 
struct Node* next; 
}; 

void printNthfromtheend(struct Node *head, int n) { 
struct Node *mainptr = head; 
struct Node *refptr = head; 

int count = 0; 
if(head != NULL) { 
	while( count < n ) { 
		if(refptr == NULL) { 
		printf("%d is greater than the no. of "
					"nodes in list", n); 
		return; 
		} 
		refptr = refptr->next; 
		count++; 
	} 
	
	if(refptr == NULL) { 
		head = head->next; 
		if(head != NULL) 
			printf("Node no. %d from last is %d ", n, mainptr->data); 
	} else{ 
	while(refptr != NULL) { 
		mainptr = mainptr->next; 
		refptr = refptr->next; 
	} 
	printf("Node no. %d from last is %d ", n, mainptr->data); 
	} 
} 
} 

void push(struct Node** headref, int new_data) { 
struct Node* new_node = new Node(); 

new_node->data = new_data; 

new_node->next = (*headref);	 

(*headref) = new_node; 
} 

int main() { 
struct Node* head = NULL; 
push(&head, 100); 
push(&head, 90); 
push(&head, 95); 
push(&head, 80); 
push(&head, 92);

printNthfromtheend(head, 5); 
}
