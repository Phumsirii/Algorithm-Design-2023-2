#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,data,count=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>data;
        v[i]=data;
        for(int j=0;j<i;j++){
            if(v[j]>data) count++;
        }
    }
    cout<<count<<"\n";
}