#include <bits/stdc++.h>
using namespace std;
int n,tmp,ans=0;
vector<vector<bool>> connections;
vector<vector<int>> workers_invalid;
vector<int> powers;
vector<bool> valid;
int tail(int no){
    int s=0;
    for(int i=no;i<n;++i){
        if(valid[i]) s+=powers[i];
    }
    return s;
}
void recur(int no,int currentpower){
    //can't reach greater answer
    int tai=tail(no);
    if (currentpower+tai<=ans) return;
    ans=max(ans,currentpower);
    if (no>=n) return;
    //can consider this employee
    if (valid[no]){
        //all employee ids which is newly restricted by this employee
        vector<int> tmp;
        for(int i=no+1;i<n;++i){
            if (valid[i] && !connections[i][no]){
                valid[i]=false;
                tmp.push_back(i);
            }
        }
        recur(no+1,currentpower+powers[no]);
        for(int &x:tmp) valid[x]=true;
    }
    //ignore this employee
    recur(no+1,currentpower);
}
int main(){
    cin>>n;
    //all players are valid to use at the start
    valid.resize(n,true);    
    powers.resize(n);
    connections.resize(n,vector<bool> (n));
    workers_invalid.resize(n);
    for(int i=0;i<n;++i) cin>>powers[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>tmp;
            if (tmp) connections[i][j]=true;
            else{
                connections[i][j]=false;
                workers_invalid[i].push_back(j);
            }
        }
    }
    recur(0,0);
    cout<<ans;
}