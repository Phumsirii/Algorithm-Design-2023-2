#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=1e6;
vector<int> datas,tail;
void recur(int noofselected,int it,int currentsum){
    if (noofselected==m){
        ans=min(ans,abs(currentsum-k));
        return;
    }
    //can't gain up to m numbers
    if (n-it<m-noofselected) return;
    //sum is too big or too small
    if (currentsum<k+ans)recur(noofselected+1,it+1,currentsum+datas[it]);
    if (currentsum+tail[it+1]>k-ans)recur(noofselected,it+1,currentsum);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    datas.resize(n);
    tail.resize(n);
    for(int i=0;i<n;++i) cin>>datas[i];
    sort(datas.rbegin(),datas.rend());
    tail[n-1]=datas[n-1];
    for(int i=n-2;i>=0;--i) tail[i]=tail[i+1]+datas[i];
    recur(0,0,0);
    cout<<ans;
}
