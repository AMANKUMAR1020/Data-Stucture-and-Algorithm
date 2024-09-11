class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(start || goal){
            bool ok1 = start & 1;
            bool ok2 = goal & 1;

            if(ok1 != ok2)cnt++;

            start = start>>1;
            goal = goal>>1;
        }
        return cnt;
    }
};
