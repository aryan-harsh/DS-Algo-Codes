/* This program is another variation of Subset Sum Problem, in which we are given the array and the sum 
we need to find the count of all those subsets of the given array with the given sum.

Since this question includes the number of ways of counting the total number of subsets with given sum, this means this is an optimal problem , which can be easily solved with Dynamic Programming

Example:
Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1
Output: 4
All the possible subsets are {1}, {1}, {1}, {1} with sum =1;

Taking Constraints:
 0<n<=100
 0<sum<=10000

*/

/*
States: sum and the number of elements in the subset
Base Cases:
  1. if sum=0, it means that the required subset contains a null element phi
  2. if n=0, it means that there is no further element left to compute the answer further.


Decision Making:

1. if the current array element have value greater than required sum, it will be rejected and further elements of the array will be checked
2. if the current array element have value smaller than the required sum, we will have two choices , either to accept it or to reject it.
3. Since, we need to find the total number of ways , we will add all the possible ways in the second point.

we need to basically find the dp[n][sum] because it will be storing the count of all such required subsets. 

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
ll dp[105][10005];  // dp with states n and sum 
ll solve(ll ar[], ll n, ll sum)
{
	if(sum==0)return 1; // base condition will nul element as the subset having sum=0
    if(n==0)return 0; // base condition , if no element is left to be processed

    if(dp[n][sum]!=-1)return dp[n][sum];
    else
    {
        if(ar[n]<=sum)   // if current element value is less than required sum, we have a choice to either count it or not to count
        {
            return dp[n][sum] = solve(ar, n-1, sum-ar[n]) + solve(ar, n-1, sum);
        }
        else   // if current element is greater than the required sum, certainly , we have reject it and move further
        {
           return dp[n][sum] = solve(ar, n-1, sum);
        }
        
    }
    
}


int main()
{
 
	fastio;
    memset(dp, -1, sizeof(dp)); // pre initializing the dp array to be -1, which will depict the value is not previously computed
    ll n, sum;
    cin>>n>>sum;
      // (cin>>sum ) is taking the input of the required sum, whose count of subsets we need to find
    
    ll ar[n+1];
    for(ll i=1;i<=n;i++)cin>>ar[i];

	cout<<solve(ar, n, sum)<<"\n";  // recursive function call with optimization and memoization
} 
