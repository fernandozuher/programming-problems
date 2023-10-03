// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int data);
void display(Node* head);

int main()
{
    int T, data;
    scanf("%d", &T);
    Node* head = NULL;

    while (T--) {
        scanf("%d", &data);
        head = insert(head, data);
    }

  display(head);
  return 0;
}

    Node* insert(Node* head, int data)
    {   
        Node* start;
        if (head) {
            start = head;
            for ( ; start->next; start = start->next);
            start->next = (Node*) malloc(sizeof(Node));
            start = start->next;
        }
        else {
            start = (Node*) malloc(sizeof(Node));
            head = start;
        }

        start->data = data;
        start->next = NULL;
        return head;
    }

    void display(Node* head)
    {
        Node* start = head;
        while (start) {
            printf("%d ", start->data);
            start = start->next;
        }
    }
