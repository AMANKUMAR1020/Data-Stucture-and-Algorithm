// by Author Aman Kumar
// void patternDownUp(ll n){
// 	for(ll i=0; i<n; i++){
// 		ll cnt=1;
// 		for(ll j=0; j<=i; j++){
// 			cout<<cnt;
// 			cnt++;
// 		}
// 		for(ll j=0; j<2*(n-i)-3; j++){
// 			cout<<" ";
// 		}
// 		--cnt;
// 		for(ll j=0; j<=i; j++){
// 			if(cnt != n)
// 				cout<<cnt;
// 			--cnt;
// 		}
// 		cout<<endl;
// 	}
// }


void patternDownUp(ll n){
	ll sp = 2*n - 4;
	ll st = 1;
	ll cnt = 1;

	for(ll i=0; i<n; i++){
		for(ll j=0; j<st; j++){
			cout<<cnt;
			cnt++;
		}
		for(ll j=0; j<=sp; j++){
			cout<<".";
		}
		if(i==n-1){
			--cnt;
		}
		for(ll j=0; j<st; j++){
			if(cnt-1 != 0)
				cout<<--cnt;
		}
		st++;
		sp -= 2;
		cout<<endl;
	}
}


// By Ai
#include <iostream>
#include <string>
using namespace std;

void patternDownUp(long long n) {
    long long sp = 2 * n - 4;
    long long st = 1;
    long long cnt = 1;
    string line;

    for (long long i = 0; i < n; i++) {
        line.clear();

        // Left side increasing numbers
        long long start = cnt;
        for (long long j = 0; j < st; j++) {
            line += to_string(cnt++);
        }

        // Dots
        line += string(sp + 1, '.');

        // Right side decreasing numbers
        long long temp = cnt - 1;
        if (i == n - 1) temp--; // avoid printing central number twice

        for (long long j = 0; j < st; j++) {
            if (temp > 0)
                line += to_string(temp--);
        }

        cout << line << "\n";

        st++;
        sp -= 2;
    }
}

1......1
23....32
456..654
7898765


// By Summit Malik
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        int sp = 2 * n - 3;
        int st = 1;
        int val = 1;

        for (int i = 1; i <= n; i++) {
            // Print increasing part
            for (int j = 1; j <= st; j++) {
                System.out.print(val + "\t");
                val++;
            }

            // Print spaces
            for (int j = 1; j <= sp; j++) {
                System.out.print("\t");
            }

            // Decrease st by 1 if it's the last row
            if (i == n) {
                st--;
                val--;
            }

            // Print decreasing part
            for (int j = 1; j <= st; j++) {
                val--;
                System.out.print(val + "\t");
            }

            // Update counts for next row
            st++;
            sp -= 2;

            // Move to next line
            System.out.println();
        }
    }i
}
