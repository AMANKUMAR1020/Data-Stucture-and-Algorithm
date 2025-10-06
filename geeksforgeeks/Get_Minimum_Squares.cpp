// User function Template for C++

// class Solution {
//   public:
//     int MinSquares(int n) {
//         int ind = sqrt(n);
//         int target = n;
//         int cnt = 0;
        
//         while(target  0){
//             int pro = ind*ind;
//             if(pro <= target){
//                 target -= pro;
//                 cnt++;
//             }else{
//                 ind--;
//             }
//         }
//         return cnt;
//     }
    
//     // private:
//     // bool prime(int N){
//     //     if (N <= 1) return true;
//     //     if(N==2 || N==3)    return true;
//     //     if(N%2==0 || N%3==0)    return false;
            
//     //     int n = sqrt(N);

//     //     for(int i=5; i<=n; i+=6){
//     //         if(N%i==0 || N%(i+2)==0){
//     //             return false;
//     //         }
//     //     }
//     //     return true;
//     // }

// };
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    int MinSquares(int n) {
        if (n <= 0) return 0;

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int s = 1; s * s <= i; ++s) {
                dp[i] = min(dp[i], dp[i - s * s] + 1);
            }
        }
        return dp[n];
    }
};

/*// User function Template for C++

class Solution {
  public:
    int MinSquares(int n) {
        
        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++)
            if(prime(i))    
                mp[i] = i*i;

        int cnt = 0;
        int ind = n;
        int target = n;
        while(target < 0){
            if(mp.find(ind) != mp.end()){
                if(mp[ind] <= target){
                    target -= mp[ind];
                    cnt++;
                }else{
                    ind--;
                }
            }else{
                ind--;
            }
        }
        
        return cnt;
    }
    
private:

    bool prime(int N){
        if (N <= 1) return false;
        if(N==2 || N==3)    return true;
        if(N%2==0 || N%3==0)    return false;
            
        int n = sqrt(N);

        for(int i=5; i<=n; i+=6){
            if(N%i==0 || N%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    
    
};
*/
