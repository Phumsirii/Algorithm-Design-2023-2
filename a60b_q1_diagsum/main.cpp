#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,data;
    cin>>n;
    vector<vector<int>> datas(n);
    for(int i=0;i<n;++i){
        vector<int> v(n);
        for(int j=0;j<n;++j) cin>>v[j];
        datas[i]=v;
    }
    int result=-1000000000;
    for(int x=0;x<n;x++){ //select starting column
        int itx=x,ity=0;
        int suf=datas[ity][itx],mss=datas[ity][itx];
        while(++itx<n && ++ity<n){
            suf=max(datas[ity][itx],suf+datas[ity][itx]);
            mss=max(mss,suf);
        }
        result=max(result,mss);
    }
    for(int y=1;y<n;y++){ //select starting row
        int itx=0,ity=y;
        int suf=datas[ity][itx],mss=datas[ity][itx];
        while(++itx<n && ++ity<n){
            suf=max(datas[ity][itx],suf+datas[ity][itx]);
            mss=max(mss,suf);
        }
        result=max(result,mss);
    }
    cout<<result;
}