/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node* temp = nullptr;
        Node* curr = head;
        temp = curr;
        int cnt=1;
        if(x==1){
            return temp->next;
        }
        while(curr != nullptr){
            if(cnt+1 == x){
                    curr->next = curr->next->next;
                break;
            }else{
                curr = curr->next;
            }
            cnt++;
        }
        return temp;
    }
};

