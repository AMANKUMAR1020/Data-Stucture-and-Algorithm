//By Author Aman Kumar
void patternArrow(ll n){
	ll mid = n/2;
	ll st = 1;

	for(ll i=0; i < n; i++){
		for(ll j=0; j<mid; j++){
			if(i==mid)
				cout<<"*";
			else
				cout<<" ";
		}

		for(ll j=0; j<st; j++){
			cout<<"*";
		}

		if(i < mid){
			st++;
		}else{
			st--;
		}

		cout<<endl;
	}
}


//By Ai


//By Sumit malik
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        // write ur code here
        int n = scn.nextInt();
        int sp = n / 2;
        int st = 1;

        for (int i = 1; i <= n; i++) {
            // Print leading spaces or center star row
            for (int j = 1; j <= sp; j++) {
                if (i == n / 2 + 1) {
                    System.out.print("*\t");
                } else {
                    System.out.print("\t");
                }
            }

            // Print stars
            for (int j = 1; j <= st; j++) {
                System.out.print("*\t");
            }

            // Update spacing and star counts
            if (i <= n / 2) {
                st++;
            } else {
                st--;
            }

            System.out.println();
        }
    }
}
