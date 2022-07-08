#include "Soundex.h"
#include "gtest/gtest.h"

// using namespace testing;
class SoundexEncoding : public testing::Test {
public:
  Soundex soundex;
};
TEST(nowy, testowy) { ASSERT_EQ(22, 1); }

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
  auto encoded = soundex.encode("A");
  ASSERT_EQ(encoded, "A000");
}
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  auto encoded = soundex.encode("I");
  ASSERT_EQ(encoded, "I000");
}
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
  // EXPECT_EQ(soundex.encode("Ab"), "A100");
  // EXPECT_EQ(soundex.encode("Ac"), "A200");
  ASSERT_EQ(soundex.encode("Ax"), "A200");
}
TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_EQ(soundex.encode("A#"), "A000");
}
// off test TEST_F(SoundexEncoding,
// DISABLED_ReplacesMultipleConsonantsWithDigits) {
TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
  ASSERT_EQ(soundex.encode("Acdl"), "A234");
}
TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_EQ(int(soundex.encode("Dcdlb").length()), 4);
}
TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
  ASSERT_EQ(soundex.encode("Baeiouhycdl"), "B234");
}
TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
  ASSERT_EQ(soundex.encode("Abfcgdt"), "A123");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
