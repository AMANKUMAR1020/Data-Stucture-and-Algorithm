//By Author Aman Kumar
void patternSwastik(ll n){
	ll mid = n/2;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(i < mid){
				if((i==0 && j<mid) || j==n-1 || j==mid)
					cout<<"*";
				else
					cout<<" ";
			}else{
				if(i==mid || j==0 || j==mid || (i==n-1 && j>mid))
					cout<<"*";
				else
					cout<<" ";
			}
		}
		cout<<endl;
	}
}


//By Ai


//By Sumit Malik
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1) {
                    if (j == n || j <= n / 2 + 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else if (i <= n / 2) {
                    if (j == n || j == n / 2 + 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else if (i == n / 2 + 1) {
                    System.out.print("*\t");
                } else if (i < n) {
                    if (j == 1 || j == n / 2 + 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else {
                    if (j == 1 || j >= n / 2 + 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                }
            }
            System.out.println();
        }
    }
}
