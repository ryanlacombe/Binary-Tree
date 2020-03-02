#include "BinaryTree.h"

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{

}

void BinaryTree::draw(TreeNode* selected)
{
	//Draw the root node
	draw(m_pRoot, 640, 680, 640, selected);
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
