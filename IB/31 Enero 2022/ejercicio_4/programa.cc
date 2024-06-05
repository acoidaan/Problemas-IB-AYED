#include <iostream>
#include <string>
#include <sstream>
class Car {
 public:
  Car() : model_("Unkown"), plate_("Unkown"), kilometers_(0) {}
  Car(std::string model, std::string plate, int kilometers) : model_(model), plate_(plate), kilometers_(kilometers) {}


  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }

  friend std::ostream& operator<<(std::ostream& os, const Car& car);
  friend std::istream& operator>>(std::istream& is, Car& car);

  bool operator>(const Car& other);

  bool operator==(const Car& other) {
    return kilometers_ == other.kilometers_;
  }

 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};


  bool Car::operator>(const Car& other) {
    return kilometers_ > other.kilometers_;
  }

std::ostream& operator<<(std::ostream& os, const Car& car) {
  os << "Modelo: " << car.model() << " Matricula: " << car.plate() << " Kilometros: " << car.kilometers();
  return os; 
}

std::istream& operator>>(std::istream& is, Car& car) {
  std::string line;
  std::getline(is, line);

  std::istringstream iss(line);
  std::string kilometers_str;

  getline(iss, car.model_, ' ');
  std::string second_part;
  getline(iss, second_part, ' ');
  car.model_ += " " + second_part;

  iss >> car.plate_;

  iss >> kilometers_str;
  car.kilometers_ = std::stoi(kilometers_str);
}

int main() {
  std::cout << "Introduce los datos del primer vehiculo, (Modelo Matricula Kilometros): ";
  Car car1;
  std::cin >> car1;
  std::cout << "Introduce los datos del segundo vehiculo, (Modelo Matricula Kilometros): ";
  Car car2;
  std::cin >> car2;

  std::cout << std::endl;

  std::cout << "Primer coche: " << car1 << std::endl;
  std::cout << "Segundo coche: " << car2 << std::endl << std::endl;

  if (car1 > car2) {
    std::cout << "El primer vehiculo tiene mas kilometros que el segundo y aparece antes en la lista." << std::endl;
  } else if (car2 > car1) {
    std::cout << "El segundo vehiculo tiene mas kilometros que el primero y aparecera antes en la lista." << std::endl;
  } else if (car1 == car2) {
    std::cout << "Los coches tienen los mismos kilometros y apareceran en el mismo orden en la lista." << std::endl;
  }
  return 0;
}