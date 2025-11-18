class Solution {
  public:
    void deleteMid(stack<int>& s) {
        int target = (s.size() + 1)/2;
        vector<int> vec;
        int start = 1;
        
        while(!s.empty()){
            if(start != target)
                vec.push_back(s.top()); s.pop();
            start++;
        }
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            s.push(*it);
        }

    }
};
