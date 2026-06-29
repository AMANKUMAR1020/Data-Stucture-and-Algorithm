const int maxi = 1e5+9;

class Solution {
  public:
    bool checkHappyNumber(int n){
        unordered_set<int> st;
        
        while(n != 1){
            if(st.find(n) != st.end())
                return false;
                
            st.insert(n);
            int sum = 0;
            
            while(n){
                int rem = n%10;
                sum += rem*rem;
                n /= 10;
            }
            n = sum;
        }
        
        return true;
    }
    int nextHappy(int N) {
        
        while(N < maxi){
            N += 1;
            if(checkHappyNumber(N))
                return N;
        }
        return -1;
    }
};
