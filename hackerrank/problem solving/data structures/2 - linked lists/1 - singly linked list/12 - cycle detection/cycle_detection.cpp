// n: number of nodes
// T: O(n) amortized
// S: O(n) extra space
bool has_cycle(SinglyLinkedListNode* head) {
    unordered_set<SinglyLinkedListNode*> refs;

    while (head && refs.find(head) == refs.end()) {
        refs.insert(head);
        head = head->next;
    }

    return head;
}
