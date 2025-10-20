/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* curr = head;
        Node* temp = curr;
        unordered_map<Node*, bool> mp;
        mp[curr]=true;
        while(curr->next != nullptr && mp.find(curr->next) == mp.end()){
            mp[curr->next] = true;
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};


/*
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* curr = head;
        Node* temp = curr;
        unordered_map<Node*, bool> mp;
        
        while(curr->next != nullptr){
            if(!mp.empty() && mp.find(curr->next) != mp.end()){
                break;
            }else{
                mp[curr->next] = true;
            }
            curr = curr->next;
        }
        curr->next = nullptr;
        head = temp;
    }
};
*/
