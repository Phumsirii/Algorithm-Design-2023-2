#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
vector<int> datas,tail;
//shows which datas have been taken
vector<bool> taken,restrictedpattern;
bool checkfengshui(int no){
    if (no<k) return true;
    for(int i=no-k;i<no;++i){
        //found different pattern
        if (i>=n || taken[i]!=restrictedpattern[i-no+k]) return true;
    }
    return false;
}
void recur(int no,int currentsum){
    if (!checkfengshui(no) || !checkfengshui(no-1)) return;
    ans=max(ans,currentsum);
    if (no>=n) return;
    //can't be better than ans
    if (currentsum+tail[no]<=ans) return;
    //consider this billboard
    taken[no]=true;
    recur(no+2,currentsum+datas[no]);
    //ignore this billboard
    taken[no]=false;
    recur(no+1,currentsum);
}
int main(){
    cin>>n>>k;
    taken.resize(n,false);
    datas.resize(n);
    restrictedpattern.resize(k);
    for(int i=0;i<n;++i) cin>>datas[i];
    for(int i=0;i<k;++i){
        int tmp;
        cin>>tmp;
        if (tmp) restrictedpattern[i]=true;
        else restrictedpattern[i]=false;
    }
    tail.resize(n);
    tail[n-1]=datas[n-1];
    for(int i=n-2;i>=0;--i){
        tail[i]=tail[i+1]+datas[i];
    }
    recur(0,0);
    cout<<ans;
}