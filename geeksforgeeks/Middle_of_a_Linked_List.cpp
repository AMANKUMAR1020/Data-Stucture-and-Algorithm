/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        Node* temp = head;
        Node* curr = head;
        while(curr != nullptr && curr->next  != nullptr){
            curr = curr->next->next;
            temp = temp->next;
        }
        return temp->data;
    }
};
