#include <bits/stdc++.h>
using namespace std;
int expmod(int x,int n,int &k){
    if (n==1) return x%k;
    if (n%2==0){
        int tmp=expmod(x,n/2,k)%k;
        return (tmp*tmp)%k;
    }
    else{
        int tmp=expmod(x,n/2,k)%k;
        tmp=(tmp*tmp)%k;
        return (tmp*(x%k))%k;
    }
}
int main(){
    int x,n,k;
    cin>>x>>n>>k;
    cout<<expmod(x,n,k);
}