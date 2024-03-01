#include <bits/stdc++.h>
using namespace std;
map<int,int> done; //currentr_pieces
int n,a,b,c,ans=0;
int recur(int currentr){
    if (currentr<0) return -1000000000;
    if (currentr==0) return 0; //starting from 0 piece
    if (done.find(currentr)!=done.end()) return done[currentr]; //if the length is stored
    int newcandi=max({recur(currentr-a),recur(currentr-b),recur(currentr-c)})+1; //add a new piece of length a b or c
    ans=max(ans,newcandi);
    done[currentr]=newcandi; //store obtained value
    return newcandi;    //return the obtained value
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>a>>b>>c;
    recur(n);
    cout<<ans;
    //for(auto &x:done) cout<<x.first<<":"<<x.second<<"\n";
}