#include <bits/stdc++.h>
using namespace std;
int bsearch(vector<int> &v,int &q,int start,int stop){
    if (start>stop) return stop;
    int mid=(start+stop)/2;
    if (v[mid]<=q) return bsearch(v,q,mid+1,stop);
    else return bsearch(v,q,start,mid-1);
}
int main(){
    int n,m,q;
    cin>>n>>m;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    while(m--){
        cin>>q;
        int result=bsearch(v,q,0,n-1);
        if (result==-1) cout<<"-1\n";
        else cout<<v[result]<<"\n";
    }
}