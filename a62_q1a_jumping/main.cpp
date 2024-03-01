#include <bits/stdc++.h>
using namespace std;
vector<int> datas(3);
vector<int> results(3,-1000000000);

int recur(int stop){
    if (stop<0) return -1000000000;
    if (stop==0) return datas[stop];
    if (results[stop]!=-1000000000) return results[stop];
    int result = max({recur(stop-1),recur(stop-2),recur(stop-3)})+datas[stop];
    results[stop]=result;
    return result;
}

int main(){
    int n;
    cin>>n;
    datas.resize(n);
    results.resize(n,-1000000000);
    for (int i=0;i<n;i++) cin>>datas[i];
    results[0]=datas[0];
    cout<<recur(n-1)<<"\n";
}