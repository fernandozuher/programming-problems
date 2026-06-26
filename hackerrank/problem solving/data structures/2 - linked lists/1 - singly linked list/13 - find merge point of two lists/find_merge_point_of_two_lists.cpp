// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true
// C++23

// This solution is better than the expected one for this problem, although it won't run on the platform,
// only locally with custom test cases.
// The problem statement is confusing and contains contradictory information about some constraints.

import std;
using namespace std;

template<class T>
concept Primitive = is_fundamental_v<T>;

template<Primitive T>
struct Node {
    T data;
    shared_ptr<Node<T>> next;
};

using two_nodes = pair<shared_ptr<Node<int>>, shared_ptr<Node<int>>>;

two_nodes test_case_point_at_2()
{
    auto head1{ make_shared<Node<int>>(1) };
    auto node2{ make_shared<Node<int>>(2) };
    auto node3{ make_shared<Node<int>>(3) };
    head1->next = node2;
    node2->next = node3;

    auto head2{ make_shared<Node<int>>(1) };
    head2->next = node2;

    return { head1, head2 };
}

two_nodes test_case_point_at_3()
{
    auto head1{ make_shared<Node<int>>(1) };
    auto node2{ make_shared<Node<int>>(2) };
    auto node3{ make_shared<Node<int>>(3) };
    head1->next = node2;
    node2->next = node3;

    auto head2{ make_shared<Node<int>>(1) };
    head2->next = node3;

    return { head1, head2 };
}

two_nodes test_case_no_merge()
{
    auto head1{ make_shared<Node<int>>(1) };
    auto node2{ make_shared<Node<int>>(2) };
    auto node3{ make_shared<Node<int>>(3) };
    head1->next = node2;
    node2->next = node3;

    auto head2{ make_shared<Node<int>>(1) };
    auto node2_2{ make_shared<Node<int>>(2) };
    auto node3_2{ make_shared<Node<int>>(3) };
    head2->next = node2_2;
    node2_2->next = node3_2;

    return { head1, head2 };
}

// n_l1: length of l1
// n_l2: length of l2
// T: O(n_l1 + n_l2)
// S: O(n_l1 + n_l2) extra space
template<Primitive T>
T find_merge_point(const shared_ptr<Node<T>>& l1, const shared_ptr<Node<T>>& l2)
{
    unordered_set<Node<T>*> addresses;
    for (auto it1{ l1 }, it2{ l2 }; it1 || it2;) {
        for (auto [i, it] : views::enumerate(array{ it1, it2 })) {
            if (it) {
                if (addresses.contains(it.get()))
                    return it->data;

                addresses.insert(it.get());

                if (i == 0)
                    it1 = it1->next;
                else
                    it2 = it2->next;
            }
        }
    }
    return T{};
}

int main()
{
    for (const auto& [head1, head2] : { test_case_point_at_2(), test_case_point_at_3(), test_case_no_merge() })
        println("{}", find_merge_point(head1, head2));
    return 0;
}
