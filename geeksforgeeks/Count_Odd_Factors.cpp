class Solution {
  public:
    int count(int N) {
        return (int)sqrt(N);
    }
};


/*
class Solution {
  public:
    int count(int N) {
        int n = sqrt(N);
        int cnt=0;
        
        for(int i=1; i<=n; i++)
            if(n%i == 0)
                cnt++;
            
            return cnt;
    }
};
*/
