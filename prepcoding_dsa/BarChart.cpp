// By Author Aman Kumar
void BarChart(ll arr[], ll n){
    ll height = maxVal(arr,n);
    char grid[height][n];

    for(ll i=0; i<height; i++){
        for(ll j=0; j<n; j++){
            grid[i][j] = '-';
        }
    }

    for(ll i=0; i<n; i++){
        ll heightOfArr = arr[i];
        for(ll j=0; j<=heightOfArr; j++){
            grid[height-j][i] = '*';
        }
    }

    for(ll i=0; i<height; i++){
        for(ll j=0; j<n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

// void BarChart(ll arr[], ll n){
//     ll height = maxVal(arr,n);
//     char grid[height][n];

//     for(ll i=0; i<height; i++){
//         for(ll j=0; j<n; j++){
//             if(arr[j] > i)
//                 grid[height-i-1][j] = '*';
//             else
//                 grid[height-i-1][j] = '-';
//         }
//     }

//     for(ll i=0; i<height; i++){
//         for(ll j=0; j<n; j++){
//             cout<<grid[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


// By Ai
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll maxVal(const vector<ll>& arr) {
    ll maxHeight = arr[0];
    for (ll val : arr) {
        if (val > maxHeight)
            maxHeight = val;
    }
    return maxHeight;
}

void BarChart(const vector<ll>& arr) {
    ll n = arr.size();
    ll height = maxVal(arr);

    for (ll row = height; row >= 1; row--) {
        for (ll col = 0; col < n; col++) {
            if (arr[col] >= row)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << '\n';
    }
}


// By Sumit Malik
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
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        for (int floor = max; floor >= 1; floor--) {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= floor) {
                    System.out.print("*\t");
                } else {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }
    }
}
