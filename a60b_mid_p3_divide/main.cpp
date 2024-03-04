#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>> done; //n then k
int recur(int cn,int ck){
    if (cn==ck || ck==1) return 1;
    if (done[cn][ck]>0) return done[cn][ck];
    int newdone=ck*recur(cn-1,ck)+recur(cn-1,ck-1);
    done[cn][ck]=newdone%1997;
    return done[cn][ck];
}
int main(){
    cin>>n>>k;
    done.resize(n+1,vector<int> (n+1,-1));
    cout<<recur(n,k);
}