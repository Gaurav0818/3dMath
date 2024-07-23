#pragma once

#include <cmath>
#include <iostream>
#include <sstream>

class vec3;
class vec2;

class vec3
{
public:
    float x, y, z;

public:
    vec3() : x(0), y(0), z(0)  {}
    vec3(float a) : x(a), y(a), z(a) {}
    vec3(float e0, float e1, float e2) : x(e0), y(e1), z(e2) {}

    void fromString(const std::string& s, char comma = ',');

    vec3 operator-() const { return vec3(-x, -y, -z); }

    vec3& operator+=(const vec3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    vec3& operator-=(const vec3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    vec3& operator*=(const vec3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    vec3& operator/=(const vec3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    
    vec3& operator*=(const float t)
    {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }

    vec3& operator/=(const float t) {
        return *this *= 1 / t;
    }

    vec3& operator+=(const float t)
    {
        x += t;
        y += t;
        z += t;
        return *this;
    }

    vec3& operator-=(const float t)
    {
        x -= t;
        y -= t;
        z -= t;
        return *this;
    }

    //Get the length of a vector.
    float length() const 
    {
        return std::sqrt(length_squared());
    }

    float length_squared() const 
    {
        return x * x + y * y + z * z;
    }

    vec3 normalise() const
    {
        float l = length();
        return vec3(x / l, y / l, z / l);
    }

    void normalise() 
    {
        float l = length();
        x /= l;
        y /= l;
        z /= l;
    }

};

class vec2
{

public:
    float x, y;

public:

    vec2() : x(0), y(0) {};
    vec2(float a) : x(a), y(a) {};
    vec2(float a, float b) :x(a), y(b) {};

    void fromString(const std::string& s, char comma = ',');


    vec2& operator+=(float f)
    {
        x += f;
        y += f;
        return *this;
    }

    vec2& operator-=(float f)
    {
        x -= f;
        y -= f;
        return *this;
    }

    vec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    vec2& operator/=(float f)
    {
        x /= f;
        y /= f;
        return *this;
    }

    vec2& operator+=(vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    vec2& operator-=(vec2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    vec2& operator*=(vec2& v)
    {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    vec2& operator/=(vec2& v)
    {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    // Get the length of a vector.
    float length() const
    {
        return std::sqrt(length_squared());
    }

    float length_squared() const
    {
        return x * x + y * y;
    }

    vec2 normalise() const
    {
        float l = length();
        return vec2(x / l, y / l);
    }

    void normalise()
    {
        float l = length();
        x /= l;
        y /= l;
    }

    // Get the angle of a Vector in radians
    float rad() const
    {
        return std::atan2(y, x);
    }
};


// Type aliases for vec2
using point2 = vec2;// 2D point

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color3 = vec3;    // RGB color

//Utility Functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline std::ostream& operator<<(std::ostream& out, const vec2& v)
{
    return out << v.x << ' ' << v.y;
}

void ExtractVectorfromString(vec2& v, const std::string& s, char comma = ',')
{
    std::stringstream ss(s);
    float x, y;

    ss >> x >> comma >> y;

    v.x = x;
    v.y = y;
}

void ExtractVectorfromString(vec3& v, const std::string& s, char comma = ',')
{
    std::stringstream ss(s);
    float x, y, z;

    ss >> x >> comma >> y >> comma >> z;

    v.x = x;
    v.y = y;
    v.z = z;
}

void vec3::fromString(const std::string& s, char comma)
{
    ExtractVectorfromString(*this, s, comma);
}

void vec2::fromString(const std::string& s, char comma)
{
    ExtractVectorfromString(*this, s, comma);
}

inline vec3 operator+(const vec3& u, const vec3& v)
{
    return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline vec2 operator+(const vec2& u, const vec2& v)
{
    return vec2(u.x + v.x, u.y + v.y);
}

inline vec3 operator-(const vec3& u, const vec3& v)
{
    return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline vec2 operator- (const vec2& u, const vec2& v)
{
    return vec2(u.x - v.x, u.y - v.y);
}

inline vec3 operator*(const vec3& u, const vec3& v)
{
    return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline vec2 operator*(const vec2& u, const vec2& v)
{
    return vec2(u.x* u.x, u.y * u.y);
}

inline vec3 operator/(const vec3& u, const vec3& v)
{
    return vec3(u.x / v.x, u.y / v.y, u.z / v.z);
}

inline vec2 operator/(const vec2& u, vec2& v)
{
    return vec2(u.x / v.x, u.y / v.y);
}

inline vec3 operator*(const float t, const vec3& v)
{
    return vec3(t * v.x, t * v.y, t * v.z);
}

inline vec3 operator*(const vec3& v, const float t)
{
    return t * v;
}

inline vec3 operator/(const float t, const vec3& v)
{
    return (1 / t) * v;
}

inline vec3 operator/(const vec3& v, const float t)
{
    return t / v;
}

inline vec2 operator/(const float t, const vec2& v)
{
    return (1 / t) * v;
}

inline vec2 operator/(const vec2& v, const float t)
{
    return t / v;
}

inline float dot(const vec3& u, const vec3& v)
{
    return u.x * v.x
        + u.y * v.y
        + u.z * v.z;
}

inline float dot(const vec2& u, const vec2& v)
{
    return u.x * v.x + u.y * v.y;
}

inline vec3 cross(const vec3& u, const vec3& v)
{
    return vec3(u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x);
}

inline float cross(const vec2& u, const vec2& v)
{
    return u.x * v.y - u.y * v.x;
}

inline vec3 unit_vector(const vec3& v)
{
    return v / v.length();

}

inline vec2 unit_vector(const vec2& v)
{
    return v / v.length();
}

inline vec2 lerp(const vec2& v, const vec2& u, float t)
{
    return v * t + u * (1 - t);
}

inline vec3 lerp(const vec3& v, const vec3& u, float t)
{
    return v * t, u* (1 - t);
}

inline float absolute(const float a)
{
    return a < 0 ? a * (-1) : a;
}

inline float distance(const vec2& v, const vec2& u)
{
    return absolute(std::sqrt((v.x - u.x) * (v.x - u.x) + (v.y - u.y) * (v.y - u.y)));
}

inline float distance(const vec3& v, const vec3& u)
{
    return absolute(std::sqrt((v.x - u.x) * (v.x - u.x) + (v.y - u.y) * (v.y - u.y) + (v.z - u.z) * (v.z - u.z)));
}

