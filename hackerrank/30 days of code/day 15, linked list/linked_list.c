// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *initialize_list(int n);
Node *insert(Node *head, int data);
Node *new_tail_node(Node *head);
Node *tail_node(Node *head);
Node *allocate_node();
void display_list(const Node *head);
Node *free_list(Node *head);

int main()
{
    int n;
    scanf("%d", &n);
    Node *head = initialize_list(n);
    display_list(head);
    head = free_list(head);
    return 0;
}

Node *initialize_list(int n)
{
    Node *head = nullptr;
    for (int data; n--;) {
        scanf("%d", &data);
        head = insert(head, data);
    }
    return head;
}

Node *insert(Node *head, int data)
{
    Node *tail = new_tail_node(head);
    tail->data = data;
    tail->next = nullptr;
    if (!head)
        head = tail;
    return head;
}

Node *new_tail_node(Node *head)
{
    Node *tail = tail_node(head);
    if (tail) {
        tail->next = allocate_node();
        tail = tail->next;
    } else
        tail = allocate_node();
    return tail;
}

Node *tail_node(Node *head)
{
    for (; head && head->next; head = head->next);
    return head;
}

Node *allocate_node()
{
    auto node = (Node *) calloc(1, sizeof(Node));
    node->next = nullptr;
    return node;
}

void display_list(const Node *head)
{
    for (; head; head = head->next)
        printf("%d ", head->data);
}

Node *free_list(Node *head)
{
    for (Node *next; head; head = next) {
        next = head->next;
        free(head);
    }
    return nullptr;
}
