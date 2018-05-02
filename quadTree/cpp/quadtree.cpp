#include <cstdlib>
#include "quadtree.h"

QuadTree::QuadTree()
{
	topLeft = Point(0,0);
	bottomRight = Point(0,0);

	node = NULL;
	topLeftTree = NULL;
	topRightTree = NULL;
	bottomLeftTree = NULL;
	bottomRightTree = NULL;
}

QuadTree::QuadTree(Point topL, Point botR)
{
	topLeft = topL;
	bottomRight = botR;

	node = NULL;
	topLeftTree = NULL;
	topRightTree = NULL;
	bottomLeftTree = NULL;
	bottomRightTree = NULL;
}

void QuadTree::insert(Node *n)
{
	if(n == NULL)
		return;
	
	// verify the point within this quad's boundary
	if(!(inBoundary(n->pos)))
		return;


	// is remaining area of unit 1
	// cannot subdivide, but can store a point 
	// in that area
	if(abs(topLeft.x - bottomRight.x) <= 1 &&
		abs(topLeft.y - bottomRight.y) <= 1)
	{
		if(node == NULL){
			node = n;
		}
	}

	// x left of center
	if((topLeft.x + bottomRight.x)/2 >= n->pos.x){
		// y in top half
		if((topLeft.y + bottomRight.y)/2 >= n->pos.y){

			// top left tree
			if(topLeftTree == NULL){
				topLeftTree = new QuadTree( Point(topLeft.x, topLeft.y),
								Point((topLeft.x+bottomRight.x)/2, (topLeft.y+bottomRight.y)/2));
				topLeftTree->insert(n);
			}
			else	// bottom left tree
			{
				if(bottomLeftTree == NULL){
					bottomLeftTree = new QuadTree(Point(topLeft.x, (topLeft.y+bottomRight.y)/2),
												Point((topLeft.x+bottomRight.x)/2, bottomRight.y));
					bottomLeftTree->insert(n);
				}
			}
		}
		else{	// right side
			if((topLeft.y + bottomRight.y)/2 >= n->pos.y){
				if(topRightTree == NULL){
					topRightTree = new QuadTree(Point( (topLeft.x+bottomRight.x)/2, topLeft.y),
												Point(bottomRight.x, (topLeft.y+bottomRight.y)/2)) ;
					topRightTree->insert(n);
				}
				else{ // bottom right
					bottomRightTree = new QuadTree(Point((topLeft.x+bottomRight.x)/2, (topLeft.y+bottomRight.y)/2),
												Point(bottomRight.x, bottomRight.y));
					bottomRightTree->insert(n);
				}
			}
		}
	}




}


Node* QuadTree::search(Point p)
{
	if(!inBoundary(p))
		return NULL;

	// node is always equal to NULL unless it is of
	// size 1. A unit node cannot be further subdivided
	if(node != NULL)
		return node;

	if( (topLeft.x + bottomRight.x)/2 >= p.x){
		// left side 
		if((topLeft.y && bottomRight.y)/2 >= p.y){
			// top left
			if(topLeftTree == NULL)
				return NULL;
			return topLeftTree->search(p);
		}
		else{	// bottom left
			if(bottomLeftTree == NULL)
				return NULL;
			return bottomLeftTree->search(p);
		}
	}
	else{	// right side
		if((topLeft.y && bottomRight.y)/2 >= p.y){
			// top right
			if(topRightTree == NULL)
				return NULL;
			
			return topRightTree->search(p);
		}
		else{	// bottom right
			if(bottomRightTree == NULL)
				return NULL;
			return bottomRightTree->search(p);
		}
	}
}


bool QuadTree::inBoundary(Point p)
{
	return  (p.x < bottomRight.x &&
			p.x > topLeft.x &&
			p.y > topLeft.y &&
			p.y < bottomRight.y);
}