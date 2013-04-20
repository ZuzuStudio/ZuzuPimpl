#include "zuzub.h"

class ZuzuB::ImZuzu
{
   public:
      ImZuzu(int x, char y);
      ImZuzu(const ImZuzu &original);
      ImZuzu &operator=(const ImZuzu &right);
      ~ImZuzu();

      ImZuzu foo()const;
      char getC()const;
      double *getD()const;
   private:
      char a;
      double *b;
};

ZuzuB::ZuzuB(int x):
   pimpl(0)
{
   pimpl = new ImZuzu(x, (char)(x + 0x30));
}

ZuzuB::ZuzuB(const ZuzuB &original):
   pimpl(0)
{
   pimpl = new ImZuzu(*(original.pimpl));
}

ZuzuB::ZuzuB(const ImZuzu &original):
   pimpl(0)
{
   pimpl = new ImZuzu(original);
}

ZuzuB &ZuzuB::operator=(const ZuzuB &right)
{
   *(this->pimpl) = *(right.pimpl);
   return *this;
}

ZuzuB::~ZuzuB()
{
   delete pimpl;
   pimpl = 0;
}

ZuzuB ZuzuB::foo()const
{
   return ZuzuB(pimpl->foo());
}

char ZuzuB::getC()const
{
   return pimpl->getC();
}

double *ZuzuB::getD()const
{
   return pimpl->getD();
}

//=======================================

ZuzuB::ImZuzu::ImZuzu(int x, char y):
   a(y),
   b(0)
{
   b = new double;
   *b = (double)(x * y);
}

ZuzuB::ImZuzu::ImZuzu(const ImZuzu &original):
   a(original.a),
   b(0)
{
   b = new double;
   *b = *(original.b);
}

ZuzuB::ImZuzu &ZuzuB::ImZuzu::operator=(const ImZuzu &right)
{
   if(this != &right)
   {
      delete b;
      b = 0;
      b = new double;
      *b = *(right.b);
      a = right.a;
   }

   return *this;
}

ZuzuB::ImZuzu::~ImZuzu()
{
   a = '\0';
   *b = 0.0;
   delete b;
   b = 0;
}

ZuzuB::ImZuzu ZuzuB::ImZuzu::foo()const
{
   return ImZuzu((int) * b + 2 * a, (char) * b);
}

char ZuzuB::ImZuzu::getC()const
{
   return a;
}

double *ZuzuB::ImZuzu::getD()const
{
   return b;
}
