#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N,W;
    vector<int> a;
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    /*dp[i][j]:a[0]~a[i-1]までを好きな数用いて総和をjに出来るかどうかの真偽値*/
    vector<vector<bool> > dp(N+1, vector<bool>(W+1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= W; j++){
            if(dp[i][j]) dp[i+1][i] = true;
            if(j >= a[i+1] && dp[i+1][j-a[i+1]]) dp[i+1][j] = true;
        }
    }
    if(dp[N][W]) cout << "Yes" << endl;
}