#include <bits/stdc++.h>
using namespace std;
bool ispossible(long long time,long long target,vector<int> &times,int n){
    long long count=0;
    for(int i=0;i<n;i++) count+=time/times[i]+1;
    return count>=target;
}
long long bsearch(long long start,long long stop,long long k,vector<int> &times,int n){
    if (start>=stop) return stop;
    long long mid =(start+stop)/2;
    if (ispossible(mid,k,times,n)) return bsearch(start,mid,k,times,n);
    else return bsearch(mid+1,stop,k,times,n);
}
int main(){
    int n,a;
    cin>>n>>a;
    vector<int> times(n);
    for(int i=0;i<n;i++) cin>>times[i];
    for(int i=0;i<a;i++){
        long long k;
        cin>>k;
        cout<<bsearch(0,LLONG_MAX,k,times,n)<<"\n";
    }
}