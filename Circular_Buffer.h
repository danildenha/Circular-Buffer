// Circular_Buffer.h -- starter code

#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	CircularBuffer() : _size(0), _head(0), _capacity(cap), _current(0), _tail(0) { };

	T& head() { return c[_head]; }
	T& tail() { return c[_tail]; }
	T const& head() const { return c[_head]; }
	T const& tail() const { return c[_tail];  }

	//circular buffer overwrites oldest data if buffer is full
    //This function updates appropriate instance variables
	void push_back(T val) noexcept
	{
		c[_current] = val;
		_tail = _current;
		
		if (_size != _capacity)
		{
			++_size;
		}
		else
		{
			//set head to the beginning if it is beyond the array
			_head = (++_head) % _capacity;
		}
		//if next current is beyond the array then we set it to beginning
		_current = (++_current) % _capacity;
	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		
		_head = (++_head) % _capacity;
		--_size;
	}

	int size() const noexcept { return _size; }

	int capacity() noexcept { return _capacity; }

	bool empty() const noexcept { return _size == 0; } //returns true if buffer is empty

	bool full() const noexcept { return  _size == _capacity; }  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		os << "Buffer info: head: " << buf._head << ", tail: " << buf._tail << ", current: "
			<< buf._current << ", capacity: " << buf._capacity << ", size: " << buf._size << endl;
		os << " Container: ";
		std::for_each(buf.begin(), buf.end(), 
			[&os](T value) { os << value << " "; });
		os << endl;
		return os;
	}


private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;
};
#endif
