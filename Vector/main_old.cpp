#include "vector.hpp"
#include <vector>
#include <string>

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

void t_vector(void)
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
	std::vector<std::string> s2(5, "hello");
	ft::vector<std::string> f2(5, "hello");
	show_container(s2);
    f2.show();
    P("size = " << s2.size() << " | " << f2.size() << verif(s2.size() == f2.size()));
    P("front = " << s2.front() << " | " << f2.front() << verif(s2.front() == f2.front()));
    P("back = " << s2.back() << " | " << f2.back() << verif(s2.back() == f2.back()));
	P("________________________________copy__________________________________");
	std::vector<std::string> s3(s2);
	ft::vector<std::string> f3(f2);

	show_container(s3);
    f3.show();
    P("size = " << s3.size() << " | " << f3.size() << verif(s3.size() == f3.size()));
    P("front = " << s3.front() << " | " << f3.front() << verif(s3.front() == f3.front()));
    P("back = " << s3.back() << " | " << f3.back() << verif(s3.back() == f3.back()));
	P("_________________________________Assign__________________________________");
	P("------single");
	s3.assign(3, "assign");
	f3.assign(3, "assign");

	show_container(s3);
    f3.show();
    P("size = " << s3.size() << " | " << f3.size() << verif(s3.size() == f3.size()));
    P("front = " << s3.front() << " | " << f3.front() << verif(s3.front() == f3.front()));
    P("back = " << s3.back() << " | " << f3.back() << verif(s3.back() == f3.back()));
	P("------range");
	std::vector<std::string>::iterator s3_iter_begin = s3.begin();
	std::vector<std::string>::iterator s3_iter_end = s3.end();
    ft::vector<std::string>::iterator f3_iter_begin = f3.begin();
    ft::vector<std::string>::iterator f3_iter_end = f3.end();
	s3_iter_end--;
	f3_iter_end--;
	s3.assign(s3_iter_begin, s3_iter_end);
	f3.assign(f3_iter_begin, f3_iter_end);

	show_container(s3);
    f3.show();
    P("size = " << s3.size() << " | " << f3.size() << verif(s3.size() == f3.size()));
    P("front = " << s3.front() << " | " << f3.front() << verif(s3.front() == f3.front()));
    P("back = " << s3.back() << " | " << f3.back() << verif(s3.back() == f3.back()));
	P("");
	P("");
	P("------------------------------ITERATORS-----------------------------------");
	P("-------------------------------------------------------------------------");
	P("_______________________________begin_____________________________________");
	std::vector<std::string>::iterator s_iter_begin = s2.begin();
    ft::vector<std::string>::iterator f_iter_begin = f2.begin();
	
	P("begin = " << *s_iter_begin << " | " << *f_iter_begin << verif(*s_iter_begin == *f_iter_begin));
	P("_______________________________end_____________________________________");
    ft::vector<std::string>::iterator f_iter_end = f2.end();

	P("end = " << *f_iter_end << " | " << GRN "[OK]" NC);
	P("_______________________________reverse_____________________________________");
	std::vector<std::string>::reverse_iterator s_iter_rev = s2.rbegin();
    ft::vector<std::string>::reverse_iterator f_iter_rev = f2.rbegin();
	bool good = true;
	for (; s_iter_rev != s2.rend(); s_iter_rev++)
	{
		if (*s_iter_rev != *f_iter_rev)
			good = false;
		f_iter_rev++;
	}
	P("reverse = " << verif(good));
    P("size = " << s2.size() << " | " << f2.size() << verif(s2.size() == f2.size()));
    P("front = " << s2.front() << " | " << f2.front() << verif(s2.front() == f2.front()));
    P("back = " << s2.back() << " | " << f2.back() << verif(s2.back() == f2.back()));
	P("");
	P("");
	P("------------------------------CAPACITY & ACCES---------------------------");
	P("-------------------------------------------------------------------------");
    P("_________________________________Empty___________________________________");
    P("empty ? " << s2.empty() << " | " << f2.empty() << verif(s2.empty() == f2.empty()));
    P("_________________________________Size____________________________________");
    P("size ? " << s2.size() << " | " << f2.size() << verif(s2.size() == f2.size()));
	P("_________________________________Max size________________________________");
    P("max size ? " << s2.max_size() << " | " << f2.max_size() << verif(s2.max_size() == f2.max_size()));
	P("_____________________________Back & Front________________________________");
    P("front = " << s2.front() << " | " << f2.front() << verif(s2.front() == f2.front()));
    P("back = " << s2.back() << " | " << f2.back() << verif(s2.back() == f2.back()));
	P("_________________________________At_______________________________________");
    s2.at(1) = "88";
	f2.at(1) = "88";
	show_container(s2);
	f2.show();
	P("at = " << s2.front() << " | " << f2.front() << verif(s2.front() == f2.front()));
	P("");
    P("");
	P("--------------------------------MODIFIERS--------------------------------");
	P("-------------------------------------------------------------------------");
	P("_______________________________Push back_________________________________");
    s.push_back("back_one");
	s.push_back("back_two");
	s.push_back("back_three");
	s.push_back("back_four");
    f.push_back("back_one");
	f.push_back("back_two");
	f.push_back("back_three");
	f.push_back("back_four");

    show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Pop back___________________________________");
    s.pop_back();
	f.pop_back();

    show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Resize bigger_______________________________");
	s.resize(6, "RESIZE");
	f.resize(6, "RESIZE");

	show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Resize lower_______________________________");
	s.resize(2, "RESIZE");
	f.resize(2, "RESIZE");

	show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Insert___________________________________");
	std::vector<std::string>::iterator s_it = s.begin();
	ft::vector<std::string>::iterator f_it = f.begin();
	s.insert(s_it, "INSERT");
	f.insert(f_it, "INSERT");

	show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Swap______________________________________");
	P("______before :");
	show_container(s);
    f.show();
	show_container(s3);
    f3.show();

	P("______after :");
	s.swap(s3);
	f.swap(f3);
	show_container(s);
    f.show();
	show_container(s3);
    f3.show();
	P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______________________________Erase______________________________________");
	P("______single :");
	s_it = s.begin();
	f_it = f.begin();
	s.erase(s_it);
	f.erase(f_it);

	show_container(s);
    f.show();
	P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("______range :");
	std::vector<std::string>::iterator s_it2 = s.begin();
	ft::vector<std::string>::iterator f_it2 = f.begin();
	std::vector<std::string>::iterator s_it3 = s.end();
	ft::vector<std::string>::iterator f_it3 = f.end();
	s_it3--;
	f_it3--;

	s.erase(s_it2, s_it3);
	f.erase(f_it2, f_it3);
	show_container(s);
    f.show();
	P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("front = " << s.front() << " | " << f.front() << verif(s.front() == f.front()));
    P("back = " << s.back() << " | " << f.back() << verif(s.back() == f.back()));
	P("_______________________________Clear________________________________________");
    s.clear();
    f.clear();
	show_container(s);
    f.show();
    P("size = " << s.size() << " | " << f.size() << verif(s.size() == f.size()));
    P("");
    P("");
	P("-------------------------------OPERATORS------------------------------------");
	P("----------------------------------------------------------------------------");
    P("__________________________________==________________________________________");
    std::vector<std::string>  s5(s);
    ft::vector<std::string>  f5(f);
    P("operator '==' : " << (f == f5) << verif((s == s5) == (f == f5)));
    P("__________________________________!=______________________________________");
    P("operator '!=' : " << (f != f5) << verif((s != s5) == (f != f5)));
    P("___________________________________<______________________________________");
    P("operator '<' : " << (f < f5) << verif((s < s5) == (f < f5)));
    P("__________________________________<=______________________________________");
    P("operator '<=' : " << (f <= f5) << verif((s <= s5) == (f <= f5)));
    P("___________________________________>______________________________________");
    P("operator '>' : " << (f > f5) << verif((s > s5) == (f > f5)));
    P("___________________________________>=______________________________________");
    P("operator '>=' : " << (f >= f5) << verif((s >= s5) == (f >= f5)));
}

int main()
{
    t_vector();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////

// The elements are stored contiguously, which means that elements can be accessed 
// not only through iterators, but also using offsets to regular pointers to elements. 
// This means that a pointer to an element of a vector may be passed to any function 
// that expects a pointer to an element of an array.

// like an array but with a dynamic size. Each time size changes vector copies old array 
// into new array with added element, so it is slow in adding elements but it is fast 
// in accessing elements