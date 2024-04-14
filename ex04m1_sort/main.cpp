#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
vector<int> datas,countentry(3,0);
int main(){
    cin>>n;
    if (n==0){
        cout<<0;
        return 0;
    }
    datas.resize(n);
    for(int i=0;i<n;++i){
        cin>>datas[i];
        ++countentry[datas[i]-1];
    }
    //iterate through all datas
    int it=0;
    for(int i=0;i<3;++i){
        for(int j=0;j<countentry[i];++j){
            //need a swap
            if(datas[it] != i+1){
                if (i==0 && datas[it]==2){
                    //find from 2 sec on
                    for(int k=countentry[0];k<n;++k){
                        if (datas[k]==1){
                            swap(datas[k],datas[it]);
                            //cout<<it<<" "<<datas[it]<<" "<<datas[k]<<endl;
                            cnt++;
                            break;
                        }
                    }
                } else {
                    //find from 3rd sec
                    for(int k=countentry[0]+countentry[1];k<n;++k){
                        if (datas[k]==i+1){
                            swap(datas[k],datas[it]);
                            //cout<<it<<" "<<datas[it]<<" "<<datas[k]<<endl;
                            cnt++;
                            break;
                        }
                    }
                }
            }
            ++it;
        }
    }
    cout<<cnt;
}