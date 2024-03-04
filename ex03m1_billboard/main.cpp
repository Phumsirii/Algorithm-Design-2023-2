#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> datas,done;
int recur(int number){
    if (number<=1) return datas[number];
    if (done[number]>0) return done[number];
    int newdata=max(recur(number-1),recur(number-2)+datas[number]);
    done[number]=newdata;
    return newdata;
}
int main(){
    cin>>n;
    datas.resize(n+1,0);
    done.resize(n+1,0);
    for(int i=1;i<=n;++i) cin>>datas[i];
    cout<<recur(n);
}