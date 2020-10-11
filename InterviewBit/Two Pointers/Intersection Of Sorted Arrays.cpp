vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    vector<int> ans;
    int i1=0,i2=0;
    while(1)
    {
        if(A[i1]>B[i2]) i2++;
        if(A[i1]<B[i2]) i1++;
        else
        {
            ans.push_back(A[i1]);
            i1++;
            i2++;
        }
        if(i1==A.size()||i2==B.size()) return ans;
    }
}
