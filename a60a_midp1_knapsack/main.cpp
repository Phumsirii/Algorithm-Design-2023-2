#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> values,weight;
vector<vector<int>> datas;
stack<int> storage;

void recur(int a,int b){ //a is number of items b is weight
    if (a==0 || b==0) return;
    int weightIfRecentlyAdded=b-weight[a-1]; //weight before ath item is added
    if (weightIfRecentlyAdded>=0){ //two possible cases: pick or not pick
        int notPicked=datas[a-1][b]; //value if this item is not picked
        int picked=datas[a-1][weightIfRecentlyAdded]+values[a-1]; //value if this has just been picked
        if (picked==datas[a][b]){ //we must pick it
            storage.push(a);
            return recur(a-1,weightIfRecentlyAdded);
        }
        else{ //we shouldn't pick it
            return recur(a-1,b);
        }
    }
    else{ //the only case is not picking this item
        return recur(a-1,b);
    }
}

int main(){
    cin>>n>>m;
    values.resize(n);weight.resize(n),datas.resize(n+1);
    for(int i=0;i<n;++i) cin>>values[i];
    for(int i=0;i<n;++i) cin>>weight[i];
    for(int i=0;i<=n;++i){
        vector<int> row(m+1,0);
        for(int j=0;j<=m;++j) cin>>row[j];
        datas[i]=row;
    }
    recur(n,m);
    cout<<storage.size()<<"\n";
    while(!storage.empty()){
        cout<<storage.top()<<" ";
        storage.pop();
    }
}