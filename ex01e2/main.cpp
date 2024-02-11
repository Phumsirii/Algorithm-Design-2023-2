#include <bits/stdc++.h>
using namespace std;
int mcs(vector<int> &sum,vector<int> &datas,int start,int stop){
    if (start==stop) return datas[start];
    int m=(start+stop)/2;
    int c1=mcs(sum,datas,start,m);
    int c2=mcs(sum,datas,m+1,stop);
    int max_sum_left=sum[m];
    for(int i=start;i<m;i++){
        int tmp=sum[m]-sum[i];
        if (max_sum_left<tmp) max_sum_left=tmp;
    }
    int max_sum_right=datas[m+1];
    for(int i=m+2;i<=stop;i++){
        int tmp=sum[i]-sum[m];
        if (max_sum_right<tmp) max_sum_right=tmp;
    }
    int c3=max_sum_left+max_sum_right;
    return max({c1,c2,c3});
}
int main(){
    int n;
    cin>>n;
    vector<int> datas(n),sum(n); 
    cin>>sum[0];
    datas[0]=sum[0];
    for(int i=1;i<n;i++) {
        cin>>datas[i];
        sum[i]=datas[i]+sum[i-1];
    }
    cout<<mcs(sum,datas,0,n-1);
}