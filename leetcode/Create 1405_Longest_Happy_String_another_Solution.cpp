class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap;

        if(a != 0)  maxHeap.push({a,'a'});
        if(b != 0)  maxHeap.push({b,'b'});
        if(c != 0)  maxHeap.push({c,'c'});

        string str;

        while(!maxHeap.empty()){
            
            pair<int,char> val = maxHeap.top(); maxHeap.pop();

            int n = str.size();
            if(n >= 2 && str[n-2] == str[n-1] && str[n-1] == val.second){

                if(maxHeap.empty()){
                    break;
                }

                pair<int,char> temp = maxHeap.top(); maxHeap.pop();

                str += temp.second;
                if(--temp.first > 0){
                    maxHeap.push(temp);
                }

                maxHeap.push(val);
            }else{

                str += val.second;
                if(--val.first > 0)
                    maxHeap.push(val);
            }
        }
        return str;
    }
};
