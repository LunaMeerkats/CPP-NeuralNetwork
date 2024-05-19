#ifndef ELEMENT_H
#define ELEMENT_H

#include <assert.h>

class Element {
private:
	Element* _nextElements;
	size_t _nextElementsSize;

	Element* _previousElements;
	size_t _previousElementsSize;

	double _data;

public:
	Element(Element* nextElement, size_t nextElementsSize, Element* previousElement, size_t previousElementsSize) : _data(0), _nextElements(nextElement), _nextElementsSize(nextElementsSize), _previousElements(previousElement), _previousElementsSize(previousElementsSize) {}

	virtual void signal() {}

	// Functions to set and get data
	void setData(double data) {
		_data = data;
	}

	double getData() const {
		return _data;
	}

	// Functions to set next and previous elements
	void setNextElements(Element* nextElements) {
		_nextElements = nextElements;
	}

	void setPreviousElements(Element* previousElements) {
		_previousElements = previousElements;
	}

	// Functions to get next and previous elements
	Element* getNextElements() const {
		return _nextElements;
	}

	size_t getNextElementsSize() {
		return _nextElementsSize;
	}

	Element* getPreviousElements() const {
		return _previousElements;
	}

	size_t getPreviousElementsSize() {
		return _previousElementsSize;
	}

	// Function to add value to data 
	void addToValue(double x) {
		setData(getData() + x);
	}
};

#endif // ELEMENT_H
