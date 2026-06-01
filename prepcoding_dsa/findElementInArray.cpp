//By Author Aman Kumar
struct getIndex{
    ll initial = -1;
    ll last = -1;
    ll total = -1;
};

getIndex findElementInArray(ll arr[], ll n, ll target){
    getIndex val;
    for(ll i=0; i<n; i++){
        if(arr[i] == target){
            if(val.initial == -1){ //Ai is correct
                val.initial = i;
            }
            val.last = i;
            val.total += 1;            
        }
    }
    return val;
}

int main(){
	text();
	ll n,i=0; cin>>n;
    ll arr[n] = {0};

    while(i < n){
        cin>>arr[i++];
    }
    ll findVal; cin>>findVal;
	   getIndex val = findElementInArray(arr, n, findVal);

       cout<<val.initial<<'\n'<<val.last<<'\n'<<val.total<<endl;

	return 0;
}


//By Ai
struct getIndex {
    ll initial, last, total;
    getIndex() : initial(-1), last(-1), total(0) {}
};


getIndex findElementInArray(ll arr[], ll n, ll target) {
    getIndex val;

    for (ll i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (val.initial == -1) val.initial = i;
            val.last = i;
            val.total++;
        }
    }

    return val;
}


//By Sumit Malik
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        int data = scn.nextInt();
        int idx = -1;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == data) {
                idx = i;
                break;
            }
        }

        System.out.println(idx);
    }
}
