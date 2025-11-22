/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */


//method 2
class Solution {
  public:
    int getMiddle(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while(fast->next && fast->next->next != nullptr){
            // cout<<slow->data<<" "<<fast->data<<endl;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<slow->data<<" "<<fast->data<<endl;
        if(fast->next != nullptr)
            slow = slow->next;
        return slow->data;
    }
};

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
