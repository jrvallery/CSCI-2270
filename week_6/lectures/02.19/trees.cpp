/*
Topics:
    -Trees
    -Binary Trees
    -Binary Search Trees
    -Recursion


-A linear data structure is a DS in which data is arranged in a sequential manner
-A tree is a non-linear DS
    -Hierarchical data structure
    -can be called a recursice data structure
Its like a organized chart

A-->(B and C)
then B-->(D and E)
and C-->(F and G)
and so on

A tree is the concept of storing two nodes in a node, a left and right node.
*/

struct Node
{
    Node *left;
    Node *right;
    int data;
};

/*
-Nodes linked together
-Top node = root
-nodes can be of any type
-connected by edges
-cannot have disconnected parts

If we point at a Node aways down the tree we now have a new sub tree within the root tree
(EVERY NODE IS A NEW SUB TREES ROOT)

A node at the bottem of the tree is defined as a leaf
LEAF = any node with no children

Applications of trees
    -File system in OS
    -Network routing algorithms

Every node in a tree is pointed to besides the root
each node that is pointed to contains a edge
so if there are 7 nodes
n = 7
there are n - 1 edges
E = n - 1 = 6
This is because the root node does not have a parent node

-The length of a path is the number of edges in the path
-The depth of a node is the length of the path from the root to the node.
So the first node in the tree is 0.
-The height of a tree is the length from the root to the furthest node
*/
