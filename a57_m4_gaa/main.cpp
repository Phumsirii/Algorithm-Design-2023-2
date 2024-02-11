#include <bits/stdc++.h>
using namespace std;
bool findg(int k,int s,int x){
    if (k==0) return x==1;
    int m=(s-k)/2;
    if (x<=m) return findg(k-1,m,x);
    if (x-m<=k) return x-m==1;
    return findg(k-1,m,x-m-k);
}
int main(){
    int n;
    cin>>n;
    int k=3,s=3;
    while(s<n){
        k++;
        s=2*s+k;
    }
    if (findg(k,s,n)) cout<<"g";
    else cout<<"a";
}