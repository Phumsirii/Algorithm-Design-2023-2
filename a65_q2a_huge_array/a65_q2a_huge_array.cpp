#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q,tx,tc,question;
    cin>>n>>q;
    vector<pair<int,int>> data_fre(n);
    for (int i =0;i<n;i++){
        cin>>tx>>tc;
        data_fre[i]=make_pair(tx,tc);
    }
    sort(data_fre.begin(),data_fre.end());
    vector<int> top(n);
    top[0]=data_fre[0].second;
    for(int i=1;i<n;i++) top[i]=top[i-1]+data_fre[i].second;
    while(q--){
        cin>>question;
        int pos=lower_bound(top.begin(),top.end(),question)-top.begin();
        cout<<data_fre[pos].first<<"\n";
    }
}