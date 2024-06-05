#include <iostream>

class Box {
 public:
  Box() : length_(0), breadth_(0), height_(0) {}
  Box(double length, double breadth, double height) : length_(length), breadth_(breadth), height_(height) {}
  bool operator==(const Box& other) const {
    return length_ == other.length_ && breadth_ == other.breadth_ && height_ == other.height_;
  }
  double length() const { return length_; }
  double breadth() const { return breadth_; }
  double height() const { return height_; }

  friend std::ostream& operator<<(std::ostream& os, const Box& box);
  friend std::istream& operator>>(std::istream& is, Box& box);
 private:
  double length_;
  double breadth_;
  double height_;
};

std::ostream& operator<<(std::ostream& os, const Box& box) {
    os << "Box(" << box.length() << ", " << box.breadth() << ", " << box.height() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Box& box) {
  is >> box.length_ >> box.breadth_ >> box.height_;
  return is;
}

int main() {
  Box box1;
  Box box2;

  std::cout << "Ingrese las dimensiones de la primera caja (largo ancho alto): ";
  std::cin >> box1;
  std::cout << "Ingrese las dimensiones de la segunda caja (largo ancho alto): ";
  std::cin >> box2;

  std::cout << box1 << std::endl;
  std::cout << box2 << std::endl;

  if (box1 == box2) {
    std::cout << "Las cajas son iguales." << std::endl;
  } else {
    std::cout << "Las cajas no son iguales." << std::endl;
  }
  return 0;
}