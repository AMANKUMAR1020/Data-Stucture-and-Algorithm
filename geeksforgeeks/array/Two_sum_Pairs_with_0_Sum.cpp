// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> vec;
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            
            if(!mp.empty() && mp.find(-arr[i]) != mp.end()){
                
                vec.push_back({min(-arr[i], arr[i]), max(arr[i], -arr[i])});
                
            }else{
                mp[arr[i]] = i;
            }
        }
        sort(vec.begin(), vec.end());
        
        return vec;
        
    }
};



/*
// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        vector<vector<int>> vec;
        unordered_map<int,bool> mp;
        
        for(int a : arr){
            if(!mp.empty() && mp.find(-a) != mp.end()){
                vec.push_back({-a,a});
                if(a<0){
                    mp.erase(-a);
                }else{
                    mp.erase(a);
                }
            }else{
                mp[a] = true;
            }
        }
        
        sort(vec.begin(),vec.end(),[](vector<int>& a, vector<int>& b){
            return a[1] > b[1] ;
        });
        
        
        return vec;
    }
};

// num1 = -num2
*/