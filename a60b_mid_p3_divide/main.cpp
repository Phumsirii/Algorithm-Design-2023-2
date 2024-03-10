#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>> done; //n then k
int recur(int cn,int ck){
    if (cn==ck || ck==1) return done[cn][ck]=1;
    if (done[cn][ck]>0) return done[cn][ck];
    return done[cn][ck]=(recur(cn-1,ck)*ck+recur(cn-1,ck-1))%1997;
}
int main(){
    cin>>n>>k;
    done.resize(n+1,vector<int> (k+1,0));
    cout<<recur(n,k);
}