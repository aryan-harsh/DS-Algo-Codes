int Solution::removeDuplicates(vector<int> &A) 
{
    int n=A.size();
    int c=0,ue=0,pe=1;
    while(pe<n)
    {
        if(A[pe]==A[ue]) pe++;
        else
        {
            ue++;
            swap(A[pe],A[ue]);
            pe++;
        }
    }
    return ue+1;
}
