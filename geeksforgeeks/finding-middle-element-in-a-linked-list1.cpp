/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        Node *slow = head;
        Node *fast = head;
        Node *curr = head;
        
        if(curr->next == NULL)
            return curr->data;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next == NULL ? fast->next : fast->next->next;
        }
        
        return slow->data;
    }
};
