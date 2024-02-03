#include <bits/stdc++.h>
using namespace std;
vector<int> matrix_multiply(vector<int> &M,vector<int> &N,int k){
    vector<int> result(4);
    int m0=M[0]%k,m1=M[1]%k,m2=M[2]%k,m3=M[3]%k,n0=N[0]%k,n1=N[1]%k,n2=N[2]%k,n3=N[3]%k;
    result[0]=(m0*n0+m1*n2)%k;
    result[1]=(m0*n1+m1*n3)%k;
    result[2]=(m2*n0+m3*n2)%k;
    result[3]=(m2*n1+m3*n3)%k;
    return result;
}
vector<int> matrix_mod(vector<int> v,int n,int &k){
    if (n==1) return {v[0]%k,v[1]%k,v[2]%k,v[3]%k};
    if (n%2==0){
        vector<int> tmp=matrix_mod(v,n/2,k);
        return matrix_multiply(tmp,tmp,k);
    }
    else{
        vector<int> tmp=matrix_mod(v,n/2,k);
        tmp=matrix_multiply(tmp,tmp,k);
        return matrix_multiply(tmp,v,k);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> original(4);
    for (int i=0;i<4;i++) cin>>original[i];
    vector<int> result=matrix_mod(original,n,k);
    //vector<int> result=matrix_multiply(original,original,k);
    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3];
}