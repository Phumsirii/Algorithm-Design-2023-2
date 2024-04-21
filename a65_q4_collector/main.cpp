#include <bits/stdc++.h>
using namespace std;
int n,k,bestprice=1e9;
//indicate versions received at each states
vector<bool> versionscollected;
//for tail [k][n] stores and version
vector<vector<int>> stores_versionsoffered;
vector<vector<bool>> tailavailability;
vector<int> stores_price;
//it is the id of store considering
void recur(int it,int versionsgained,int pricepayed){
    // cout<<it<<" "<<versionsgained<<" "<<pricepayed<<endl;
    if (versionsgained==n){
        bestprice=min(bestprice,pricepayed);
        return ;
    }
    if (pricepayed>=bestprice) return;
    if (it==k) return ;
    //consider all versions
    for(int i=0;i<n;++i){
        if (!versionscollected[i] && !tailavailability[it][i]) return;
    }
    vector<bool> indicesedited(n,false);
    //consider purchasing this store
    int noofversionsgain=0;
    //for all versions in this store
    for(auto&x:stores_versionsoffered[it]){
        if (!versionscollected[x-1]){
            versionscollected[x-1]=true;
            indicesedited[x-1]=true;
            noofversionsgain++;
        }
    }
    recur(it+1,versionsgained+noofversionsgain,pricepayed+stores_price[it]);
    //ignoring this store
    for(int i=0;i<n;++i){
        if (indicesedited[i]) versionscollected[i]=false;
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
    tailavailability.resize(k,vector<bool> (n,false));
    //consider the i th store 
    for(int i=0;i<k;++i){
        cin>>stores_price[i];
        int noofversions;
        cin>>noofversions;
        stores_versionsoffered[i].resize(noofversions);
        for(int j=0;j<noofversions;++j){
            //get the new version offered
            cin>>stores_versionsoffered[i][j];
            for(int it=i;it>=0;--it){
                if (tailavailability[it][stores_versionsoffered[i][j]-1]) break;
                tailavailability[it][stores_versionsoffered[i][j]-1]=true;
            }
        }
    }
    recur(0,0,0);
    cout<<bestprice;
}