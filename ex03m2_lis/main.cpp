#include <bits/stdc++.h>
using namespace std;
vector<int> done,datas; //done store maximum length when considered until ith element
int n,ans;
int recur(int currentn){
    if (currentn==0) return 1;
    if (done[currentn]>0) return done[currentn];
    //iterate through all lower n
    int newdata=1;
    for(int i=0;i<currentn;++i){
        //to consider the lower n, that data must be lesser than currentnth data
        int tmp=recur(i);
        if (datas[currentn]>datas[i]) newdata=max(newdata,tmp+1);
    }
    done[currentn]=newdata;
    ans=max(ans,newdata);
    return newdata;
}
int main(){
    cin>>n;
    datas.resize(n); done.resize(n,0);
    for(int i=0;i<n;++i) cin>>datas[i];
    recur(n-1);
    cout<<ans;
}