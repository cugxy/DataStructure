// Author��		xiongw
// Date��		2018-3-17
// filename:	BinaryTree.h

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <istream>
#include <stack>
#include <queue>

/**
* \brief �������ڵ�
* \author	xy
*/
template<class T>
struct BinTreeNode
{
	T					data;			/**< ���� */
	BinTreeNode<T>	   *pLeftChild;		/**< ������ */
	BinTreeNode<T>	   *pRightChild;	/**< ������ */

	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	BinTreeNode()
		: pLeftChild(NULL)
		, pRightChild(NULL)
	{
	}

	/**
	* \brief ���캯��
	* \param[in] d ����
	* \param[in] pL ������
	* \param[in] pR ������
	*/
	BinTreeNode(T d, BinTreeNode<T> *pL = NULL, BinTreeNode<T> *pR = NULL)
		: data(d)
		, pLeftChild(pL)
		, pRightChild(pR)
	{
	}
};

/**
* \brief ������
* \author	xy
*/
template<class T>
class BinaryTree
{
protected:
	BinTreeNode<T>*		m_pRoot;	/**< ���ڵ� */
	T					m_RefValue;	/**< ������ʶ */

protected:
	/**
	* \brief ����������
	* \param[in|out] in ������
	* \param[in|out] pSubTree ����
	* \return void
	*/
	void CreateBinTree(std::istream& in, BinTreeNode<T>*& pSubTree);

	/**
	* \brief ����ڵ� �������Ϊ �� > �� > ��
	* \param[in] d ����Ԫ��
	* \param[in|out] pSubTree ����
	* \return bool
	*/
	bool Insert(BinTreeNode<T>*& pSubTree, const T& d);

	/**
	* \brief �ݹ� delete
	* \param[in|out] pSubTree ����
	* \return void
	*/
	void Destory(BinTreeNode<T>*& pSubTree);

	/**
	* \brief �ݹ� copy
	* \param[in] pOriTree ����
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Copy(BinTreeNode<T>* pOriTree);
	
	/**
	* \brief ��ȡ�����߶�
	* \param[in] pSubTree ����
	* \return int
	*/
	int	Height(BinTreeNode<T>* pSubTree);
	
	/**
	* \brief ��ȡ�����ڵ�����
	* \param[in] pSubTree ����
	* \return int
	*/
	int	Size(BinTreeNode<T>* pSubTree);

	/**
	* \brief �ݹ���Ҹ��ڵ�
	* \param[in] pSubTree ����
	* \param[in] pCurrent ��ǰ�ڵ�
	* \return BinTreeNode<T>* ��ǰ�ڵ㸸�ڵ�
	*/
	BinTreeNode<T>*	Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent);

	/**
	* \brief �ж�Ԫ�� x �Ƿ����
	* \param[in] pSubTree ����
	* \return bool
	*/
	bool IsExist(BinTreeNode<T>* pSubTree, const T& x);

	/**
	* \brief ����Ԫ�� x ��Ӧ�ڵ㣨�ڵ��а���������������Ϣ��
	* \param[in] pSubTree ����
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Find(BinTreeNode<T>* pSubTree, const T& x);

	/**
	* \brief ���Ԫ������
	* \param[in] pSubTree ����
	* \param[out] �����
	* \return void
	*/
	void Traverse(BinTreeNode<T>* pSubTree, std::ostream& out);

	/**
	* \brief �ݹ� ǰ�����
	* \param[in] pSubTree ����
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void PreOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief �ݹ� �������
	* \param[in] pSubTree ����
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void InOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief �ݹ� �������
	* \param[in] pSubTree ����
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void PostOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p));

	// ���� ����
	friend std::istream& operator >> (std::istream& in, BinaryTree<T> tree);

	// ���� ���
	friend std::ostream& operator << (std::ostream& out, BinaryTree<T> tree);

public:
	/**
	* \brief Ĭ�Ϲ��캯��
	*/
	BinaryTree();

	/**
	* \brief ���캯��
	* \param v ������ʶ
	*/
	explicit BinaryTree(T v);

	/**
	* \brief �������캯��
	* \param tree 
	*/
	BinaryTree(BinaryTree<T>& tree);

	/**
	* \brief ��������
	*/
	virtual ~BinaryTree();

	/**
	* \brief �Ƿ�Ϊ��
	* \return bool
	*/
	bool IsEmpty();

	/**
	* \brief ��ȡ���ڵ�
	* \param pCurrent ��ǰ�ڵ�
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	Parent(BinTreeNode<T>*& pCurrent);
	
	/**
	* \brief ��ȡ������
	* \param pCurrent ��ǰ�ڵ�
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>* LeftChild(BinTreeNode<T>* pCurrent);

	/**
	* \brief ��ȡ������
	* \param pCurrent ��ǰ�ڵ�
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>*	RightChild(BinTreeNode<T>* pCurrent);

	/**
	* \brief ��ȡ����
	* \return int
	*/
	int Height();

	/**
	* \brief ��ȡԪ�ظ���
	* \return int
	*/
	int	Size();

	/**
	* \brief ��ȡ���ڵ�
	* \return BinTreeNode<T>*
	*/
	BinTreeNode<T>* GetRoot() const;

	/**
	* \brief �ж�Ԫ���Ƿ����
	* \param v Ԫ��
	* \return bool
	*/
	bool IsExist(T& v);

	/**
	* \brief ����Ԫ�ؽڵ�
	* \param v Ԫ��
	* \return bool
	*/
	BinTreeNode<T>* Find(T& v);

	/**
	* \brief ����Ԫ��
	* \param v Ԫ��
	* \return bool
	*/
	int Insert(const T& v);

	/**
	* \brief ǰ�����
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void PreOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief ǰ�����
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void InOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief �������
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void PostOrder(void( * fun)(BinTreeNode<T>* p));

	/**
	* \brief �������
	* \param[out] ����ָ�루����ֵΪvoid������ΪBinTreeNode<T>*��
	* \return void
	*/
	void LevelOrder(void( * fun)(BinTreeNode<T>* p));
};

// ���������ж�ȡ���ݲ����β������ڵ��� �� >> �� >> ��
template<class T>
void BinaryTree<T>::CreateBinTree(std::istream & in, BinTreeNode<T>*& pSubTree)
{
	T data;
	if (!in.eof())
	{
		in >> data;
		if (data != m_RefValue)
		{
			pSubTree = new BinTreeNode<T>(data);
			if (pSubTree == NULL)
			{
				std::cerr << "new error " << endl;
				throw std::exception("new error ");
			}
			CreateBinTree(in, pSubTree->pLeftChild);
			CreateBinTree(in, pSubTree->pRightChild);
		}
		else
			pSubTree = NULL;
	}

}

// �������� d ����������ڵ�Ϊ�գ��������������� d > pSubTree �������
template<class T>
bool BinaryTree<T>::Insert(BinTreeNode<T>*& pSubTree, const T & d)
{
	if (pSubTree == NULL)
	{
		BinTreeNode<T>* pNode = new BinTreeNode<T>(d);
		pSubTree = pNode;
		return true;
	}
	else if (pSubTree->data == d)
		return false;
	else if (d > pSubTree->data)
	{
		return Insert(pSubTree->pLeftChild, d);
	}
	else
	{
		return Insert(pSubTree->pRightChild, d);
	}
	return false;
}

template<class T>
void BinaryTree<T>::Destory(BinTreeNode<T>*& pSubTree)
{
	if (pSubTree != NULL)
	{
		Destory(pSubTree->pLeftChild);
		Destory(pSubTree->pRightChild);
		delete pSubTree;
		pSubTree = NULL;
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* pOriTree)
{
	if (pOriTree == NULL)
		return NULL;
	BinTreeNode<T>* pTmp = new BinTreeNode<T>();
	pTmp->data = pOriTree->data;
	pTmp->pLeftChild = Copy(pOriTree->pLeftChild);
	pTmp->pRightChild = Copy(pOriTree->pRightChild);
	return pTmp;
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* pSubTree)
{
	if (pSubTree == NULL)
		return 0;
	else
	{
		int i = Height(pSubTree->pLeftChild);
		int j = Height(pSubTree->pRightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* pSubTree)
{
	if (pSubTree == NULL)
		return 0;
	else
		return 1 + Size(pSubTree->pLeftChild) + Size(pSubTree->pRightChild);
}

template<class T>
BinTreeNode<T>*	BinaryTree<T>::Parent(BinTreeNode<T>* pSubTree, BinTreeNode<T>* pCurrent)
{
	if(pSubTree == NULL)
		return NULL;
	if (pSubTree->pLeftChild == pCurrent || pSubTree->pRightChild == pCurrent)
		return pSubTree;
	BinTreeNode<T>* pNode = NULL;
	if ((pNode = Parent(pSubTree->pLeftChild, pCurrent)) != NULL)
		return pNode;
	else
		return Parent(pSubTree->pRightChild, pCurrent);
}

template<class T>
bool BinaryTree<T>::IsExist(BinTreeNode<T>* pSubTree, const T& x)
{
	if(pSubTree == NULL)
		return false;
	if (pSubTree->data == x)
		return true;
	else
	{
		bool bl = IsExist(pSubTree->pLeftChild, x);
		bool br = IsExist(pSubTree->pRightChild, x);
		return bl || br;
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* pSubTree, const T& x)
{
	if (pSubTree == NULL)
		return NULL;
	if (pSubTree->data == x)
		return pSubTree;
	else
	{
		BinTreeNode<T>* pL = Find(pSubTree->pLeftChild, x);
		BinTreeNode<T>* pR = Find(pSubTree->pRightChild, x);
		if (pL != NULL)
			return pL;
		else
			return pR;
	}
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* pSubTree, std::ostream& out)
{
	if (pSubTree != NUll)
	{
		out << pSubTree->data << ' ';
		Traverse(pSubTree->pLeftChild, out);
		Traverse(pSubTree->pRightChild, out);
	}
}


template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		fun(pSubTree);
		PreOrder(pSubTree->pLeftChild, fun);
		PreOrder(pSubTree->pRightChild�� fun);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T>* pSubTree, void( * fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		InOrder(pSubTree->pLeftChild, fun);
		fun(pSubTree);
		InOrder(pSubTree->pRightChild�� fun);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>* pSubTree, void(*fun)(BinTreeNode<T>* p))
{
	if (pSubTree != NULL)
	{
		PostOrder(pSubTree->pLeftChild, fun);
		PostOrder(pSubTree->pRightChild�� fun);
		fun(pSubTree);
	}
}


template<class T>
BinaryTree<T>::BinaryTree()
	: m_pRoot(NULL)
{
}

template<class T>
BinaryTree<T>::BinaryTree(T v)
	: m_pRoot(NULL)
	, m_RefValue(v)
{
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& tree)
{
	m_pRoot = Copy(tree.m_pRoot);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	Destory(m_pRoot);
}

template<class T>
bool BinaryTree<T>::IsEmpty()
{
	return (m_pRoot == NULL) ? true : false;
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>*& pCurrent)
{
	return (m_pRoot == NULL || pCurrent == NULL) ? NULL : Parent(m_pRoot, pCurrent);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* pCurrent)
{
	return (pCurrent == NULL) ? NULL : pCurrent->pLeftChild;
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* pCurrent)
{
	return (pCurrent == NULL) ? NULL : pCurrent->pRightChild;
}

template<class T>
int BinaryTree<T>::Height()
{
	return Height(m_pRoot);
}

template<class T>
int BinaryTree<T>::Size()
{
	return Size(m_pRoot);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::GetRoot() const
{
	return m_pRoot;
}

template<class T>
bool BinaryTree<T>::IsExist(T & v)
{
	return IsExist(m_pRoot, v); 
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(T & v)
{
	return Find(m_pRoot, v);
}

template<class T>
int BinaryTree<T>::Insert(const T & v)
{
	return Insert(m_pRoot, v);
}

template<class T>
void BinaryTree<T>::PreOrder(void(*fun)(BinTreeNode<T>*p))
{
	std::stack<BinTreeNode<T>* > st;
	BinTreeNode<T>* pNode = m_pRoot;
	st.push(NULL);
	while (pNode != NULL)
	{
		fun(pNode);
		if (pNode->pRightChild != NULL)
			st.push(pNode->pRightChild);
		if (pNode->pLeftChild != NULL)
			pNode = pNode->pLeftChild;
		else
			st.pop(pNode);
	}
}

template<class T>
void BinaryTree<T>::InOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
void BinaryTree<T>::PostOrder(void(*fun)(BinTreeNode<T>*p))
{
}

template<class T>
void BinaryTree<T>::LevelOrder(void(*fun)(BinTreeNode<T>*p))
{
	std::queue<BinTreeNode<T>* > q;
	BinTreeNode<T>* pNode = m_pRoot;
	q.push(pNode);
	while (!q.empty())
	{
		pNode = q.front();
		fun(pNode);
		q.pop();
		if (pNode->pLeftChild != NULL)
			q.push(pNode->pLeftChild);
		if (pNode->pRightChild != NULL)
			q.push(pNode->pRightChild);
	}
}

template<class T>
std::istream&	operator >> (std::istream& in, BinaryTree<T> tree)
{
	CreateBinTree(in, tree.m_pRoot);
	return in;
}

template<class T>
std::ostream&	operator << (std::ostream& out, BinaryTree<T> tree)
{
	out << "binary tree order:\n";
	tree.Traverse(tree.m_pRoot, out);
	out << std::endl;
	return out;
}

#endif // !_BINARYTREE_H_
