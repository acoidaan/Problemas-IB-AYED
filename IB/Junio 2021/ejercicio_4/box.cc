#include <iostream>
using namespace std;

class Box {
 public:
  Box() : length_(0), breadth_(0), height_(0) {}
  Box(double length, double breadth, double height) : length_(length), breadth_(breadth), height_(height) {}
  double length() const { return length_; }
  double breadth() const { return breadth_; }
  double height() const { return height_; }

  bool operator==(const Box& other) {
    return length_ == other.length_ && breadth_ == other.breadth_ && height_ == other.height_;
  }

  friend ostream& operator<<(ostream& os, const Box& box);
  friend istream& operator>>(istream& is, Box& box);

 private:
  double length_;
  double breadth_;
  double height_;
};

ostream& operator<<(ostream& os, const Box& box) {
  os << "La caja mide(" << box.length() << 'x' << box.breadth() << 'x' << box.height() << ')' << endl; 
  return os;
}

istream& operator>>(istream& is, Box& box) {
  is >> box.length_ >> box.breadth_ >> box.height_;
  return is;
}

int main() {
  Box box1, box2;
  cin >> box1;
  cout << box1;
  cin >> box2;
  cout << box2;

  if (box1 == box2) cout << "son iguales" << endl;
  else cout << "no son iguales" << endl;
  return 0;
}
