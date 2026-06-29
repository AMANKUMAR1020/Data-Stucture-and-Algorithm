/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int cnt = 0;
    void print(Node* head){
        Node* curr = head;
        
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    // Node* removeKthNodeFromLast(Node* head, int k){
    // }
    
    int GetKthFromLast(Node* head, int k){
        if(head == NULL)
            return -1;
            
        int val = GetKthFromLast(head->next, k);
        
        cnt += 1;
        if(cnt == k)
            val = head->data;
        
        return val;
    }
    
    int getKthFromLast(Node* head, int k) {
        
        return GetKthFromLast(head, k);
    }
};
