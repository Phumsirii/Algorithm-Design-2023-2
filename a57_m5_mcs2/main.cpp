#include <bits/stdc++.h>
using namespace std;
int mcs(vector<int> &sum,vector<int> &datas,int start,int stop){
    if (start==stop) return datas[start];
    int m=(start+stop)/2;
    int c1=mcs(sum,datas,start,m),c2=mcs(sum,datas,m+1,stop);
    int minl=sum[m];
    for(int i=start;i<m;i++) {
        int tmp=sum[m]-sum[i];
        if(tmp<minl) minl=tmp;
    }
    int minr=sum[stop]-sum[m];
    for(int i=m+1;i<stop;i++){
        int tmp=sum[i]-sum[m];
        if (tmp<minr) minr=tmp;
    }
    int c3=minl+minr;
    return min({c1,c2,c3});
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<int> datas(n),sum(n);
    cin>>datas[0];
    sum[0]=datas[0];
    for(int i=1;i<n;i++) {
        cin>>datas[i];
        sum[i]=sum[i-1]+datas[i];
    }
    int min_sub=mcs(sum,datas,0,n-1);
    int max_ele=*max_element(datas.begin(),datas.end());
    if (max_ele<0) cout<<max_ele;
    else cout<<sum[n-1]-min({min_sub,0});
}