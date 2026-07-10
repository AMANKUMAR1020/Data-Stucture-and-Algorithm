/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void deleteNode(Node* del_node) {
        // code here
        Node* curr = del_node;
        
        
        if(curr->next->next == nullptr){
            curr->data = curr->next->data;
            curr->next = nullptr;
            
        } else if(curr->next->next != nullptr){
            curr->data = curr->next->data;
            curr->next = curr->next->next;
            
        } else{
            curr = nullptr;
        }
    }
};
