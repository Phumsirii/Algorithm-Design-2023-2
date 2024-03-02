#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<long long> datas;
long long recur(int currentn){
    if (currentn<=k) return currentn+1;
    if (datas[currentn]>=0) return datas[currentn];
    long long newn=(recur(currentn-1)+recur(currentn-k))%100000007;
    datas[currentn]=newn;
    return newn;
}
int main(){
    cin>>n>>k;
    datas.resize(n+1,-1);
    cout<<recur(n)%100000007;
}