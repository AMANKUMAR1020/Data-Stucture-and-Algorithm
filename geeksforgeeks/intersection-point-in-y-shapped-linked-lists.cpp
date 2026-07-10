/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        int cnt1 = 0, cnt2 = 0;
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        while(curr1 != nullptr || curr2 != nullptr){
            if(curr1 != nullptr){cnt1++; curr1 = curr1->next;}
            if(curr2 != nullptr){cnt2++; curr2 = curr2->next;}
        }
        
        curr1 = head1;
        curr2 = head2;
        
        if(cnt2 < cnt1){
            int k = cnt1 - cnt2;
            while(k--){curr1 = curr1->next;}
            
        }else{
            int k = cnt2 - cnt1;
            while(k--){curr2 = curr2->next;}
        }
        
        while(curr1 != nullptr || curr2 != nullptr){
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return curr2;
    }
};
