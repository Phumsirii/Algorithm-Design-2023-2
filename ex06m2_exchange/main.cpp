#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>k;
    while(k--){
        cin>>n;
        vector<vector<double>> chart(n,vector<double> (n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>chart[i][j];
            }
        }
        //floyd-warshall
        for(int kk=0;kk<n;++kk){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    chart[i][j]=max(chart[i][j],chart[i][kk]*chart[kk][j]);
                }
            }
        }
        bool done=false;
        for(int i=0;i<n;++i){
            if (chart[i][i]>1){
                cout<<"YES\n";
                done=true;
                break;
            }
        }
        if (done) continue;
        cout<<"NO\n";
    }
}