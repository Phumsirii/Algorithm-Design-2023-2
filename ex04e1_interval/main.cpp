#include<bits/stdc++.h>
using namespace std;
int n,tmp,cnt,currentstop=-1;
vector<pair<int,int>> stop_start;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    stop_start.resize(n);
    for(int i=0;i<n;++i){
        cin>>tmp;
        stop_start[i].second=tmp;
    }
    for(int i=0;i<n;++i){
        cin>>tmp;
        stop_start[i].first=tmp;
    }
    sort(stop_start.begin(),stop_start.end());
    for(int i=0;i<n;++i){
        if (currentstop<=stop_start[i].second){
            currentstop=stop_start[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}