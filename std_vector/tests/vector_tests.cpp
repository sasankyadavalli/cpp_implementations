#include <gtest/gtest.h>
#include "vector.hpp"


TEST(VECTOR, SwapEmptyVectors) {
    // By empty vectors we mean only size = 0, but they have capacity
    Vector<int> a(2);
    Vector<int> b(10);

    swap(a, b);

    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(a.capacity(), 10);
    EXPECT_EQ(b.capacity(), 2);

}

TEST(Vector, SwapSelf) {
    Vector<int> a(10);
    swap(a, a);

    a.push_back(1);
    a.push_back(2);

    ASSERT_EQ(a.size(), 2);
    EXPECT_EQ(a.capacity(), 10);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);

}
TEST(Vector, SwapDifferentCapacities) {
    Vector<int> a(2);
    Vector<int> b(10);

    swap(a, b);

    ASSERT_EQ(a.capacity(), 10);
    ASSERT_EQ(b.capacity(), 2);
}
TEST(Vector, SwapDifferentSizes){
    Vector<int> a(5);
    Vector<int> b(4);
    a.push_back(1);
    a.push_back(2);
    b.push_back(10);
    b.push_back(12);
    b.push_back(13);

    swap(a, b);

    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(b.size(), 2);
    EXPECT_EQ(a.capacity(), 4);
    EXPECT_EQ(b.capacity(), 5);
    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(a[1], 12);
    EXPECT_EQ(a[2], 13);
    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 2);
}
TEST(Vector, SwapEmptyWithNonEmpty){
    Vector<int> a(5);
    Vector<int> b(2);
    a.push_back(1);
    a.push_back(2);

    swap(a, b);

    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 2);
    EXPECT_EQ(a.capacity(), 2);
    EXPECT_EQ(b.capacity(), 5);
    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 2);
}