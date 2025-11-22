/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* temp = head;
        Node* curr = temp;
        Node* newNode = new Node(x);

        if(head == nullptr)
            return newNode;
            
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
        
        head = temp;
        return head;
    }
};



// method 2
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node** curr = &head;
        while(*curr != nullptr){
            curr = &((*curr)->next);
        }
        *curr = new Node(x);
        return head;
    }
};