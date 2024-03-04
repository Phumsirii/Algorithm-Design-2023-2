#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> datas,done;
int recur(int cn){
    if (cn<0) return 0;
    if (done[cn]>=0) return done[cn];
    if (cn==0) return datas[0];
    int newdata=min(recur(cn-1),recur(cn-2*k)+datas[cn]);
    done[cn]=newdata;
    return newdata;
}
int main(){
    cin>>n>>k;
    datas.resize(n);done.resize(n,-1);
    for(int i=0;i<n;++i) cin>>datas[i];
    // cout<<recur(n-1);
    recur(n-1);
    for(int i=0;i<n;++i) cout<<done[i]<<" ";
}