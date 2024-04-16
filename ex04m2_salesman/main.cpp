#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> order,times;
//times to reach element i from 0, the last one is from 0 to 0 (the loop)
int timeused(int i,int f){
    if (i==f) return 0;
    if (i>f) swap(i,f);
    return min({times[f]-times[i],times[m]+times[i]-times[f]});
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    order.resize(m+1);times.resize(m+1,0);
    for(int i=0;i<m;++i) cin>>order[i];
    order[m]=order[0];
    for(int i=1;i<=m;++i){
        cin>>times[i];
        times[i]+=times[i-1];
    }
    while(n--){
        cin>>a>>b;
        int ans=0;
        //direct or have a rext at a b
        for(int i=1;i<=m;++i)ans+=min({timeused(order[i-1],order[i]),timeused(order[i-1],a)+timeused(b,order[i]),timeused(order[i-1],b)+timeused(a,order[i])});
        cout<<ans<<"\n";
    }
}