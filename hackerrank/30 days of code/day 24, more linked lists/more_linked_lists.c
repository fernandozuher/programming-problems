// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insert(Node *head, const int data);
Node* remove_duplicates(Node *head);
void display(Node *head);

int main()
{
    int n_tests, data;
    scanf("%d", &n_tests);
    Node *head = NULL;

    while (n_tests--) {
        scanf("%d", &data);
        head = insert(head, data);
    }

    head = remove_duplicates(head);
    display(head);

    return 0;
}

    Node* insert(Node *head, const int data)
    {
        Node *p = (Node*) malloc(sizeof(Node));
        p->data = data;
        p->next = NULL;

        if (!head)
            head = p;
        else if (!head->next)
            head->next = p;
        else {
            Node *start = head;
            while (start->next)
                start = start->next;
            start->next = p;
        }

        return head;
    }

    Node* remove_duplicates(Node *head)
    {
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

    void display(Node *head)
    {
        Node *start = head;
        while (start) {
            printf("%d ", start->data);
            start = start->next;
        }
    }
