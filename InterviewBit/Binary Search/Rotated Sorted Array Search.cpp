/*
Given an array of integers A of size N and an integer B. Array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.
NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

Input Format
The first argument given is the integer array A. The second argument given is the integer B.

Output Format
Return index of B in array A, otherwise return -1

Constraints
1 <= N <= 1000000
1 <= A[i] <= 10^9 , all elements in A are disitinct.

For Example
Input :
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output :
    0
Explanation :
 Target 4 is found at index 0 in A.
*/

#int Solution::search(const vector<int> &A, int B)
{ int n = A.size();
  int low = 0, high = n-1;
  while(low<=high)
  {
    int mid = low + (high-low)/2;
    if(A[mid] == B)
     return mid;
    else if(A[0]<=A[mid])
      {        //i.e. left part is sorted
        if(A[0]<=B && B < A[mid])
           high = mid-1;    //B lies on left part
        else low = mid+1;

      }
    else
    {         //right part is sorted
        if(A[mid] < B && B<=A[n-1])
         low = mid+1;   //B lies on right part
        else high = mid-1;
    }
}
return -1;
}
