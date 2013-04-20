#include "zuzua.h"

class ZuzuA::ImZuzu
{
   public:
      ImZuzu(int x, char y);
      ImZuzu(const ImZuzu &original);
      ImZuzu &operator=(const ImZuzu &right);
      ~ImZuzu();

      int foo()const;
      char getC()const;
      double *getD()const;
   private:
      char a;
      double *b;
};

ZuzuA::ZuzuA(int x):
   pimpl(0)
{
   pimpl = new ImZuzu(x, (char)(x + 0x30));
}

ZuzuA::ZuzuA(const ZuzuA &original):
   pimpl(0)
{
   pimpl = new ImZuzu(*(original.pimpl));
}

ZuzuA &ZuzuA::operator=(const ZuzuA &right)
{
   *(this->pimpl) = *(right.pimpl);
   return *this;
}

ZuzuA::~ZuzuA()
{
   delete pimpl;
   pimpl = 0;
}

int ZuzuA::foo()const
{
   return pimpl->foo();
}

char ZuzuA::getC()const
{
   return pimpl->getC();
}

double *ZuzuA::getD()const
{
   return pimpl->getD();
}

//=======================================

ZuzuA::ImZuzu::ImZuzu(int x, char y):
   a(y),
   b(0)
{
   b = new double;
   *b = (double)(x * y);
}

ZuzuA::ImZuzu::ImZuzu(const ImZuzu &original):
   a(original.a),
   b(0)
{
   b = new double;
   *b = *(original.b);
}

ZuzuA::ImZuzu &ZuzuA::ImZuzu::operator=(const ImZuzu &right)
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

ZuzuA::ImZuzu::~ImZuzu()
{
   a = '\0';
   *b = 0.0;
   delete b;
   b = 0;
}

int ZuzuA::ImZuzu::foo()const
{
   return (int)(*b - (double)a);
}

char ZuzuA::ImZuzu::getC()const
{
   return a;
}

double *ZuzuA::ImZuzu::getD()const
{
   return b;
}
