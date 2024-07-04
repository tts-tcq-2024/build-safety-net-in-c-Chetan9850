#include <gtest/gtest.h>
#include <cstring> 
#include "Soundex.h" 

// Fixture for Soundex tests
class SoundexTestsuite : public ::testing::Test {
protected:
    char soundex[5];

    void generateAndAssert(const std::string& input, const std::string& expected) {
        generateSoundex(input.c_str(), soundex);
        ASSERT_STREQ(soundex, expected.c_str());
    }
};

TEST_F(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    generateAndAssert("AX", "A200");
}

TEST_F(SoundexTestsuite, PadsWithZerosToEnsureLengthIsFour) {
    generateAndAssert("A", "A000");
}

TEST_F(SoundexTestsuite, IgnoresCase) {
    generateAndAssert("Ashcraft", "A261");
    generateAndAssert("ashcraft", "A261");
}

TEST_F(SoundexTestsuite, CombinesMultipleCharactersCorrectly) {
    generateAndAssert("Robert", "R163");
}

TEST_F(SoundexTestsuite, HandlesNamesWithDifferentLengths) {
    generateAndAssert("A", "A000");
    generateAndAssert("Abcdefg", "A123");
}

TEST_F(SoundexTestsuite, HandlesNamesWithAdjacentSimilarCodes) {
    generateAndAssert("Pfister", "P236");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
