#include <bits/stdc++.h>
using namespace std;
int n,m,tmp,it=0;
double sumsub=0.0;
vector<int> currenttime;
priority_queue<int,vector<int>,greater<int>> datas;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    currenttime.resize(n,0);
    for(int i=0;i<m;++i){
        cin>>tmp;
        datas.push(tmp);
    }
    while(!datas.empty()){
        currenttime[it]+=datas.top();
        sumsub+=currenttime[it];
        datas.pop();
        it=(it+1)%n;
    }
    printf("%.3lf",sumsub/m);
}