#include "Soundex.h"
#include <gtest/gtest.h>

// using namespace testing;
class SoundexEncoding : public testing::Test {
public:
  Soundex soundex;
};
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
