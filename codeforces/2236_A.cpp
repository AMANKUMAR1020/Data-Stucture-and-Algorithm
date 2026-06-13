#define ONLINEJUDGE
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template<typename Container>
void sorting(Container &x) { sort(x.begin(), x.end()); }

// vscan for (auto &x : v) cin >> x;
// for(auto &x : v) cout << x << " ";
// using pb(x) push_back(x);

typedef long long int ll;

#define MAX 1e9

void text(){
	#ifdef ONLINEJUDGE
		freopen("input.txt", "r",stdin);
		freopen("output.txt", "w",stdout);
	#endif
}

void solve() {
    ll n; cin >> n;
    // cout<<n<<endl;

    vector<ll> v(n);

    ll mini = INT_MAX;
    ll maxi = INT_MIN;

    for (auto &x : v) {
        cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    cout<< (maxi - mini + 1) <<endl;
}


int main(){        
	text();
    int t=1; cin>>t;
    while(t--){
    	solve();
    }
}











/*
Let's break down the problem carefully.

What are we trying to do?

Given tower heights:

h
1
	​

,h
2
	​

,...,h
n
	​


For each tower, we must choose exactly one integer x
i
	​

 such that:

1≤x
i
	​

≤k

and add it to the tower:

h
i
	​

→h
i
	​

+x
i
	​


After doing this for every tower, all towers must have the same height.

We need to find the smallest possible k.

Key Observation

Suppose the final common height is H.

Then for every tower:

x
i
	​

=H−h
i
	​


Since 1≤x
i
	​

≤k,

1≤H−h
i
	​

≤k

for every tower.

Converting to intervals

For a tower with height h
i
	​

,

1≤H−h
i
	​

≤k

means

h
i
	​

+1≤H≤h
i
	​

+k

So each tower allows H to lie in an interval:

[h
i
	​

+1,h
i
	​

+k]

All towers can be made equal iff these intervals have a common intersection.

Condition for intersection

For intervals to intersect:

max(h
i
	​

+1)≤min(h
i
	​

+k)

Since

max(h
i
	​

+1)=max(h
i
	​

)+1

and

min(h
i
	​

+k)=min(h
i
	​

)+k

Let

mx=max(h)
mn=min(h)

Then:

mx+1≤mn+k

Therefore:

k≥mx−mn+1

The smallest possible k is

mx−mn+1
	​

Verify with examples
Example 1
1 3
mn = 1
mx = 3
k=3−1+1=3

Answer = 3

Example 2
2 6 4
mn = 2
mx = 6
k=6−2+1=5

Answer = 5

Example 3
5 4 6 6 1
mn = 1
mx = 6
k=6

Answer = 6

Example 4
3 3 3 3
mn = mx = 3
k=1

Answer = 1
(Each tower can add exactly 1 and become 4.)

Why does this formula always work?

Choose:

H=mx+1

Then:

For the tallest tower:

x=H−mx=1

For the shortest tower:

x=H−mn=mx−mn+1

So all required additions lie between:

1 and mx−mn+1

Hence k=mx−mn+1 is sufficient.

And we already proved no smaller k can work.

Therefore:

## answer=max(h)−min(h)+1
	​

*/
