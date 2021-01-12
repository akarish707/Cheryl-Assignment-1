#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node { 
	int data; 
	struct Node *next; 
}; 
 
void largestElement(struct Node *head) 
{ 
	 
	int max = INT_MIN; 
 
	while (head != NULL) { 		 
		if (max < head->data) 
			max = head->data; 
		head = head->next; 
	} 
	printf("%d",max); 
} 
 
void smallestElement(struct Node *head) 
{ 

	int min = INT_MAX; 
 
	while (head != NULL) { 
 
		if (min > head->data) 
			min = head->data; 

		head = head->next; 
	} 
	printf("%d",min); 
} 

 
void push(struct Node** head, int data) 
{  
	struct Node *newNode = 
		(struct Node*)malloc(sizeof(struct Node)); 

 
	newNode->data = data;
	newNode->next = (*head);  
	(*head) = newNode; 
} 

// 
void printList(struct Node *head) 
{ 
	while (head != NULL) { 
		printf("%d -> ", head->data); 
		head = head->next; 
	} 
	puts("NULL"); 
} 

// Driver program to test the functions 
int main() 
{ 
	// Start with empty list 
	struct Node *head = NULL; 

	// Using push() function to construct 
	// singly linked list 
	// 17->22->13->14->15 
	push(&head, 19); 
	push(&head, 14); 
	push(&head, 10); 
	push(&head, 21); 
	push(&head, 18); 
	
    printf("Linked list : ");
    printList(head); 
	
    printf("Elemen terbesar : \n"); 
    largestElement(head);
	
    printf("\nElemen terkecil : \n");  
	smallestElement(head); 

	return 0; 
} 
