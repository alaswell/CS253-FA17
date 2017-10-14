#include"Histogram.h"
#include"Porter.h"
#include<limits.h>
#include<gtest/gtest.h>

TEST(isDouble, TestTrue) {
	Porter p0;
	string str0 = "bb";
	string str1 = "dd";
	string str2 = "ff";
	string str3 = "gg";
	string str4 = "mm";
	string str5 = "nn";
	string str6 = "pp";
	string str7 = "rr";
	string str8 = "tt";

	EXPECT_TRUE(p0.isDouble(str0));
	EXPECT_TRUE(p0.isDouble(str1));
	EXPECT_TRUE(p0.isDouble(str2));
	EXPECT_TRUE(p0.isDouble(str3));
	EXPECT_TRUE(p0.isDouble(str4));
	EXPECT_TRUE(p0.isDouble(str5));
	EXPECT_TRUE(p0.isDouble(str6));
	EXPECT_TRUE(p0.isDouble(str7));
	EXPECT_TRUE(p0.isDouble(str8));
}

TEST(isShortSyllable, ConsonantVowelConsonantTestTrue) {
	Porter p0;
	string str = "bed";
	EXPECT_TRUE(p0.isShortSyllable(str));
}

TEST(isShortSyllable, ConsonantVowelConsonantTestFalse) {

	Porter p0;
	string str = "bead";
	EXPECT_FALSE(p0.isShortSyllable(str));
}
	
TEST(isShortSyllable, TwoCharStringTrue) {
	Porter p0;
	string str = "at";
	EXPECT_TRUE(p0.isShortSyllable(str));
}

TEST(isShortSyllable, TwoCharStringFalse) {
	Porter p0;
	string str = "me";
	EXPECT_FALSE(p0.isShortSyllable(str));
}

TEST(isVowel, yazeyixowuvyTestFTFTFTFTFTFT) {
	Porter p0;
	string str = "yazeyixowuvy";
	EXPECT_FALSE(p0.isVowel(str, 0));
	EXPECT_TRUE(p0.isVowel(str, 1));
	EXPECT_FALSE(p0.isVowel(str, 2));
	EXPECT_TRUE(p0.isVowel(str, 3));
	EXPECT_FALSE(p0.isVowel(str, 4));
	EXPECT_TRUE(p0.isVowel(str, 5));
	EXPECT_FALSE(p0.isVowel(str, 6));
	EXPECT_TRUE(p0.isVowel(str, 7));
	EXPECT_FALSE(p0.isVowel(str, 8));
	EXPECT_TRUE(p0.isVowel(str, 9));
	EXPECT_FALSE(p0.isVowel(str,10));
	EXPECT_TRUE(p0.isVowel(str, 11));
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
