#include "BigInt.h"
#include <stdint.h>
#include <algorithm>

using namespace std;

BigInt operator + (BigInt &n1, BigInt &n2)
{
	BigInt sum;
	uint32_t word_sum, word_carry;
	uint64_t word_sum_64;
	int n1_size, n2_size;
	int min_size;
	int i;
	n1_size = n1.buffer.size();
	n2_size = n2.buffer.size();
	min_size = min(n1_size, n2_size);
	word_carry = 0;
	for (i = 0; i < min_size; ++i) {
		word_sum_64 = uint64_t(n1.buffer[i]) + n2.buffer[i] +
				word_carry;
		word_carry = word_sum_64 >> 32;
		word_sum = word_sum_64 & 0xffffffff;
		sum.buffer.push_back(word_sum);
	}
	while (i < n1_size) {
		word_sum_64 = uint64_t(n1.buffer[i]) +
				word_carry;
		word_carry = word_sum_64 >> 32;
		word_sum = word_sum_64 & 0xffffffff;
		sum.buffer.push_back(word_sum);
		++i;
	}
	while (i < n2_size) {
		word_sum_64 = uint64_t(n2.buffer[i]) +
				word_carry;
		word_carry = word_sum_64 >> 32;
		word_sum = word_sum_64 & 0xffffffff;
		sum.buffer.push_back(word_sum);
		++i;
	}
}
