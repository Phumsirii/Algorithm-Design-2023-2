#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> datas,done;
int recur(int currentn){
    if (currentn<0) return 0;
    if (currentn==0) return 1;
    if (done[currentn]>=0) return done[currentn];
    int result=0;
    for(int &data:datas) result=(result+(recur(currentn-data)%1000003))%1000003;
    done[currentn]=result;
    return result;
}
int main(){
    cin>>n>>k;
    datas.resize(k),done.resize(n+1,-1);
    for(int i=0;i<k;++i) cin>>datas[i];
    cout<<recur(n);
}