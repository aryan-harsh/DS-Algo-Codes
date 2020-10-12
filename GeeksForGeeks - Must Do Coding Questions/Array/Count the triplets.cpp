/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets:
1 + 2 = 3 and 3 +2 = 5

*/

#include<iostream>
typedef long long int ll;
using namespace std;

int main()
{
    //ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int n,res=0;
        cin>>n;
        vector<int>v(n);

        for(int i=0;i<n;i++)
        cin>>v[i];
        sort(v.begin(),v.end());

        for(int i=n-1;i>=0;i--)
        {
            int a=v[i],b=0,c=i-1,x;
            while(b<c)
            {
                x=v[b]+v[c];
                if(x==a){res++;b++;c++;}
                else if(x<a)b++;
                else c--;
            }
        }
        if(res==0)cout<<-1;
        else cout<<res;

        cout<<endl;
    }
    return 0;
}
