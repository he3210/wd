/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月22日 星期日 16时02分32秒
 *******************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

const std::string input_file_path("input.txt");

int main(void)
{
	std::ifstream input_file(input_file_path.c_str());
	if(!input_file)
	{
		std::cerr << "error: unable open input file: " << input_file_path << std::endl;
		return -1;
	}

	std::map< std::string, std::vector< std::pair< std::string, std::string> > > map_lastname;
	std::string lastname, firstname, birthday;
	std::string line;
	while(getline(input_file, line))
	{
		std::vector< std::pair< std::string, std::string > > vec_name;
		std::istringstream oss(line);
		oss >> lastname;
		while(oss >> firstname && oss >> birthday)
		{
			vec_name.push_back(make_pair(firstname, birthday));
		}
		map_lastname.insert(make_pair(lastname, vec_name));
	}

	std::map< std::string, std::vector< std::pair< std::string, std::string > > >::const_iterator ret;
	std::vector< std::pair< std::string, std::string> >::const_iterator iter;
	while(std::cin >> lastname)
	{
		ret = map_lastname.find(lastname);
		if(ret == map_lastname.end())
		{
			std::cout << "There is not the lastname: " << lastname << std::endl;
		}
		else
		{
			iter = ret -> second.begin();
			while(iter != ret -> second.end())
			{
				std::cout << std::setw(16) << std::left << (*iter).first << '\t' << (*iter).second << std::endl; 
				++iter;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
