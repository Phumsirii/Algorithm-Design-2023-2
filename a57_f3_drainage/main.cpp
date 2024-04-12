#include <bits/stdc++.h>
using namespace std;
int n,l,h,current=0,cnt=0;
priority_queue<int,vector<int>,greater<int>> holes;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    for(int i=0;i<n;++i){
        cin>>h;
        holes.push(h);
    }
    while(!holes.empty()){
        int tmp=holes.top();
        holes.pop();
        if (current>tmp) continue;
        current=tmp+l;
        cnt++;
    }
    cout<<cnt;
}