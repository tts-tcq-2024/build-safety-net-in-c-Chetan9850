#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
generateSoundex("$rrr", soundex);
ASSERT_STREQ(soundex,"$666");
}
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
//AAA
char soundex[5];
generateSoundex("pvt", soundex);
ASSERT_STREQ(soundex,"P130");
}
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
//AAA
  char soundex[5];
generateSoundex("*#12hi", soundex);
ASSERT_STREQ(soundex,"*000");
}
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_vowels) {
//AAA
char soundex[5];
generateSoundex("aeiou", soundex);
ASSERT_STREQ(soundex,"A000");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_space) {
//AAA
char soundex[5];
generateSoundex(" ", soundex);
ASSERT_STREQ(soundex," 000");
}
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
//AAA
char soundex[5];
generateSoundex("bcdlmnr", soundex);
ASSERT_STREQ(soundex,"B234");
}
