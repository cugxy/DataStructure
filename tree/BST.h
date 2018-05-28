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
template<class E>
struct BSTNode
{
	E data;					/**< ���� */
	BSTNode<E> *pLeft;	/**< ������ */
	BSTNode<E> *pRight;	/**< ������ */

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
	BSTNode(const E d, BSTNode<E> *pL = NULL, BSTNode<E> *pR = NULL)
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
template<class E>
class BST
{
private:
	BSTNode<E> *m_pRoot;	/**< ���ڵ� */

private:
	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \param[in] ptr ��������
	* \return BSTNode<E>* 
	*/
	BSTNode<E>* Search(const E x, BSTNode<E>* ptr);

	/**
	* \brief ��������
	* \param[in] ptr ����
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Copy(BSTNode<E>* ptr);

	/**
	* \brief ��ȡ��Сֵ�ڵ�
	* \param[in] ptr ����
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Min(BSTNode<E>* ptr) const;

	/**
	* \brief ��ȡ���ֵ�ڵ�
	* \param[in] ptr ����
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Max(BSTNode<E>* ptr) const;

	/**
	* \brief ����
	* \param[in] v ����Ԫ��
	* \param[in] ptr ����
	* \return bool
	*/
	bool Insert(const E& v, BSTNode<E>*& ptr);

	/**
	* \brief ɾ��
	* \param[in] x ɾ��Ԫ��
	* \param[in] ptr ����
	* \return bool
	*/
	bool Remove(const E x, BSTNode<E>*& ptr);

	/**
	* \brief ����
	* \param[in] ptr ����
	* \return void
	*/
	void Destory(BSTNode<E>*& ptr);

	/**
	* \brief �ÿ�
	* \param[in] ptr ����
	* \return void
	*/
	void makeEmpty(BSTNode<E>*& ptr);

	/**
	* \brief ��ӡ
	* \param[in] ptr ����
	* \return void
	*/
	void PrintTree(BSTNode<E>*& ptr) const;

public:
	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	BST();

	/**
	* \brief ���� = ������
	* \param[in] tree 
	* \return BST<E>&
	*/
	BST<E>&	operator=(const BST<E> &tree);

	/**
	* \brief ��������
	*/
	~BST();

	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \return BSTNode<E>*
	*/
	BSTNode<E>* Search(const E x)const;

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
	bool Remove(const E x);
};

template<class E>
BSTNode<E>* BST<E>::Search(const E x, BSTNode<E>* ptr)
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

template<class E>
BSTNode<E>* BST<E>::Copy(BSTNode<E>* ptr)
{
	if (ptr == NULL) return NULL;
	BSTNode<E>* pTmp = new BSTNode<E>(ptr->data);
	pTmp->pLeft = Copy(ptr->pLeft);
	pTmp->pRight = Copy(ptr->pRight);
	return pTmp;
}

template<class E>
BSTNode<E>* BST<E>::Min(BSTNode<E>* ptr) const
{
	if (ptr == NULL) return NULL;
	while (ptr->pLeft != NULL)
	{
		ptr = ptr->pLeft
	}
	return ptr;
}

template<class E>
BSTNode<E>* BST<E>::Max(BSTNode<E>* ptr) const
{
	 if (ptr == NULL) return NULL;
	 while (ptr->pRight != NULL)
	 {
		 ptr = ptr->pRight
	 }
	 return ptr;
}

template<class E>
bool BST<E>::Insert(const E & v, BSTNode<E>*& ptr)
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<E>(v);
		return true;
	}
	else if (v < ptr->data)
		Insert(v, ptr->pLeft);
	else if (v > ptr->data)
		Insert(v, ptr->pRight);
	else
		return false;
}

template<class E>
bool BST<E>::Remove(const E x, BSTNode<E>*& ptr)
{
	BSTNode<E> *pTmp = NULL;
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

template<class E>
void BST<E>::Destory(BSTNode<E>*& ptr)
{
	if (ptr == NULL)return;

	Destory(ptr->pLeft);
	Destory(ptr->pRight);
	delete ptr;
	ptr = nullptr;
}

template<class E>
void BST<E>::makeEmpty(BSTNode<E>*& ptr)
{
	Destory(ptr);
}

template<class E>
void BST<E>::PrintTree(BSTNode<E>*& ptr) const
{
	if (ptr == NULL)return;
	PrintTree(ptr->pLeft);
	std::cout << ptr->data;
	PrintTree(ptr->pRight);
}

template<class E>
BST<E>::BST()
	: m_pRoot(NULL)
{
}

template<class E>
BST<E>& BST<E>::operator=(const BST<E>& tree)
{
	return Copy(tree);
}

template<class E>
BST<E>::~BST()
{
	Destory(m_pRoot);
}

template<class E>
BSTNode<E>* BST<E>::Search(const E x) const
{
	return Search(x, m_pRoot);
}

template<class E>
void BST<E>::MakeEmpty()
{
	makeEmpty(m_pRoot);
}

template<class E>
void BST<E>::PrintTree() const
{
	PrintTree(m_pRoot);
}

template<class E>
 E BST<E>::Min()
{
	return Min(m_pRoot);
}

template<class E>
 E BST<E>::Max()
{
	return Max(m_pRoot);
}

template<class E>
 bool BST<E>::Insert(const E & v)
{
	return Insert(v, m_pRoot);
}

template<class E>
bool BST<E>::Remove(const E x)
{
	return Remove(x, m_pRoot);
}

#endif // !_BST_H_
