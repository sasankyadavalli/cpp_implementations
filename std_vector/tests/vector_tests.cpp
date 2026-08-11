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

/*
    RESERVE() function Test
*/


TEST(Vector, ReserveIncreaseCapacity) {
    Vector<int> a(6);

    a.reserve(10);

    ASSERT_EQ(a.capacity(), 10);
}

TEST(Vector, ReserveSmallerCapacity){
    Vector<int> a(5);

    a.reserve(3);

    ASSERT_EQ(a.capacity(), 5);

}

TEST(Vector, ReservePreservesElements) {
    Vector<int> a(3);

    a.push_back(1);
    a.push_back(2);

    a.reserve(10);

    ASSERT_EQ(a.capacity(), 10);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}

TEST(Vector, GrowWithInCapacity) {
    Vector<int> a(10);

    a.push_back(1);
    a.push_back(2);

    a.resize(6);
    ASSERT_EQ(a.size(), 6);
    EXPECT_EQ(a[2], 0);
    EXPECT_EQ(a[3], 0);
    EXPECT_EQ(a[4], 0);
    EXPECT_EQ(a[5], 0);
}
TEST(Vector, GrowBeyondCapacity) {
    Vector<int> a(3);
    
    a.push_back(1);
    a.push_back(2);
    
    ASSERT_EQ(a.capacity(), 3);
    
    a.resize(4);
    
    ASSERT_EQ(a.capacity(), 4);
    ASSERT_EQ(a.size(), 4);
    EXPECT_EQ(a[2], 0);
    EXPECT_EQ(a[3], 0);
}
TEST(Vector, ShinkSize) {
    Vector<int> a(5);
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    a.resize(2);
    
    ASSERT_EQ(a.capacity(), 5);
    ASSERT_EQ(a.size(), 2);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}
TEST(Vector, ResizeToZero) {
    Vector<int> a(3);
    
    a.push_back(1);
    a.push_back(2);
    
    a.resize(0);
    
    ASSERT_EQ(a.capacity(), 3);
    ASSERT_EQ(a.size(), 0);
    
}
TEST(Vector, ResizeToSameSize) {
    Vector<int> a(3);
    
    a.push_back(1);
    a.push_back(2);
    
    a.resize(2);
    
    ASSERT_EQ(a.capacity(), 3);
    ASSERT_EQ(a.size(), 2);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}

TEST(Vector, PopBackSingleElement) {
    Vector<int> a(4);

    a.push_back(1);
    a.push_back(2);

    a.pop_back();

    ASSERT_EQ(a.size(), 1);
    EXPECT_EQ(a[0], 1);
}

TEST(Vector, PopBackMultipleElements) {
    Vector<int> a(4);

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    a.pop_back();
    a.pop_back();

    ASSERT_EQ(a.size(), 2);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);

}

TEST(Vector, PopBackPreservesCapacity) {
    Vector<int> a(4);

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    a.pop_back();
    a.pop_back();

    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.capacity(), 4);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}

TEST(Vector, PopBackLeavesRemainingElementsIntact) {
    Vector<int> a(4);

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    a.pop_back();
    a.pop_back();

    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.capacity(), 4);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}

TEST(Vector, ClearElements) {
    Vector<int> a(4);

    a.push_back(1);
    a.push_back(2);

    a.clear();

    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 4);
}

TEST(Vector, IteratorTraversal) {
    Vector<int> a(6);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    int i = 0;
    for(auto it = a.begin(); it != a.end(); ++it) {
        EXPECT_EQ(*it, a[i]);
        i++;
    }
    ASSERT_EQ(a.size(), 4);
    ASSERT_EQ(a.capacity(), 6);    
}

TEST(Vector, RangeBasedFor)
{
    Vector<int> a(5);

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    int expected = 10;

    for (auto& x : a)
    {
        EXPECT_EQ(x, expected);
        expected += 10;
    }
}