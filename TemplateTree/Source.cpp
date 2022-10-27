#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	tree<int> t;
	t.add(11);
	t.add(3);
	t.add(10);
	t.add(1);
	t.add(5);
	t.add(4);
	t.add(7);
	t.add(9);
	t.sumelem();
	t.maxvalue();

	return 0;
}