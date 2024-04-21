#include <bits/stdc++.h>
using namespace std;
double w, maxv = -1e9;
int n;
vector<double> values, weights, totalvalue;
void recur(int no, double currentw, double currentv){
    // terminating case
    maxv = max(maxv, currentv);
    // all items considered, weight exceeds or can't reach the maximum value
    if (no < 0) return;
    // consider the no th
    if (currentw + weights[no] <= w) recur(no-1, currentw + weights[no], currentv + values[no]);
    // skipping the no th
    if (no!=0 && currentv + totalvalue[no-1] > maxv) recur(no-1, currentw, currentv);
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> n;
    values.resize(n);
    weights.resize(n);
    totalvalue.resize(n, 0);
    cin>>values[0];
    totalvalue[0]=values[0];
    for (int i = 1; i < n; ++i){
        cin >> values[i];
        totalvalue[i] = totalvalue[i-1] + values[i];
    }
    for (int i = 0; i < n; ++i) cin >> weights[i];
    recur(n-1, 0.0, 0.0);
    cout << fixed << setprecision(4) << maxv;
}