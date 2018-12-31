#ifndef MyList_h__
#define MyList_h__

template<class _Val>
class MyList
{
private:
	template<class _Val>
	struct Node {
		_Val _value;
		Node<_Val>* _next;
		Node<_Val>* _prev;

		Node()
			:_value(NULL), _next(nullptr), _prev(nullptr)
		{}
		Node(_Val value)
			: _next(nullptr), _prev(nullptr)
		{
			_value = value;
		}
	};

public:
	MyList();
	~MyList();

public:
	_Val& front(void);
	_Val& back(void);
	void clear(void);
	void pop_front(void);
	void pop_back(void);
	void push_front(const _Val& _value);
	void push_back(const _Val& _value);
	void remove(const _Val& _value);
	size_t size(void);
	void resize(size_t _size);
	void reverse(void);

	// 차후 구현
	template<_Val, typename Pred>
	void remove_if(_Val _value, Pred _pred)
	{

	}
	// sort

private:
	//void Search_Do(void (ft*)(void));
	void Deallocate(void);

private:
	Node<_Val>* Header;
	Node<_Val>* Tail;
	size_t iSize;
};




#endif // !MyList_h__

template<class _Val>
inline MyList<_Val>::MyList()
	:Header(nullptr), Tail(nullptr), iSize(0)
{
}

template<class _Val>
inline MyList<_Val>::~MyList()
{
	Deallocate();
}

template<class _Val>
inline _Val & MyList<_Val>::front(void)
{
	return Header->_value;
}

template<class _Val>
inline _Val & MyList<_Val>::back(void)
{
	return Tail->_value;
}

template<class _Val>
inline void MyList<_Val>::clear(void)
{
	Header = Tail = nullptr;
	iSize = 0;
}

template<class _Val>
inline void MyList<_Val>::pop_front(void)
{
	Header = Header->_next;
	Header->_prev = nullptr;
	--iSize;
}

template<class _Val>
inline void MyList<_Val>::pop_back(void)
{
	Tail = Tail->_prev;
	Tail->_next = nullptr;
	--iSize;
}

template<class _Val>
inline void MyList<_Val>::push_front(const _Val & _value)
{
	Node<_Val>* newNode = new Node<_Val>(_value);
	newNode->_next = Header;
	Header = newNode;
	++iSize;
}

template<class _Val>
inline void MyList<_Val>::push_back(const _Val & _value)
{
	Node<_Val>* newNode = new Node<_Val>(_value);
	Tail->_next = newNode;
	newNode->_prev = Tail;
	Tail = newNode;
	++iSize;
}

template<class _Val>
inline void MyList<_Val>::remove(const _Val & _value)
{
}

template<class _Val>
inline size_t MyList<_Val>::size(void)
{
	return iSize;
}

template<class _Val>
inline void MyList<_Val>::resize(size_t _size)
{
	for (size_t i = 0; i < _size; ++i)
	{
		Node<_Val>* newNode = new Node<_Val>;
		++iSize;
	}
}

template<class _Val>
inline void MyList<_Val>::reverse(void)
{
}

template<class _Val>
inline void MyList<_Val>::Deallocate(void)
{
	Node<_Val>* pHeader = Header;
	Node<_Val>* pNext = nullptr;

	for (size_t i = 0; i < iSize; ++i)
	{
		if (pHeader->_value != NULL)
		{
			pNext = pHeader->_next;
			delete pHeader;
			pHeader = pNext;
		}
	}
}