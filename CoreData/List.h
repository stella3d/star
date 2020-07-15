#pragma once
#include <array>

using namespace std;

namespace StarEngine
{

template <class T, size_t MIN_ELEMENTS = 8>
class List
{
public:
	List(size_t intialCapacity) : m_count(0), m_capacity(intialCapacity)
	{
		m_data = new T[intialCapacity];
	}

	~List()
	{
		delete[] m_data;
		m_data = NULL;
	}

	size_t push_back(T value)
	{
		if (m_count < m_capacity)
		{
			m_data[m_count] = value;
			m_count++;
			return;
		}

		// resize underlying array if we need more capacity
		delete[] m_data;
		GrowCapacity();
		m_data = new T[m_capacity];
	}

	public void size() { return m_capacity; }

	public void data() { return n_data; }

	inline T const& operator[](const size_t index) const
	{
		return m_data[index];
	}

private:

	size_t m_count;
	size_t m_capacity;
	T* m_data = NULL;

	inline size_t GrowCapacity() { m_capacity *= 2; }
};

}

