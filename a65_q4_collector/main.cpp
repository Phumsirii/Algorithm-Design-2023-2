#include <bits/stdc++.h>
using namespace std;
int n,k,bestprice=1e9;
//indicate versions received at each states
vector<bool> versionscollected;
vector<vector<int>> stores_versionsoffered;
vector<int> stores_price,cumoffers;
//it is the id of store considering
void recur(int it,int versionsgained,int pricepayed){
    if (versionsgained==n){
        bestprice=min(bestprice,pricepayed);
        return ;
    }
    //no chance of gaining every versions
    if (versionsgained+cumoffers[k]-cumoffers[it]<n) return;
    if (pricepayed>=bestprice) return;
    if (it==k) return ;
    vector<int> indicesedited(stores_versionsoffered[it].size(),-1);
    //consider purchasing this store
    int noofversionsgain=0;
    //for all versions in this store
    for(auto&x:stores_versionsoffered[it]){
        if (!versionscollected[x-1]){
            versionscollected[x-1]=true;
            indicesedited[noofversionsgain]=x-1;
            noofversionsgain++;
        }
    }
    recur(it+1,versionsgained+noofversionsgain,pricepayed+stores_price[it]);
    //ignoring this store
    for(int &x:indicesedited){
        if (x==-1) break;
        versionscollected[x]=false;
    }
    recur(it+1,versionsgained,pricepayed);
    return ;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    versionscollected.resize(n,false);
    stores_versionsoffered.resize(k);
    stores_price.resize(k);
    cumoffers.resize(k+1,0);
    for(int i=0;i<k;++i){
        cin>>stores_price[i];
        int noofversions;
        cin>>noofversions;
        cumoffers[i+1]=cumoffers[i]+noofversions;
        stores_versionsoffered[i].resize(noofversions);
        for(int j=0;j<noofversions;++j) cin>>stores_versionsoffered[i][j];
    }
    recur(0,0,0);
    cout<<bestprice;
}
