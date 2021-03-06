/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月08日 星期日 11时19分59秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<fstream>
int main(void)
{
	std::ifstream ifs("in.txt");
	std::vector<int> vec_int;
	int val;
	while(ifs >> val)
	{
		std::cout << val << "	";
		vec_int.push_back(val);
	}
	std::cout << std::endl;

	for(std::vector<int>::iterator iter_left = vec_int.begin(); iter_left != vec_int.end(); ++iter_left)
	{
		if(iter_left + 1 != vec_int.end())
		{
			std::cout << *iter_left + *(++iter_left) << std::endl;
		}
		else
		{
			std::cout << "The last one is not been added !" << std::endl
				<< "And the last one is :" << *iter_left << std::endl;
		}
	}
 
	std::cout << "---------------------------" << std::endl;

	for(std::vector<int>::iterator iter_right = vec_int.end() -1,iter_left = vec_int.begin();
			iter_left <= iter_right; ++iter_left, --iter_right)
	{
		if(iter_left == iter_right)
		{
			std::cout << "The middle element is :" << *iter_left << std::endl;
		}
		else
		{
			std::cout << *iter_left + *iter_right << "	" << std::endl;
		}
	}


	return 0;
}
