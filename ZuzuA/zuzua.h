#ifndef ZUZUA_H
#define ZUZUA_H


class ZuzuA
{
   public:
      ZuzuA(int x);
      ZuzuA(const ZuzuA &original);
      ZuzuA &operator=(const ZuzuA &right);
      ~ZuzuA();

      int foo()const;
   protected:
      char getC()const;
      double *getD()const;
   private:
      class ImZuzu;
      ImZuzu *pimpl;
};

#endif // ZUZUA_H
