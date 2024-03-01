#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int,int>,int> ma; //position_maximum sum from lower positions
vector<vector<int>> datas(n); //datas

int recur(int x,int y){
    if (y>=n) return 0;
    int r1,r2;
    if (ma.find(make_pair(x,y+1))!=ma.end()){
        r1=ma[make_pair(x,y+1)];
    }
    else{
        r1=recur(x,y+1);
        ma[make_pair(x,y+1)]=r1;
    }
    if (ma.find(make_pair(x+1,y+1))!=ma.end()){
        r2=ma[make_pair(x+1,y+1)];
    }
    else{
        r2=recur(x+1,y+1);
        ma[make_pair(x+1,y+1)]=r2;
    }
    return max(r1,r2)+datas[y][x];
}

int main(){
    cin>>n;
    datas.resize(n);
    for(int i=0;i<n;++i){
        vector<int> rows(n,0);
        for(int j=0;j<=i;++j) cin>>rows[j];
        datas[i]=rows;
    }
    cout<<recur(0,0);
}