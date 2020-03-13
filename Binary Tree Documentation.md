| Ryan LaCombe |
|:---       |
| s198023 |
| Introduction to C++ |
| Binary Tree Documentation |

## I. Requirements

1. Description of problem:
    - **Name:** Binary Tree Demonstration

    - **Problem Statement:** Creation of a program that sufficiently displays a finished Binary Tree.

    - **Problem Specifications:** The program must be console based and execute without crashing.

2. Output Information
    - The program displays a Binary Tree that were input through the coder.

## II. Design

1. _System Architecture_

|
|:--------------- |
Main Loop:

Draws the Binary Tree to the RayLib window.

2. ### Object Information

    **File:** BinaryTree.h

        Description: Used to hold the functions for the creation of the Binary Tree.

        **Attributes:**

            Name: isEmpty
                Description: Checks if the Binary Tree is currently empty.
                Type: public bool const

            Name: insert
                Description: Inserts a node of the passed in data into the Binary Tree.
                Type: public void

            Name: remove
                Description: Removes a node of the passed in data from the Binary Tree.
                Type: public void

            Name: find
                Description: Finds a node of the passed in data.
                Type: public TreeNode*

            Name: draw
                Description: Draws the Binary Tree and highlts a node if a data is passed in.
                Type: public void

            Name: findNode
                Description: Finds a node of the passed in data and returns it and its parent.
                Type: private bool

            Name: draw
                Description: Draws the Binary Tree.
                Type: private node

            Name: m_proot
                Description: Variable that keeps track of the root node.
                Type: private TreeNode*

    **File:** TreeNode.h

        Description: Used to create the Nodes to place into the Binary Tree.

        **Attributes:**

            Name: TreeNode
                Description: A constructor that creates a node of the passed in value.
                Type: public constructor

            Name: hasLeft
                Description: Checks if the current node has a left node.
                Type: public bool

            Name: hasRight
                Description: Checks if the current node has a right node.
                Type: public bool

            Name: getData
                Description: Gets the current node's data.
                Type: public int

            Name: getLeft
                Description: Gets the current node's left node.
                Type: public TreeNode*

            Name: getRight
                Description: Gets the current node's right node.
                Type: public TreeNode*

            Name: setData
                Description: Sets the current node's data to the passed in value.
                Type: public void

            Name: setLeft
                Description: Sets the current node's left to the passed in node.
                Type: public void

            Name: setRight
                Description: Sets the current node's right to the passed in node.
                Type: public void

            Name: draw
                Description: Draws the passed in node.
                Type: public void

            Name: m_value
                Description: Keeps track of the passed in values.
                Type: public int

            Name: m_left
                Description: Keeps track of the current node's left.
                Type: public TreeNode*

            Name: m_right
                Description: Keeps track of the current node's right.
                Type: public TreeNode*