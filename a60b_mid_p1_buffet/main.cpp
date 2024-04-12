#include <bits/stdc++.h>
using namespace std;
int f,w,n,cnt=0,current=1;
vector<int> datas;
int main(){
    cin>>f>>w>>n;
    datas.resize(f);
    for(int i=0;i<f;++i) cin>>datas[i];
    sort(datas.begin(),datas.end());
    for(int i=0;i<f;++i){
        if (datas[i]>=current){
            current=datas[i]+(2*w+1);
            cnt++;
        }
    }
    cout<<cnt;
}