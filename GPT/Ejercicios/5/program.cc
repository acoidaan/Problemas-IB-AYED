#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;

bool is_balanced(const string& expression) {
  stack_v_t<char> stack;
  for (int i = 0; i < expression.size(); i++) {
    if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
      stack.push(expression[i]);
    } else {
      if (expression[i] == ')' && stack.top() != '(') return false;
      if (expression[i] == '}' && stack.top() != '{') return false;
      if (expression[i] == ']' && stack.top() != '[') return false;
      stack.pop();
    } 
  }
  return stack.empty();
}