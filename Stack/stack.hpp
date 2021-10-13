#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <limits>
#include <iterator>
#include <deque>

#include "vector.hpp"

namespace ft
{
	template<class T, class Container = std::deque<T> >
	class stack
	{
		private:
			Container	_cont;
			// comparaison lexicographique (pas la taille mais chaque elements)
			// friend => peut acceder a la classe amie
			friend bool operator==(const stack<value_type,container_type>& rhs) {return (_cont == rhs._cont);}
			friend bool operator!=(const stack<value_type,container_type>& rhs) {return (_cont != rhs._cont);} 
			friend bool operator<(const stack<value_type,container_type>& rhs) {return (_cont < rhs._cont);} 
			friend bool operator<=(const stack<value_type,container_type>& rhs) {return (_cont <= rhs._cont);} 
			friend bool operator>(const stack<value_type,container_type>& rhs) {return (_cont > rhs._cont);} 
			friend bool operator>=(const stack<value_type,container_type>& rhs) {return (_cont >= rhs._cont);} 

		public:
			/////////////////// Typedef /////////////////////////////////////
			typedef Container					container_type;
			typedef T							value_type;
			typedef size_t						size_type;

			////////////////// Constructors /////////////////////////////////
			explicit stack(const container_type& cont = Container()) : _size(cont.size()), _cont(cont) {}
			stack(const stack& other) : _cont(other._cont) {}

			////////////////// Element access ///////////////////////////////
			value_type & top() { return _cont.back(); }
			const value_type & top() const { return _cont.back(); }

			////////////////// Capacity /////////////////////////////////////
			bool empty() const  { return _cont.empty(); }
			size_type size() const { return _cont.size(); }

			////////////////// Modifiers ////////////////////////////////////
			void push( const value_type& value ) { _cont.push_back(value); _size++; }
			void pop() { _cont.pop_back(); _size--; }
			
	};
}

#endif
