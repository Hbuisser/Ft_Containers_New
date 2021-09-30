#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include <iterator>

#include "vector_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
        private:
            T 		*_vector;
            size_t	_size;
			size_t	_max_size;
			Alloc	*_allocator;

        public:
            /////////////////// Typedef /////////////////////////////////////
			typedef T											value_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef size_t										size_type;
			typedef Vector::iterator<value_type>				iterator;
			typedef const Vector::iterator<value_type>			const_iterator;
			typedef Vector::reverse_iterator<value_type>		reverse_iterator;
			typedef const Vector::reverse_iterator<value_type>	const_reverse_iterator;
			typedef Alloc   									allocator_type;

            ////////////////// Constructors /////////////////////////////////
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template<typename InputIterator> 
			vector(InputIterator first, InputIterator last)
			{
				_size = 0;
				_max_size = 10;
				assign(first, last);
			}
			vector(const vector &x);
			virtual ~vector();
			void assign(size_type count, const value_type& value);
			template<class InputIterator>
			void assign(InputIterator first, InputIterator last);

			///////////////// Iterators ////////////////////////////////////
			iterator begin() {return (iterator(_vector));}
			const_iterator begin() const {return (const_iterator(_vector));}
			iterator end() {return (iterator(_vector + _size));}
			const_iterator end() const {return (const_iterator(_vector + _size));}
			reverse_iterator rbegin(){if (!_size) return (reverse_iterator(_vector));  return (reverse_iterator(_vector + _size - 1));}
			const_reverse_iterator rbegin() const {if (!_size) return (const_reverse_iterator(_vector));  return (const_reverse_iterator(_vector + _size - 1));}
			reverse_iterator rend(){ return reverse_iterator(_vector - 1);}
			const_reverse_iterator rend() const { return const_reverse_iterator(_vector - 1) ;}

			/////////////////// Capacity ////////////////////////////////////
			bool empty() const;
			size_type size() const {return _size;}
			size_type max_size() const {return (std::numeric_limits<unsigned long long>::max() / sizeof(T));}
			void reserve(size_type new_cap);
			size_type capacity() const {return _max_size;}
			void resize(size_type count, T value = T());

			/////////////////// Element access ///////////////////////////////
			reference at(size_type pos) {return _vector[pos];}
			const_reference at(size_type pos) const {return _vector[pos];}
			reference front() {return _vector[0];}
			const_reference front() const {return _vector[0];}
			reference back() {return (_vector[_size - 1]);}
			const_reference back() const {return (_vector[_size - 1]);}
			reference operator[](size_type pos) {return _vector[pos];}
			const_reference operator[](size_type pos) const {return _vector[pos];}

			/////////////////// Allocator ///////////////////////////////////
			allocator_type get_allocator() const {return _allocator;}

			/////////////////// Modifiers ///////////////////////////////////
			void push_back(const value_type & val);
			void pop_back(void) {_size--;}
			void swap(vector& other);
			void clear();
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
					first = erase(first);
				return (last);
			}
			iterator erase(iterator pos)
			{
				T *vec_tmp = new T[_size - 1];
				size_t i = 0;
				size_t j = 0;

				for (iterator it = begin(); it < end(); ++it)
				{
					if (it != pos)
					{
						vec_tmp[j] = _vector[i];
						i++;
						j++;
					}
					else
						i++;
				}
				delete [] _vector;
				_vector = vec_tmp;
				_size--;
				_max_size--;
				return pos;
			}
			iterator insert(iterator pos, const T& value)
			{
				T *vec_tmp = new T[_size + 1];
				size_t i = 0;
				size_t j = 0;

				if (pos == end())
				{
					push_back(value);
					return iterator(_vector + _size - 1);
				}
				for (iterator it = begin(); it < end(); ++it)
				{
					if (it != pos)
					{
						vec_tmp[j] = _vector[i];
						i++;
						j++;
					}
					else
					{
						vec_tmp[j] = value;
						j++;
					}
				}
				vec_tmp[j] = _vector[i];
				delete [] _vector;
				_vector = vec_tmp;
				_size++;
				_max_size++;
				return pos;
			}

			/////////////////// Show ////////////////////////////////////////
			void show()
			{
				std::cout << "My container : ";
				for (unsigned int i = 0; i < _size; i++)
					std::cout << _vector[i] << " << ";
				std::cout << "-END" << std::endl;
			}
    };
	////////////////////////// Relational operators ///////////////////////////
	template<typename T>
	bool operator==(const vector<T>& lhs, const vector<T>& rhs)
	{
		Vector::iterator<T>	it_l = lhs.begin();
		Vector::iterator<T>	it_r = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l != *it_r)
				return (false);
			++it_l;
			++it_r;
		}
		return (true);
	}
    template<typename T>
    bool operator!=(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
    {
        return (!(lhs == rhs));
    }
    template<typename T>
	bool operator<(const vector<T>& lhs, const vector<T>& rhs)
	{
		Vector::iterator<T>	it_l = lhs.begin();
		Vector::iterator<T>	it_r = rhs.begin();

		if (lhs.size() != rhs.size() || (lhs.size() == 0 && rhs.size() == 0))
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l != *it_r)
            {
                if (*it_l < *it_r)
                    return (true);
                else
                    return (false);
            }
			++it_l;
			++it_r;
		}
        if (lhs.size() >= rhs.size())
            return (false);
		return (true);
	}
    template<typename T>
	bool operator<=(const vector<T>& lhs, const vector<T>& rhs)
	{
		Vector::iterator<T> l_it;
        Vector::iterator<T> r_it;

        if (lhs.size() == 0 and rhs.size() == 0)
            return (true);
        else if (lhs.size() == 0)
            return (true);
        else if (rhs.size() == 0)
            return (false);
        l_it = lhs.begin();
        r_it = rhs.begin();
        while (l_it != lhs.end() and r_it != rhs.end())
        {
            if (*l_it != *r_it)
            {
                if (*l_it < *r_it)
                return (true);
                else
                return (false);
            }
            ++l_it;
            ++r_it;
        }
        if (lhs.size() > rhs.size())
            return (false);
        else
            return (true);
	}
    template<typename T>
    bool operator>(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
    {
        Vector::iterator<T>	it_l = lhs.begin();
		Vector::iterator<T>	it_r = rhs.begin();

		if (lhs.size() != rhs.size() || (lhs.size() == 0 && rhs.size() == 0))
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l != *it_r)
            {
                if (*it_l > *it_r)
                    return (true);
                else
                    return (false);
            }
			++it_l;
			++it_r;
		}
        if (lhs.size() <= rhs.size())
            return (false);
		return (true);
    }
    template<typename T>
    bool operator>=(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
    {
        Vector::iterator<T> l_it;
        Vector::iterator<T> r_it;

        if (lhs.size() == 0 and rhs.size() == 0)
            return (true);
        else if (lhs.size() == 0)
            return (true);
        else if (rhs.size() == 0)
            return (false);
        l_it = lhs.begin();
        r_it = rhs.begin();
        while (l_it != lhs.end() and r_it != rhs.end())
        {
            if (*l_it != *r_it)
            {
                if (*l_it > *r_it)
                return (true);
                else
                return (false);
            }
            ++l_it;
            ++r_it;
        }
        if (lhs.size() < rhs.size())
            return (false);
        else
            return (true);
    }
	template <class T>
	void swap(vector<T>& x, vector<T>& y) {x.swap(y);}
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// Constructors ////////////////////////////////////////////
template < class T, class Alloc >
ft::vector<T, Alloc>::vector(const Alloc &alloc)
{
    _size = 0;
	_max_size = 10;
	_vector = new T[10];
	_allocator = new Alloc(alloc);
}

template < class T, class Alloc >
ft::vector<T, Alloc>::vector(size_t n, const T & val, const Alloc &alloc)
{
    _size = n;
	_max_size = n;
	_vector = new T[n];
	_allocator = new Alloc(alloc);
    for (size_t i = 0; i < n; i++)
		_vector[i] = val;
}

template < class T, class Alloc >
ft::vector<T, Alloc>::vector(const vector &x)
{
    _size = x._size;
	_max_size = x._max_size;
	_vector = x._vector;
	_allocator = x._allocator;
}

template < class T, class Alloc >
ft::vector<T, Alloc>::~vector()
{
    _size = 0;
    delete [] _vector;
}

template < class T, class Alloc >
void ft::vector<T, Alloc>::assign(size_t count, const T& value)
{
	T *tmp = new T[count];

	for (size_t i = 0; i < count; i++)
		tmp[i] = value;
	delete [] _vector;
	_vector = tmp;
	_size = count;
	_max_size = count;
}

template < class T, class Alloc >
template<class InputIterator>
void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	size_t i = 0;

	while (first != last)
	{
		last--;
		i++;
	}
	_size = i;
	while (first != last)
		push_back(*first);
}

//////////////////////////////// Capacity ////////////////////////////////////////////
template < class T, class Alloc >
bool ft::vector<T, Alloc>::empty() const 
{
    if (_size == 0) 
        return true; 
    return false; 
}

template < class T, class Alloc >
void ft::vector<T, Alloc>::reserve(size_t new_cap)
{
	if (new_cap > _max_size)
	{
		_max_size = new_cap;
		T *tmp = new T[_max_size];
		for (size_t i = 0; i < _size; i++)
			tmp[i] = _vector[i];
		delete [] _vector;
		_vector = tmp;
	}
}

//////////////////////////////// Element access ///////////////////////////////////////
//////////////////////////////// Allocator ////////////////////////////////////////////

// template < class T, class Alloc >
// Alloc ft::vector<T, Alloc>::get_allocator() const


//////////////////////////////// Modifiers ////////////////////////////////////////////
template < class T, class Alloc >
void ft::vector<T, Alloc>::push_back(const T & val) 
{
	T *tmp = new T[_size + 1];

	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _vector[i];
	}
	tmp[_size] = val;
	delete [] _vector;
	_vector = tmp;
	_size++;
}

template < class T, class Alloc >
void ft::vector<T, Alloc>::resize(size_t count, T val)
{
	T *new_vec = new T[count];

	if (count > _size)
	{
		for (size_t i = 0; i < _size; i++)
			new_vec[i] = _vector[i];
		for (size_t i = _size; i < count; i++)
			new_vec[i] = val;
	}
	else
	{
		for (size_t i = 0; i < count; i++)
			new_vec[i] = _vector[i];
	}
	delete [] _vector;
	_vector = new T[count];
	for (size_t i = 0; i < count; i++)
		_vector[i] = new_vec[i];
	_max_size = count;
	_size = count;
}

template < class T, class Alloc >
void ft::vector<T, Alloc>::swap(vector& other)
{
	vector<T> tmp;

    tmp = *this;
    *this = other;
    other = tmp;
}

template < class T, class Alloc >
void ft::vector<T, Alloc>::clear()
{
	delete [] _vector;
	_vector = new T[10];
	_size = 0;
	_max_size = 0;
}

#endif