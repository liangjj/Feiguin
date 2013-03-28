#ifndef __DMTK_TENSOR_H__
#define __DMTK_TENSOR_H__

#include <iosfwd>
#include "range.h"
#include "slice_iter.h"
#include "gslice_iter.h"
#include "vector.h"

using namespace std;

namespace dmtk
{

#include "meta.h"

template <class T>
class Tensor: public Vector<T>
{
  private:
    size_t _d1; 
    size_t _d2; 
    size_t _d3; 
    size_t _d4; 
  public:

    Tensor(): _d1(1), _d2(1), _d3(1), _d4(1) {}
    Tensor(size_t d1, size_t d2, size_t d3, size_t d4): _d1(d1), _d2(d2), _d3(d3), _d4(d4), Vector<T>(d1*d2*d3*d4) {}
    Tensor(const Vector<T> &v): Vector<T>(v) {}
    Tensor(const Tensor<T>& v): _d1(v.d1()), _d2(v.d2()), _d3(v.d3()), _d4(v.d4()), Vector<T>(v) {}

    Tensor& operator=(const T& v)
      { Vector<T>::operator=(v); return *this; }
    
    Tensor& operator=(const Tensor<T>& v)
      { Vector<T>::operator=(v); _d1 = v.d1(); _d2 = v.d2(); _d3 = v.d3(); _d4 = v.d4(); return *this; }

    Tensor& operator=(const Vector<T>& v)
      { Vector<T>::operator=(v); return *this; };

    template<class Expr>
    Tensor& operator=(const IterExpr<T,Expr>& exp)
      { Vector<T>::operator=(exp); return *this; }

    Tensor& operator+=(const Tensor<T> &v)
      { Vector<T>::operator+=(v); return *this; }
    Tensor& operator-=(const Tensor<T> &v)
      { Vector<T>::operator-=(v); return *this; }
    Tensor& operator*=(const Tensor<T> &v)
      { Vector<T>::operator*=(v); return *this; }
    Tensor& operator/=(const Tensor<T> &v)
      { Vector<T>::operator/=(v); return *this; }

    Tensor& operator+=(const T &v)
      { Vector<T>::operator+=(v); return *this; }
    Tensor& operator-=(const T &v)
      { Vector<T>::operator-=(v); return *this; }
    Tensor& operator*=(const T &v)
      { Vector<T>::operator*=(v); return *this; }
    Tensor& operator/=(const T &v)
      { Vector<T>::operator/=(v); return *this; }

    template<class Expr>
    Tensor& operator+=(const IterExpr<T,Expr>&exp)
      { Vector<T>::operator+=(exp); return *this; }
    template<class Expr>
    Tensor& operator-=(const IterExpr<T,Expr>&exp)
      { Vector<T>::operator-=(exp); return *this; }
    template<class Expr>
    Tensor& operator*=(const IterExpr<T,Expr>&exp)
      { Vector<T>::operator*=(exp); return *this; }
    template<class Expr>
    Tensor& operator/=(const IterExpr<T,Expr>&exp)
      { Vector<T>::operator/=(exp); return *this; }

    T& operator[](size_t i)
      { return Vector<T>::operator[](i); }

    T operator[](size_t i) const
      { return Vector<T>::operator[](i); }

    T& operator()(size_t i)
      { return Vector<T>::operator[](i); }

    T operator()(size_t i) const
      { return Vector<T>::operator[](i); }

    size_t d1() const { return _d1; }
    size_t d2() const { return _d2; }
    size_t d3() const { return _d3; }
    size_t d4() const { return _d4; }

    T& operator()(size_t i1, size_t i2, size_t i3, size_t i4)
      {
        return Vector<T>::operator[](i1*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+i4);
      }

    T operator()(size_t i1, size_t i2, size_t i3, size_t i4) const
      {
        return Vector<T>::operator[](i1*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+i4);
      }

    T& operator()(size_t i1, size_t i2, size_t i3, size_t i4, int mask)
      {
        if(mask & MASK_BLOCK1 && mask & MASK_BLOCK2)
          return operator()(i1,i2,i3,i4);
        else if(mask & MASK_BLOCK2 && mask & MASK_BLOCK3)
          return operator()(i3,i1,i2,i4);
        else if(mask & MASK_BLOCK3 && mask & MASK_BLOCK4)
          return operator()(i3,i4,i1,i2);
      }

    Tensor& resize(size_t d1, size_t d2, size_t d3, size_t d4) 
      { 
         Vector<T>::resize(d1*d2*d3*d4);
         _d1 = d1; _d2 = d2; _d3 = d3; _d4 = d4;
         return *this;
      } 

    Tensor& condense(size_t mask)
      {
         if(mask == (MASK_BLOCK1|MASK_BLOCK2)){
           resize(_d1*_d2,1,_d3,_d4);
         } else if (mask == (MASK_BLOCK2|MASK_BLOCK3)){
           resize(_d1,_d2*_d3,1,_d4);
         } else if (mask == (MASK_BLOCK3|MASK_BLOCK4)){
           resize(_d1,_d2,1,_d3*_d4);
         }
         return *this;
      }

    Tensor& decondense(const Tensor & orig)
      {
         resize(orig.d1(),orig.d2(),orig.d3(),orig.d4());
         return *this;
      }

// Slices

    gslice_iter<T> operator()(size_t i1, size_t i2, Range r3, Range r4);
    cgslice_iter<T> operator()(size_t i1, size_t i2, Range r3, Range r4) const;
    gslice_iter<T> operator()(size_t i1, Range r2, size_t i3, Range r4);
    cgslice_iter<T> operator()(size_t i1, Range r2, size_t i3, Range r4) const;
    gslice_iter<T> operator()(Range r1, size_t i2, size_t i3, Range r4);
    cgslice_iter<T> operator()(Range r1, size_t i2, size_t i3, Range r4) const;

    gslice_iter<T> operator()(size_t i1, Range r2, Range r3, size_t i4);
    cgslice_iter<T> operator()(size_t i1, Range r2, Range r3, size_t i4) const;
    gslice_iter<T> operator()(Range r1, size_t i2, Range r3, size_t i4);
    cgslice_iter<T> operator()(Range r1, size_t i2, Range r3, size_t i4) const;
    gslice_iter<T> operator()(Range r1, Range r2, size_t i3, size_t i4);
    cgslice_iter<T> operator()(Range r1, Range r2, size_t i3, size_t i4) const;

    slice_iter<T> operator()(size_t i1, size_t i2, size_t i3, Range r4);
    cslice_iter<T> operator()(size_t i1, size_t i2, size_t i3, Range r4) const;
    slice_iter<T> operator()(size_t i1, size_t i2, Range r3, size_t i4);
    cslice_iter<T> operator()(size_t i1, size_t i2, Range r3, size_t i4) const;
    slice_iter<T> operator()(size_t i1, Range r2, size_t i3, size_t i4);
    cslice_iter<T> operator()(size_t i1, Range r2, size_t i3, size_t i4) const;
    slice_iter<T> operator()(Range r1, size_t i2, size_t i3, size_t i4);
    cslice_iter<T> operator()(Range r1, size_t i2, size_t i3, size_t i4) const;


//  Streams

    void write(std::ostream &s) const
    {
      Vector<T>::write(s);
    }

    void read(std::istream &s) 
    {
      Vector<T>::read(s);
    }

};


////////////////////////////////////////////////////////
template<class T>
gslice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, Range r3, Range r4)
{
  slice s3(i1*_d2*_d3*_d4+i2*_d3*_d4+r3.start()*_d4,r3.size(),r3.stride()*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return gslice_iter<T>(this, s3, s4);
}

template<class T>
gslice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, Range r3, size_t i4)
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4,r2.size(),r2.stride()*_d3*_d4);
  slice s3(r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return gslice_iter<T>(this, s2, s3);
}

template<class T>
gslice_iter<T>
Tensor<T>::operator()(Range r1, Range r2, size_t i3, size_t i4)
{
  slice s1(r1.start()*_d2*_d3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s2(r2.start()*_d3*_d4+i3*_d4+i4,r2.size(),r2.stride()*_d3*_d4);
  return gslice_iter<T>(this, s1, s2);
}

template<class T>
gslice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, size_t i3, Range r4)
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4+i3*_d4,r2.size(),r2.stride()*_d3*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return gslice_iter<T>(this, s2, s4);
}

template<class T>
gslice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, size_t i3, Range r4)
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return gslice_iter<T>(this, s1, s4);
}

template<class T>
gslice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, Range r3, size_t i4)
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s3(r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return gslice_iter<T>(this, s1, s3);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, Range r3, Range r4) const
{
  slice s3(i1*_d2*_d3*_d4+i2*_d3*_d4+r3.start()*_d4,r3.size(),r3.stride()*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return cgslice_iter<T>(this, s3, s4);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, Range r3, size_t i4) const
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4,r2.size(),r2.stride()*_d3*_d4);
  slice s3(r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return cgslice_iter<T>(this, s2, s3);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, size_t i3, Range r4) const
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4+i3*_d4,r2.size(),r2.stride()*_d3*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return cgslice_iter<T>(this, s2, s4);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(Range r1, Range r2, size_t i3, size_t i4) const
{
  slice s1(r1.start()*_d2*_d3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s2(r2.start()*_d3*_d4+i3*_d4+i4,r2.size(),r2.stride()*_d3*_d4);
  return cgslice_iter<T>(this, s1, s2);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, size_t i3, Range r4) const
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s4(r4.start(),r4.size(),r4.stride());
  return cgslice_iter<T>(this, s1, s4);
}

template<class T>
cgslice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, Range r3, size_t i4) const
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4,r1.size(),r1.stride()*_d2*_d3*_d4);
  slice s3(r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return cgslice_iter<T>(this, s1, s3);
}

////////////////////////////////////////////////////////

template<class T>
slice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, size_t i3, Range r4)
{
  slice s4(i1*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+r4.start(),r4.size(),r4.stride());
  return slice_iter<T>(this, s4);
}

template<class T>
slice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, Range r3, size_t i4)
{
  slice s3(i1*_d2*_d3*_d4+i2*_d3*_d4+r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return slice_iter<T>(this, s3);
}

template<class T>
slice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, size_t i3, size_t i4)
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4+i3*_d4+i4,r2.size(),r2.stride()*_d3*_d4);
  return slice_iter<T>(this, s2);
}

template<class T>
slice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, size_t i3, size_t i4)
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+i4,r1.size(),r1.stride()*_d2*_d3*_d4);
  return slice_iter<T>(this, s1);
}

template<class T>
cslice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, size_t i3, Range r4) const
{
  slice s4(i1*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+r4.start(),r4.size(),r4.stride());
  return cslice_iter<T>(this, s4);
}

template<class T>
cslice_iter<T>
Tensor<T>::operator()(size_t i1, size_t i2, Range r3, size_t i4) const
{
  slice s3(i1*_d2*_d3*_d4+i2*_d3*_d4+r3.start()*_d4+i4,r3.size(),r3.stride()*_d4);
  return cslice_iter<T>(this, s3);
}

template<class T>
cslice_iter<T>
Tensor<T>::operator()(size_t i1, Range r2, size_t i3, size_t i4) const
{
  slice s2(i1*_d2*_d3*_d4+r2.start()*_d3*_d4+i3*_d4+i4,r2.size(),r2.stride()*_d3*_d4);
  return cslice_iter<T>(this, s2);
}

template<class T>
cslice_iter<T>
Tensor<T>::operator()(Range r1, size_t i2, size_t i3, size_t i4) const
{
  slice s1(r1.start()*_d2*_d3*_d4+i2*_d3*_d4+i3*_d4+i4,r1.size(),r1.stride()*_d2*_d3*_d4);
  return cslice_iter<T>(this, s1);
}




////////////////////////////////////////////////////////
} // namespace dmtk

#endif // __DMTK_TENSOR_H__
