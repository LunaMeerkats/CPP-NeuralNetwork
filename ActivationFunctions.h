#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H

class ActivationFunction {
public:
	virtual double activate(double x) const {
		return x;
	}
};

class LeakyReluActivationFunction : public ActivationFunction {
public:
	double activate(double x) const override {
		if (x < 0)
			return 0.1 * x;
		else
			return x;
	}
};

#endif // ACTIVATIONFUNCTIONS_H
