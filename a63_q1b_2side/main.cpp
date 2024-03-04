#include <bits/stdc++.h>
using namespace std;
vector<int> leftdone,rightdone;
vector<int> leftboard,rightboard;
int n,w,k;
int recur(int currentn,bool isleft){ //currentn is number of board considering
    if (currentn<=0) return 0;
    if (isleft){ //current consideration is the left board
        if (leftdone[currentn-1]>0) return leftdone[currentn-1];
        int candi1=recur(currentn-1,true); //consider case this currentn should not be selected
        int candi2=recur(currentn-w-1,false)+leftboard[currentn-1];//consider case this currentn should be selected
        //for (int i=currentn-w;i<currentn-1;++i) candi1=max(candi1,recur(i,true)); //all cases which this currentn is not selected
        leftdone[currentn-1]=max(candi1,candi2);
        return leftdone[currentn-1];
    }else{ //current consideration is the right board
        if (rightdone[currentn-1]>0) return rightdone[currentn-1];
        int candi1=recur(currentn-1,false); //consider case this currentn should not be selected
        int candi2=recur(currentn-w-1,true)+rightboard[currentn-1];//consider case this currentn should be selected
        //for (int i=currentn-w;i<currentn-1;++i) candi1=max(candi1,recur(i,false)); //all cases which this currentn is not selected
        rightdone[currentn-1]=max(candi1,candi2);
        return rightdone[currentn-1];
    }
}
int main(){
    cin>>n>>w>>k;
    leftboard.resize(n);rightboard.resize(n);
    leftdone.resize(n+1,-1);rightdone.resize(n+1,-1);
    for(int i=0;i<n;++i) cin>>leftboard[i];
    for(int i=0;i<n;++i) cin>>rightboard[i];
    cout<<max(recur(n,false),recur(n,true));
    // cout<<endl;
    // for(int i=0;i<=n;++i) cout<<leftdone[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;++i) cout<<rightdone[i]<<" ";
}