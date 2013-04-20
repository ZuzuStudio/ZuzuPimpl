#include <iostream>
#include "zuzub.h"
using namespace std;

class ConZuzu: private ZuzuB
{
   public:
      ConZuzu(int x);
      ConZuzu(const ConZuzu &original);
      ConZuzu &operator=(const ConZuzu &right);
      ~ConZuzu();

      ConZuzu foo()const;

      friend ostream &operator<<(ostream &out, const ConZuzu &b);
   private:
      ConZuzu(const ZuzuB &original);
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
   ZuzuB(x)
{

}

ConZuzu::ConZuzu(const ConZuzu &original):
   ZuzuB(original)
{

}

ConZuzu::ConZuzu(const ZuzuB &original):
   ZuzuB(original)
{

}

ConZuzu &ConZuzu::operator=(const ConZuzu &right)
{
   ZuzuB::operator=(right);
   return *this;
}

ConZuzu::~ConZuzu()
{
   //пасля гэтага дэструктара аўтаматычна вызываецца дэструктар продка
}

ConZuzu ConZuzu::foo()const
{
   return ConZuzu(ZuzuB::foo());
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
