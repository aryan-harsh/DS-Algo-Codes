vector<int> Solution::nextPermutation(vector<int> &A)
{
int idx = -1;

    for(auto i=A.size()-1; i>=0; --i)
    {
        if(A[i] > A[i-1])
        {
            idx = i-1;
            break;
        }
    }

    if(idx != -1)   // if permutation exists
    {
        int i = A.size()-1;
        while(A[i] < A[idx])    //find the number which is just greater
        {
            --i;
        }
        swap(A[i], A[idx]);
    }

    int i = idx+1;
    int j = A.size()-1;

    while(i < j)   //now just reverse the nums from the (k+1)th position to get the next permutation
    {
        swap(A[i++], A[j--]);
    }
    return A;
}
