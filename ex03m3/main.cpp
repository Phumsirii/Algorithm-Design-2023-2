#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> datas,done;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    datas.resize(n+1),done.resize(n+1);
    for(int i=1;i<=n;++i) cin>>datas[i];
    if (k>=n){
        cout<<*min_element(datas.begin()+1,datas.end());
        return 0;
    }
    int limit=min(n,k);
    for(int i=1;i<=limit+1;++i) done[i]=datas[i];
    //iterate to fill the rest done with the minimum cost to build a station at data[i]
    for(int i=limit+2;i<=n;++i){
        int newdata=1000000000;
        //where to take the previous done
        for(int j=i-2*k-1;j<i;++j){
            //for negative j
            if (j<=0) continue;
            newdata=min(newdata,done[j]+datas[i]);
        }
        //in case newdata can't be changed
        if (newdata==1000000000) newdata=datas[i];
        done[i]=newdata;
    }
    // for(int i=1;i<=n;++i) cout<<done[i]<<" ";
    // cout<<endl;
    int ans=1000000000;
    for(int i=n;i>=n-k;i--){
        ans=min(ans,done[i]);
    }
    cout<<ans;
}
