#pragma once

#include <cstdlib>

class RandomGenerator {
public:
	RandomGenerator() {}
	virtual int generateTwo() {
		return rand() % 2;
	}
	virtual int generate(int number, bool uniform = true) {
		if (uniform || (number < 3)) {
			return rand() % number;
		}
		const int leaf_prob = 10; // 0.1
		int k = rand() % leaf_prob;
		if (!k) {
			return generateTwo();
		}
		int val = rand() % (number - 2);
		return 2 + val;
	}
};