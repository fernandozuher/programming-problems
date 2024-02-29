// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true

// // BAD INPUT COMPOSED BY HACKERRANK SOURCE. So not much was changed from the initial code.

#include <iostream>
#include <memory>

using namespace std;

class Singly_Linked_List_Node {
public:
    int data;
    shared_ptr<Singly_Linked_List_Node> next;

    Singly_Linked_List_Node(const int data): data{data}, next{nullptr} {}
};

class Singly_Linked_List {
public:
    shared_ptr<Singly_Linked_List_Node> head;
    shared_ptr<Singly_Linked_List_Node> tail;

    Singly_Linked_List(): head{nullptr}, tail{nullptr} {}

    void insert_node(const int data)
    {
        shared_ptr<Singly_Linked_List_Node> node {new Singly_Linked_List_Node(data)};

        if (!head)
            head = node;
        else
            tail->next = node;

        tail = node;
    }
};

shared_ptr<Singly_Linked_List> initialize_list(int n)
{
    shared_ptr<Singly_Linked_List> list {new Singly_Linked_List()};
    while (n--) {
        int x;
        cin >> x;
        list->insert_node(x);
    }
    return list;
}

bool has_cycle(shared_ptr<Singly_Linked_List_Node> head, int n)
{
    for (; n--; head = head->next);
    return head->data != -1;
}

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int index;
        cin >> index;

        int n;
        cin >> n;
        shared_ptr<Singly_Linked_List> list {initialize_list(n)};

        shared_ptr<Singly_Linked_List_Node> extra {new Singly_Linked_List_Node(-1)};
        shared_ptr<Singly_Linked_List_Node> temp {list->head};

        for (int i = 0; i < n; ++i) {
            if (i == index)
                extra = temp;
            if (i != n - 1)
                temp = temp->next;
        }
        temp->next = extra;

        cout << has_cycle(list->head, n) << '\n';
    }

    return 0;
}
