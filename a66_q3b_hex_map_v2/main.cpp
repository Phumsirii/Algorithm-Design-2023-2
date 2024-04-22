#include<bits/stdc++.h>
using namespace std;
vector<int> movingassistancer={-1,-1,1,1,0,0};
vector<int> movingassistancecodd={0,1,0,1,1,-1};
vector<int> movingassistanceceven={-1,0,-1,0,1,-1};
//cost and ordered pair of r c
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
vector<vector<int>> entry,result;
int r,c,a1,b1,a2,b2;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>r>>c;
    entry.resize(r+1,vector<int>(c+1));
    result.resize(r+1,vector<int>(c+1,1e9));
    cin>>a1>>b1>>a2>>b2;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j) cin>>entry[i][j];
    }
    pq.push(make_pair(entry[a1][b1],make_pair(a1,b1)));
    while(!pq.empty()){
        int currentr=pq.top().second.first;
        int currentc=pq.top().second.second;
        int currentdist=pq.top().first;
        pq.pop();
        if (currentdist>=result[currentr][currentc]) continue;
        result[currentr][currentc]=currentdist;
        vector<int> movingassistancec;
        if (currentr%2==1) movingassistancec=movingassistancecodd;
        else movingassistancec=movingassistanceceven;
        //see all neighbors
        for(int i=0;i<6;++i){
            int newr=currentr+movingassistancer[i];
            int newc=currentc+movingassistancec[i];
            //newr newc is out of range
            if (newr<=0 || newr>r || newc<=0 || newc>c) continue;
            //not better than thje result
            if (currentdist+entry[newr][newc]>=result[newr][newc]) continue;
            pq.push(make_pair(currentdist+entry[newr][newc],make_pair(newr,newc)));
        }
    }
    cout<<result[a2][b2]<<"\n";
}