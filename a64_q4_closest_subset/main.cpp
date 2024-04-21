#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=1e9;
vector<int> a,cumsum;
//cnt is count of selected elements
void recur(int cnt,int currentit,int currentsum){
    //if we have finished choosing
    if (cnt==m){
        ans=min(ans,abs(currentsum-k));
        return ;
    }
    //finishes with all elements or can't reach k elements
    if (currentit==n || m-cnt>n-currentit) return;
    //if we can still select it
    if (currentsum<k+ans) recur(cnt+1,currentit+1,currentsum+a[currentit]);
    //can still ignore it
    if (currentsum+cumsum[n]-cumsum[currentit+1]>k-ans) recur(cnt,currentit+1,currentsum);
    
    return ;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    a.resize(n);cumsum.resize(n+1,0);
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;++i) cumsum[i+1]=cumsum[i]+a[i];
    recur(0,0,0);
    cout<<ans;
}
