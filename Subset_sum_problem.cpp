#include <bits/stdc++.h>
using namespace std;

bool findPartition(int *, int);
bool issum(int a[], int sum, int n){
    bool t[n+1][sum+1];
    
    for(int j=0;j<=sum;j++){
        t[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                t[i][j]=(t[i-1][j] | t[i-1][j-a[i-1]]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
bool findPartition(int a[], int n) {
    
    long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum%2!=0){
        return false;
    }
    long half=sum/2;
    
     return issum(a,half,n);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];

        if (findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


