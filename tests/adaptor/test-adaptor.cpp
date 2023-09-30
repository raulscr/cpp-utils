#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE query_builder


#include <boost/test/unit_test.hpp>

#include <adaptor/Adaptor.h>

using utils::adaptor::Adaptor;

struct Square {
    int side{ 0 };

    explicit Square(const int side)
        : side(side){
    }

    int area() const {
        return side * side;
    }
};

struct Rectangle {
    int area() const {
        return width() * height();
    }

    int width() const {
        return _width;
    }

    int height() const {
        return _height;
    }

    int _width;
    int _height;
};


class SquareToRectangleAdapter : public Adaptor<Square, Rectangle> {
public:
    explicit SquareToRectangleAdapter(const Square& square) :
        Adaptor<Square, Rectangle>(from(square)){
    }

    Rectangle& from(const Square& square){
        this->_width  = square.side;
        this->_height = square.side;
        return *this;
    }
};

BOOST_AUTO_TEST_CASE(AdaptorTest){
    Square square{ 5 };


    Rectangle rectangle{ SquareToRectangleAdapter(square) };

    BOOST_CHECK_EQUAL(square.area(), 25);
    BOOST_CHECK_EQUAL(rectangle.area(), 25);
}
