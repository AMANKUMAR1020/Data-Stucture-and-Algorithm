/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    Node* start = NULL;
    bool check(Node* end){
        if(end == NULL)
            return true;
        
        bool flag = check(end->next);
        flag = flag && start->data == end->data;
        start = start->next;

        return flag;
    }

    bool isPalindrome(Node *head) {
        start = head;
        return check(head);
    }
};
