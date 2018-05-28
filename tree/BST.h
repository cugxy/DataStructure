// Author��		xiongw
// Date��		2018-3-17
// filename:	BST.h
// ����������

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stdlib.h>

/**
* \brief	�������������ڵ�
* \author	xy
*/
template<class E, class K>
struct BSTNode
{
	E data;					/**< ���� */
	BSTNode<E, K> *pLeft;	/**< ������ */
	BSTNode<E, K> *pRight;	/**< ������ */

	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	BSTNode() :pLeft(NULL), pRight(NULL) {}

	/**
	* \brief ���캯��
	* \param[in] d ����
	* \param[in] pL ������
	* \param[in] pR ������
	*/
	BSTNode(const E d, BSTNode<E, K> *pL = NULL, BSTNode<E, K> *pR = NULL)
		:data(d), pLeft(pL), pRight(pR) {}

	/**
	* \brief ��������
	*/
	~BSTNode() { }
};

/**
* \brief ������ ������������ڵ����һ����С��ϵ
* \author	xy
*/
template<class E, class K>
class BST
{
private:
	BSTNode<E, K> *m_pRoot;	/**< ���ڵ� */
	K m_RefValue;			/**< ������� */

private:
	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \param[in] ptr ��������
	* \return BSTNode<E, K>* 
	*/
	BSTNode<E, K>* Search(const K x, BSTNode<E, K>* ptr);

	/**
	* \brief ��������
	* \param[in] ptr ����
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Copy(BSTNode<E, K>* ptr);

	/**
	* \brief ��ȡ��Сֵ�ڵ�
	* \param[in] ptr ����
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Min(BSTNode<E, K>* ptr) const;

	/**
	* \brief ��ȡ���ֵ�ڵ�
	* \param[in] ptr ����
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Max(BSTNode<E, K>* ptr) const;

	/**
	* \brief ����
	* \param[in] v ����Ԫ��
	* \param[in] ptr ����
	* \return bool
	*/
	bool Insert(const E& v, BSTNode<E, K>*& ptr);

	/**
	* \brief ɾ��
	* \param[in] x ɾ��Ԫ��
	* \param[in] ptr ����
	* \return bool
	*/
	bool Remove(const K x, BSTNode<E, K>*& ptr);

	/**
	* \brief ����
	* \param[in] ptr ����
	* \return void
	*/
	void Destory(BSTNode<E, K>*& ptr);

	/**
	* \brief �ÿ�
	* \param[in] ptr ����
	* \return void
	*/
	void makeEmpty(BSTNode<E, K>*& ptr);

	/**
	* \brief ��ӡ
	* \param[in] ptr ����
	* \return void
	*/
	void PrintTree(BSTNode<E, K>*& ptr) const;

public:
	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	BST();

	/**
	* \brief ���캯��
	* \param[in] value ������־
	*/
	explicit BST(K value);

	/**
	* \brief ���� = ������
	* \param[in] tree 
	* \return BST<E, K>&
	*/
	BST<E, K>&	operator=(const BST<E, K> &tree);

	/**
	* \brief ��������
	*/
	~BST();

	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \return BSTNode<E, K>*
	*/
	BSTNode<E, K>* Search(const K x)const;

	/**
	* \brief �ÿ�
	* \return void
	*/
	void MakeEmpty();

	/**
	* \brief ��ӡ
	* \return void
	*/
	void PrintTree() const;
		
	/**
	* \brief ��Сֵ
	* \return E
	*/
	E Min();

	/**
	* \brief ���ֵ
	* \return E
	*/
	E Max();

	/**
	* \brief ����
	* \param[in] v ����Ԫ��
	* \return bool
	*/
	bool Insert(const E& v);

	/**
	* \brief ɾ��
	* \param[in] x ɾ��Ԫ��
	* \return bool
	*/
	bool Remove(const K x);
};

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Search(const K x, BSTNode<E, K>* ptr)
{
	if (ptr == NULL)
		return NULL;
	else if (x < ptr->data)
		return Search(x, ptr->pLeft);
	else if (x > ptr->data)
		return Search(x, ptr->pRight);
	else
		return ptr;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Copy(BSTNode<E, K>* ptr)
{
	if (ptr == NULL) return NULL;
	BSTNode<E, K>* pTmp = new BSTNode<E, K>(ptr->data);
	pTmp->pLeft = Copy(ptr->pLeft);
	pTmp->pRight = Copy(ptr->pRight);
	return pTmp;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Min(BSTNode<E, K>* ptr) const
{
	if (ptr == NULL) return NULL;
	while (ptr->pLeft != NULL)
	{
		ptr = ptr->pLeft
	}
	return ptr;
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Max(BSTNode<E, K>* ptr) const
{
	 if (ptr == NULL) return NULL;
	 while (ptr->pRight != NULL)
	 {
		 ptr = ptr->pRight
	 }
	 return ptr;
}

template<class E, class K>
bool BST<E, K>::Insert(const E & v, BSTNode<E, K>*& ptr)
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<E, K>(v);
		return true;
	}
	else if (v < ptr->data)
		Insert(v, ptr->pLeft);
	else if (v > ptr->data)
		Insert(v, ptr->pRight);
	else
		return false;
}

template<class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K>*& ptr)
{
	BSTNode<E, K> *pTmp = NULL;
	if (ptr == NULL) return false;
	if (x < ptr->data)
		Remove(x, ptr->pLeft);
	else if (x > ptr->data)
		Remove(x, ptr->pRight);
	else if (ptr->pLeft != NULL && ptr->pRight != NULL) // ������Ҿ���Ϊ�� �򽫱����ĵ�һ��ֵ�ŵ���λ�� ��ת��������������ɾ����ֵ
	{
		pTmp = ptr->pRight;
		while (pTmp->pLeft != NULL)
		{
			pTmp = pTmp->pLeft;
		}
		ptr->data = pTmp->data;
		Remove(ptr->data, ptr->pRight);
	}
	else
	{
		pTmp = ptr;
		if (ptr->pLeft == NULL)// ������Ϊ�� 
			ptr = ptr->pRight;
		else                   // ��������Ϊ��
			ptr = ptr->pLeft;
		delete pTmp;
		return true;
	}
}

template<class E, class K>
void BST<E, K>::Destory(BSTNode<E, K>*& ptr)
{
	if (ptr == NULL)return;

	Destory(ptr->pLeft);
	Destory(ptr->pRight);
	delete ptr;
	ptr = nullptr;
}

template<class E, class K>
void BST<E, K>::makeEmpty(BSTNode<E, K>*& ptr)
{
	Destory(ptr);
}

template<class E, class K>
void BST<E, K>::PrintTree(BSTNode<E, K>*& ptr) const
{
	if (ptr != NULL)
	{
		PrintTree(ptr->pLeft);
		std::cout << ptr->data;
		PrintTree(ptr->pRight);
	}
}

template<class E, class K>
BST<E, K>::BST()
	: m_pRoot(NULL)
{
}

template<class E, class K>
BST<E, K>::BST(K value)
	: m_pRoot = NULL
	, m_RefValue(value)
{
}

template<class E, class K>
BST<E, K>& BST<E, K>::operator=(const BST<E, K>& tree)
{
	return Copy(tree);
}

template<class E, class K>
BST<E, K>::~BST()
{
	Destory(m_pRoot);
}

template<class E, class K>
BSTNode<E, K>* BST<E, K>::Search(const K x) const
{
	return Search(x, m_pRoot);
}

template<class E, class K>
void BST<E, K>::MakeEmpty()
{
	makeEmpty(m_pRoot);
}

template<class E, class K>
void BST<E, K>::PrintTree() const
{
	PrintTree(m_pRoot);
}

template<class E, class K>
 E BST<E, K>::Min()
{
	return Min(m_pRoot);
}

template<class E, class K>
 E BST<E, K>::Max()
{
	return Max(m_pRoot);
}

template<class E, class K>
 bool BST<E, K>::Insert(const E & v)
{
	return Insert(v, m_pRoot);
}

template<class E, class K>
bool BST<E, K>::Remove(const K x)
{
	return Remove(x, m_pRoot);
}

#endif // !_BST_H_
