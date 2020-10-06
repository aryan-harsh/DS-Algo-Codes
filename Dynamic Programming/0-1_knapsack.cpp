#include<bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n) 
{ 
    int t[n+1][W+1];
    for(int j=0;j<=W;j++){
        t[0][j]=0;
    }
    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(t[i-1][j], (val[i-1]+ t[i-1][j-wt[i-1]]));
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][W];
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 
