#ifndef TYPE_HPP
#define TYPE_HPP

template <typename T> struct tvec2{
    T x, y;

    tvec2(void) = default;
    tvec2(T s): x(s), y(s) {}
    tvec2(T x, T y): x(x), y(y) {}

    void operator+=(tvec2<T> other){
        x += other.x;
        y += other.y;
    }

    void operator-=(tvec2<T> other){
        x -= other.x;
        y -= other.y;
    }

    void operator*=(tvec2<T> other){
        x *= other.x;
        y *= other.y;
    }

    void operator/=(tvec2<T> other){
        x /= other.x;
        y /= other.y;
    }

    tvec2<T> operator+(tvec2<T> other){
        return tvec2<T>(x + other.x, y + other.y);
    }

    tvec2<T> operator-(tvec2<T> other){
        return tvec2<T>(x - other.x, y - other.y);
    }

    tvec2<T> operator*(tvec2<T> other){
        return tvec2<T>(x * other.x, y * other.y);
    }

    tvec2<T> operator/(tvec2<T> other){
        return tvec2<T>(x / other.x, y / other.y);
    }

    tvec2<T> operator+(T other){
        return tvec2<T>(x + other, y + other);
    }

    tvec2<T> operator-(T other){
        return tvec2<T>(x - other, y - other);
    }

    tvec2<T> operator*(T other){
        return tvec2<T>(x * other, y * other);
    }

    tvec2<T> operator/(T other){
        return tvec2<T>(x / other, y / other);
    }
};

template <typename T>
tvec2<T> operator+(T a, tvec2<T> b)
{
    return tvec2<T>(a + b.x, a + b.y);
}

template <typename T>
tvec2<T> operator-(T a, tvec2<T> b)
{
    return tvec2<T>(a - b.x, a - b.y);
}

template <typename T>
tvec2<T> operator*(T a, tvec2<T> b)
{
    return tvec2<T>(a * b.x, a * b.y);
}

template <typename T>
tvec2<T> operator/(T a, tvec2<T> b)
{
    return tvec2<T>(a / b.x, a / b.y);
}

template <typename T>
T length(tvec2<T> v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

template <typename T>
tvec2<T> normalize (tvec2<T> v)
{
    return v / length(v);
}

template <typename T>
T distance (tvec2<T> a, tvec2<T> b)
{
    return length(a - b);
}

typedef tvec2<char>          vec2b;
typedef tvec2<int>           vec2i;
typedef tvec2<float>         vec2f;
typedef tvec2<double>        vec2d;
typedef tvec2<unsigned int>  vec2ui;
typedef tvec2<unsigned char> vec2ub;

#endif