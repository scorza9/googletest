#include <gtest/gtest.h>
#include <climits>


int add(int a, int b) {
  return a + b;
}

bool IsEven(int number) {
    return (number % 2) == 0;
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


// MyString class
class MyString {
private:
    char* buffer_;
    int size_;

public:
    explicit MyString(const char* str) {
        size_ = strlen(str);
        buffer_ = new char[size_ + 1];
        strcpy(buffer_, str);
    }

    ~MyString() {
        delete[] buffer_;
    }

    int Length() const {
        return size_;
    }

    const char* GetString() const {
        return buffer_;
    }
};

// Test fixture
class MyStringTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup steps you need to perform before each test
    }

    void TearDown() override {
        // Any teardown steps you need to perform after each test
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

TEST(IsEvenTest, PositiveNumbers) {
    EXPECT_TRUE(IsEven(2));
    EXPECT_TRUE(IsEven(10));
    EXPECT_TRUE(IsEven(100));
}

TEST(IsEvenTest, NegativeNumbers) {
    EXPECT_TRUE(IsEven(-2));
    EXPECT_TRUE(IsEven(-10));
    EXPECT_TRUE(IsEven(-100));
}

TEST(IsEvenTest, Zero) {
    EXPECT_TRUE(IsEven(0));
}

TEST(IsEvenTest, OddNumbers) {
    EXPECT_FALSE(IsEven(1));
    EXPECT_FALSE(IsEven(3));
    EXPECT_FALSE(IsEven(11));
}

TEST_F(MyStringTest, Length) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.Length(), 13);
}

TEST_F(MyStringTest, GetString) {
    MyString str("Hello, World!");
    EXPECT_STREQ(str.GetString(), "Hello, World!");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
