cd#include <gtest/gtest.h> 

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return "A";
    }
};

TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, "A");
}