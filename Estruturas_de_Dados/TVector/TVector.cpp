#include "TVector.h"

TVector::TVector()
{
    this->x = 0;
    this->y = 0;
}

TVector::TVector(double x_, double y_)
{
    x = x_;
    y = y_;
}

TVector TVector::operator+ (TVector p) const
{
    return TVector(x + p.x, y + p.y);
}

TVector TVector::operator- (TVector p) const
{
    return TVector(x - p.x, y - p.y);
}

double TVector::operator* (TVector p) const
{
    return x * p.x + y * p.y;
}

TVector TVector::operator* (double scalar)  const
{
    return TVector(x * scalar, y * scalar);
}

double TVector::operator^ (TVector p)  const
{
    return x * p.y - y * p.x;
}

bool TVector::operator==(const TVector& p)
{
    return (isZero(x - p.x) && isZero(y - p.y));
}

bool TVector::isZero(double a)
{
    return std::abs(a) < eps;
}


