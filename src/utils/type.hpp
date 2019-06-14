#ifndef TYPE_HPP
#define TYPE_HPP

template <typename T> struct tvec2;

template <typename T> tvec2<T> operator+(T a, tvec2<T> b);
template <typename T> tvec2<T> operator-(T a, tvec2<T> b);
template <typename T> tvec2<T> operator*(T a, tvec2<T> b);
template <typename T> tvec2<T> operator/(T a, tvec2<T> b);
template <typename T> tvec2<T> normalize (tvec2<T> v);

template <typename T> T length(tvec2<T> v);
template <typename T> T distance (tvec2<T> a, tvec2<T> b);

typedef tvec2 <char>          vec2b;
typedef tvec2 <int>           vec2i;
typedef tvec2 <float>         vec2f;
typedef tvec2 <double>        vec2d;
typedef tvec2 <unsigned int>  vec2ui;
typedef tvec2 <unsigned char> vec2ub;

#endif