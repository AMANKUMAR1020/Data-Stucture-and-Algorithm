//by Author Aman Kumar
ll convertToAnyBaseCase(ll num, ll ib, ll fb){
	ll numBasePow = ib;
	ll numBase = 1;
	ll result = 0;

	while(num){
		ll rem = num%fb;
		ll temp = rem*numBase;

		result += temp;

		numBase *= numBasePow;
		num /= fb;
	}
	return result%(ll)MAX;
}



//By Ai


//By Sumit malik
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int b = scn.nextInt();

        int dn = getValueInBase(n, b);
        System.out.println(dn);
    }

    public static int getValueInBase(int n, int b) {
        int rv = 0;
        int p = 1;

        while (n > 0) {
            int dig = n % b;
            n = n / b;

            rv += dig * p;
            p = p * 10;
        }

        return rv;
    }
}
