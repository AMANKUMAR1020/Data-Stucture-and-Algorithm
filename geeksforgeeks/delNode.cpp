class Solution {
  public:
    Node* delPos(Node* head, int x) {
    
        Node* curr = head;
        
        while(curr != nullptr){
            if(curr->data == x){
                
                if(curr->prev != nullptr && curr->next != nullptr){
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    break;

                }else if(curr->prev == nullptr){
                    Node* temp = curr->next;
                    curr->next->prev = nullptr;
                    break;

                }else if(curr->next == nullptr){
                    Node* temp = curr->prev;
                    curr->prev->next = nullptr;
                    break;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
