class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,bool> mp;
        int n = nums.size();
        int m = nums[0].size();

        for(string n : nums){
            mp[n]=true;
        }

        for(int i=0; i< 2<<n; i++){
            string str = inBits(i,m);
            if(mp.find(str) == mp.end()){
                return str;
            }
        }
        return "0";
    }
private:
    string inBits(int num,int n){
        string str="";
        while(num){
            str = num&1 ? "1" + str : "0" + str;
            num >>= 1;
        }
        for(int i=str.size(); i<n; i++){
            str = "0" + str;
        }
        cout<<str<<endl;
        return str;
    }
};
