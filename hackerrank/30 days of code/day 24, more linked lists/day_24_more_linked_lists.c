#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

// HackerRank immutable code above

Node* removeDuplicates(Node *head) {
    Node *original = head;
    while (head->next) {
        if (head->data == head->next->data) {
            Node *to_be_removed = head->next;
            head->next = head->next->next;
            free(to_be_removed);
        }
        else
            head = head->next;
    }
    return original;
}

// HackerRank immutable code below

Node* insert(Node *head,int data)
{
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = data;
  p->next=NULL;   
  
  if(head==NULL){
   head=p;  
  
  }
  else if(head->next==NULL)
  {
      head->next=p;
      
  }
  else{
  Node *start=head;
  while(start->next!=NULL)
    start=start->next;
  
  start->next=p;   
  
  }
      return head;
}
void display(Node *head)
{
    Node *start=head;
    while(start)
    {
        printf("%d ",start->data);
        start=start->next;
    }
}
int main()
{
    int T,data;
    scanf("%d",&T);
    Node *head=NULL;    
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
    head=removeDuplicates(head);
    display(head);
        
}
