int Solution::removeDuplicates(vector<int> &A) 
{
    int n=A.size();
    if(n<=2) return n;
    
    int up=1, pp=2;
    while(pp<n)
    {
        if(A[up]==A[pp]&&A[up]==A[up-1]) pp++;
        else
        {
            up++;
            A[up]=A[pp];
            pp++;
        }
    }
    return up+1;
}
