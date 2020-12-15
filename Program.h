#pragma once
#include<list>
using std::list;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
#include<fstream>
#include<iterator>
#include<deque>
using std::deque;
#include<algorithm>
#include <numeric>

class Program
{
public:
	static list<string> p_list;
	static deque<string> p_deque;
	static vector<string> p_vector;

	template<typename T>
	void read(std::istream& in, vector<T>& container)
	{
		std::istream_iterator<T> start(in), cur;
		std::copy(start, cur, std::back_inserter(container));
	}
	template<typename T>
	void print(std::ostream& out, vector<T>& container)
	{
		std::ostream_iterator<T> start(out, ", ");
		std::copy(container.begin(), container.end(), start);
	}

	template<typename T>
	void read(std::istream& in, list<T>& container)
	{
		std::istream_iterator<T> start(in), cur;
		std::copy(start, cur, std::back_inserter(container));
	}
	template<typename T>
	void print(std::ostream& out, list<T>& container)
	{
		std::ostream_iterator<T> start(out, ", ");
		std::copy(container.begin(), container.end(), start);
	}

	template<typename T>
	void read(std::istream& in, deque<T>& container)
	{
		std::istream_iterator<T> start(in), cur;
		std::copy(start, cur, std::back_inserter(container));
	}
	template<typename T>
	void print(std::ostream& out, deque<T>& container)
	{
		std::ostream_iterator<T> start(out, ", ");
		std::copy(container.begin(), container.end(), start);
	}

	template<typename T>
	void copy_(vector<T>& cont1, list<T>& cont2)
	{
		cont2.clear();
		std::copy(cont1.begin(), cont1.end(), std::back_inserter(cont2));
	}
	template<typename T>
	void copy_(vector<T>& cont1, deque<T>& cont2)
	{
		cont2.clear();
		std::copy(cont1.begin(), cont1.end(), std::back_inserter(cont2));
	}

	//find elements with given letter on the given place
	vector<string> find_(list<string>& list_, char letter, size_t pos);
	//erase elements starting with given letter
	void erase_(list<string>& list_, char letter);
	//count num of elements containing given letter
	size_t count_(list<string>& list_, char letter);
	//count num of elements larger than given element
	size_t count_larger(list<string>& list_, string word);
	//create all possible permutations of the elements
	void permutation(vector<string>& vector_, size_t count_of_permutation);
};

vector<string> Program::p_vector;
list<string> Program::p_list;
deque<string> Program::p_deque;

vector<string> Program::find_(list<string>& list_, char letter, size_t pos)
{
	vector<string> result;
	pos--; //correction for proper indexation
	std::copy_if(list_.begin(), list_.end(), std::back_inserter(result),
		[letter, pos](auto obj)
		{
			if (pos >= obj.size()) return false;
			return obj[pos] == letter;
		});
	return result;
}
void Program::erase_(list<string>& list_, char letter)
{
	list_.remove_if([letter](auto obj)
		{
			return obj[0] == letter;
		});
}
size_t Program::count_(list<string>& list_, char letter)
{
	return std::count_if(list_.begin(), list_.end(), [letter](auto obj)
		{
			for (auto i : obj)
			{
				if (i == letter) return true;
				else return false;
			}
		});
}
size_t Program::count_larger(list<string>& list_, string word)
{
	size_t temp = word.size();
	return std::count_if(list_.begin(), list_.end(), [temp](string obj)
		{
			if (obj.size() > temp) return true;
				else return false;
		});
}
void Program::permutation(vector<string>& vector_, size_t count_of_permutation)
{
	std::sort(vector_.begin(), vector_.begin() + count_of_permutation);
	do
	{
		std::copy(vector_.begin(), vector_.begin() + count_of_permutation, std::ostream_iterator<string>(cout, " "));
	} while (std::next_permutation(vector_.begin(), vector_.begin() + count_of_permutation));

}
