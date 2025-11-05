/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = nullptr;

        while(temp1 != nullptr){st1.push(temp1); temp1 = temp1->next;}
        while(temp2 != nullptr){st2.push(temp2); temp2 = temp2->next;}  
        temp1 = l1; temp2 = l2;

        int rem = 0;    
        while(!st1.empty() && !st2.empty()){
            int val = st1.top()->val + st2.top()->val + rem;
            st1.pop();  st2.pop();

            rem = val/10;
            int div = val%10;
            ListNode* curr = new ListNode(div);

            curr->next = ans;
            ans = curr;
        }
        while(!st1.empty()){
            int val = st1.top()->val + rem;
            st1.pop();

            rem = val/10;
            int div = val%10;
            ListNode* curr = new ListNode(div);

            curr->next = ans;
            ans = curr;
        }
        while(!st2.empty()){
            int val = st2.top()->val + rem;
            st2.pop();

            rem = val/10;
            int div = val%10;
            ListNode* curr = new ListNode(div);

            curr->next = ans;
            ans = curr;
        }
        if(rem){
            ListNode* curr = new ListNode(rem);
            curr->next = ans;
            ans = curr;
        }
        return ans;
    }
};
