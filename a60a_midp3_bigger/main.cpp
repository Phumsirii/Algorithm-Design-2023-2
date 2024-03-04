#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> datas,done;
int recur(int currentn){
    if (currentn<0) return 0;
    if (done[currentn]>0) return done[currentn];
    //choose to not use the billboard, there can be one in 2 ahead, or there was one three board ahead and there will be one here 
    int newdone=max({recur(currentn-1),recur(currentn-2),recur(currentn-3)+datas[currentn]});
    done[currentn]=newdone;
    return newdone;
}
int main(){
    cin>>n;
    datas.resize(n);done.resize(n,0);
    for(int i=0;i<n;++i) cin>>datas[i];
    cout<<recur(n-1);
}