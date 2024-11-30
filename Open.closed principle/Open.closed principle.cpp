#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};


class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};


class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};


class ShapeRenderer {
public:
    void render(const std::vector<std::shared_ptr<Shape>>& shapes) const {
        for (const auto& shape : shapes) {
            shape->draw(); 
        }
    }
};

int main() {
  std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Circle>());
    shapes.push_back(std::make_shared<Rectangle>());

    ShapeRenderer renderer;
    renderer.render(shapes);

    return 0;
}
