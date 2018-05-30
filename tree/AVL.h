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
template<class E>
struct AVLNode : public BSTNode<E>
{
	int nbf;		/**< ƽ�����ӣ�balance factor���������߶ȼ�ȥ�������߶� */

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
	AVLNode(E d, AVLNode<E>* pL = NULL, AVLNode<E>* pR = NULL)
		: data(d), pLeft(pL), pRight(pR), nff(0) { }
};

/**
* \brief ������ ������������ڵ����һ����С��ϵ����������ƽ��
* \author	xy
*/
template<class E>
class AVLTree :public BST<E>
{
private:
	AVLNode<E> *m_pRoot;	/**< ���ڵ� */

protected:

	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \param[in] par ��������
	* \return AVLNode<E>*
	*/
	AVLNode<E>* Search(E x, AVLNode<E>*& par) const;

	/**
	* \brief ����
	* \param[in] ptr ����
	* \param[in] el ����Ԫ��
	* \return bool
	*/
	bool Insert(AVLNode<E>*& ptr, E& el);

	/**
	* \brief �Ƴ�
	* \param[in] ptr ����
	* \param[in] x �Ƴ�Ԫ��
	* \param[in] el �Ƴ�Ԫ��
	* \return bool
	*/
	bool Remove(AVLNode<E>*& ptr, E& el);

	/**
	* \brief ����ת
	* \param[in] ptr ����
	* \return void
	*/
	void RotateL(AVLNode<E>*& ptr);

	/**
	* \brief �ҵ���ת
	* \param[in] ptr ����
	* \return void
	*/
	void RotateR(AVLNode<E>*& ptr);

	/**
	* \brief ������ת
	* \param[in] ptr ����
	* \return void
	*/
	void RotateLR(AVLNode<E>*& ptr);

	/**
	* \brief ������ת
	* \param[in] ptr ����
	* \return void
	*/
	void RotateRL(AVLNode<E>*& ptr);
		
	/**
	* \brief ������
	* \param[in] ptr ����
	* \return int
	*/
	int	Height(AVLNode<E>* ptr) const;

public:

	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	AVLTree() : m_pRoot(NULL) {}

	/**
	* \brief ����
	* \param[in] el ����Ԫ��
	* \return bool
	*/
	bool Insert(E& el);

	/**
	* \brief ����
	* \param[in] x ����Ԫ��
	* \return AVLNode<E>*
	*/
	AVLNode<E>* Search(E & el) const;

	/**
	* \brief �Ƴ�
	* \param[in] el �Ƴ�Ԫ��
	* \return bool
	*/
	bool Remove(E& el);

	/**
	* \brief ����
	* \return int
	*/
	int Height() const;

	friend std::istream& operator >> (std::istream& in, AVLTree<E>& tree);

	friend std::ostream& operator << (std::ostream& in, AVLTree<E>& tree);
};


template<class E>
bool AVLTree<E>::Insert(E & el)
{
	return false;
}

template<class E>
AVLNode<E>* AVLTree<E>::Search(E & el) const
{
	return false;
}

template<class E>
bool AVLTree<E>::Remove(E & el)
{
	return false;
}

template<class E>
int AVLTree<E>::Height() const
{
	return 0;
}

template<class E>
AVLNode<E>* AVLTree<E>::Search(E x, AVLNode<E>*& par) const
{
	return NULL;
}

template<class E>
bool AVLTree<E>::Insert(AVLNode<E>*& ptr, E & el)
{
	return false;
}

template<class E>
bool AVLTree<E>::Remove(AVLNode<E>*& ptr, E & el)
{
	return false;
}

template<class E>
void AVLTree<E>::RotateL(AVLNode<E>*& ptr)
{
	AVLNode<E> *pSubL= ptr;			// ָ�� pSubL ָ�� ֮ǰ���ڵ㣬
	ptr = pSubL->pRight;			// ptr ָ�� ֮ǰ���ڵ������������Ϊ�µĸ��ڵ�
	pSubL->pRight = ptr->pLeft;		// ��֮ǰ���ڵ㣨���µ����������ڵ�)���ҽڵ㸳ֵΪ�µĸ��ڵ����ڵ㣩
	ptr->pLeft = pSubL;				// �µĸ��ڵ���ڵ㸳ֵΪpSubL(֮ǰ���ڵ�) �ҽڵ㲻��
	ptr->nbf = 0;					// ����ƽ������
	pSubL->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateR(AVLNode<E>*& ptr)
{
	AVLNode<E> *pSubR = ptr;
	ptr = pSubR->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	ptr->nbf = 0;
	pSubR->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateLR(AVLNode<E>*& ptr)
{
	// ������
	AVLNode<K>* pSubR = ptr;
	AVLNode<K>* pSubL = ptr->pLeft;
	ptr = pSubL->pRight;
	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;

	if (ptr->nbf <= 0)
		pSubL->nbf = 0;
	else
		pSubL->nbf = -1;
	// �ҵ���
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;

	if (ptr->nbf == -1)
		pSubR->nbf = 1;
	else
		pSubR->nbf = 0;
	ptr->nbf = 0;
}

template<class E>
void AVLTree<E>::RotateRL(AVLNode<E>*& ptr)
{
	AVLNode<K>* pSubL = ptr;
	AVLNode<K>* pSubR = ptr->pRight;
	ptr = pSubL->pLeft;
	pSubR->pLeft = ptr->pRight;
	ptr->pRight = pSubR;
	
	if (ptr->nbf >= 0)
		pSubR->nbf = 0;
	else
		pSubR->nbf = 1;

	pSubL->pRight = ptr->pLeft;
	ptr->pLeft = pSubL;
	
	if (ptr->nbf == 1)
		pSubL->nbf = -1;
	else
		pSubL->nbf = 0;
	ptr->nbf = 0;
}

template<class E>
int AVLTree<E>::Height(AVLNode<E>* ptr) const
{
	return 0;
}

template<class E>
std::istream & operator >> (std::istream & in, AVLTree<E>& tree)
{
	// TODO: �ڴ˴����� return ���
}

template<class E>
std::ostream & operator<<(std::ostream & in, AVLTree<E>& tree)
{
	// TODO: �ڴ˴����� return ���
}

#endif // !_AVL_H


