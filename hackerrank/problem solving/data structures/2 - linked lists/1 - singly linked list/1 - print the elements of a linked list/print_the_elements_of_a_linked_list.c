// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct singly_linked_list_node singly_linked_list_node;
typedef struct singly_linked_list singly_linked_list;

struct singly_linked_list_node {
    int data;
    singly_linked_list_node *next;
};

struct singly_linked_list {
    singly_linked_list_node *head;
    singly_linked_list_node *tail;
};

singly_linked_list* read_list(const int n);
    singly_linked_list* create_singly_linked_list();
    void insert_into_list(singly_linked_list* const list, const int data);
        singly_linked_list_node* create_node(const int data);
void print_list(const singly_linked_list* const list);
void* free_list(singly_linked_list *list);

int main()
{
    int n;
    scanf("%d", &n);
    singly_linked_list *list = read_list(n);
    print_list(list);

    free_list(list);

    return 0;
}

    singly_linked_list* read_list(const int n)
    {
        singly_linked_list *list = create_singly_linked_list();
        for (int i = 0, data; i < n && scanf("%d", &data); ++i)
            insert_into_list(list, data);
        return list;
    }

        singly_linked_list* create_singly_linked_list()
        {
            singly_linked_list *list = (singly_linked_list*) malloc(sizeof(singly_linked_list));
            list->head = list->tail = NULL;
            return list;
        }

        void insert_into_list(singly_linked_list* const list, const int data)
        {
            singly_linked_list_node *node = create_node(data);

            if (!list->head)
                list->head = node;
            else
                list->tail->next = node;

            list->tail = node;
        }

            singly_linked_list_node* create_node(const int data)
            {
                singly_linked_list_node *node = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
                node->data = data;
                node->next = NULL;
                return node;
            }

        void print_list(const singly_linked_list* const list)
        {
            for (singly_linked_list_node *node = list->head; node; node = node->next)
                printf("%d\n", node->data);
        }

    void* free_list(singly_linked_list *list)
    {
        for (singly_linked_list_node *node = list->head; node;) {
            singly_linked_list_node *garbage = node;
            node = node->next;
            free(garbage);
        }
        return NULL;
    }
