// Author��xiongw	
// Date��2018-03-16
// filename:MinHeap.h

#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#define DEFAULTSIZE 10
#include "PQueue.h"

/**
* \brief ��С��
* \author	xy
*/
template<class E>
class MinHeap :public PQueue<E>
{
private:
	//E	   *m_pHeap;	/**< ����洢��ʽ */
	//int		m_nCount;	/**< Ԫ�ظ��� */
	//int		m_nMaxSize;	/**< ��� */

private:

	/**
	* \brief 
	* \param[in] nStart
	* \param[in] m
	* \return void
	*/
	void siftDown(int nStart, int m);

	/**
	* \brief 
	* \param[in] nStart
	* \return void
	*/
	void siftUp(int nStart);

public:

	/**
	* \brief ���캯��
	* \param[in] size �������
	*/
	MinHeap(int size = DEFAULTSIZE);

	/**
	* \brief ���캯��
	* \param[in] arr ���飬���ڹ�����С��
	* \param[in] size �������
	*/
	MinHeap(E arr[], int size);

	/**
	* \brief ��������
	*/
	~MinHeap();

	/**
	* \brief ����Ԫ��
	* \param[in] x ����Ԫ��
	* \return bool
	*/
	bool Insert(const E& x);

	/**
	* \brief ɾ����СԪ��
	* \param[out] x ɾ����Ԫ��
	* \return bool
	*/
	bool RemoveMin(E& x);

	/**
	* \brief �Ƿ�Ϊ��
	* \return bool
	*/
	bool IsEmpty() const;

	/**
	* \brief �Ƿ�Ϊ��
	* \return bool
	*/
	bool IsFull() const;

	/**
	* \brief �ÿ�
	* \return void
	*/
	void MakeEmpty();
};

template<class E>
void MinHeap<E>::siftDown(int nStart, int m)
{
	return;
}

template<class E>
void MinHeap<E>::siftUp(int nStart)
{
	return;
}

template<class E>
MinHeap<E>::MinHeap(int size)
	: m_pHeap(nullptr)
	, m_nCount(0)
	, m_nMaxSize(0)
{
	m_nMaxSize = (DEFAULTSIZE < size) ? size : DEFAULTSIZE;
	m_pHeap = new E[m_nMaxSize];
	if (m_pHeap == nullptr)
	{
		cerr << "faild";
		exit(1);
	}
	m_nCount = 0;
}

template<class E>
MinHeap<E>::MinHeap(E arr[], int size)
{
	m_nMaxSize = (DEFAULTSIZE < size) ? size : DEFAULTSIZE;
	m_pHeap = new E[m_nMaxSize];
	if (m_pHeap == nullptr)
	{
		cerr << "faild";
		exit(1);
	}
	for (int i = 0; i < size; ++i)
		m_pHeap[i] = arr[i];
	m_nCount = size;

	int nTmpPos = (m_nCount - 2) / 2;
	while (nTmpPos > 0)
	{
		siftDown(nTmpPos, m_nCount - 1);
		--nTmpPos;
	}
}


template<class E>
MinHeap<E>::~MinHeap()
{
	if (m_pHeap != nullptr)
	{
		delete m_pHeap;
		m_pHeap = nullptr;
	}
}


template<class E>
bool MinHeap<E>::Insert(const E& x)
{
	return false;
}

template<class E>
bool MinHeap<E>::RemoveMin(E& x)
{

	return false;
}

template<class E>
bool MinHeap<E>::IsEmpty() const
{
	return (m_nCount == 0) ? true : false;
}

template<class E>
bool MinHeap<E>::IsFull()const
{
	return (m_nCount == m_nMaxSize) ? true : false;
}

template<class E>
void MinHeap<E>::MakeEmpty()
{
	m_nCount = 0;
}


#endif // !_MINHEAP_H_

