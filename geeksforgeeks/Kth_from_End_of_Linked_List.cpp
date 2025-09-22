/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        int cnt = 0;
        Node *curr = head;
        while(curr != nullptr){
            curr = curr->next;
            cnt++;
        }
        if(cnt < k)
            return -1;
        curr = head;
        cnt -= k;
        while(cnt--){
            curr = curr->next;
        }
        return curr->data;
    }
};



