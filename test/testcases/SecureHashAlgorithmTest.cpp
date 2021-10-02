#include <SecureHashAlgorithm.hpp>
#include <gtest/gtest.h>

class SecureHashAlgorithmTest : public testing::Test
{
    void SetUp(){}
    void TearDown(){}

};

TEST_F(SecureHashAlgorithmTest, finalTest)
{
    const std::string input = "abc";
    const std::string answer = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";

    SecureHashAlgorithm sha(input);

    ASSERT_EQ(sha.toString(), answer);
}
TEST_F(SecureHashAlgorithmTest, finalAgainTest)
{
    const std::string input = "abc";
    const std::string answer = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";

    SecureHashAlgorithm sha(input);

    ASSERT_EQ(sha.toString(), answer);

    sha = SecureHashAlgorithm(input);
    ASSERT_EQ(sha.toString(), answer);
}
TEST_F(SecureHashAlgorithmTest, CasOneTest)
{
    const std::string input = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff6";
    const std::string answer = "6d6f126b3ed934872ae43ea8371376b18e2902518bb3d450527eef59aa2f0d49";

    SecureHashAlgorithm sha(input);

    ASSERT_EQ(sha.toString(), answer);
}
TEST_F(SecureHashAlgorithmTest, CasTwoTest)
{
    const std::string input = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61";
    const std::string answer = "fdf1d763c0866838b060c9657fefb6cf964058b356b0a2fb8103bd6396600747";

    SecureHashAlgorithm sha(input);

    ASSERT_EQ(sha.toString(), answer);
}
TEST_F(SecureHashAlgorithmTest, CaseThirdTest)
{
    const std::string input = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
    const std::string answer = "dfe7a23fefeea519e9bbfdd1a6be94c4b2e4529dd6b7cbea83f9959c2621b13c";

    SecureHashAlgorithm sha(input);

    ASSERT_EQ(sha.toString(), answer);
}
