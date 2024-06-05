#include <iostream>
int main() {
int i{0};
while (i < 2) {
for (int j{0}; j < 2; ++j) {
std::cout << i << j;
}
++i;
}
return 0;
}