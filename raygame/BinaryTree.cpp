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

	//If the tree is empty, the value is inserted at the root
	if (isEmpty() == true)
	{
		m_pRoot = insertNode;
	}
	else
	{
		//Set the current node to the root and keep track of its parent
		TreeNode* currentNode = m_pRoot;
		TreeNode* parentNode = currentNode;

		//While the current node is not null
		while (currentNode != nullptr)
		{
			//If the value to be inserted is less than the value in the current node
			if (a_nValue < currentNode->getData())
			{
				//Set the current node to the left child and continue
				parentNode = currentNode;
				currentNode = currentNode->getLeft();
			}
			//If the value to be inserted is greater than the current node
			else if (a_nValue > currentNode->getData())
			{
				//Set the current node to the right child and continue
				parentNode = currentNode;
				currentNode = currentNode->getRight();
			}
			//If the value to be inserted is the same as the value in the current node
			else if (a_nValue == currentNode->getData())
			{
				//The value is already in the tree, so return
				return;
			}
			//End while
		}

		//If value to be inserted is less than parent
		if (a_nValue < parentNode->getData())
		{
			//Insert value as left child node
			parentNode->setLeft(insertNode);
		}
		//Otherwise
		else if (a_nValue > parentNode->getData())
		{
			//Insert value as right child node
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
	//Set the current node to the root
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = nullptr;

	//While the current node is not null
	while (currentNode != nullptr)
	{
		//If the search value equals the current node value,
		if (a_nSearchValue == currentNode->getData())
		{
			//Return the current node and its parent
			*ppOutNode = currentNode;
			*ppOutParent = parentNode;
			return true;
		}
		//If the search value is less than the current node
		else if (a_nSearchValue < currentNode->getData())
		{
			//Set the current node to the left child
			parentNode = currentNode;
			currentNode = currentNode->getLeft();
		}
		//Otherwise
		else if (a_nSearchValue > currentNode->getData())
		{
			//Set the current node to the right child
			parentNode = currentNode;
			currentNode = currentNode->getRight();
		}
		//End while
		else
		{
			currentNode = nullptr;
		}
	}

	//If the loop exits, then a match was not found, so return false
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
