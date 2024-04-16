#include <bits/stdc++.h>
using namespace std;
int n,d,days;
vector<int> camps;
//get number of days used to reach the top, given a gap of not more than gap
int getdays(int gap){
    //check if this gap is possible
    for(int i=1;i<n;++i){
        if (camps[0]>gap || camps[i]-camps[i-1]>gap) return 1e9;
    }
    //last stop is the height of the lastest stop
    //campit is the position on the mountain
    int ans=0,campit=0,laststop=0;
    while(campit<n-1){
        //can still go on
        while(campit<n-1 && camps[campit+1]<=laststop+gap) campit++;
        ++ans;
        //needs a stop, update laststop
        laststop=camps[campit];
    }
    return ans;
}
int binsearch(int start,int stop){
    //correct ans found
    if (start==stop){
        days=getdays(start);
        return start;
    }
    int mid=(start+stop)/2;
    //no of days of mid is too high, needs to increase gap
    if (getdays(mid)>d) return binsearch(mid+1,stop);
    else return binsearch(start,mid);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>d;
    camps.resize(n);
    for(int i=0;i<n;++i) cin>>camps[i];
    //search for appropriate amount of gap
    cout<<binsearch(0,camps[n-1])<<" "<<days;
}