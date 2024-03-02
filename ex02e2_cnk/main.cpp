#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>> datas;
int recur(int n,int k){
    if (n==0) return 1;
    if (k==0 || n==k) return 1;
    if (datas[n][k]>0) return datas[n][k];
    int newdata=recur(n-1,k)+recur(n-1,k-1);
    datas[n][k]=newdata;
    return newdata;
}
int main(){
    cin>>n>>k;
    datas.resize(n+1);
    for(int i=0;i<=n;++i){
        vector<int> row(n+1,0);
        datas[i]=row;
    }
    cout<<recur(n,k);
}
