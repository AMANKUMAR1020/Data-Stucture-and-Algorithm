class Solution {
  public:

    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        unordered_map<string,int> mp;
        
        for(int i=0; i<n; i++)
            mp[arr[i]]++;

        int ans1 = 0;
        string ans2="";

        for(auto m : mp){
           if (m.second > ans1) {
                ans1 = m.second;
                ans2 = m.first;                 // set on new max
            } else if (m.second == ans1) {
                ans2 = min(ans2, m.first);      // tie -> lexicographically smaller
            }
        }
        return {ans2, iTos(ans1)};
    }
    
    string iTos(int num){
        string str = "";
        while(num){
            char i = ('0' + (num%10));
            str += i;
            num /= 10;
            // cout<<num<<endl;
        }
        // cout<<str<<endl;
        return str;
    }
};
