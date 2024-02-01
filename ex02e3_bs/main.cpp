#include <bits/stdc++.h>
using namespace std;
int bsearch(vector<int> &v,int k,int start,int stop){
    //terminating case
    if (start>stop) return stop;
    int m=(start+stop)/2;
    // in case v[m]==k, it is pushed to do the upper one
    if (v[m]>k) return bsearch(v,k,start,m-1);
    else return bsearch(v,k,m+1,stop);
}
int main(){
    int n,m,query;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    for(int i=0;i<m;i++){
        cin>>query;
        cout<<bsearch(vec,query,0,n-1)<<"\n";
    }
}