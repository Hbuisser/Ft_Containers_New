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

template<class T>
void show_container(T & l)
{
	std::cout << "Container : ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " << ";
	std::cout << "-END" << std::endl;
}

int main()
{
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
	show_container(s);
	show_container(f);
	std::vector<std::string> s2(5, "hello");
	ft::vector<std::string> f2(5, "hello");
	show_container(s2);
	show_container(f2);
	s2.pop_back();
	f2.pop_back();
	show_container(s2);
	show_container(f2);
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
	show_container(s);
	show_container(f);

	s2.resize(7, "heyyy");
	f2.resize(7, "heyyy");
	show_container(s2);
	show_container(f2);
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
	P("________________________________Assign___________________________________");
	s2.assign(4, "ASSIGNED");
	f2.assign(4, "ASSIGNED");
	show_container(s2);
	show_container(f2);
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("size: " << s2.size());
	P("size: " << f2.size());
	P("________________________________Push back________________________________");
	P("size: " << s2.size());
	P("size: " << f2.size());
	s2.push_back("bonjour");
	f2.push_back("bonjour");
	show_container(s2);
	show_container(f2);
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("size: " << s2.size());
	P("size: " << f2.size());
	P("________________________________Pop back__________________________________");
	show_container(s2);
	show_container(f2);
	s2.pop_back();
	f2.pop_back();
	show_container(s2);
	show_container(f2);
	P("back: " << s2.back());
	P("back: " << f2.back());
	P("size: " << s2.size());
	P("size: " << f2.size());
	s2.pop_back();
	f2.pop_back();
	show_container(s2);
	show_container(f2);
	P("________________________________Insert__________________________________");
	P("________________________________Erase___________________________________");
	P("________________________________Swap___________________________________");
	std::vector<std::string> s3(6, "yoyo");
	ft::vector<std::string> f3(6, "yoyo");
	show_container(s3);
	show_container(f3);
	s.swap(s3);
	f.swap(f3);
	show_container(s3);
	show_container(f3);
	show_container(s);
	show_container(f);
	P("back: " << s.back());
	P("back: " << f.back());
	P("size: " << s.size());
	P("size: " << f.size());
	P("back: " << s3.back());
	P("back: " << f3.back());
	P("size: " << s3.size());
	P("size: " << f3.size());
	P("------------------------------Iterators----------------------------------");
	P("-------------------------------------------------------------------------");
	P("________________________________Begin____________________________________");
	std::vector<std::string>::iterator s_iter_begin = s2.begin();
    ft::vector<std::string>::iterator f_iter_begin = f2.begin();
	
	show_container(s2);
	show_container(f2);
	P("begin = " << *s_iter_begin);
	P("begin = " << *f_iter_begin);
	P("________________________________End_______________________________________");
	std::vector<std::string>::iterator s_iter_end = s2.end();
    ft::vector<std::string>::iterator f_iter_end = f2.end();
	
	show_container(s2);
	show_container(f2);
	P("end = " << *s_iter_end);
	P("end = " << *f_iter_end);
	P("_______________________________reverse_____________________________________");
	std::vector<std::string>::reverse_iterator s_iter_rev = s2.rend();
    ft::vector<std::string>::reverse_iterator f_iter_rev = f2.rend();

	P(*s_iter_rev);
	P(*f_iter_rev);
	// bool good = true;
	// int count = 0;
	// P("reverse begin = " << good);
	// for (; s_iter_rev != s2.rbegin(); s_iter_rev++)
	// {
	// 	if (*s_iter_rev != *f_iter_rev)
	// 	{
	// 		good = false;
	// 		count++;
	// 		// break;
	// 		P("reverse s = " << *s_iter_rev);
	// 		P("reverse f = " << *f_iter_rev);
	// 	}
	// 	s_iter_rev++;
	// 	f_iter_rev++;
	// }
	// P("reverse end = " << good << "-" << count << "-" << *f_iter_rev);
	P("-------------------------------OPERATORS------------------------------------");
	P("----------------------------------------------------------------------------");
    P("__________________________________==________________________________________");
    std::vector<std::string>  s4(s2);
    ft::vector<std::string>  f4(f2);

	show_container(s2);
	show_container(f2);
	show_container(s4);
	show_container(f4);
    P("operator '==' : " << (s4 == s2));
	P("operator '==' : " << (f4 == f2));
	P("----------------------------------------------------------------------------");
    P("__________________________________!=________________________________________");
	s2.push_back("diffff");
	f2.push_back("diffff");
	show_container(s2);
	show_container(f2);

	show_container(s4);
	show_container(f4);
    P("operator '!=' : " << (s4 != s2));
	P("operator '!=' : " << (f4 != f2));
	P("----------------------------------------------------------------------------");
    P("__________________________________<________________________________________");
	show_container(s2);
	show_container(f2);
	show_container(s4);
	show_container(f4);
    P("operator '<' : " << (s4 < s2));
	P("operator '<' : " << (f4 < f2));
	s4.push_back("min");
	f4.push_back("min");
	P("operator '<' : " << (s4 < s2));
	P("operator '<' : " << (f4 < f2));
	P("----------------------------------------------------------------------------");
    P("__________________________________<=________________________________________");
	show_container(s2);
	show_container(f2);
	show_container(s4);
	show_container(f4);
    P("operator '<=' : " << (s4 <= s2));
	P("operator '<=' : " << (f4 <= f2));
	s4.push_back("min");
	f4.push_back("min");
	P("operator '<=' : " << (s4 <= s2));
	P("operator '<=' : " << (f4 <= f2));
	P("----------------------------------------------------------------------------");
    P("__________________________________>________________________________________");
	show_container(s2);
	show_container(f2);
	show_container(s4);
	show_container(f4);
    P("operator '>' : " << (s4 > s2));
	P("operator '>' : " << (f4 > f2));
	P("----------------------------------------------------------------------------");
    P("__________________________________>=________________________________________");
	show_container(s2);
	show_container(f2);
	show_container(s4);
	show_container(f4);
    P("operator '>' : " << (s4 >= s2));
	P("operator '>' : " << (f4 >= f2));
	return 0;
}