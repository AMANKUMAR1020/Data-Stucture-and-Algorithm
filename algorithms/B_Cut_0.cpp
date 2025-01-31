void solve() {
	char str[10];	scanf("%s",str);
	int i=0,len = strlen(str);
	
	while(str[len-i-1] == '0' && i<len){i++;}
	
	if(str[len-i-1]=='.'){
		for(int j=0; j<len-i-1; j++)printf("%c",str[j]);
	}
	else{
		for(int j=0; j<len-i; j++)
		printf("%c",str[j]);
	}
}

/*
Sample Input 1
Copy
1.012
Sample Output 1
Copy
1.012
1.012 can be printed as it is.

Sample Input 2
Copy
12.340
Sample Output 2
Copy
12.34
Printing 12.340 without the trailing 0 results in 12.34.

Sample Input 3
Copy
99.900
Sample Output 3
Copy
99.9
Printing 99.900 without the trailing 0s results in 99.9.

Sample Input 4
Copy
0.000
Sample Output 4
Copy
0
Printing 0.000 without trailing 0s or an unnecessary decimal point results in 0.


*/
