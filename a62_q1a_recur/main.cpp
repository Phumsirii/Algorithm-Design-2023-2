#include <bits/stdc++.h>
using namespace std;
void recur(int x1,int y1,int a,int b,vector<vector<int>> &result){
    if (a==0){
        result[y1][x1]=b;
        return;
    }
    int l=(int)pow(2,a)/2;
    recur(x1,y1,a-1,b,result);
    recur(x1+l,y1,a-1,b-1,result);
    recur(x1,y1+l,a-1,b+1,result);
    recur(x1+l,y1+l,a-1,b,result);
}
int main(){
    int a,b;
    cin>>a>>b;
    int n=pow(2,a);
    vector<int> tmp(n);
    vector<vector<int>> result(n,tmp);
    recur(0,0,a,b,result);
    for(vector<int> &x:result){
        for(int &y:x) cout<<y<<" ";
        cout<<"\n";
    }
}