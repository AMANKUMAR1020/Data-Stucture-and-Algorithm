/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                int cnt = 1;
                Node* temp = slow->next;
                
                while(temp != fast){
                    cnt++;
                    temp = temp->next;
                }
                return cnt;
            }
            
        }
        return 0;
    }
};
