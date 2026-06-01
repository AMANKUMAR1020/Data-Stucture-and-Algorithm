// by Author Aman Kumar
bool isPrime(ll n){
	if(n < 1)
		return false;
	
	if(n==2 || n==3)
		return true;
	
	if(n%2==0 || n%3==0)
		return false;

	for(ll i=5; i <= n/i; i += 6)
		if(n/i==0 || n/(i+2)==0)
			return false;

	return true;

}

vector<ll> primeFactorList(ll n){
	ll div = 2;
	vector<ll> arr;

	while(n != 1){
		if(isPrime(div)){
			if(n%div==0){
				n /= div;
				arr.push_back(div);
			}
			else
				div++;
		}else{
			div++;
		}
	}
	return arr;
}

void print(vector<ll>& num){
	for(ll n : num)
		cout<<n<<" ";
}



// By AI
const int N = 1e6 + 5;
int spf[N];  // Smallest Prime Factor

void computeSPF() {
    for (int i = 0; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {  // i is prime
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}



// By Simit Malik
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        for (int div = 2; div * div <= n; div++) {
            while (n % div == 0) {
                n = n / div;
                System.out.print(div + " ");
            }
        }

        if (n != 1) {
            System.out.print(n);
        }
    }
}
