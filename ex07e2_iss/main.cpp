#include <bits/stdc++.h>
using namespace std;
int n,ans;
void recur(int start,int sum){
    for(int i=start;i<=sum;++i){
        if (i<sum) recur(i,sum-i);
        else if (i==sum) ans++;
    }
}
int main(){
    cin>>n;
    recur(1,n);
    cout<<ans;
}