#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int longestSubsequence(int n, int a[])
{
   int l[n]={0};
   l[0]=1;
   
   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(a[j]<a[i] && l[j]>l[i]){
               l[i]=l[j];
           }
       }
       l[i]++;
   }
   
    int maxv=INT_MIN;
  for(int i=0;i<n;i++){
        maxv=max(maxv,l[i]);
  }
   return maxv;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}




