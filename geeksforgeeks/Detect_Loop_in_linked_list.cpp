class Solution {
  public:
    bool detectLoop(Node* head) {
        if(head == nullptr)   return true;
        
        Node* nxt1 = head;
        Node* nxt2 = head;

        while(nxt1 != nullptr && nxt2 != nullptr){
            if(nxt1->next == nullptr || nxt2->next == nullptr 
                || nxt2->next->next == nullptr)
                return false;
                
            nxt1 = nxt1->next;
            nxt2 = nxt2->next->next;
            if(nxt1 == nxt2)
                return true;
//            cout<<nxt1->data<<" ";
        }
        return false;
    }
};
