#include<bits/stdc++.h>
#include<iostream>

#define ONLINE_JUDGE

using namespace std;
using ll = long long int;

void text(){
	#ifdef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

// void minimumStack(stack<ll>& st){
// 	int mini = INT_MAX;
// 	mini = min(mini,10);st.push(10);
// 	cout<<mini<<endl;
// 	mini = min(mini,20);st.push(20);
// 	cout<<mini<<endl;
// 	mini = min(mini,0);st.push(0);
// 	cout<<mini<<endl;
// 	mini = min(mini,40);st.push(40);
// 	cout<<mini<<endl;
// }

// void minimumStack(stack<ll>& st){
// 	stack<ll> minSt;
// 	vector<ll> vec{10,20,30,5,8,12,3,16,2,14};

// 	for(ll v : vec){
// 		if(minSt.empty() || minSt.top() >= v){
// 			minSt.push(v);
// 		}
// 		st.push(v);
// 	}

// 	while(!st.empty()){
// 		if(!minSt.empty() && minSt.top() == st.top()){
// 			cout<<"min is "<<minSt.top()<<endl;
// 			minSt.pop();
// 		}else{
// 			cout<<st.top()<<endl;
// 		}
// 		st.pop();
// 	}

// 	while(!minSt.empty()){
// 		cout<<minSt.top()<<" ";
// 		minSt.pop();
// 	}
// }

// void minimumStack(stack<ll>& st) {
//     stack<ll> minSt;
//     vector<ll> vec{10, 20, 30, 5, 8, 12, 3, 16, 2, 14};

//     for (ll v : vec) {
//         if (minSt.empty() || minSt.top() >= v) {
//             minSt.push(v);
//         }
//         st.push(v);
//     }

//     // Output elements and their corresponding minimums
//     cout << "Original stack (top to bottom): ";
//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;

//     cout << "Minimum stack (top to bottom): ";
//     while (!minSt.empty()) {
//         cout << minSt.top() << " ";
//         minSt.pop();
//     }
//     cout << endl;
// }


int main(){
	text();
	stack<ll> st;
	minimumStack(st);
	return 0;
}