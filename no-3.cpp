#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    node *next;
} *head, *tail;

node *createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}
void pushhead (int data){

    node *temp = createnode(data);
    if(!head){
        head = tail = temp;
    }
    else{
        temp -> next = head;
        head = temp;
    }

}

void pushtail (int data){

    node *temp = createnode(data);
    if(!head){
        head = tail = temp;
    }
    else{
        tail-> next = temp;
        head = temp;
    }

}

void mid(){
    node *bawah = head;
    node *atas  = head;
    if (head != NULL){
        while (atas != NULL && atas ->next != NULL){
            atas = atas->next->next;
            bawah = bawah->next;
        }

        printf (" Elemen tengah dari link-list is %d\n", bawah->next);
    }
}

void printList(struct node *ptr) 
{ 
	while (ptr != NULL) 
	{ 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	puts("NULL");
} 

void printMiddle(struct node *head)  
{  
     node *bawah = head;  
     node *atas = head;  
  
    if (head!=NULL)  
    {  
        while (atas != NULL && atas->next != NULL)  
        {  
            atas = atas->next->next;  
            bawah = bawah->next;  
        }  
        printf("");
        printf("The middle element is %d\n", bawah->data);  
    }  
}  

int main(){
   pushhead(15);
   pushhead(20);
   pushhead(45);
   pushhead(44);
   pushhead(46);
   printList(head);
   printMiddle(head);
   return 0;
}