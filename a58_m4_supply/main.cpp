#include <bits/stdc++.h>
using namespace std;
int n,m,k,d,e,l;
//for e , 0 is production done by a plant for 1, a store requests for a product
queue<int> storeswaiting,plantstock;
//These two vectors stores event or storesplant in event of each day
vector<bool> event;
vector<int> storesOrplant;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    event.resize(k+1);
    storesOrplant.resize(k+1);
    for(int i=1;i<=k;++i){
        cin>>d>>e>>l;
        event[d]=e;
        storesOrplant[d]=l;
    }
    for(int i=1;i<=k;++i){
        //request from store
        if (event[i]){
            if (plantstock.empty()){
                storeswaiting.push(storesOrplant[i]);
                cout<<"0\n";
            }
            else{
                cout<<plantstock.front()<<"\n";
                plantstock.pop();
            }
        }else{  //product from plant
            if (storeswaiting.empty()){
                plantstock.push(storesOrplant[i]);
                cout<<"0\n";
            }
            else{
                cout<<storeswaiting.front()<<"\n";
                storeswaiting.pop();
            }
        }
    }
}