#include <iostream>
#include "Node.h"
#include "Link.h"
#include "Layer.h"
#include "Main.h"

//To do:
//	Understand the mathematics behind backpropogation.
//	Implement backpropogation.


int main() {

	// Create layers
	Layer inputLayer(new ActivationFunction(), 2);
	Layer hiddenLayer(new LeakyReluActivationFunction(), 1);
	Layer outputLayer(new ActivationFunction(), 1);

	// Connect layers
	inputLayer.connect(&hiddenLayer);
	hiddenLayer.connect(&outputLayer);

	// Propagate signal
	double data[2] = {0.5, 0.5};
	inputLayer.setData(data, 2);
	inputLayer.signal();
	std::cout << inputLayer.getLayerNodes()->getData() << std::endl;
	hiddenLayer.signal();
	std::cout << hiddenLayer.getLayerNodes()->getData() << std::endl;
	outputLayer.signal();
	std::cout << outputLayer.getLayerNodes()->getData() << std::endl;


	return 0;
}
