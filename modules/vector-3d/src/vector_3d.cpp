// Copyright 2019 Tolstikov Maksim

#include "include/vector_3d.h"

#include <stdbool.h>
#include <string>
#include <limits>
#include <cmath>

Vector3d::Vector3d() : x_(0), y_(0), z_(0) {}

Vector3d::Vector3d(const double x, const double y, const double z) : x_(x), y_(y), z_(z) {}

Vector3d::Vector3d(const Vector3d& v) : x_(v.getX()), y_(v.getY()), z_(v.getZ()) {}

Vector3d& Vector3d::operator=(const Vector3d& v) {
    x_ = v.getX();
    y_ = v.getY();
    z_ = v.getZ();

    return *this;
}

double Vector3d::getX() const {
    return x_;
}

double Vector3d::getY() const {
    return y_;
}

double Vector3d::getZ() const {
    return z_;
}

void Vector3d::setX(const double x) {
    x_ = x;
}

void Vector3d::setY(const double y) {
    y_ = y;
}

void Vector3d::setZ(const double z) {
    z_ = z;
}

Vector3d Vector3d::operator+(const Vector3d& v) const {
    Vector3d sum;

    sum.setX(this->getX() + v.getX());
    sum.setY(this->getY() + v.getY());
    sum.setZ(this->getZ() + v.getZ());

    return sum;
}

Vector3d Vector3d::operator-(const Vector3d& v) const {
    Vector3d difference;

    difference.setX(this->getX() - v.getX());
    difference.setY(this->getY() - v.getY());
    difference.setZ(this->getZ() - v.getZ());

    return difference;
}

Vector3d Vector3d::operator*(const double& d) const {
    Vector3d multiplication;

    multiplication.setX(this->getX() * d);
    multiplication.setY(this->getY() * d);
    multiplication.setZ(this->getZ() * d);

    return multiplication;
}

Vector3d Vector3d::operator/(const double& d) const {
    Vector3d division;

    if (d == 0.0) {
        throw std::string("Can't divide by zero");
    } else {
        division.setX(this->getX() / d);
        division.setY(this->getY() / d);
        division.setZ(this->getZ() / d);
    }

    return division;
}

double Vector3d::operator*(const Vector3d& v) const {
    return this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * v.getZ();
}

Vector3d Vector3d::cross(const Vector3d& v) const {
    Vector3d multiplication_v;

    multiplication_v.setX(this->getY() * v.getZ() - this->getZ() * v.getY());
    multiplication_v.setY(this->getZ() * v.getX() - this->getX() * v.getZ());
    multiplication_v.setZ(this->getX() * v.getY() - this->getY() * v.getX());

    return multiplication_v;
}

double Vector3d::norma() const {
    return sqrt(*this * *this);
}

Vector3d Vector3d::normalize() const {
    Vector3d normal;
    double Norm = this->norma();

    if (Norm > 0) {
        normal.setX(this->getX() / Norm);
        normal.setY(this->getY() / Norm);
        normal.setZ(this->getZ() / Norm);
    }
    else {
        throw std::string("Can't find norma");
    }

    return normal;
}

bool Vector3d::operator == (const Vector3d& v) const {
    if ((this->getX() == v.getX()) && (this->getY() == v.getY()) && (this->getZ() == v.getZ())) {
        return true;
    }
    else {
        return false;
    }
}

bool Vector3d::operator != (const Vector3d& v) const {
    return !(*this == v);
}
