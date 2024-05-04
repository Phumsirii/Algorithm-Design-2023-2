#include<bits/stdc++.h>
using namespace std;
int x;
queue<pair<int,int>> q;
int main(){
    cin>>x;
    q.push(make_pair(x,0));
    while(!q.empty()){
        if(q.front().first==0){
            cout<<q.front().second;
            return 0;
        }
        if ((q.front().first+1)%16777216==0){
            cout<<q.front().second+1;
            return 0;
        }
        q.push(make_pair((q.front().first+1)%16777216,q.front().second+1));
        if ((q.front().first*2)%16777216==0){
            cout<<q.front().second+1;
            return 0;
        }
        q.push(make_pair((q.front().first*2)%16777216,q.front().second+1));
        q.pop();
    }
}