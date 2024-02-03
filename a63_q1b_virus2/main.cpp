#include <bits/stdc++.h>
using namespace std;
bool recur(vector<int> &v){
    int n=v.size();
    if (n==2) return true;
    int mid=n/2;
    vector<int> vfront(mid),vback(mid);
    int countback=0,countfront=0;
    for (int i=0;i<mid;i++){
        vfront[i]=v[i];
        countfront+=v[i];
        countback+=v[i+mid];
        vback[i]=v[i+mid];
    }
    return (abs(countfront-countback)<=1) && recur(vfront)&&recur(vback);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int s=pow(2,k);
    while(n--){
        vector<int> v(s);
        for(int i=0;i<s;i++) cin>>v[i];
        if (recur(v)) cout<<"yes\n";
        else cout<<"no\n";
    }
}