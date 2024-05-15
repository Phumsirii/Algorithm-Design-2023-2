#include <bits/stdc++.h>
//using state space search
using namespace std;
class student{
    public:
    vector<int> daysfree;
    student(){}
    bool operator<(const student &others) const{
        return daysfree.size()>others.daysfree.size();
    }
};
int n,m,nood,day,ans=10000;
vector<student> students;
vector<vector<bool>> tail;
vector<bool> dayscovered;
void recur(int it,int noostudentstaken,int daysdonecnt){
    if (daysdonecnt==n){
        ans=min(ans,noostudentstaken);
        return ;
    }
    if (noostudentstaken>=ans || it>=m) return ;
    for(int i=1;i<=n;++i){
        //no chance to complete this day
        if (!dayscovered[i] && !tail[it][i]) return;
    }
    vector<int> tmp;
    for(int &x:students[it].daysfree){
        if (!dayscovered[x]){
            dayscovered[x]=true;
            tmp.push_back(x);
        }
    }
    //choosing this student
    recur(it+1,noostudentstaken+1,daysdonecnt+tmp.size());
    for(int &x:tmp) dayscovered[x]=false;
    //ignoring this student
    recur(it+1,noostudentstaken,daysdonecnt);
}
int main(){
    cin>>n>>m;
    //no of days
    dayscovered.resize(n+1,false);
    students.resize(m);
    //current student focusing and the availability of its tail day
    tail.resize(m,vector<bool> (n+1,false));
    for(int i=0;i<m;++i){
        cin>>nood;
        students[i].daysfree.resize(nood);
        for(int j=0;j<nood;++j) cin>>students[i].daysfree[j];
    }
    sort(students.begin(),students.end());
    for(int &x:students[m-1].daysfree){
        for(int i=0;i<=m-1;++i) tail[i][x]=true;
    }
    for(int i=m-2;i>=0;--i){
        for(int &x:students[i].daysfree){
            if (!tail[i][x]){
                for(int j=0;j<=i;++j) tail[j][x]=true;
            }
        }
    }
    recur(0,0,0);
    cout<<ans;
}