#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> datacell(257,vector<int> (257));
bool checkzero(int lx,int ly,int rx,int ry){
    if (lx==rx && ly==ry) return datacell[ly][lx]==0;
    return checkzero(lx,ly,(rx+lx)/2,(ry+ly)/2) && checkzero(((rx+lx)/2)+1,ly,rx,(ry+ly)/2) && checkzero(lx,((ly+ry)/2)+1,(lx+rx)/2,ry) && checkzero(((rx+lx)/2)+1,((ry+ly)/2)+1,rx,ry);
}
int check(int lx,int ly,int rx,int ry){
    if (lx==rx-1 && ly==ry-1){ //when n=2
        if (datacell[ry][rx]!=0) return 0;
        if (datacell[ly][lx]==0 || datacell[ry][lx]==0 || datacell[ly][rx]==0) return 0;
        if (datacell[ly][lx] == datacell[ry][lx] || datacell[ry][lx] == datacell[ly][rx]) return datacell[ry][lx];
        else if (datacell[ly][lx]==datacell[ly][rx]) return datacell[ly][lx];
        else return 0; 
    }
    else if (checkzero((lx+rx)/2+1,(ly+ry)/2+1,rx,ry)){
        int q1=check(lx,ly,(lx+rx)/2,(ly+ry)/2);
        int q2=check((lx+rx)/2+1,ly,rx,(ry+ly)/2);
        int q3=check(lx,(ry+ly)/2+1,(rx+lx)/2,ry);
        if (q1==0 || q2==0 || q3==0) return 0;
        if ((q1==q2 || q1==q3)) return q1;
        else if((q2==q3)) return q2;
        else return 0;
    }
    return 0;
}
int main(){
    for(int i=0;i<3;++i){
        int n;
        cin>>n;
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k) cin>>datacell[j][k];
        }
        cout<<check(1,1,n,n)<<"\n";
    }
}