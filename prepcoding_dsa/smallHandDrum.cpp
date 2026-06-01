// By Author Aman Kumar
void smallHandDrum(ll n){
	ll mid = n/2;
	ll st = 1;
	ll k = 0;

	for(ll i=0; i < n; i++){
		if(i < mid){
			for(ll j=0; j<n; j++){
				if(i==j || j==n-i-1 || i == 0)
					cout<<"*";
				else
					cout<<" ";
			}			
		}else{
			for(ll j=0; j<mid-k; j++){
				cout<<" ";
			}
			for(ll j=0; j<st; j++){
				cout<<"*";
			}
			st += 2;
			k++;
		}
		cout<<endl;
	}
}



//By Ai


// By Sumit malik
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // write ur code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int st = n;
        int sp = 0;

        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 1; j <= sp; j++) {
                System.out.print("\t");
            }

            // Print stars with hollow center logic
            for (int j = 1; j <= st; j++) {
                if (i > 1 && i <= n / 2 && j > 1 && j < st) {
                    System.out.print("\t"); // hollow space
                } else {
                    System.out.print("*\t");
                }
            }

            // Update space and star counts
            if (i <= n / 2) {
                sp++;
                st -= 2;
            } else {
                sp--;
                st += 2;
            }

            System.out.println();
        }
    }
}
