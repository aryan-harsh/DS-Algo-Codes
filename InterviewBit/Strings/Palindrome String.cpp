/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A)
{ string str;
  if(A.size()==0)
   return 1;
  int n=A.size();
  for(int i=0; i<n; i++)
  {
        char c = A[i];
        if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
          {
            if(c>='A' && c<='Z')
            {
                c = ((char)(c + 32));
            }
            str.push_back(c);
        }
    }

    int i=0, j = str.size()-1;

    while(i<j)
      {
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
