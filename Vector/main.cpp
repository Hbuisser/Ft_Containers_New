#include <vector>
#include <iostream>
#include "vector.hpp"

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
	P("size: " << s.size());
	P("size: " << f.size());
	P("size: " << s2.size());
	P("size: " << f2.size());
	P("________________________________max_size__________________________________");
	P("max size: " << s.max_size());
	P("max size: " << f.max_size());
	P("max size: " << s2.max_size());
	P("max size: " << f2.max_size());
	P("________________________________capacity__________________________________");
	P("capacity: " << s.capacity());
	P("capacity: " << f.capacity());
	P("capacity: " << s2.capacity());
	P("capacity: " << f2.capacity());
	P("________________________________resize____________________________________");
	s.resize(7, "heyyy");
	f.resize(7, "heyyy");
	s2.resize(7, "heyyy");
	f2.resize(7, "heyyy");
	P("resize: " << s.size());
	P("resize: " << f.size());
	P("resize: " << s2.size());
	P("resize: " << f2.size());
	P("------------------------------Element access-----------------------------");
	P("-------------------------------------------------------------------------");
	P("________________________________operator []______________________________");
	P("[3]: " << s2[3]);
	P("[3]: " << f2[3]);
	P("________________________________at_______________________________________");
	// no try catch => abort if error
	P("at: " << s2.at(6));
	P("at: " << f2.at(6));
	P("________________________________front____________________________________");
	P("front: " << s2.front());
	P("front: " << f2.front());
	P("________________________________back_____________________________________");
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("------------------------------Modifiers----------------------------------");
	P("-------------------------------------------------------------------------");
	P("________________________________Push back________________________________");
	P("size: " << s2.size());
	P("size: " << f2.size());
	s2.push_back("bonjour");
	f2.push_back("bonjour");
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("size: " << s2.size());
	P("size: " << f2.size());
	P("________________________________Pop back__________________________________");
	s2.pop_back();
	f2.pop_back();
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("size: " << s2.size());
	P("size: " << f2.size());
	return 0;
}