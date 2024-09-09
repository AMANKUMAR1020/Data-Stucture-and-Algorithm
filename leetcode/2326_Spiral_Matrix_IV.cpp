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

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m,vector<int>(n,-1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                if(head != nullptr)
                    {vec[top][j] = head->val;
                    head=head->next;}
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                if(head != nullptr)
                {vec[i][right] = head->val;
                head = head->next;}
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    if(head != nullptr)
                    {vec[bottom][j] = head->val;
                    head = head->next;}
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    if(head != nullptr)
                        {vec[i][left] = head->val;
                        head = head->next;}
                }
                left++;
            }
        }
        return vec;
    }
};
