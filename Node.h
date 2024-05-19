#ifndef NODE_H
#define NODE_H

#include "Element.h"
#include "ActivationFunctions.h"

class Node : public Element {
private:
	ActivationFunction* _activationFunction;

public:
	Node(ActivationFunction* activationFunction) : Element(nullptr, 0, nullptr, 0), _activationFunction(activationFunction) {}

	Node() : Element(nullptr, 0, nullptr, 0), _activationFunction(new ActivationFunction) {}

	Node(Element* nextElements, Element* previousElements, size_t previousElementsSize, ActivationFunction* activationFunction)
		: Element(nextElements, 1, previousElements, previousElementsSize),
		_activationFunction(activationFunction) {}

	void signal() {
		std::cout << "Node Signal" << std::endl;
		setData(_activationFunction->activate(getData()));
		
		if (getNextElements() == 0) return;

		getNextElements()->setData(getData());
		getNextElements()->signal();
	}
};

#endif // NODE_H
