#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<vector<int>>> done;

int recur(int currentn,int currentm,int currentk){
    if (currentk==-1 || currentk>=currentn) return 0;
    if (done[currentn][currentm][currentk]>0) return done[currentn][currentm][currentk];
    if (currentn==1) return 0;
    if (currentm==1){ //the case we have just changed its colour
        int newdata=0;
        for(int i=1;i<=m;++i) newdata+=recur(currentn-1,i,currentk-1);
        return done[currentn][currentm][currentk]=newdata;
    }
    return done[currentn][currentm][currentk]=recur(currentn-1,currentm-1,currentk);
}

int main(){
    cin>>n>>m>>k;
    if (m>n) m=n;
    if (k>=n){
        cout<<0; 
        return 0;
    }
    done.resize(n+1,vector<vector<int>> (m+1,vector<int> (k+1,0)));
    done[1][1][0]=1;
    int ans=0;
    for(int i=1;i<=m;++i) ans+=recur(n,i,k);
    cout<<ans;
}