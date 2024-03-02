#include <bits/stdc++.h>
using namespace std;
vector<long long> grass;
long long recur(long long start,long long stop,long long budget){
    if (start==stop) return start;
    long long mid=(start+stop+1)/2;
    if (grass[mid]<=budget) return recur(mid,stop,budget);
    return recur(start,mid-1,budget);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,m,k,g;
    cin>>n>>m>>k;
    grass.resize(n+1,0);
    for(long long i=1;i<=n;++i){
        cin>>g;
        grass[i]=grass[i-1]+g+k;
    }
    while(m--){
        long long a,b;
        cin>>a>>b;
        long long result=recur(a,n,b+grass[a]);
        cout<<grass[result]-grass[a]-(result-a)*k<<endl;
    }
}