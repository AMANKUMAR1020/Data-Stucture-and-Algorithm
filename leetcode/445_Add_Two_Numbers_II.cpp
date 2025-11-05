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
        int cnt1 = 0, cnt2 = 0;

        for (ListNode* t = l1; t != nullptr; t = t->next) cnt1++;
        for (ListNode* t = l2; t != nullptr; t = t->next) cnt2++;

        int carry = 0;
        ListNode* res = solve(l1, l2, cnt1, cnt2, carry);

        if (carry) {
            ListNode* head = new ListNode(carry);
            head->next = res;
            return head;
        }
        return res;
    }

private:
    ListNode* solve(ListNode* l1, ListNode* l2, int n1, int n2, int& carry) {
        if (n1 == 0 && n2 == 0) return nullptr;

        ListNode* next = nullptr;
        int sum = 0;

        if (n1 > n2) {
            next = solve(l1->next, l2, n1 - 1, n2, carry);
            sum = l1->val + carry;
        } else if (n1 < n2) {
            next = solve(l1, l2->next, n1, n2 - 1, carry);
            sum = l2->val + carry;
        } else {
            next = solve(l1->next, l2->next, n1 - 1, n2 - 1, carry);
            sum = l1->val + l2->val + carry;
        }

        ListNode* node = new ListNode(sum % 10);
        node->next = next;
        carry = sum / 10;
        return node;
    }
}; 
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1 = 0, cnt2 = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = nullptr;

        while(temp1 != nullptr){cnt1++; temp1 = temp1->next;}
        while(temp2 != nullptr){cnt2++; temp2 = temp2->next;}
        temp1 = l1; temp2 = l2;

        return solve(l1,l2,cnt1,cnt2,0);
    }
private:
    ListNode* solve(ListNode* l1, ListNode* l2, int n1, int n2, int rem){
        if(n1==0 && n2==0)
            return nullptr;
        ListNode* newNode1;
        ListNode* newNode2;
        int val = 0;
        if(n1 < n2){
            val = (l2->val + rem)%10;
            newNode2 = solve(l1,l2->next,n1, n2-1, val/10);
            cout<<l2->val<<" "<<val<<endl;

        }else if(n1 > n2){
            val = (l1->val + rem)%10;
            newNode2 = solve(l1->next,l2,n1-1, n2, val/10);
            cout<<l1->val<<" "<<val<<endl;

        }else{
            val = (l1->val + l2->val + rem)%10;
            newNode2 = solve(l1->next,l2->next,n1-1, n2-1, val/10);
            cout<<l1->val<<" "<<l2->val<<" "<<val<<endl;
        }
        newNode1 = new ListNode(val);
        newNode1->next = newNode2;
        return newNode1;
    }
};
*/


/*
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
*/
