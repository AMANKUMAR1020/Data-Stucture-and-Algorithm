/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        int cnt = 1;
        Node* ans = new Node(-1);
        Node* temp = ans;
        Node* curr = head;
        unordered_map<Node*, int> mp1;
        unordered_map<int, Node*> mp2;
        
        while(curr != nullptr){
            Node* temp2 = new Node(curr->data);
            
            mp1[curr] = cnt;
            mp2[cnt] = temp2;

            temp->next = temp2;
            temp = temp->next;
            
            curr = curr->next;
            
            cnt++;
        }
        
        curr = head;
        temp = ans->next;
        
        while(curr != nullptr){
            
            temp->random = mp2[mp1[curr->random]];

            curr = curr->next;
            temp = temp->next;
            
            cnt++;
        }
        return ans->next;
    }
};

