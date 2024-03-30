#include <bits/stdc++.h>
using namespace std;
int n,m,tmp;
vector<int> noofarrival;
vector<vector<int>> destination;
queue<int> q;
int main(){
    cin>>n;
    noofarrival.resize(n,0);
    destination.resize(n);
    for(int i=0;i<n;++i){
        cin>>m;
        for(int j=0;j<m;++j){
            cin>>tmp;
            destination[tmp].push_back(i);
            noofarrival[i]++;
        }
    }
    for(int i=0;i<n;++i){
        if(noofarrival[i]==0) q.push(i);
    }
    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        //all destination of the current node
        for(int i:destination[current]){
            if (--noofarrival[i]==0) q.push(i);
        }
    }
}