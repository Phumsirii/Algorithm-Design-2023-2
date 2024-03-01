#include <bits/stdc++.h>
using namespace std;

vector<int> datas;

int recur(int start,int stop){
    if (start==stop) return datas[start];
    int m=(start+stop)/2;
    int r1=recur(start,m) , r2=recur(m+1,stop);
    int ans=max(r1,r2);
    vector<int> ma(1999,-1000000000);
    int sum=0;
    for(int i=m;i>=start;i--){
        sum+=datas[i];
        ma[datas[i]+999]=max(sum,ma[datas[i]+999]);
    }
    int s=0;
    for(int i=m+1;i<=stop;++i){
        s+=datas[i];
        if (ma[datas[i]+999]!=-1000000000) ans=max(ans,ma[datas[i]+999]+s);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    datas.resize(n);
    for(int i=0;i<n;i++) cin>>datas[i];
    cout<<recur(0,n-1);
}