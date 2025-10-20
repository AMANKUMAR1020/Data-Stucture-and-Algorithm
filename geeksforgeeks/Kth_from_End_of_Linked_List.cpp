/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/


//method 1
class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* curr = head;
        int ans = -1;
        queue<Node*> qu;
        
        while(curr != nullptr){
            qu.push(curr);
            if(qu.size() == k){
                ans = qu.front()->data; qu.pop();
            }
            curr = curr->next;
        }
        return ans;
    }
};


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


// Alternative

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        int cnt = 0;
        Node *fst = head;
        Node *sec = head;
        
        while(k--){
            if(fst==nullptr)
                return -1;
            fst = fst->next;
        }
        
        while(fst != nullptr){
            fst = fst->next;
            sec = sec->next;
            cnt++;
        }
        return sec->data;
    }
};



