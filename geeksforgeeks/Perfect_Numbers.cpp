class Solution {
  public:
    bool isPerfect(int n) {
        int sum = 0;
        int target = n;
        int i=1;
        while(i < n){
            if(target%i==0)
                sum += i;
            i++;
        }
        return sum == n;
    }
};
