#include <bits/stdc++.h>
#include<iostream>
#define ONLINE_JUDGE

using namespace std;

using ll = long long int;

void text(){
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class CustomStack{
    int cap;
    int tos;
    int stack[100000]={0};
public:
    CustomStack(int cap){
        this->cap = cap;
        this->tos = -1;
    }
    int size(){
        return tos+1;
    }
    void display(){
        for(int i=tos; i>=0; i--)
            cout<<stack[i]<<", ";
        cout<<endl;
    }

    int push(int val){
        if(tos+1 > cap)
            return 999999;
        stack[tos++] = val;
        return stack[tos];
    }
    int pop(){
        if(tos == -1)
            return -1;
        return stack[tos--];
    }
    int top(){
        if(tos == -1)
            return -1;
        return stack[tos];
    }
};


int main() {
    text();
    int t; cin>>t;
    CustomStack c(t);
    cout<<c.size()<<endl;
    cout<<c.push(10)<<endl;
    cout<<c.push(20)<<endl;
    cout<<c.size()<<endl;
    c.display();
    cout<<c.pop()<<endl;
    cout<<c.push(30)<<endl;
    cout<<c.push(40)<<endl;
    cout<<c.top()<<endl;
    c.display();

    return 0;
}
