#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include <iterator>


namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		private:
            size_t	_size;
            size_t 	_capacity;
			Alloc 	_base;
			T* _ptr;

        public:
            /////////////////// Typedef /////////////////////////////////////
			typedef T											value_type;
			typedef Alloc   									allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef	typename allocator_type::pointer 					pointer;
			typedef typename allocator_type::const_pointer 				const_pointer;
			// a changer std
			// typedef std::iterator<value_type>						iterator;
			// typedef std::iterator<const value_type>					const_iterator;
			// typedef ft::reverse_iterator<value_type>			reverse_iterator;
			// typedef ft::reverse_iterator<const value_type>		const_reverse_iterator;
			// typedef iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t										size_type;

			////////////////// Constructors /////////////////////////////////
			explicit vector(const allocator_type& alloc = allocator_type()) : _base(alloc), _size(0), _capacity(0) {}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _base(alloc), _size(n), _capacity(n)
			{
				_ptr = _base.allocate(n);
				size_t i = 0;

				while (i < n)
				{
					_base.construct(_ptr + i, val);
					i++;
				}
			}
			template<typename InputIterator> 
			vector(InputIterator first, InputIterator last)
			{
				_size = 0;
				// assign(first, last);
			}
			vector(const vector &x) : _base(x._base), _size(x._size) {};
			virtual ~vector()
			{
			// 	_base.deallocate(_base, _size);
			}

			allocator_type getAllocator(void) const { return _base; }
			size_t size(void) const { return _size; }
			size_t max_size(void) const { return _base.max_size(); }
			void resize(size_type n, value_type val = value_type())
			{
				pointer ptr;
				allocator_type cpy;
				size_t i = 0;

				// ptr = cpy.allocate(this->_size);
				// while (i < this->_size)
				// {
				// 	cpy.construct(ptr + i, *(this->_ptr + i));
				// 	i++;
				// }
				// // _base.deallocate(this->_ptr, _size);
				// this->_ptr = _base.allocate(n);
				// i = 0;
				// while (i < this->_size)
				// {
				// 	_base.construct(this->_ptr + i, *(ptr + i));
				// 	i++;
				// }
				// while (i < n)
				// {
				// 	_base.construct(this->_ptr + i, val);
				// 	i++;
				// }
				// this->_size = n;
				
				if (n > this->_size)
				{
					this->_base.reserve(n);
					i = this->_size;
					while (i < this->_capacity)
					{
						_base.construct(this->_ptr + i, val);
						i++;
					}
				}
				else
				{
					ptr = cpy.allocate(n);
					while (i < n)
					{
						cpy.construct(ptr + i, *(this->ptr + i));
						i++;
					}
					// _base.deallocate(this->_ptr, _size);
					this->_ptr = this->_base.allocate(n);
					i = 0;
					while (i < n)
					{
						this->_base.construct(this->_ptr + i, *(ptr + i));
						i++;
					}
				}
				this->_size = n;
				if (n > this->_capacity)
					this->_capacity = n;
			}
			size_type capacity() const { return _size; }
			bool empty() const 
			{ 
				if (_size == 0)
					return true;
				return false; 
			}
			void reserve(size_type n)
			{
				pointer ptr;
				allocator_type cpy;
				size_t i = 0;

				if (n > this->_capacity)
				{
					ptr = cpy.allocate(this->_capacity);
					while (i < this->_capacity)
					{
						cpy.construct(ptr + i, *(this->_ptr + i));
						i++;
					}
					// _base.deallocate(this->_ptr, _size);
					this->_ptr = this->_base.allocate(n);
					i = 0;
					while (i < this->_capacity)
					{
						this->_base.construct(this->_ptr + i, *(ptr + i));
						i++;
					}
					this->_capacity = n;
				}
			}
	};
}


#endif
