/*structure of the node of the DLL
class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* temp = new Node(x);
        
        if(curr->data > x){
            temp->next = curr;
            curr->prev = temp;
            return temp;
        }
        
        while(curr != nullptr){
            
            if(curr->data > x){
                prev->next = temp;
                temp->prev = prev;
                
                temp->next = curr;
                curr->prev = temp;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
        if(curr == NULL){
            prev->next = temp;
            temp->prev = prev;
        }

        return head;
    }
};
