#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesDuplicatesAndSkips) {
    EXPECT_EQ(generateSoundex("AABBBB"), "A100");
}

TEST(SoundexTest, HandlesMixedCase) {
    EXPECT_EQ(generateSoundex("McDonald"), "M235");
}

TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("John123"), "J500");
}

// Additional tests to cover edge cases and typical inputs

TEST(SoundexTest, HandlesLongInput) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");
}

TEST(SoundexTest, HandlesShortInput) {
    EXPECT_EQ(generateSoundex("Li"), "L000");
}

TEST(SoundexTest, ProducesExactlyFourCharacters) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

TEST(SoundexTest, HandlesAllZeros) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
}

TEST(SoundexTest, HandlesSameSoundexCodeCharacters) {
    EXPECT_EQ(generateSoundex("BFPV"), "B000");
}

TEST(SoundexTest, HandlesSkippedCharacters) {
    EXPECT_EQ(generateSoundex("Aeiouhwy"), "A000");
}

TEST(SoundexTest, HandlesSeperationByZeroCodeCharacters) {
    EXPECT_EQ(generateSoundex("BhFyPV"), "B000");
}
