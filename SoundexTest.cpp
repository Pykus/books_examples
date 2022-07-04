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
  ASSERT_EQ(soundex.encode("Ab"), "A100");
}
