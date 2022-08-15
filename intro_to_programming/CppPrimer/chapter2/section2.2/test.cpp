#include <iostream>

int reused =33;
int main() {
  std::cout << reused << std::endl;
  int reused = 22;
  std::cout << reused << std::endl;
  std::cout << ::reused << std::endl;
  return 0;
}
