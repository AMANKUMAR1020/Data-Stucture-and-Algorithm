//By Auhtor Aman Kumar
void patternW(ll n){
	ll mid = n/2;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(i < mid){
				if(j==0 || j==n-1){
					cout<<"*\t";
				}else{
					cout<<"\t";
				}
			}else{				
				if(j==i || j==n-i-1 || j==0 || j==n-1){
					cout<<"*\t";
				}else{
					cout<<"\t";
				}
			}
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
        int n = scn.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == 1 || j == n) {
                    System.out.print("*\t");
                } else if (i > n / 2 && (i == j || i + j == n + 1)) {
                    System.out.print("*\t");
                } else {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }
    }
}
