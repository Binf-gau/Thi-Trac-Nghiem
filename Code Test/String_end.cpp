// string::begin/end
#include <iostream>
#include <string>

int main ()
{
  std::string str ("Test string \f 7777");
  for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
    std::cout << *it;
  std::cout << '\n';
std::cout<<str.begin();
  return 0;
}
