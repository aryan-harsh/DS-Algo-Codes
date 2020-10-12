int Solution::diffPossible(vector<int> &A, int B)
{
    int n=A.size();
    long long int diff=0;
    
    for(int i=0;i<n;i++)
    {
        int l=i, r=i+1;
        while(l<r)
        {
            diff=A[r]*1LL-A[l];
            if(diff==B) return 1;
            else if(diff<B) r++;
            else l++;
        }
    }
    return 0;
}
