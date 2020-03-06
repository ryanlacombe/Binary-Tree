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

	if (isEmpty() == true)
	{
		m_pRoot = insertNode;
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
				return;
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
	TreeNode* currentNode;
	TreeNode* parentNode;

	if (findNode(a_nValue, &currentNode, &parentNode) == true)
	{
		//Checks if current node has a right branch
		if (currentNode->hasRight())
		{
			TreeNode* iteratorNode = currentNode->getRight();
			TreeNode* iteratorParent = currentNode;

			//Checks if the iterator node's left isn't nullptr
			while (iteratorNode->getLeft() != nullptr)
			{
				iteratorParent = iteratorNode;
				iteratorNode = iteratorNode->getLeft();
			}

			//copies the iterator's data to current node
			currentNode->setData(iteratorNode->getData());

			//If we are deleting the parent's left node
			if (iteratorNode == iteratorParent->getLeft())
			{
				//Set the left child of the parent to the right child of the minimum node
				if (iteratorNode->hasRight())
				{
					iteratorParent->setRight(iteratorNode->getRight());
					delete iteratorNode;
				}
				else
				{
					delete iteratorNode;
					iteratorParent->setLeft(nullptr);
				}
			}
			//If we are deleting the parent's right node
			else if (iteratorNode == iteratorParent->getRight())
			{
				//Set the right child of the parent to the right child of the minimum node
				if (iteratorNode->hasRight())
				{
					iteratorParent->setRight(iteratorNode->getRight());
					delete iteratorNode;
				}
				else
				{
					delete iteratorNode;
					iteratorParent->setRight(nullptr);
				}
			}
		}
		//If the current Node has no right branch
		else
		{
			//If we are deleting the parent's left child
			if (currentNode == parentNode->getLeft())
			{
				//Set the left child of the parent to the left child of the current node
				if (currentNode->hasLeft())
				{
					parentNode->setLeft(currentNode->getLeft());
					delete currentNode;
				}
				else 
				{
					delete currentNode;
					parentNode->setLeft(nullptr);
				}
			}
			//If we are deleting the parent's right child
			else if (currentNode == parentNode->getRight())
			{
				//Set the right child of the parent to the left child of the current node
				if (currentNode->hasLeft())
				{
					parentNode->setRight(currentNode->getLeft());
					delete currentNode;
				}
				/*else if (currentNode->hasLeft())
				{
					parentNode->setLeft(currentNode->getLeft());
					delete currentNode;
				}*/
				else
				{
					delete currentNode;
					parentNode->setRight(nullptr);
				}
			}
			//If we are deleting the root
			else if (currentNode == m_pRoot)
			{
				//The root becomes the left child of the current node
				m_pRoot = currentNode->getLeft();
				m_pRoot->setLeft(currentNode->getLeft()->getLeft());
				delete currentNode->getLeft();
			}
		}
	}
}

TreeNode* BinaryTree::find(int a_nValue)
{
	TreeNode* currentNode;
	TreeNode* parentNode;

	if (findNode(a_nValue, &currentNode, &parentNode) == true)
	{
		return currentNode;
	}
	else
	{
		return nullptr;
	}
}

void BinaryTree::draw(TreeNode* selected)
{
	//Draw the root node
	draw(m_pRoot, 640, 200, 340, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nSearchValue == currentNode->getData())
		{
			*ppOutNode = currentNode;
			*ppOutParent = parentNode;
			return true;
		}
		else if (a_nSearchValue < currentNode->getData())
		{
			parentNode = currentNode;
			currentNode = currentNode->getLeft();
		}
		else if (a_nSearchValue > currentNode->getData())
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
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Check for a right node
		if (pNode->hasRight())
		{
			//Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draw the current node
		pNode->draw(x, y, (selected == pNode));
	}
}
