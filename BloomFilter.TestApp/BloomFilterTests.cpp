#include "stdafx.h"

#include "gtest/gtest.h"

#include "TestUtils.h"

#include "../BloomFilter/BloomFilter.cpp"

using namespace TestUtils;

TEST(BloomFilter, Put)
{
	// Arrange
	int size = 10;
	int k = 3;
	auto bloomFilter = CreateBloomFilter(size, k);

	std::string input = "A";

	// Act
	bloomFilter.put(input);
}

TEST(BloomFilter, IsMaybePresentTrueIfItemPut)
{
	// Arrange
	int size = 10;
	int k = 3;
	auto bloomFilter = CreateBloomFilter(size, k);

	std::string input = "A";

	bloomFilter.put(input);

	// Act
	bool isMaybePresent = bloomFilter.isMaybePresent(input);

	// Assert
	EXPECT_TRUE(isMaybePresent);
}

TEST(BloomFilter, IsMaybePresentFalseIfFilterEmpty)
{
	// Arrange
	int size = 10;
	int k = 3;
	auto bloomFilter = CreateBloomFilter(size, k);

	std::string input = "A";

	// Act
	bool isMaybePresent = bloomFilter.isMaybePresent(input);

	// Assert
	EXPECT_FALSE(isMaybePresent);
}