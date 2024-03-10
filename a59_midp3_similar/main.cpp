#include <bits/stdc++.h>
using namespace std;
string word1,word2;
bool recur(string s1,string s2,int n){
    if (n==1) return s1==s2;
    return ( recur(s1.substr(0,n/2),s2.substr(0,n/2),n/2) && recur(s1.substr(n/2,n),s2.substr(n/2,n),n/2) )||( recur(s1.substr(0,n/2),s2.substr(n/2,n),n/2) && recur(s1.substr(n/2,n),s2.substr(0,n/2),n/2) );
}
int main(){
    cin>>word1>>word2;
    if (recur(word1,word2,word1.size())) cout<<"YES";
    else cout<<"NO";    
}