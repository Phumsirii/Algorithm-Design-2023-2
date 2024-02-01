#include <bits/stdc++.h>

using namespace std;

void combi(int &a, int len, int n,string result,int current_count){
    if (len<n){
        combi(a,len+1,n,result+"0",current_count);
        if (current_count<a) combi(a,len+1,n,result+"1",current_count+1);
    }
    else{
        if (current_count==a) cout<<result+"\n";
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    combi(a,0,b,"",0);
}
