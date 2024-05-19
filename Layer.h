#ifndef LAYER
#define LAYER

#include "Node.h"
#include "ActivationFunctions.h"

class Layer {
private:
	Node* _layerNodes;
	size_t _sizeOfNodes;

public:
	Layer(Node* layerNodes, size_t sizeOfNodes) : _layerNodes(layerNodes), _sizeOfNodes(sizeOfNodes) {}

	Layer(size_t sizeOfNodes) : _sizeOfNodes(sizeOfNodes) {
		_layerNodes = new Node[_sizeOfNodes]; // Allocate memory for nodes
	}

	Layer(ActivationFunction* activationFunctionType, size_t sizeOfNodes) : _sizeOfNodes(sizeOfNodes) {
		_layerNodes = new Node[_sizeOfNodes]; // Allocate memory for nodes
		for (int i = 0; i < _sizeOfNodes; ++i) {
			_layerNodes[i] = Node(nullptr, nullptr, 0, activationFunctionType); // Initialize each node
		}
	}

	~Layer() {
		delete[] _layerNodes; // Deallocate memory
	}

	Node* getLayerNodes() {
		return _layerNodes;
	}

	size_t getLayerSize() {
		return _sizeOfNodes;
	}

	void connect(Layer* otherLayer) {
		Link* links = new Link[getLayerSize() * otherLayer->getLayerSize()];
		size_t count = 0;
		for (int i = 0; i < getLayerSize(); ++i) {
			for (int j = 0; j < otherLayer->getLayerSize(); ++j) {
				links[count] = Link(&(otherLayer->getLayerNodes()[j]), &getLayerNodes()[i]);
				getLayerNodes()[i].setNextElements(&links[count]);
				otherLayer->getLayerNodes()[j].setPreviousElements(&links[count]);
				++count;
			}
		}
	}

	void signal() {
		for (int i = 0; i < _sizeOfNodes; ++i)
			_layerNodes[i].signal();
	}

	void setData(double* data, size_t dataSize) {
		for (int i = 0; i < _sizeOfNodes && i < dataSize; ++i) {
			_layerNodes[i].setData(data[i]);
		}

	}
};

#endif
