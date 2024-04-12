#include <bits/stdc++.h>
using namespace std;
int n;
double w,cw=0,cp=0;
vector<double> va,we;
vector<pair<double,int>> density_index;
int main(){
    cin>>w>>n;
    va.resize(n);we.resize(n),density_index.resize(n);
    for(int i=0;i<n;++i){
        cin>>va[i];
        density_index[i].first=va[i];
        density_index[i].second=i;
    }
    for(int i=0;i<n;++i){
        cin>>we[i];
        density_index[i].first/=we[i];
    }
    sort(density_index.begin(),density_index.end());
    for(int i=n-1;i>=0;--i){
        if (w-cw>we[density_index[i].second]){ //can fit the full piece
            cw+=we[density_index[i].second];
            cp+=va[density_index[i].second];
        }else{ //can partially fit
            double fracw=(w-cw)/we[density_index[i].second];
            cp+=fracw*va[density_index[i].second];
            break;
        }
    }
    cout<<fixed<<setprecision(4)<<cp;
}