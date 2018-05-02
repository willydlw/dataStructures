#ifndef QUADTREE_H
#define QUADTREE_H


struct Point{
	int x;
	int y;

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Point()
	{
		x = 0;
		y = 0;
	}
};

struct Node{
	Point pos;
	bool leaf;

	Node(Point _pos, bool _leaf)
	{
		pos = _pos;
		leaf = _leaf;
	}

	Node()
	{
		leaf = true;
	}

};


class QuadTree{
public:

	QuadTree();
	QuadTree(Point topL, Point botR);

	void insert(Node *n);
	Node *search(Point p);
	bool inBoundary(Point p);

private:

	// Boundary
	Point topLeft;
	Point bottomRight;

	// Leaf node details
	Node *node;

	// Children of the tree
	QuadTree *topLeftTree;
	QuadTree *topRightTree;
	QuadTree *bottomLeftTree;
	QuadTree *bottomRightTree;
};


#endif