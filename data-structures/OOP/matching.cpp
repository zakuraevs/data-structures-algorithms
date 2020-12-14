#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

// The interface which cannot be instantiated.
class Shape {
  public:
    virtual int GetArea() = 0;  
};

// Rectangle class which overrides the abstract fucntion GetArea().
class Rectangle : public Shape {
  private:
    int height_, width_;  
    
  public:
    Rectangle() {
        height_ = 0;
        width_ = 0;
    }
  
    Rectangle(int& height, int& width) {
        // Checking for invalid input.
        if(height < 0 || width < 0) throw std::invalid_argument("Please use a positive value");
        height_ = height;
        width_ = width;
    }  
    
    // These methods allow access to private members from outside the class.
    int GetHeight() { return height_; }
    
    int GetWidth() { return width_; }
    
    virtual int GetArea() override { return GetHeight() * GetWidth(); }
};

/* 
* Both Rectangle and Triangle share similar methods.
* Because of this, a common ancestor such as Polygon would make sense.
* This does not compile with the current HackerRank test, but might make sense in practice.
* The Triangle class is extremely similar to a REctangle. The difference is in GetArea().
*/
class Triangle : public Shape {
  private:
    int height_, width_;  
    
  public:
    Triangle() {
        height_ = 0;
        width_ = 0;
    }
  
    Triangle(int& height, int& width) {
        if(height < 0 || width < 0) throw std::invalid_argument("Please use a positive value");
        height_ = height;
        width_ = width;
    }  
    
    int GetHeight() { return height_; }
    
    int GetWidth() { return width_; }
  
    virtual int GetArea() override { return (GetHeight() * GetWidth()) / 2; }
};

/* 
*Similar to the other 2 classes, but the private member is different.
* This class could inherit from ConicSection for example.
* Otherwise the implementation is similar to the above 2 classes.
*/
class Circle : public Shape {
  private:
    int radius_;
    
  public:
    Circle() {
        radius_ = 0;
    }
    
    Circle(int& radius) { 
        if(radius < 0) throw std::invalid_argument("Please use a positive value");
        radius_ = radius; 
    }
    
    int GetRadius() { return radius_; }
    
    virtual int GetArea() override { 
        // Rounding to an integer in the end.
        int area = (int)(3.14 * GetRadius() * GetRadius() + 0.5);
        return area; 
    }
};


int main() {
    int rectangleHeight = 0, rectangleWidth = 0;
    int triangleHeight = 0, triangleWidth = 0;
    int circleRadius = 0;
    
    std::cin >> rectangleHeight >> rectangleWidth >> triangleHeight >> triangleWidth >> circleRadius;

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Rectangle>(rectangleHeight, rectangleWidth));
    shapes.emplace_back(std::make_unique<Triangle>(triangleHeight, triangleWidth));
    shapes.emplace_back(std::make_unique<Circle>(circleRadius));

    const int totalArea = std::accumulate(shapes.begin(), shapes.end(), 0, [](int total, const auto& shape)
            { return total + shape->GetArea(); });
    std::cout << totalArea << "\n";

    return 0;
}