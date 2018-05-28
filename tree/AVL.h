// Author��		xiongw
// Date��		2018-3-22
// filename:	AVL.h

#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>
#include <stack>
#include "BST.h"

/**
* \brief	ƽ��������������ڵ�
* \author	xy
*/
template<class E, class K>
struct AVLNode : public BSTNode<E>
{
	int nbf;		/**< ƽ�����ӣ�balance factor�� */

	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	AVLNode() :pLeft(NULL), pRight(NULL), nbf(0) { }

	/**
	* \brief ���캯��
	* \param[in] d ����
	* \param[in] pL ������
	* \param[in] pR ������
	*/
	AVLNode(E d, AVLNode<E, K>* pL = NULL, AVLNode<E, K>* pR = NULL)
		: data(d), pLeft(pL), pRight(pR), nff(0) { }
};

/**
* \brief ������ ������������ڵ����һ����С��ϵ����������ƽ��
* \author	xy
*/
template<class E, class K>
class AVLTree :public BST<E>
{
private:
	AVLNode<E, K> *m_pRoot;	/**< ���ڵ� */
	K m_RefValue;			/**< ������� */

public:
	AVLTree() : m_pRoot(NULL) {}

	AVLTree(K ref) : m_pRoot(NULL), m_RefValue(ref) {}

	bool					Insert(E& el);

	bool					Remove(K x, E& el);

	int						Height() const;

	friend std::istream&	operator >> (std::istream& in, AVLTree<E, K>& tree);

	friend std::ostream&	operator << (std::ostream& in, AVLTree<E, K>& tree);

protected:
	AVLNode<E, K>*			Search(K x, AVLNode<E, K>*& par) const;

	bool					Insert(AVLNode<E, K>*& ptr, E& el);

	bool					Remove(AVLNode<E, K>*& ptr, K x, E& el);

	void					RotateL(AVLNode<E, K>*& ptr);

	void					RotateR(AVLNode<E, K>*& ptr);

	void					RotateLR(AVLNode<E, K>*& ptr);

	void					RotateRL(AVLNode<E, K>*& ptr);
			
	int						Height(AVLNode<E, K>* ptr) const;
};


template<class E, class K>
bool AVLTree<E, K>::Insert(E & el)
{
	return false;
}

template<class E, class K>
bool AVLTree<E, K>::Remove(K x, E & el)
{
	return false;
}

template<class E, class K>
int AVLTree<E, K>::Height() const
{
	return 0;
}

template<class E, class K>
AVLNode<E, K>* AVLTree<E, K>::Search(K x, AVLNode<E, K>*& par) const
{
	return NULL;
}

template<class E, class K>
bool AVLTree<E, K>::Insert(AVLNode<E, K>*& ptr, E & el)
{
	return false;
}

template<class E, class K>
bool AVLTree<E, K>::Remove(AVLNode<E, K>*& ptr, K x, E & el)
{
	return false;
}

template<class E, class K>
void AVLTree<E, K>::RotateL(AVLNode<E, K>*& ptr)
{
	AVLNode<E, K> *pSubL= ptr;		// ָ�� pSubL ָ�� ֮ǰ���ڵ㣬
	ptr = pSubL->pRight;			// ptr ָ�� ֮ǰ���ڵ������������Ϊ�µĸ��ڵ�
	pSubL->pRight = ptr->pLeft;		// ��֮ǰ���ڵ㣨���µ����������ڵ�)���ҽڵ㸳ֵΪ�µĸ��ڵ����ڵ㣩
	ptr->pLeft = pSubL;				// �µĸ��ڵ���ڵ㸳ֵΪpSubL(֮ǰ���ڵ�) �ҽڵ㲻��
	ptr-nbf = 0;
	pSubL->nbf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K>*& ptr)
{
	AVLNode<E, K> *pSubR = ptr;
	ptr = pSubR->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	ptr - nbf = 0;
	pSubR->nbf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K>*& ptr)
{
	AVLNode<K, E>* pSubR = ptr;
	AVLNode<K, E>* pSubL = ptr->pLeft;
	ptr = pSubL->pRight;

	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;

	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;

	if (ptr->nbf <= 0) ///?????????
		pSubL->nbf = 0;
	else
		pSubL->nbf = 0;

	if (ptr->nbf == -1)
		pSubR->nbf = 1;
	else
		pSubR->nbf = 0;
	ptr->nbf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateRL(AVLNode<E, K>*& ptr)
{



}

template<class E, class K>
int AVLTree<E, K>::Height(AVLNode<E, K>* ptr) const
{
	return 0;
}

template<class E, class K>
std::istream & operator >> (std::istream & in, AVLTree<E, K>& tree)
{
	// TODO: �ڴ˴����� return ���
}

template<class E, class K>
std::ostream & operator<<(std::ostream & in, AVLTree<E, K>& tree)
{
	// TODO: �ڴ˴����� return ���
}

#endif // !_AVL_H


