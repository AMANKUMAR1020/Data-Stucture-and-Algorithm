// By Author Aman Kumar
void patternNumDaimond(ll n){
	ll num = 1;
	ll sp = n/2;
	ll cnt = 1;

	for(ll i=0; i<n; i++){
		for(ll j=0; j<sp; j++){
			cout<<" ";
		}
		ll val = cnt;
		for(ll j=0; j<num; j++){
			cout<<val<<"";
			if(j < num/2){
				val++;
			}else{
				val--;
			}
		}
		if(i < n/2){
			sp--;
			cnt++;
			num += 2;
		}else{
			sp++;
			cnt--;
			num -= 2;
		}
		cout<<endl;
	}
}

//By Ai
import java.util.Scanner;

public class OptimizedPattern {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int spaces = n / 2;
        int stars = 1;
        int val = 1;
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            // Print spaces
            sb.append("\t".repeat(spaces));

            // Print pyramid values
            int cval = val;
            int mid = stars / 2;
            for (int j = 0; j < stars; j++) {
                sb.append(cval).append("\t");
                cval += (j < mid) ? 1 : -1;
            }
            sb.append("\n");

            // Update counters
            if (i <= n / 2) {
                spaces--;
                stars += 2;
                val++;
            } else {
                spaces++;
                stars -= 2;
                val--;
            }
        }

        System.out.print(sb);
    }
}


// By Sumit malik
import java.util.Scanner;

public class PatternProgram {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int sp = n / 2;
        int st = 1;
        int val = 1;

        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 1; j <= sp; j++) {
                System.out.print("\t");
            }

            // Print values
            int cval = val;
            for (int j = 1; j <= st; j++) {
                System.out.print(cval + "\t");

                if (j <= st / 2) {
                    cval++;
                } else {
                    cval--;
                }
            }

            // Update counters
            if (i <= n / 2) {
                sp--;
                st += 2;
                val++;
            } else {
                sp++;
                st -= 2;
                val--;
            }
        }
    }
}

