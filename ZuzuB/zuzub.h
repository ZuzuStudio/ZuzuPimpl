#ifndef ZUZUB_H
#define ZUZUB_H


class ZuzuB
{
   public:
      ZuzuB(int x);
      ZuzuB(const ZuzuB &original);
      ZuzuB &operator=(const ZuzuB &right);
      ~ZuzuB();

      ZuzuB foo()const;
   protected:
      char getC()const;
      double *getD()const;
   private:
      class ImZuzu;
      ImZuzu *pimpl;
      ZuzuB(const ImZuzu &original);
};

#endif // ZUZUB_H
