#include <bits/stdc++.h>
using namespace std;
int n,m,k,w,ittower=1,towercnt=0;
vector<pair<int,int>> monsterposition_health;
int main(){
    cin>>n>>m>>k>>w;
    monsterposition_health.resize(m);
    for(int i=0;i<m;++i)cin>>monsterposition_health[i].first;
    for(int i=0;i<m;++i) cin>>monsterposition_health[i].second;
    sort(monsterposition_health.begin(),monsterposition_health.end());
    //iterate through all towers
    for(int i=0;i<m;++i){
        //ittower already exceed the cell or limit
        if (ittower>n || towercnt>=k) break;
        //no chance to shoot this monster
        if (ittower>monsterposition_health[i].first+w) continue;
        //the min position of tower which can attack this monster
        int start=max(1,monsterposition_health[i].first-w);
        while(ittower<start) ittower++;
        //attack this monster
        while(ittower<=n && towercnt<k && ittower<=monsterposition_health[i].first+w && monsterposition_health[i].second>0){
            towercnt++;
            --monsterposition_health[i].second;
            ittower++;
        }
    }
    int ans=0;
    for(int i=0;i<m;++i) ans+=monsterposition_health[i].second;
    cout<<ans;
}