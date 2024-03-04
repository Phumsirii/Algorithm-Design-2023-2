#include <bits/stdc++.h>
using namespace std;
int n,k,m,x,st,ta;
vector<int> sumd;
int recur(int start,int stop){ //used to find m, targeted sum
    if (start==stop) return start;
    if (sumd[start]>=ta) return start;
    int mid=(start+stop)/2;
    if (sumd[mid]>=ta) return recur(start,mid);
    return recur(mid+1,stop);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>m;
    sumd.resize(n+1,0);
    for(int i=1;i<=n;++i){ //get all ds
        cin>>x;
        sumd[i]=sumd[i-1]+x-m;
    }
    while(k--){
        cin>>st>>ta;
        ta+=sumd[st-1];
        cout<<recur(st,n)<<"\n";
    }
}