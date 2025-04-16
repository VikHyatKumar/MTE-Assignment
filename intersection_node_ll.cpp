#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


Node *intersectPoint(Node *head1, Node *head2) {
  	
  	// Iterate over second list and for each node
  	// Search it in first list
    while (head2 != nullptr) {
        Node *temp = head1;
        while (temp) {
          
            // If both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
  	
    return nullptr;
}

int main() {
    
  	Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

  	Node *head2 = new Node(3);  
  	head2->next = new Node(6);
    head2->next->next = new Node(9);
  
    head2->next->next->next = head1->next;

    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}
