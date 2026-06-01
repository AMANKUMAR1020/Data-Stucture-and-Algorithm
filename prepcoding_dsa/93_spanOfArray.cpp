//By Author Aman Kumar
ll maxVal(ll a, ll b){
    return a > b ? a : b;
}

ll minVal(ll a, ll b){
    return a < b ? a : b;
}

ll spanOfArray(ll arr[], ll n){
    if(n==0)
        return 0;
    if(n==1)
        return arr[0];

    ll maxi = arr[0];
    ll mini = arr[0];
    ll res = 0;

    for(ll i=0; i<n; i++){
        maxi = maxVal(maxi, arr[i]);
        mini = minVal(mini, arr[i]);

        if(res < maxi - mini){
            res = maxi - mini;
        }
    }
    return res;
}

//By Ai

ll spanOfArray(ll arr[], ll n) {
    if (n == 0) return 0;

    ll maxi = arr[0], mini = arr[0];

    for (ll i = 1; i < n; i++) {
        if (arr[i] > maxi) maxi = arr[i];
        if (arr[i] < mini) mini = arr[i];
    }

    return maxi - mini;
}


//By Sumit Malik
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        int max = arr[0];
        int min = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        int span = max - min;
        System.out.println(span);
    }
}
