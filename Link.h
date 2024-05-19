#ifndef LINK
#define LINK

#include "Element.h"
#include "Node.h"

class Link : public Element {

private:
	double _weight;

public:
	Link() : Element(nullptr, 0, nullptr, 0)
	{
		_weight = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
	}

	Link(Node* nextElements, Node* previousElements)
		: Element(nextElements, 1, previousElements, 1)
	{
		_weight = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
	}

	void signal() {
		std::cout << "Link Signal" << std::endl;
		setData(_weight * getData());
		getNextElements()->addToValue(getData());
		
	}
};
#endif