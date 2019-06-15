// Leetcode283_MoveZeros.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/* 解法1：时间复杂度O（n），空间复杂度O（n） */
/* 新申请一个数组，保存原数组中的非零元素，再赋值给原来数组 */
class Solution1
{
public:
	void moveZeros(vector<int>& nums)
	{
		vector<int>nonZeroElements;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
			{
				nonZeroElements.push_back(nums[i]);
			}
		}

		for (int  i = 0; i < nonZeroElements.size(); i++)
		{
			nums[i] = nonZeroElements[i];
		}
		for (int i = nonZeroElements.size(); i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}

private:

};

/* 解法2：定义两个指针，一个指向 */
/* 时间复杂度为O(n)，空间复杂度为O(1) */
class Solution2
{
public:
	void moveZeros(vector<int>& nums)
	{
		int k = 0; //nums中[0...k]的元素均为非0元素
		//遍历到第i个元素后，保证[0...i]中所有非0元素
		//都按照顺序排列在[0...k)中
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
			{
				nums[k++] = nums[i];
			}
		}

		for (int i = k; i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}

private:

};

/* 解法3：当发现非零元素和前面的0元素交换，省去最后统一赋值操作 */
class Solution3
{
public:
	void moveZeros(vector<int>& nums)
	{
		int k = 0; //nums中[0...k]的元素均为非0元素
		//遍历到第i个元素后，保证[0...i]中所有非0元素
		//都按照顺序排列在[0...k)中
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
			{
				if (i != k)
				{
					//将非0元素和0元素交换位置
					swap(nums[k++], nums[i]);
				}
				else
					k++;
			}
		}

		for (int i = k; i < nums.size(); i++)
		{
			nums[i] = 0;
		}
	}
};

int main()
{
	int arr[] = { 0,1,0,2,3,0,4 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	Solution3().moveZeros(vec);

	for (int i=0;i<vec.size();i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
