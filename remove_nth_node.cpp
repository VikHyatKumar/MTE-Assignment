#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};


Node* removeNthFromEnd(Node* head, int N) {
  
    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < N; i++) {
        if (fast == nullptr) return head; 
        fast = fast->next;
    }

    if (fast == nullptr) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }


    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }


    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return head;
}


void printList(Node* node) {
    Node* curr = node;
    while (curr != nullptr) {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

int main() {
  

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int N = 2;
    head = removeNthFromEnd(head, N);

    printList(head);  

    return 0;
}

//Time Complexity: O(n)     

//Space Complexity: O(1)