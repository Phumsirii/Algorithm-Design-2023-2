#include <bits/stdc++.h>
using namespace std;
vector<int> f={0,1};
int recur(int n){
    if (f[n]>=0) return f[n];
    return f[n]=recur(n-1)+recur(n-2);
}
int main(){
    int n;
    cin>>n;
    f.resize(n+1,-1);
    cout<<recur(n);
}