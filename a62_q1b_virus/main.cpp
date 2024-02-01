#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &v,int n){
    if (n==2) return v[0]==0 && v[1]==1;
    int n2=n/2;
    vector<int> vfront1(n2),vback(n2),vfront2(n2);
    for(int i=0;i<n2;i++){
        vfront1[i]=v[i];
        vfront2[n2-1-i]=v[i];
        vback[i]=v[n2+i];
    }
    return (check(vfront1,n/2)||check(vfront2,n/2))&&check(vback,n/2);
}
int main(){
    int n,k,len;
    cin>>n>>k;
    len=pow(2,k);
    while(n--){
        vector<int> question(len);
        for(int i=0;i<len;i++) cin>>question[i];
        if (check(question,len)) cout<<"yes\n";
        else cout<<"no\n";
    }
}