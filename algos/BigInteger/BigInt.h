/*
 * BigInt class to support arbitrary sized integers
 */

#ifndef BIGINT_H
#define BIGINT_H

#include <stdint.h>
#include <vector>

class BigInt {
private:
	std::vector<uint32_t> buffer;
public:
	friend BigInt operator + (BigInt &n1, BigInt &n2);
	BigInt(unsigned size = 1) : buffer(size, 0)
	{
	}
	BigInt(BigInt &integer) : buffer(integer.buffer)
	{
	}
	~BigInt()
	{
	}
};



#endif
