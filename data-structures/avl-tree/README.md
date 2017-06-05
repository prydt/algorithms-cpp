#AVL Trees
A self-balancing variant to the Binary Search Tree

##Why?
AVL Trees balance themselves to make an optimal tree instead of an arbitrary one...

##Computing Heights of Nodes
Height of a Leaf = 0
Height of a non-leaf = MAX(a, b) + 1 where a and b are the heights of its children
Height of a NULL Node = -1

##Controlling Heights
AVL Trees require that the heights of both left and right children differ by at most only +/- 1.
