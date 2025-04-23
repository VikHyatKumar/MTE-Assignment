#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    ListNode* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createList(arr, 5);

    cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "List after removing " << n << "-th node from the end: ";
    printList(head);

    return 0;
}