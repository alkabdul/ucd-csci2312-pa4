#include <string>
#include "Exceptions.h"

void Gaming::GamingException::setName(std::string name) {
    __name = name;
}

Gaming::DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height) : GamingException(), __exp_width(expWidth), __exp_height(expHeight), __width(width), __height(height)
{
}

unsigned Gaming::DimensionEx::getExpWidth() const {
    return __exp_width;
}

unsigned Gaming::DimensionEx::getExpHeight() const {
    return __exp_width;
}

unsigned Gaming::DimensionEx::getWidth() const {
    return __width;
}

unsigned Gaming::DimensionEx::getHeight() const {
    return __height;
}

Gaming::InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height) : DimensionEx(minWidth,minHeight,width,height)
{
    setName("InsufficientDimensionsEx");
}

void Gaming::InsufficientDimensionsEx::__print_args(std::ostream &os) const {
    os << "Minimum Height: " << __exp_height << ", Minimum Width: " << __exp_width << ", Current Height: " << __height << ", Current Width: " << __width;
}

void Gaming::OutOfBoundsEx::__print_args(std::ostream &os) const {
    os << "Maximum Height: " << __exp_height << ", Maximum Width: " << __exp_width << ", Current Height: " << __height << ", Current Width: " << __width;
}

Gaming::OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height) : DimensionEx(maxWidth,maxHeight,width,height)
{
    setName("OutOfBoundsEx");
}

void Gaming::PositionEx::__print_args(std::ostream &os) const {
	os << "X-axis: " << __x << "Y-axis: " << __y ;
}

Gaming::PositionEx::PositionEx(unsigned x, unsigned y) {
	__x = x ;
	__y = y ;
	setName("PositionEx");
}

Gaming::PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y) : PositionEx(x,y)
{
	setName("PositionNonemptyEx");
}

Gaming::PositionEmptyEx::PositionEmptyEx(unsigned x , unsigned y) : PositionEx(x,y)
{
	setName("PositionEmptyEx");
}

Gaming::PosVectorEmptyEx::PosVectorEmptyEx() : GamingException()
{
	setName("PosVectorEmptyEx");
}

void Gaming::PosVectorEmptyEx::__print_args(std::ostream &os) const {
	os << "NoInformation about Variables" ; 
}

namespace Gaming {
    std::ostream &operator<<(std::ostream &os, const GamingException &ex) {
        os << ex.__name << ": ";
        ex.__print_args(os);
        return os;
    }
}
