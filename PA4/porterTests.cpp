#include"Histogram.h"
#include"Porter.h"
#include<limits.h>
#include<gtest/gtest.h>

/****************************************/
/*		getRegion()		*/
/****************************************/
TEST(getRegionOne, TestValidRegion_abysmal) {
	Porter p0; 
	EXPECT_EQ("ysmal", p0.getRegion("abysmal"));
}

TEST(getRegionOne, TestValidRegion_definition) {
	Porter p0; 
	EXPECT_EQ("inition", p0.getRegion("definition"));
}

TEST(getRegionOne, TestValidRegion_region) {
	Porter p0; 
	EXPECT_EQ("ion", p0.getRegion("region"));
}

TEST(getRegionOne, TestSizeLT3) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion("it"));
}

TEST(getRegionOne, TestNoRegion_try) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion("try"));
}

TEST(getRegionOne, TestNoRegion_yes) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion("yes"));
}

/****************************************/
/*		getRegion2()		*/
/****************************************/
TEST(getRegionOne, TestNoRegion_zzzzz) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion("zzzzz"));
}

TEST(getRegionTwo, TestValidRegion_abysmal) {
	Porter p0; 
	EXPECT_EQ("mal", p0.getRegion2("abysmal"));
}

TEST(getRegionTwo, TestValidRegion_definition) {
	Porter p0; 
	EXPECT_EQ("ition", p0.getRegion2("definition"));
}

TEST(getRegionTwo, TestValidRegion_systemic) {
	Porter p0; 
	EXPECT_EQ("ic", p0.getRegion2("systemic"));
}

TEST(getRegionTwo, TestSizeLT5) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion2("fore"));
}

TEST(getRegionTwo, TestNoRegion_region) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion2("region"));
}

TEST(getRegionTwo, TestNoRegion_yetti) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion2("yetti"));
}


TEST(getRegionTwo, TestNoRegion_zzzzz) {
	Porter p0;
	EXPECT_EQ("", p0.getRegion2("zzzzz"));
}

/****************************************/
/*		isDouble()		*/
/****************************************/
TEST(isDouble, TestTrue_bb) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("bb"));
}

TEST(isDouble, TestTrue_dd) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("dd"));
}

TEST(isDouble, TestTrue_ff) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("ff"));
}

TEST(isDouble, TestTrue_gg) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("gg"));
}

TEST(isDouble, TestTrue_mm) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("mm"));
}

TEST(isDouble, TestTrue_nn) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("nn"));
}

TEST(isDouble, TestTrue_pp) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("pp"));
}

TEST(isDouble, TestTrue_rr) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("rr"));
}

TEST(isDouble, TestTrue_tt) {
	Porter p0;
	EXPECT_TRUE(p0.isDouble("tt"));
}

TEST(isDouble, TestFalse_zz) {
	Porter p0;
	EXPECT_FALSE(p0.isDouble("zz"));
}

TEST(isDouble, TestFalse_abc) {
	Porter p0;
	EXPECT_FALSE(p0.isDouble("abc"));
}

TEST(isDouble, TestFalse_azz) {
	Porter p0;
	EXPECT_FALSE(p0.isDouble("azz"));
}

TEST(isDouble, TestFalse_aa) {
	Porter p0;
	EXPECT_FALSE(p0.isDouble("aa"));
}

/****************************************/
/* 		isShort()	 	*/
/****************************************/
TEST(isShort, TestTrue_bed) {
	Porter p0; 
	EXPECT_TRUE(p0.isShort("bed"));
}

TEST(isShort, TestTrue_shed) {
	Porter p0; 
	EXPECT_TRUE(p0.isShort("shed"));
}

TEST(isShort, TestTrue_shred) {
	Porter p0; 
	EXPECT_TRUE(p0.isShort("shred"));
}

TEST(isShort, TestFalse_bead) {
	Porter p0;
	EXPECT_FALSE(p0.isShort("bead"));
}

TEST(isShort, TestFalse_embed) {
	Porter p0;
	EXPECT_FALSE(p0.isShort("embed"));
}

TEST(isShort, TestFalse_beds) {
	Porter p0;
	EXPECT_FALSE(p0.isShort("beds"));
}

/****************************************/
/*	     isShortSyllable()		*/
/****************************************/
TEST(isShortSyllable, ConsonantVowelConsonantTestTrue) {
	Porter p0;
	EXPECT_TRUE(p0.isShortSyllable("bed"));
}

TEST(isShortSyllable, ConsonantVowelConsonantTestFalse) {
	Porter p0;
	EXPECT_FALSE(p0.isShortSyllable("bead"));
}
	
TEST(isShortSyllable, TwoCharStringTrue) {
	Porter p0;
	EXPECT_TRUE(p0.isShortSyllable("at"));
}

TEST(isShortSyllable, TwoCharStringFalse) {
	Porter p0;
	EXPECT_FALSE(p0.isShortSyllable("me"));
}

/****************************************/
/*		isValidli()		*/
/****************************************/
TEST(isValidliEnding, TestTrue_c) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("c"));
}

TEST(isValidliEnding, TestTrue_d) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("d"));
}

TEST(isValidliEnding, TestTrue_e) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("e"));
}

TEST(isValidliEnding, TestTrue_g) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("g"));
}

TEST(isValidliEnding, TestTrue_h) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("h"));
}

TEST(isValidliEnding, TestTrue_k) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("k"));
}

TEST(isValidliEnding, TestTrue_m) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("m"));
}

TEST(isValidliEnding, TestTrue_n) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("n"));
}

TEST(isValidliEnding, TestTrue_r) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("r"));
}

TEST(isValidliEnding, TestTrue_t) {
	Porter p0;
	EXPECT_TRUE(p0.isValidli("t"));
}

TEST(isValidliEnding, TestFalse_abfijlopqsuvwzyz) {
	Porter p0;
	string str = "abfijlopqsuvwxyz";
	string ch = "";
	for(int i = 0; i < 16; i++) {
 		ch = str.at(i);
		EXPECT_FALSE(p0.isValidli(ch));
	}
}

/****************************************/
/*		isVowel()		*/
/****************************************/
TEST(isVowel, yazeyixowuvyTest_FTFTFTFTFTFT) {
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

TEST(isVowel, TestFalse_bcdfghjklmnpqrstvwxz) {
	Porter p0;
	string str = "bcdfghjklmnpqrstvwxz";
	for(int i = 0; i < 20; i++) 
		EXPECT_FALSE(p0.isVowel(str, i));
}

/****************************************/
/*		replace()		*/
/****************************************/
TEST(replace, TestTrue_abysmal_emptystr_size0) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 0);
	EXPECT_EQ("abysmal", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size1) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 1);
	EXPECT_EQ("abysma", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size2) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 2);
	EXPECT_EQ("abysm", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size3) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 3);
	EXPECT_EQ("abys", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size4) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 4);
	EXPECT_EQ("aby", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size5) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 5);
	EXPECT_EQ("ab", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size6) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 6);
	EXPECT_EQ("a", str);
}

TEST(replace, TestTrue_abysmal_emptystr_size7) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "", 7);
	EXPECT_EQ("", str);
}

TEST(replace, TestTrue_abysmal_test_size0) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 0);
	EXPECT_EQ("abysmaltest", str);
}

TEST(replace, TestTrue_abysmal_test_size1) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 1);
	EXPECT_EQ("abysmatest", str);
}

TEST(replace, TestTrue_abysmal_test_size2) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 2);
	EXPECT_EQ("abysmtest", str);
}

TEST(replace, TestTrue_abysmal_test_size3) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 3);
	EXPECT_EQ("abystest", str);
}

TEST(replace, TestTrue_abysmal_test_size4) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 4);
	EXPECT_EQ("abytest", str);
}

TEST(replace, TestTrue_abysmal_test_size5) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 5);
	EXPECT_EQ("abtest", str);
}

TEST(replace, TestTrue_abysmal_test_size6) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 6);
	EXPECT_EQ("atest", str);
}

TEST(replace, TestTrue_abysmal_test_size7) {
	Porter p0;
	string str = "abysmal";
	p0.replace(str, "test", 7);
	EXPECT_EQ("test", str);
}

/****************************************/
/*		StemUno()		*/
/****************************************/
TEST(StemUno, TestEQ_test_testXsX) {
	Porter p0;
	string str = "test's'";
	p0.StemUno(str, str.size());
	EXPECT_EQ("test", str);
}

TEST(StemUno, TestEQ_test_testXs) {
	Porter p0;
	string str = "test's";
	p0.StemUno(str, str.size());
	EXPECT_EQ("test", str);
}

TEST(StemUno, TestEQ_test_testX) {
	Porter p0;
	string str = "test'";
	p0.StemUno(str, str.size());
	EXPECT_EQ("test", str);
}

TEST(StemUno, TestEQ_abysmal_abysmal) {
	Porter p0;
	string str = "abysmal";
	p0.StemUno(str, str.size());
	EXPECT_EQ("abysmal", str);
}

/****************************************/
/*		StemDos()		*/
/**********************i*****************/
TEST(StemDos, TestEQ_sses) {
	Porter p0;
	string str = "busses";
	p0.StemDos(str, str.size());
	EXPECT_EQ("buss", str);
}

TEST(StemDos, TestEQ_ied_precederEQ1) {
	Porter p0;
	string str = "tied";
	p0.StemDos(str, str.size());
	EXPECT_EQ("tie", str);
}

TEST(StemDos, TestEQ_ied_precederGT1) {
	Porter p0;
	string str = "unified";
	p0.StemDos(str, str.size());
	EXPECT_EQ("unifi", str);
}

TEST(StemDos, TestEQ_ies_precederEQ1) {
	Porter p0;
	string str = "pies";
	p0.StemDos(str, str.size());
	EXPECT_EQ("pie", str);
}

TEST(StemDos, TestEQ_ies_precederGT1) {
	Porter p0;
	string str = "varies";
	p0.StemDos(str, str.size());
	EXPECT_EQ("vari", str);
}

TEST(StemDos, TestEQ_us) {
	Porter p0;
	string str = "bus";
	p0.StemDos(str, str.size());
	EXPECT_EQ("bus", str);
}

TEST(StemDos, TestEQ_ss) {
	Porter p0;
	string str = "truss";
	p0.StemDos(str, str.size());
	EXPECT_EQ("truss", str);
}

TEST(StemDos, TestEQ_s_passCondition) {
	Porter p0;
	string str = "cats";
	p0.StemDos(str, str.size());
	EXPECT_EQ("cat", str);
}

TEST(StemDos, TestEQ_s_failCondition) {
	Porter p0;
	string str = "tps";
	p0.StemDos(str, str.size());
	EXPECT_EQ("tps", str);
}

/****************************************/
/*		StemTres()		*/
/****************************************/
TEST(StemTres, TestEQ_eedly_passCondition) {
	Porter p0;
	string str = "goateedly";
	p0.StemTres(str, str.size());
	EXPECT_EQ("goatee", str);
}

TEST(StemTres, TestEQ_eedly_failCondition) {
	Porter p0;
	string str = "needly";
	p0.StemTres(str, str.size());
	EXPECT_EQ("needly", str);
}

TEST(StemTres, TestEQ_ingly_passCondition_all) {
	Porter p0;
	string str[] = {"atingly", "abingly", "izingly", 
		"abbingly", "addingly", "affingly", 
		"aggingly", "ammingly", "anningly",
		"appingly", "arringly", "attingly",
		"bedingly"};
	// stem them all
	for(int i = 0; i < 13; i++) {
		p0.StemTres(str[i], str[i].size());
	}
	// tests
	EXPECT_EQ("ate", str[0]);
	EXPECT_EQ("abe", str[1]);
	EXPECT_EQ("ize", str[2]);
	EXPECT_EQ("ab", str[3]);
	EXPECT_EQ("ad", str[4]);
	EXPECT_EQ("af", str[5]);
	EXPECT_EQ("ag", str[6]);
	EXPECT_EQ("am", str[7]);
	EXPECT_EQ("an", str[8]);
	EXPECT_EQ("ap", str[9]);
	EXPECT_EQ("ar", str[10]);
	EXPECT_EQ("at", str[11]);
	EXPECT_EQ("bede", str[12]);
}

TEST(StemTres, TestEQ_ingly_failCondition) {
	Porter p0;
	string str = "shingly";
	p0.StemTres(str, str.size());
	EXPECT_EQ("shingly", str);
}

TEST(StemTres, TestEQ_edly_passCondition_all) {
	Porter p0;
	string str[] = {"atedly", "abedly", "izedly", 
		"abbedly", "addedly", "affedly", 
		"aggedly", "ammedly", "annedly",
		"appedly", "arredly", "attedly",
		"bededly"};
	// stem them all
	for(int i = 0; i < 13; i++) {
		p0.StemTres(str[i], str[i].size());
	}
	// tests
	EXPECT_EQ("ate", str[0]);
	EXPECT_EQ("abe", str[1]);
	EXPECT_EQ("ize", str[2]);
	EXPECT_EQ("ab", str[3]);
	EXPECT_EQ("ad", str[4]);
	EXPECT_EQ("af", str[5]);
	EXPECT_EQ("ag", str[6]);
	EXPECT_EQ("am", str[7]);
	EXPECT_EQ("an", str[8]);
	EXPECT_EQ("ap", str[9]);
	EXPECT_EQ("ar", str[10]);
	EXPECT_EQ("at", str[11]);
	EXPECT_EQ("bede", str[12]);
}

TEST(StemTres, TestEQ_edly_failCondition) {
	Porter p0;
	string str = "redly";
	p0.StemTres(str, str.size());
	EXPECT_EQ("redly", str);
}

TEST(StemTres, TestEQ_ing_passCondition_all) {
	Porter p0;
	string str[] = {"ateing", "abeing", "izeing", 
		"abbing", "adding", "affing", 
		"agging", "amming", "anning",
		"apping", "arring", "atting",
		"beding"};
	// stem them all
	for(int i = 0; i < 13; i++) {
		p0.StemTres(str[i], str[i].size());
	}
	// tests
	EXPECT_EQ("ate", str[0]);
	EXPECT_EQ("abe", str[1]);
	EXPECT_EQ("ize", str[2]);
	EXPECT_EQ("ab", str[3]);
	EXPECT_EQ("ad", str[4]);
	EXPECT_EQ("af", str[5]);
	EXPECT_EQ("ag", str[6]);
	EXPECT_EQ("am", str[7]);
	EXPECT_EQ("an", str[8]);
	EXPECT_EQ("ap", str[9]);
	EXPECT_EQ("ar", str[10]);
	EXPECT_EQ("at", str[11]);
	EXPECT_EQ("bede", str[12]);
}

TEST(StemTres, TestEQ_ing_failCondition) {
	Porter p0;
	string str = "ring";
	p0.StemTres(str, str.size());
	EXPECT_EQ("ring", str);
}

TEST(StemTres, TestEQ_eed_passCondition) {
	Porter p0;
	string str = "goateed";
	p0.StemTres(str, str.size());
	EXPECT_EQ("goatee", str);
}

TEST(StemTres, TestEQ_eed_failCondition) {
	Porter p0;
	string str = "beed";
	p0.StemTres(str, str.size());
	EXPECT_EQ("beed", str);
}

TEST(StemTres, TestEQ_ed_passCondition_all) {
	Porter p0;
	string str[] = {"ated", "abed", "ized", 
		"abbed", "added", "affed", 
		"agged", "ammed", "anned",
		"apped", "arred", "atted",
		"beded"};
	// stem them all
	for(int i = 0; i < 13; i++) {
		p0.StemTres(str[i], str[i].size());
	}
	// tests
	EXPECT_EQ("ate", str[0]);
	EXPECT_EQ("abe", str[1]);
	EXPECT_EQ("ize", str[2]);
	EXPECT_EQ("ab", str[3]);
	EXPECT_EQ("ad", str[4]);
	EXPECT_EQ("af", str[5]);
	EXPECT_EQ("ag", str[6]);
	EXPECT_EQ("am", str[7]);
	EXPECT_EQ("an", str[8]);
	EXPECT_EQ("ap", str[9]);
	EXPECT_EQ("ar", str[10]);
	EXPECT_EQ("at", str[11]);
	EXPECT_EQ("bede", str[12]);
}

TEST(StemTres, TestEQ_ed_failCondition) {
	Porter p0;
	string str = "red";
	p0.StemTres(str, str.size());
	EXPECT_EQ("red", str);
}

/****************************************/
/*		StemCuatro()		*/
/****************************************/
TEST(StemCuatro, TestEQ_y_passCondition) {
	Porter p0;
	string str = "baby";
	p0.StemCuatro(str, str.size());
	EXPECT_EQ("babi", str);
}

TEST(StemCuatro, TestEQ_y_failCondition) {
	Porter p0;
	string str0 = "my";
	string str1 = "bay";	

	p0.StemCuatro(str0, str0.size());
	p0.StemCuatro(str1, str1.size());

	EXPECT_EQ("my", str0);
	EXPECT_EQ("bay", str1);	
}

/****************************************/
/*		StemCinco()		*/
/****************************************/
TEST(StemCinco, TestEQ_ization) {
	Porter p0;
	string str = "lization";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lize", str);
}

TEST(StemCinco, TestEQ_ational) {
	Porter p0;
	string str = "lational";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("late", str);
}

TEST(StemCinco, TestEQ_fulness) {
	Porter p0;
	string str = "lfulness";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lful", str);
}

TEST(StemCinco, TestEQ_ousness) {
	Porter p0;
	string str = "lousness";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lous", str);
}

TEST(StemCinco, TestEQ_iveness) {
	Porter p0;
	string str = "liveness";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("live", str);
}

TEST(StemCinco, TestEQ_tional) {
	Porter p0;
	string str = "ltional";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("ltion", str);
}

TEST(StemCinco, TestEQ_biliti) {
	Porter p0;
	string str = "lbiliti";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lble", str);
}

TEST(StemCinco, TestEQ_lessli) {
	Porter p0;
	string str = "llessli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lless", str);
}

TEST(StemCinco, TestEQ_entli) {
	Porter p0;
	string str = "lentli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lent", str);
}

TEST(StemCinco, TestEQ_ation) {
	Porter p0;
	string str = "lation";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("late", str);
}

TEST(StemCinco, TestEQ_alism) {
	Porter p0;
	string str = "lalism";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lal", str);
}

TEST(StemCinco, TestEQ_aliti) {
	Porter p0;
	string str = "laliti";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lal", str);
}

TEST(StemCinco, TestEQ_ousli) {
	Porter p0;
	string str = "lousli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lous", str);
}

TEST(StemCinco, TestEQ_iviti) {
	Porter p0;
	string str = "liviti";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("live", str);
}

TEST(StemCinco, TestEQ_fulli) {
	Porter p0;
	string str = "lfulli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lful", str);
}

TEST(StemCinco, TestEQ_enci) {
	Porter p0;
	string str = "lenci";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lence", str);
}

TEST(StemCinco, TestEQ_anci) {
	Porter p0;
	string str = "lanci";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lance", str);
}

TEST(StemCinco, TestEQ_abli) {
	Porter p0;
	string str = "labli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lable", str);
}

TEST(StemCinco, TestEQ_izer) {
	Porter p0;
	string str = "lizer";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lize", str);
}

TEST(StemCinco, TestEQ_ator) {
	Porter p0;
	string str = "lator";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("late", str);
}

TEST(StemCinco, TestEQ_alli) {
	Porter p0;
	string str = "lalli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lal", str);
}

TEST(StemCinco, TestEQ_ogi) {
	Porter p0;
	string str = "logi";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("log", str);
}

TEST(StemCinco, TestEQ_bli) {
	Porter p0;
	string str = "lbli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("lble", str);
}

TEST(StemCinco, TestEQ_li) {
	Porter p0;
	string str = "cli";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("c", str);
}

TEST(StemCinco, TestEQ_abysmal) {
	Porter p0;
	string str = "abysmal";
	p0.StemCinco(str, str.size());
	EXPECT_EQ("abysmal", str);
}

/****************************************/
/*		StemSeis()		*/
/****************************************/
TEST(StemSeis, TestEQ_ational) {
	Porter p0;
	// PASS CONDITION
	string str = "axational";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axate", str);
	// FAIL no region1
	str = "xational";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xational", str);
}

TEST(StemSeis, TestEQ_ative) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxative";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axative";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axative", str);
}

TEST(StemSeis, TestEQ_tional) {
	Porter p0;
	// PASS CONDITION
	string str = "axtional";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axtion", str);
	// FAIL no region1
	str = "xational";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xational", str);
}

TEST(StemSeis, TestEQ_alize) {
	Porter p0;
	// PASS CONDITION
	string str = "axalize";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axal", str);
	// FAIL no region1
	str = "xalize";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xalize", str);
}

TEST(StemSeis, TestEQ_icate) {
	Porter p0;
	// PASS CONDITION
	string str = "axicate";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axic", str);
	// FAIL no region1
	str = "xicate";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xicate", str);
}

TEST(StemSeis, TestEQ_iciti) {
	Porter p0;
	// PASS CONDITION
	string str = "axiciti";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axic", str);
	// FAIL no region1
	str = "xiciti";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xiciti", str);
}

TEST(StemSeis, TestEQ_ical) {
	Porter p0;
	// PASS CONDITION
	string str = "axical";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("axic", str);
	// FAIL no region1
	str = "xical";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xical", str);
}

TEST(StemSeis, TestEQ_ness) {
	Porter p0;
	// PASS CONDITION
	string str = "axness";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("ax", str);
	// FAIL no region1
	str = "xness";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xness", str);
}

TEST(StemSeis, TestEQ_ful) {
	Porter p0;
	// PASS CONDITION
	string str = "axful";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("ax", str);
	// FAIL no region1
	str = "xful";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("xful", str);
}

TEST(StemSeis, TestEQ_abysmal) {
	Porter p0;
	string str = "abysmal";
	p0.StemSeis(str, str.size());
	EXPECT_EQ("abysmal", str);
}

/****************************************/
/*		StemSiete()		*/
/****************************************/
TEST(StemSiete, TestEQ_ement) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxement";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axement";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axement", str);
}

TEST(StemSiete, TestEQ_ance) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxance";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axance";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axance", str);
}

TEST(StemSiete, TestEQ_ence) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxence";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axence";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axence", str);
}

TEST(StemSiete, TestEQ_able) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxable";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axable";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axable", str);
}

TEST(StemSiete, TestEQ_ible) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxible";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axible";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axible", str);
}

TEST(StemSiete, TestEQ_ment) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxment";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axment";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axment", str);
}

TEST(StemSiete, TestEQ_ant) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxant";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axant";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axant", str);
}

TEST(StemSiete, TestEQ_ent) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxent";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axent";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axent", str);
}

TEST(StemSiete, TestEQ_ism) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxism";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axism";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axism", str);
}

TEST(StemSiete, TestEQ_ate) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxate";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axate";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axate", str);
}

TEST(StemSiete, TestEQ_iti) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxiti";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axiti";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axiti", str);
}

TEST(StemSiete, TestEQ_ous) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxous";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axous";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axous", str);
}

TEST(StemSiete, TestEQ_ive) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxive";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axive";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axive", str);
}

TEST(StemSiete, TestEQ_ize) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxize";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axize";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axize", str);
}

TEST(StemSiete, TestEQ_ion_s) {
	Porter p0;
	// PASS CONDITION 's' 
	string str = "axasion";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axas", str);
}

TEST(StemSiete, TestEQ_ion_t) {
	Porter p0;
	// PASS CONDITION 't' 
	string str = "axation";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axat", str);
}

TEST(StemSiete, TestEQ_ion_fail_on_sORt) {
	Porter p0;
	// FAIL no 's' or 't'
	string str = "axaxion";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axaxion", str);
}

TEST(StemSiete, TestEQ_ion_fail_on_region) {
	Porter p0;
	// FAIL no region2
	string str = "axion";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axion", str);
}

TEST(StemSiete, TestEQ_al) {
	Porter p0;
	// PASS CONDITION
	string str = "abysmal";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("abysm", str);
	// FAIL no region2
	str = "axal";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axal", str);
}

TEST(StemSiete, TestEQ_er) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxer";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axer";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axer", str);
}

TEST(StemSiete, TestEQ_ic) {
	Porter p0;
	// PASS CONDITION
	string str = "axaxic";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axax", str);
	// FAIL no region2
	str = "axic";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("axic", str);
}

TEST(StemSiete, TestEQ_hyphen) {
	Porter p0;
	string str = "hyphen";
	p0.StemSiete(str, str.size());
	EXPECT_EQ("hyphen", str);
}

/****************************************/
/*		StemOcho()		*/
/****************************************/
TEST(StemOcho, TestEQ_e_no_region1) {
	Porter p0;
	string str = "xe";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("xe", str);
}

TEST(StemOcho, TestEQ_e_in_region1_not_ShortSyllable) {
	Porter p0;
	string str = "axxe";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("axx", str);
}

TEST(StemOcho, TestEQ_e_in_region1_is_ShortSyllable) {
	Porter p0;
	string str = "axe";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("axe", str);
}

TEST(StemOcho, TestEQ_e_in_region2) {
	Porter p0;
	string str = "axaxe";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("axax", str);
}

TEST(StemOcho, TestEQ_l_in_region2_and_ll) {
	Porter p0;
	string str = "axall";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("axal", str);
}

TEST(StemOcho, TestEQ_l_in_region2_and_not_ll) {
	Porter p0;
	string str = "axaxl";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("axaxl", str);
}

TEST(StemOcho, TestEQ_l_not_in_region2) {
	Porter p0;
	string str = "all";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("all", str);
}

TEST(StemOcho, TestEQ_not_eORl) {
	Porter p0;
	string str = "add";
	p0.StemOcho(str, str.size());
	EXPECT_EQ("add", str);
}

/****************************************/
/*		GoGoPorter#2()		*/
/****************************************/
TEST(GoGoPorterNumeroDos, TestEQ_abatement) {
	Porter p0;
	string str = "abatement";
	p0.GoGoPorterNumeroDos(str, str.size());
	EXPECT_EQ("abat", str);
}

TEST(GoGoPorterNumeroDos, TestEQ_arrowonezXsX) {
	Porter p0;
	string str = "arrowonez's'";
	p0.GoGoPorterNumeroDos(str, str.size());
	EXPECT_EQ("abat", str);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
