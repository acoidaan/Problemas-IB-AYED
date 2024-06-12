#include <iostream>
using namespace std;

class Car {
 public:
  Car() : model_("unknown"), plate_("unknown"), kilometers_(0) {}
  Car(string model, string plate, int kilometers) : model_(model), plate_(plate), kilometers_(kilometers) {}
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }

  bool operator>(const Car& other) {
    return (kilometers_ > other.kilometers_);
  }

  friend ostream& operator<<(ostream& os, const Car& car);
  friend istream& operator>>(istream& is, Car& car);

 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

ostream& operator<<(ostream& os, const Car& car) {
  os << "Modelo: " << car.model() << endl << "Matricula: " << car.plate() << endl << "Kilometros: " << car.kilometers() << endl;
  return os;
}

istream& operator>>(istream& is, Car& car) {
  is >> car.model_ >> car.plate_ >> car.kilometers_;
  return is;
}

int main() {
  Car car1, car2;
  cin >> car1;
  cout << car1 << endl;
  cin >> car2;
  cout << car2 << endl;
  if (car1 > car2) cout << "el primer coche tiene mas kms" << endl;
  else cout << "el segundo coche tiene mas kms" << endl;
  return 0;
}