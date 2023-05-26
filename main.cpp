#include <gtest/gtest.h>
#include <climits>

// Sample function to test1
int add(int a, int b) {
  return a + b;
}

// Test class
class AddTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Add any setup code if needed
  }

  void TearDown() override {
    // Add any teardown code if needed
  }
};



// Test cases
// Testing addition of positive numbers
TEST_F(AddTest, PositiveNumbers) {
  EXPECT_EQ(add(3, 4), 7);
  EXPECT_EQ(add(10, 20), 30);
}

// Testing addition of negative numbers
TEST_F(AddTest, NegativeNumbers) {
  EXPECT_EQ(add(-3, -4), -7);
  EXPECT_EQ(add(-10, -20), -30);
}

// Testing addition of mixed (positive and negative) numbers
TEST_F(AddTest, MixedNumbers) {
  EXPECT_EQ(add(3, -4), -1);
  EXPECT_EQ(add(-10, 20), 10);
}

// Testing addition with zero
TEST_F(AddTest, Zero) {
  EXPECT_EQ(add(0, 5), 5);
  EXPECT_EQ(add(-5, 0), -5);
}

// Testing addition with the same number
TEST_F(AddTest, SameNumber) {
  EXPECT_EQ(add(5, 5), 10);
  EXPECT_EQ(add(-5, -5), -10);
}

// Testing addition with min and max integer values
TEST_F(AddTest, MinMaxIntegers) {
  EXPECT_EQ(add(INT_MAX, 0), INT_MAX);
  EXPECT_EQ(add(INT_MIN, 0), INT_MIN);
  EXPECT_EQ(add(INT_MAX, INT_MIN), -1);
}

// Testing addition with overflow and underflow
TEST_F(AddTest, OverflowUnderflow) {
  EXPECT_EQ(add(INT_MAX, 1), INT_MIN);
  EXPECT_EQ(add(INT_MIN, -1), INT_MAX);
}

// Testing addition with reverse order of numbers
TEST_F(AddTest, ReverseOrder) {
  EXPECT_EQ(add(4, 3), 7);
  EXPECT_EQ(add(20, 10), 30);
  EXPECT_EQ(add(-4, -3), -7);
  EXPECT_EQ(add(20, -10), 10);
}
// Testing the Increment() method
// TEST_F(Counter, Increment) {
//  Counter c;
//  EXPECT_EQ(0, c.Decrement());
//  EXPECT_EQ(0, c.Increment());
//  EXPECT_EQ(1, c.Increment());
//  EXPECT_EQ(2, c.Increment());
//  EXPECT_EQ(3, c.Decrement());
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
