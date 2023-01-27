#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

class Fibonachi
{
private:
	std::vector<std::string> m_line;
	std::vector<std::string> m_line_out;
	std::vector<int> m_shifr;
	std::vector<int> m_shifr_sorted;
	int m_errors;

	void set_line()
	{	
		std::cout << "Enter your line: ";
		std::string cur_str;
		getline(std::cin, cur_str);
		
		int ind;
		for (int i = 0; i < cur_str.length(); i = ind + 1)
		{
			ind = cur_str.find_first_of(" ", i) ;
			if (ind < 0) ind = cur_str.length();
			std::string sub = cur_str.substr(i, ind-i);
			m_line.push_back(sub);		
		}
	}

	void set_shifr()
	{
		std::cout << "Enter shifr: ";
		std::string cur_str;
		getline(std::cin, cur_str);

		int ind;
		for (int i = 0; i < cur_str.length(); i = ind + 1)
		{
			ind = cur_str.find_first_of(" ", i);
			if (ind < 0) ind = cur_str.length();
			std::string sub = cur_str.substr(i, ind - i);
			int p = std::atoi(sub.c_str()); //atoi преобразует string в int
			m_shifr.push_back(p);

		}
		for (int i = 0; i < size(m_shifr); i++)
		{
			m_shifr_sorted.push_back(m_shifr[i]);
		}
		std::sort(m_shifr_sorted.begin(), m_shifr_sorted.end());
	}

	int error_over_30()
	{
		if (size(m_line) > 30)
		{
			std::cout << "Incorrect line " << std::endl;
			return 1;
		}
		return 0; 
	}

	int error_in_shifr()
	{
		if (size(m_shifr) != size(m_line))
		{
			std::cout << "Incorrect shifr " << std::endl;
			return 1;
		}
		for (int i = 1; i < size(m_shifr); i++)
		{
			if (m_shifr[i - 1] == m_shifr[i]) 
			{ 
				std::cout << "Incorrect shifr " << std::endl;
				return 1; 
			}
		}
		return 0;
	}

	void print_line_out()
	{
		for (int i = 0; i < size(m_line_out); i++)
		{
			std::cout << m_line_out[i] << " ";
		}
		std::cout << "\n";
	}


public:
	
	Fibonachi()
	{
		set_line();
		set_shifr();
		if (error_in_shifr() or error_over_30())
		{
			m_errors = 1;
		}
		else { m_errors = 0; }
		if (m_errors)
		{
			std::cout << "Faild, incorrect data" << std::endl;					
		}
	}
	void print_line()
	{
		for (int i = 0; i < size(m_line); i++)
		{
			std::cout << m_line[i] << " ";
		}
		std::cout << "\n";
	}

	void print_shifr()
	{
		for (int i = 0; i < size(m_shifr); i++)
		{
			std::cout << m_shifr[i] << " ";
		}
		std::cout << "\n";
	}

	void encode()
	{
		if (m_errors == 0) 
		{
			std::vector<int>::iterator it;
			for (int i = 0; i < size(m_shifr); i++)
			{
				it = std::find(m_shifr_sorted.begin(), m_shifr_sorted.end(), m_shifr[i]);
				m_line_out.push_back(m_line[it- m_shifr_sorted.begin()]); //*it преобразование итератора в позицию не работает
			}
			print_line_out();
		}	
	}

	void decode()
	{
		if (m_errors == 0)
		{
			std::vector<int>::iterator it;
			for (int i = 0; i < size(m_shifr_sorted); i++)
			{
				it = std::find(m_shifr.begin(), m_shifr.end(), m_shifr_sorted[i]);
				m_line_out.push_back(m_line[it- m_shifr.begin()]);
			}
			print_line_out();
		}
	}

	
};

int main()
{
	Fibonachi a;
	a.encode();
	//a.decode();
	a.print_shifr();
	a.print_line();
	
	
}


