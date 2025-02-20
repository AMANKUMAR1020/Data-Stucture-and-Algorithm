class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> st;
        st.push("");
        int cnt=0;

        while(st.size() > 0){
            string curr = st.top(); st.pop();

            if(curr.size() == n){
                cnt++;
                if(cnt == k){
                    return curr;
                }
                continue;
            }

            for(char c = 'c'; c >='a'; c--){
                if(curr.size()>0 && curr.back() == c)
                    continue;
                st.push(curr + c);
            }
        }
        return "";
    }
};


/*
@another solution
class Solution {
public:
    string getHappyString(int n, int k) {
        string str="";
        vector<string> vec;
        unordered_map<string,bool> mp;

        res(vec,str,n,mp);

        if (vec.size() < k) return "";

        sort(vec.begin(), vec.begin());

        return vec[k-1];
    }
private:
    void res(vector<string> &vec, string &str,int n, unordered_map<string, bool> &mp){
        if(str.length() == n){
            vec.push_back(str);
            return ;
        }

        if(!str.empty()){
            if(mp[str])return;
            mp[str]=true;
        }

        for(char c : {'a','b','c'}){
            if(!str.empty() && str.back() == c)
                continue;
            str.push_back(c);
            res(vec,str,n,mp);
            str.pop_back();
        }
    }
};

@another solution 
class Solution {
public:
    string getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an
        // empty string
        if (k > total) return "";

        string result(n, 'a');

        // Define mappings for the next smallest and greatest valid characters
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        // Calculate the starting indices for strings beginning with 'a', 'b',
        // and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } else {
            result[0] = 'c';
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character
            // position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }

        return result;
    }
};
*/
