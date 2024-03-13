#include<bits/stdc++.h>
using namespace std;
vector<int> datas;
int n,m,q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    datas.resize(n);
    for(int i=0;i<n;++i) cin>>datas[i];
    for(int i=0;i<m;++i){
        cin>>q;
        int count=0;
        for(int j=0;j<n;++j){
          if (datas[j]==q) break;
          if (datas[j]>q) count++;
        }
        cout<<count<<"\n";
    }
}