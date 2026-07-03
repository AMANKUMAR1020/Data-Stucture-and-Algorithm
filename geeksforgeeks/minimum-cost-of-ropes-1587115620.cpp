class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int a : arr)
            pq.push(a);
            
        int ans = 0;
        
        while(pq.size() != 1){
            
            int num1 = pq.top(); pq.pop();
            
            if(pq.empty())
                return num1;
                
            int num2 = pq.top(); pq.pop();
            
            ans += num1 + num2;
            
            pq.push(num1 + num2);
            
        }
        return ans;
    }
};
