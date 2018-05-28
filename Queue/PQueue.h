// Author��xiongw	
// Date��2018-03-16
// filename:MinHeap.h

#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <iostream>
#include <stdlib.h>

const int knDefaultPQSize = 50;

/**
* \brief ���ȶ��� С������
* \author	xy
*/
template<class E>
class PQueue
{
protected:
	E * m_pElemets; /**< ����洢��ʽ */
	int m_nCount;	/**< Ԫ�ظ��� */
	int m_nMaxSize;	/**< ��� */

protected:
	/**
	* \brief ���� ���¼ӵ�Ԫ�ص��������ʵ�λ�ã�֮ǰ������Ԫ���Ѿ�����ã������ʱ�临�Ӷ�Ϊ O(n)���еĶ�Ҫ����ƶ�һ��
	* return
	*/
	void adjust()
	{
		E tmp = m_pElemets[m_nCount - 1]; // ���һ��Ԫ��
		int j = 0;
		for (j = m_nCount - 2; j >= 0; --j)
		{
			if (m_pElemets[j] < tmp) break;
			else m_pElemets[j + 1] = m_pElemets[j];
		}
		m_pElemets[j + 1] = tmp;
	}

public:
	/**
	* \brief ���캯��
	* \param[in] size ������󳤶�
	*/
	PQueue(int size = knDefaultPQSize)
		: m_pElemets(nullptr)
		, m_nCount(0)
		, m_nMaxSize(-1)
	{
		m_nMaxSize = size;
		m_pElemets = new T[m_nMaxSize];
	}

	/**
	* \brief ��������
	*/
	virtual ~PQueue()
	{
		if (m_pElemets != nullptr)
		{
			delete m_pElemets;
			m_pElemets = nullptr;
		}
	}

	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \return bool
	*/
	bool Insert(const E& x)
	{
		if (m_nCount == m_nMaxSize) return false;
		m_pElemets[m_nCount++] = x;
		adjust();
		return true;
	}

	/**
	* \brief �Ƴ� ��һ��Ԫ��
	* \param[out] x �Ƴ�Ԫ��
	* \return bool
	*/
	bool RemoveMin(E& x)
	{
		if (m_nCount == 0) return false;
		x = m_pElemets[0];
		for (int i = 1; i < m_nCount; ++i)
		{
			m_pElemets[i - 1] = m_pElemets[i];
		}
		--m_nCount;
		return true;
	}
	
	/**
	* \brief ��ȡ��һ��
	* \param[out] x ��ȡԪ��
	* \return bool
	*/
	bool GetFront(E& x)const
	{
		if (m_nCount == 0) return false;
		x = m_pElemets[0];
		return true;
	}

	/**
	* \brief �ÿ�
	* \return 
	*/
	void MakeEmpty() { m_nCount = 0; }

	/**
	* \brief �Ƿ�Ϊ��
	* \return bool
	*/
	bool IsEmpty() const
	{
		return (0 == m_nCount) ? true : false;
	}

	/**
	* \brief �Ƿ�����
	* \return bool
	*/
	bool IsFull() const
	{
		return (m_nCount == m_nMaxSize) ? true : false;
	}

	/**
	* \brief ��ȡ��С
	* \return int
	*/
	int GetSize() const { return m_nCount; }
};

#endif // !_PQUEUE_H_

