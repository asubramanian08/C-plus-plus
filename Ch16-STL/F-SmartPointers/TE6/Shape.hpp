#include <memory>
#include <string>
struct Shape
{
    int sides;
    bool isRegular;
    Shape(int sides = -1, bool isRegular = false) : sides(sides), isRegular(isRegular) {}
};
struct Triangle : public Shape
{
    double s1, s2, s3;
    Triangle(double s1 = 1, double s2 = 1, double s3 = 1)
        : Shape(3, s1 == s2 && s2 == s3), s1(s1), s2(s2), s3(s3) {}
};
struct Ellipse : public Shape
{
    double major, minor;
    Ellipse(double major = 1, double minor = 1)
        : Shape(0, major == minor), major(major), minor(minor) {}
};
struct Quadrilateral : public Shape
{
    double width, height;
    Quadrilateral(double width = 1, double height = 1)
        : Shape(4, width == height), width(width), height(height) {}
};

std::unique_ptr<Shape> MakeShape(std::string shape)
{
    if (shape == "Triangle")
        return std::make_unique<Triangle>();
    if (shape == "Ellipse")
        return std::make_unique<Ellipse>();
    if (shape == "Quadrilateral")
        return std::make_unique<Quadrilateral>();
    return std::make_unique<Shape>();
}