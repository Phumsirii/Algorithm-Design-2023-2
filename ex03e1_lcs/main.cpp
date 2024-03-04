#include <bits/stdc++.h>
using namespace std;
string x,y;
vector<vector<int>> done; //x then y
int recur(int ix,int iy){
    if (ix==-1 || iy==-1) return 0;
    if (done[ix][iy]>=0) return done[ix][iy];
    if (x[ix]==y[iy]) {
        int newdata=1+recur(ix-1,iy-1);
        done[ix][iy]=newdata;
        return newdata;
    }
    int newdata=max(recur(ix-1,iy),recur(ix,iy-1));
    done[ix][iy]=newdata;
    return newdata;
}
int main(){
    cin>>x>>y;
    done.resize(x.size(),vector<int> (y.size(),-1));
    cout<<recur(x.size()-1,y.size()-1);
}