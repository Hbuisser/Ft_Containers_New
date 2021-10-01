#include <vector>
#include <iostream>
#include "vector2.hpp"

#define P(x) std::cout << x << std::endl
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define NC "\e[0m"

template <class T>
std::string verif(T elem)
{
	std::string value;

	if (elem)
		return (" | " GRN "[OK]" NC);
	else
		return (" | " RED "[K0]" NC);
}


int main()
{
	std::vector<int> vec(5);
	// int i = 0;

	// while (i < 100)
	// {
	// 	vec.push_back(5);
	// 	i++;
	// }
	std::cout << "size = " << vec.max_size() << std::endl;

	P("-------------------------------------------------------------------------");
    P("---------------------------------VECTOR----------------------------------");
    P("-------------------------------------------------------------------------");
    P("                                                                         ");
	P("                                                                         ");
    P("------------------------------CONSTRUCTORS-------------------------------");
	P("-------------------------------------------------------------------------");
	P("________________________________default__________________________________");
	std::vector<std::string> s;
	ft::vector<std::string> f;
	std::vector<std::string> s2(5, "hello");
	ft::vector<std::string> f2(5, "hello");
	P("------------------------------CAPACITY-----------------------------------");
	P("-------------------------------------------------------------------------");
	P("________________________________size_____________________________________");
	P(s.size());
	P(f.size());
	P(s2.size());
	P(f2.size());
	P("________________________________max_size__________________________________");
	P(s.max_size());
	P(f.max_size());
	P(s2.max_size());
	P(f2.max_size());
	P("________________________________capacity__________________________________");
	P(s.capacity());
	P(f.capacity());
	P(s2.capacity());
	P(f2.capacity());
	P("________________________________resize____________________________________");
	s.resize(4, "heyyy");
	f.resize(4, "heyyy");
	s2.resize(4, "heyyy");
	f2.resize(4, "heyyy");
	P(s.size());
	P(f.size());
	P(s2.size());
	P(f2.size());

	// no try catch => abort if error
	P(s2.at(6));
	P(f2.at(6));
	P("________________________________Push back____________________________________");

	return 0;
}