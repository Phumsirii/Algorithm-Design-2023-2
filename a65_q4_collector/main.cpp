#include <bits/stdc++.h>
using namespace std;
int n,k,ans=1e9,tprice,tcnt;
class shop{
    public:
    int price;
    vector<int> versionsoffered;
    shop(){};
    bool operator<(const shop &other) const{
        return versionsoffered.size()>other.versionsoffered.size();
    }
};
//the order of the shop and whether there is the version from that shop
vector<vector<bool>> tail;
//datas for each shop
vector<shop> datas;
//gained will be used in recursion function
vector<bool> gained;
//return true if there is a tail for all versions not gained
bool heutest(int no){
    for(int i=1;i<=n;++i){
        //not gained and does not contain in the tail
        if (!gained[i] && !tail[no][i]) return false;
    }
    return true;
}
//shop number no
void recur(int no,int versionsgained,int totalprice){
    //if gained all versions
    if (versionsgained==n) ans=min(ans,totalprice);
    //have considered all shops
    if (no>=k) return;
    if (totalprice>=ans || !heutest(no)) return;
    vector<int> newlygained;
    for(int &x:datas[no].versionsoffered){
        if (!gained[x]) newlygained.push_back(x);
    }
    //this shop is useful, choose it
    if (newlygained.size()>0){
        for(int &x:newlygained) gained[x]=true;
        recur(no+1,versionsgained+newlygained.size(),totalprice+datas[no].price);
        for(int &x:newlygained) gained[x]=false;
    }
    recur(no+1,versionsgained,totalprice);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    gained.resize(n+1,false);
    datas.resize(k);
    tail.resize(k,vector<bool>(n+1,false));
    for(int i=0;i<k;++i){
        cin>>tprice>>tcnt;
        datas[i].price=tprice;
        datas[i].versionsoffered.resize(tcnt);
        for(int j=0;j<tcnt;++j) cin>>datas[i].versionsoffered[j];
    }
    //will consider lower prices first
    sort(datas.begin(),datas.end());
    //edit tail
    for(int shopid=k-1;shopid>=0;shopid--){
        //for all versions 
        for(int &i:datas[shopid].versionsoffered){
            if (!tail[shopid][i]){
                //all lower shops will ahve this version in their tail
                for(int j=0;j<=shopid;++j) tail[j][i]=true;
            }
        }
    }
    recur(0,0,0);
    cout<<ans;
}