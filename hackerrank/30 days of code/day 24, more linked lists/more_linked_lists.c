// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *read_list();
Node *allocate_node(int data);
void remove_consecutive_duplicates(Node *head);
void display(Node *head);
Node *free_list(Node *head);

int main()
{
    Node *head = read_list();
    remove_consecutive_duplicates(head);
    display(head);
    free_list(head);
    return 0;
}

Node *read_list()
{
    int n;
    scanf("%d", &n);
    Node *head = nullptr, *tail = nullptr;

    while (n--) {
        int data;
        scanf("%d", &data);
        Node *new_node = allocate_node(data);

        if (head == nullptr)
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

Node *allocate_node(int data)
{
    auto node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = nullptr;
    return node;
}

void remove_consecutive_duplicates(Node *head)
{
    for (Node *node = head; node->next != nullptr;) {
        if (node->data == node->next->data) {
            Node *to_be_removed = node->next;
            node->next = node->next->next;
            free(to_be_removed);
        } else
            node = node->next;
    }
}

void display(Node *head)
{
    for (Node *node = head; node != nullptr; node = node->next)
        printf("%d ", node->data);
}

Node *free_list(Node *head)
{
    for (Node *node = head; node != nullptr; node = head) {
        head = head->next;
        free(node);
    }
    return nullptr;
}
