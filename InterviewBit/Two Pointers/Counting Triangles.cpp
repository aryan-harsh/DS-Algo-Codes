	#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define MOD 1000000007

int Solution::nTriang(vector<int> &A) 
{
    ll n=A.size();
    sort(A.rbegin(),A.rend());
    ll sum=0;
    ll count=0;
    for(int i=0;i<n;i++)
    {
        ll l=i+1;
        ll r=n-1;
        while(l<r)
        {
            sum=1LL*A[l]+A[r];
            if(sum>A[i])
            {
                count=((count%MOD)+((r-l)%MOD))%MOD;
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return count%MOD;
}
