#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Util.h"

TEST(eqTest, self)
{
	EXPECT_TRUE(Util::Eq(0.0f, 0.0f));
	EXPECT_TRUE(Util::Eq(1.0f, 1.0f));
}

TEST(eqTest, posNeg)
{
	EXPECT_FALSE(Util::Eq(-1.0f, 1.0f));
}

TEST(eqTest, zero)
{
	EXPECT_FALSE(Util::Eq(0.0f, 1.0f));
}

TEST(eqTest, similar)
{
	EXPECT_FALSE(Util::Eq(1.0f, 1.0001f));
}

TEST(eqTest, far)
{
	EXPECT_FALSE(Util::Eq(75.654f, 1.0001f));
}