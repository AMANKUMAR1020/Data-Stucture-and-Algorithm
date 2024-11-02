class Solution {
public:
    bool isCircularSentence(string sent) {
        int n = sent.size();

        for(int i=0; i<n; i++){
            if( sent[i] == ' '){

                cout<<sent[i-1]<<" "<<sent[i+1]<<'\n';

                if(sent[i-1] != sent[i+1])
                    return false;
            }
        }
        return sent[0] == sent[n-1];
    }
};
