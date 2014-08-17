#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

//#include "LeetCode/median-of-two-sorted-arrays.h"
#include "LeetCode/palindrome-number.h"
#ifdef LEETCODE
int main()
{
	Solution().isPalindrome(1410110141);
	////int A[] = {1,2,3};
	////int B[] = {6,7,8};
	////Solution().findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
	//int arr[] = {3,2};
	//vector<vector<int>> matrix;
	//matrix.push_back(vector<int>(arr, arr+1));
	//matrix.push_back(vector<int>(arr+1, arr+2));
	//Solution().spiralOrder(matrix);
}

#else
struct Test
{
	Test()
	{
		freopen("in.in", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
};
static Test test;
#endif