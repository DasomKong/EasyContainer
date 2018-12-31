#ifndef MyVector_h__
#define MyVector_h__

template<class T>
class MyVector
{
public:
	MyVector();
	MyVector(size_t InitSize);
	/*MyVector(const MyVector<T>& rhs);
	MyVector& operator=(const MyVector<T>& rhs);*/
	T& operator[](size_t Index);
	~MyVector();

public:
	const T& at(const size_t& iIndex);
	const T& back(void);
	size_t capacity(void);
	size_t size(void);
	void clear(void);
	bool empty(void);
	void push_back(const T& Val);
	void pop_back(void);
	void resize(size_t NewSize);
	void reserve(size_t Count);

private:
	void DealloacateMemory(void);

private:
	T* Container;
	size_t iSize;
	size_t iCapacity;
	size_t iChunk;
};

template<class T>
inline MyVector<T>::MyVector()
	:Container(nullptr), iSize(0), iCapacity(0), iChunk(0)
{
}

template<class T>
inline MyVector<T>::MyVector(size_t InitSize)
	: iSize(InitSize), iCapacity(InitSize)
{
	Container = new T[InitSize];

	memset(Container, NULL, sizeof(T) * InitSize);
}

// 임의 접근
template<class T>
inline T & MyVector<T>::operator[](size_t Index)
{
	return Container[Index];
}

template<class T>
inline MyVector<T>::~MyVector()
{
	DealloacateMemory();
}

/*
template<class T>
inline MyVector<T>::MyVector(const MyVector<T> & rhs)
: Container(rhs.Container)
{
}

template<class T>
inline MyVector & MyVector<T>::operator=(const MyVector<T> & rhs)
{
return *this;
}
*/

template<class T>
const T& MyVector<T>::at(const size_t & iIndex)
{
	if (iIndex < iSize && iSize >= 0)
		return Container[iIndex];
}

template<class T>
const T& MyVector<T>::back(void)
{
	if(iCount > 0)
		return Container[iSize];
}

template<class T>
size_t MyVector<T>::capacity(void)
{
	return iCapacity;
}

template<class T>
size_t MyVector<T>::size(void)
{
	return iSize;
}

template<class T>
void MyVector<T>::clear(void)
{
	memset(Container, NULL, sizeof(T) * iSize);
	iSize = 0;
}

template<class T>
bool MyVector<T>::empty(void)
{
	return iSize > 0 ? false : true;
}

template<class T>
void MyVector<T>::push_back(const T & Val)
{
	if (iSize == iCapacity)
	{
		iChunk = static_cast<size_t>(iCapacity * 0.5);
		iCapacity += iChunk;

		if (nullptr != Container)
		{
			T* newContainer = new T[iCapacity];

			for (size_t i = 0; i < iSize; ++i)
				newContainer[i] = Container[i];
			
			delete[] Container;
			Container = newContainer;
		}
		else
		{
			Container = new T[iCapacity];
		}
	}

	Container[iSize++] = Val;
}

template<class T>
void MyVector<T>::pop_back(void)
{
	if (iSize < 0)
		return;

	Container[iSize--] = nullptr;
}

template<class T>
void MyVector<T>::resize(size_t NewSize)
{

}

template<class T>
void MyVector<T>::reserve(size_t Count)
{
}

template<class T>
inline void MyVector<T>::DealloacateMemory(void)
{
	for (size_t i = 0; i < iSize; ++i)
	{
		T* temp = &Container[i];

		if (NULL == *temp)
			delete temp;
	}
}

#endif // !MyVector_h__