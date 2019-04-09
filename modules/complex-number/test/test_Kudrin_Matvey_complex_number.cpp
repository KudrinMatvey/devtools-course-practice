// Copyright 2017 Kudrin Matvey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kudrin_Matvey_ComplexNumberTest, Test_Multiply_Commutativity) {
    // Arrange
    int random_number = 576467547;
    double re = random_number / 1000.0;
    double im = random_number / 5000.0;
    double re1 = random_number / 1234.0;
    double im1 = random_number / 5234.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    // Assert
    EXPECT_EQ(z1 * z, z * z1);
}

TEST(Kudrin_Matvey_ComplexNumberTest, Test_Throw_If_Divided_By_Zero) {
    // Arrange
    double re = 1.0;
    double im = 50.0;
    double re1 = 0.0;
    double im1 = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber zero(re1, im1);
    ComplexNumber result;

    // Assert
    try {
        result = z / zero;
        FAIL();
    }
    catch (...) {}
}

TEST(Kudrin_Matvey_ComplexNumberTest, Test_Multiplied_By_Zero_Equals_To_Zero) {
    // Arrange
    double re = 1.0;
    double im = 50.0;
    double re1 = 0.0;
    double im1 = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber zero(re1, im1);
    ComplexNumber result;

    // Assert
    result = z * zero;
    ASSERT_EQ(result, zero);
}

TEST(Kudrin_Matvey_ComplexNumberTest, Test_Multiplied_By_One_Equals_To_Itself) {
    // Arrange
    double re = 1.0;
    double im = 50.0;
    double re1 = 1.0;
    double im1 = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber one(re1, im1);
    ComplexNumber result;

    // Assert
    result = z * one;
    ASSERT_EQ(result, z);
}
