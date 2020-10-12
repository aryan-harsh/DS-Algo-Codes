/*
Given an integar A. Compute and return the square root of A.
If A is not a perfect square, return floor(sqrt(A)).


Input Format
The first and only argument given is the integer A.

Output Format
Return floor(sqrt(A))

Constraints
1 <= A <= 10^9

For Example
Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
*/

#define ll long long int
int Solution::sqrt(int A)
{
    if(A==1)
     return 1;
    ll low=0, high = A/2;
    ll mid= low+(high-low)/2;
    while(low<=high)
    {
       mid=low+(high-low)/2;
       if(mid*mid<=A && (mid+1)*(mid+1)>A)
        return mid;
       else if(mid*mid>A)
        high=mid-1;
       else low=mid+1;
    }
}
