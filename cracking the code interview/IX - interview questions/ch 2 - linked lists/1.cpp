// From C++23

#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

#include  "Singly_Linked_List.h"

using namespace std;
using namespace list_exercises;

template<class T = int>
vector<Singly_Linked_List<T>> data_test();
template<class T = int>
void test(Singly_Linked_List<T>& list, bool with_buffer);
template<class T = int>
void deduplicate(Singly_Linked_List<T>& list);
template<class T = int>
void deduplicate_without_buffer(Singly_Linked_List<T>& list);

int main()
{
    for (const auto with_buffer : {true, false}) {
        for (auto& list : data_test())
            test(list, with_buffer);
        println("");
    }
    return 0;
}

template<class T>
vector<Singly_Linked_List<T>> data_test()
{
    return {
        Singly_Linked_List{{1, 2, 3, 3, 2, 1}},
        Singly_Linked_List{{1, 2, 3, 3, 2, 1, 1, 2, 3, 3, 2, 1, 5, 1, 2, 3, 3, 2, 1}}
    };
}

template<class T>
void test(Singly_Linked_List<T>& list, const bool with_buffer)
{
    cout << "Original list: ";
    list.print_list();

    if (with_buffer) {
        deduplicate(list);
        cout << "Deduplicated list: ";
    }
    else {
        deduplicate_without_buffer(list);
        cout << "Deduplicated list without buffer ";
    }

    list.print_list();
}

template<class T>
void deduplicate(Singly_Linked_List<T>& list)
{
    unordered_map<int, int> hash;
    // SPACE and RUNTIME = O(n)
    for (auto node{list.head()}, previous_node{list.head()}; node; previous_node = node, node = node->next)
        if (auto data{node->data}; ++hash[data] > 1) {
            previous_node->next = node->next;
            --hash[data];
            node = previous_node;
        }
}

template<class T>
void deduplicate_without_buffer(Singly_Linked_List<T>& list)
{
    // RUNTIME = O(n^2)
    for (auto p1{list.head()}; p1; p1 = p1->next)
        for (auto p2{p1->next}, p2_previous{p1}; p2; p2_previous = p2, p2 = p2->next)
            if (p1->data == p2->data) {
                p2_previous->next = p2->next;
                p2 = p2_previous;
            }
}
