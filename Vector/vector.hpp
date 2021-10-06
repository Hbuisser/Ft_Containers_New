#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include <iterator>

#include "vector_iterator.hpp"

// https://internalpointers.com/post/writing-custom-iterators-modern-cpp
// https://www.it-swarm-fr.com/fr/c%2B%2B/ecrire-votre-propre-conteneur-stl/939838072/

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		private:
            size_t	_size;
            size_t 	_capacity;
			Alloc 	_base;
			T* 		_ptr;

        public:
            /////////////////////////////////////////////////////// Typedef /////////////////////////////////////
			typedef T											value_type;
			typedef Alloc   									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;			
			typedef It<value_type>								iterator;
			typedef It<const value_type>						const_iterator;
			// // typedef ft::reverse_iterator<value_type>			reverse_iterator;
			// // typedef ft::reverse_iterator<const value_type>		const_reverse_iterator;
			// typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t										size_type;

			/////////////////////////////////////////////////////// Constructors /////////////////////////////////
			explicit vector(const allocator_type& alloc = allocator_type()) : _base(alloc), _size(0), _capacity(0) { this->_ptr = this->_base.allocate(0); }
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _base(alloc), _size(n), _capacity(n)
			{
				this->_ptr = this->_base.allocate(n);
				size_t i = 0;

				while (i < n)
				{
					this->_base.construct(this->_ptr + i, val);
					i++;
				}
			}
			template<typename InputIterator> 
			vector(InputIterator first, InputIterator last)
			{
				this->_size = 0;
				// assign(first, last);
			}
			vector(const vector &x) : _base(allocator_type()), _size(x._size), _capacity(x._capacity) 
			{
				this->_ptr = this->_base.allocate(0);
				*this = x;
			}
			virtual ~vector()
			{
				this->clear();
				this->_base.deallocate(this->_ptr, this->_capacity);
			}
			vector & operator=(const vector & x)
			{
				size_t i = 0;

				// if (*this != &x)
				{
					this->clear();
					this->_base.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_base.allocate(x._capacity);
					while (i < x._size)
					{
						this->_base.construct(this->_ptr + i, *(x._ptr + i));
						//this->_base.construct(this->_ptr + i, &(x._ptr[i]));
						i++;
					}
					this->_size = x._size;
					this->_capacity = x._capacity;
				}
				return *this;
			}
			///////////////////////////////////////////////////// Iterators /////////////////////////////////////////
			iterator begin(void) { return iterator(_ptr); }
			const_iterator begin(void) const { return const_iterator(_ptr); }
			iterator end(void) { return iterator(_ptr + _size);}
			const_iterator end(void) const { return iterator(_ptr + _size);}
			// reverse_iterator rbegin(void);
			// const_reverse_iterator rbegin(void) const;
			// reverse_iterator rend(void);
			// const_reverse_iterator rend(void) const;
			/////////////////////////////////////////////////////// Capacity /////////////////////////
			size_t size(void) const { return this->_size; }
			size_t max_size(void) const { return this->_base.max_size(); }
			void reserve(size_type n)
			{
				if (n > this->_capacity)
				{
					size_t i;
					vector cpy;

					i = 0;
				   	cpy = *this;
					this->clear();
					this->_base.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_base.allocate(n);
					while (i < cpy._size)
					{
						this->_base.construct(this->_ptr + i, *(cpy._ptr + i));
						i++;
					}
					this->_size = cpy._size;
					this->_capacity = n;
				}
			}
			size_type capacity() const { return _capacity; }
			bool empty() const 
			{ 
				if (_size == 0)
					return true;
				return false; 
			}
			void resize(size_type n, value_type val = value_type())
			{
				size_t i = 0;
				
				if (n > this->_size)
				{
					this->reserve(n);
					i = this->_size;
					while (i < n)
					{
						this->_base.construct(this->_ptr + i, val);
						i++;
					}
				}
				else
				{
					i = n;
					while(i < this->_size)
					{
						this->_base.destroy(this->_ptr + i);
						i++;
					}
				}
				this->_size = n;
			}
			/////////////////////////////////////////////////////// Element acces ////////////////////////
			reference operator[]( size_type n ) { return this->at(n); }
			reference at(size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				else
					return *(this->_ptr + n);
			}
			const_reference at(size_type n) const
			{
				if ( n >= this->_size )
					throw std::out_of_range("vector");
				else
					return *(this->_ptr + n);
			}
			reference front() { return *this->_ptr; }
			const_reference front() const { return *this->_ptr; }
			reference back() { return *(this->_ptr + this->_size - 1); }
			const_reference back() const { return *(this->_ptr + this->_size - 1); }
			//////////////////////////////////////////////////////// Modifiers /////////////////////////////////////
			// template <class InputIterator>
  			// void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const value_type& val)
			{
				size_t i = 0;
				
				this->clear();
				this->_base.deallocate(this->_ptr, this->_capacity);
				this->_ptr = this->_base.allocate(n);
				while (i < n)
				{
					this->_base.construct(this->_ptr + i, val);
					i++;
				}
				this->_size = n;
				this->_capacity = n;
			}
			void push_back(const value_type& val)
			{
				if (this->_capacity == this->_size)
					this->reserve(this->_size + 1);
				this->_base.construct(this->_ptr + this->_size, val);
				this->_size = this->_size + 1;
			}
			void pop_back() { this->resize(this->_size - 1); }
			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			void swap(vector& x)
			{
				vector tmp;

				tmp = *this;
				this->clear();
				*this = x;
				x.clear();
				x = tmp;
			}
			void clear(void)
			{				
				size_t i;
				
				i = 0;
				while (i < this->_size)
				{
					this->_base.destroy(this->_ptr + i);
					i++;
				}
				this->_size = 0;
			}
			////////////////////////////////////////////////// Allocator ////////////////////////////////////
			allocator_type getAllocator(void) const { return _base; }
	};
	template< class T, class Alloc >
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		size_t count = 0;
		ft::vector<T>::iterator it1 = lhs.begin();
		ft::vector<T>::iterator it2 = rhs.begin();

		if (lhs.size() != rhs.size())
			return false;
		// while (it1 != lhs.end())
		// {
		// 	if (it1 + count != it2 + count)
		// 		return false;
		// 	count++;
		// }
		return true;
	}
	// template< class T, class Alloc >
	// constexpr bool operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {
		
	// }
	// template< class T, class Alloc >
	// bool operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {

	// }
	// template< class T, class Alloc >
	// bool operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {

	// }
	// template< class T, class Alloc >
	// bool operator<=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {

	// }
	// template< class T, class Alloc >
	// bool operator>(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {

	// }
	// template< class T, class Alloc >
	// bool operator>=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
	// {

	// }
}


#endif
