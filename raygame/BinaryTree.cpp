#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{

}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* insertNode = new TreeNode(a_nValue);

	if (isEmpty() == false)
	{
		m_pRoot->setData(a_nValue);
	}
	else
	{
		TreeNode* currentNode = m_pRoot;
		TreeNode* parentNode = currentNode;

		while (currentNode != nullptr)
		{
			if (a_nValue < currentNode->getData())
			{
				parentNode = currentNode;
				currentNode = currentNode->getLeft();
			}
			else if (a_nValue > currentNode->getData())
			{
				parentNode = currentNode;
				currentNode = currentNode->getRight();
			}
			else if (a_nValue == currentNode->getData())
			{
				currentNode = nullptr;
			}			
		}

		if (a_nValue < parentNode->getData())
		{
			parentNode->setLeft(insertNode);
		}
		else if (a_nValue > parentNode->getData())
		{
			parentNode->setRight(insertNode);
		}
	}
}

void BinaryTree::remove(int a_nValue)
{

}

TreeNode* BinaryTree::find(int a_nValue)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nValue == currentNode->getData())
		{
			return currentNode, parentNode;
		}
		else if (a_nValue < currentNode->getData())
		{
			parentNode = currentNode;
			currentNode = currentNode->getLeft();
		}
		else if (a_nValue > currentNode->getData())
		{
			parentNode = currentNode;
			currentNode = currentNode->getRight();
		}
		else
		{
			currentNode = nullptr;
		}
	}

	if (currentNode = nullptr)
	{
		return nullptr;
	}
}

void BinaryTree::draw(TreeNode* selected)
{
	//Draw the root node
	draw(m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	*ppOutNode = m_pRoot;
	ppOutParent = nullptr;

	while (ppOutNode != nullptr)
	{
		if (a_nSearchValue == (*ppOutNode)->getData())
		{
			return ppOutNode, ppOutParent;
		}
		else if (a_nSearchValue < (*ppOutNode)->getData())
		{
			ppOutParent = ppOutNode;
			*ppOutNode = (*ppOutNode)->getLeft();
		}
		else if (a_nSearchValue > (*ppOutNode)->getData())
		{
			ppOutParent = ppOutNode;
			*ppOutNode = (*ppOutNode)->getRight();
		}
		else
		{
			ppOutNode = nullptr;
		}
	}

	if (ppOutNode = nullptr)
	{
		return false;
	}
}

void BinaryTree::draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	//Cut the horizantal spacing in half
	horizontalSpacing /= 2;

	//Check that the node exists
	if (pNode)
	{
		//Check for a left node
		if (pNode->hasLeft())
		{
			//Draw a line to the left node
			DrawLine(x, y, x - horizontalSpacing, y - 80, RED);
			//Draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		//Check for a right node
		if (pNode->hasRight())
		{
			//Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y - 80, RED);
			//Draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		//Draw the current node
		pNode->draw(x, y, (selected == pNode));
	}
}
