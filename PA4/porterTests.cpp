#include"Histogram.h"
#include"Porter.h"
#include<limits.h>
#include<gtest/gtest.h>


TEST(isShortSyllable, ConsonantVowelConsonantTest) {
	Porter p0;
	string str = "bed";
	string str1 = "bead";
	EXPECT_TRUE(p0.isShortSyllable(str));
	EXPECT_FALSE(p0.isShortSyllable(str1));
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
