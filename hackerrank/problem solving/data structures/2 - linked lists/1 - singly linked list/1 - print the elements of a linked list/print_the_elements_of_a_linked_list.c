// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t;
typedef struct linked_list linked_list;

typedef struct node_t {
    int data;
    node_t *next;
} node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
} linked_list;

linked_list *read_numbers(int n);
linked_list *create_list();
void add_node(linked_list *list, int data);
node_t *create_node(int data);
void print_list(const linked_list *list);
void *free_list(const linked_list *list);

int main()
{
    int n;
    scanf("%d", &n);
    linked_list *list = read_numbers(n);
    print_list(list);

    free_list(list);

    return 0;
}

// T: O(n)
// S: O(n) extra space
linked_list *read_numbers(int n)
{
    linked_list *list = create_list();
    for (int i = 0, data; i < n; ++i) {
        scanf("%d", &data);
        add_node(list, data);
    }
    return list;
}

linked_list *create_list()
{
    auto list = (linked_list *) malloc(sizeof(linked_list));
    list->head = list->tail = nullptr;
    return list;
}

void add_node(linked_list *list, int data)
{
    auto node = create_node(data);

    if (!list->head)
        list->head = node;
    else
        list->tail->next = node;

    list->tail = node;
}

node_t *create_node(int data)
{
    auto node = (node_t *) malloc(sizeof(node_t));
    node->data = data;
    node->next = nullptr;
    return node;
}

// n: length of nodes in list
// T: O(n)
// S: O(1) extra space
void print_list(const linked_list *list)
{
    for (auto node = list->head; node; node = node->next)
        printf("%d\n", node->data);
}

void *free_list(const linked_list *list)
{
    for (auto node = list->head; node;) {
        auto garbage = node;
        node = node->next;
        free(garbage);
    }
    return nullptr;
}
