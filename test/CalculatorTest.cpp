#include "Calculator.h"
#include "gtest/gtest.h"

class CalculatorTest: public ::testing::Test {
  protected:
    CalculatorTest() {
    }

    ~CalculatorTest() override {
    }

   void SetUp() override {
   }

   void TearDown() override {
   }

};

TEST_F(CalculatorTest, sum) {

  Calculator calculator;

  EXPECT_EQ(calculator.sum(1, 1), 2);
}

TEST_F(CalculatorTest, minus) {
  Calculator calculator;

  EXPECT_EQ(calculator.minus(4, 2), 2);
}

TEST_F(CalculatorTest, divide) {
  Calculator calculator;

  EXPECT_EQ(calculator.divide(10, 2), 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
