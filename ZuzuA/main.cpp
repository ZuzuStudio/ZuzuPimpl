#include <iostream>
#include "zuzua.h"
using namespace std;

class ConZuzu: public ZuzuA
{
   public:
      ConZuzu(int x);
      ConZuzu(const ConZuzu &original);
      ConZuzu &operator=(const ConZuzu &right);
      ~ConZuzu();

      friend ostream &operator<<(ostream &out, const ConZuzu &b);
};

int main()
{
   ConZuzu a(17), b(19);
   cout << a << endl << b << endl << a.foo() << endl;
   b = a;
   ConZuzu c(b);
   cout << c << endl;
   return 0;
}

ConZuzu::ConZuzu(int x):
   ZuzuA(x)
{

}

ConZuzu::ConZuzu(const ConZuzu &original):
   ZuzuA(original)
{

}

ConZuzu &ConZuzu::operator=(const ConZuzu &right)
{
   ZuzuA::operator=(right);
   return *this;
}

ConZuzu::~ConZuzu()
{
   //пасля гэтага дэструктара аўтаматычна вызываецца дэструктар продка
}

ostream &operator<<(ostream &out, const ConZuzu &b)
{
   char x = b.getC();
   double *y = b.getD();
   out.width(20);
   out.precision(5);
   out.fill(x);
   out << *y;
   return out;
}
