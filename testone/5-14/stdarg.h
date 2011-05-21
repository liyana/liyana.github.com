#ifndef __STDARG_H__

#define __STDARG_H__

typedef char *va_list;

#define va_arg(ap,T)    \
        (*(T*)(((ap) += _Bnd(T,3U)) - _Bnd(T,3U)))

#define va_end(ap) (void)0

#define va_start(ap,A)   \
      (void)((ap) =(char *)&(A) + _Bnd(A,3U))

#define  _Bnd(X,bnd)   (sizeof (X) +(bnd) & ~(bnd))

#endif
