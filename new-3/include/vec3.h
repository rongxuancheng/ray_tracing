#ifndef VEC3_H
#define VEC3_H
#include<cmath>
#include<iostream>
class vec3
{
    public:
        double e[3];
        vec3():e{0,0,0}{};
        vec3(double x,double y,double z):e{x,y,z}{};

        double x() const{return e[0];}
        double y() const{return e[1];}
        double z() const{return e[2];}

        vec3 operator-() const{return vec3(-e[0],-e[1],-e[2]);}
        double operator[](int i) const{return e[i];}
        double &operator[](int i) {return e[i];}

        vec3& operator+=(const vec3& v){
            e[0]+=v.e[0];
            e[1]+=v.e[1];
            e[2]+=v.e[2];
            return *this;
        }
        vec3& operator*=(double t){
            e[0]*=t;
            e[1]*=t;
            e[2]*=t;
            return *this;
        }
        vec3& operator/=(double t){
            return *this*=1/t;
        }

        double length_squared() const{
            return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
        }
        bool near_zero() const{
            auto s=1e-8;
            return (std::fabs(e[0])<s)&&(std::fabs(e[1])<s)&&(std::fabs(e[2])<s);
        }
        double length() const{
            return std::sqrt(length_squared());
        }

        // static vec3 random(){
        //     return vec3(random_double(),random_double(),random_double());
        // }
        // static vec3 random(double min,double max){
        //     return vec3(random_double(min,max),random_double(min,max),random_double(min,max));
        // }
        static vec3 random(){
            auto x = std::rand() /(RAND_MAX + 1.0);
            auto y = std::rand() /(RAND_MAX + 1.0);
            auto z = std::rand() /(RAND_MAX + 1.0);
            return vec3(x, y, z);
        }

        static vec3 random(double min, double max){
            auto x = min+(max-min) * (std::rand() /(RAND_MAX + 1.0));
            auto y = min+(max-min) * (std::rand() /(RAND_MAX + 1.0));
            auto z = min+(max-min) * (std::rand() /(RAND_MAX + 1.0));
            return  vec3(x, y, z);
        }
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out,const vec3& v){
    return out <<v.e[0]<<" "<<v.e[1]<<" "<<v.e[2];
}

inline vec3 operator+(const vec3&v,const vec3& u){
    return vec3(v[0]+u[0],v[1]+u[1],v[2]+u[2]);
}

inline vec3 operator-(const vec3&v,const vec3& u){
    return vec3(v[0]-u[0],v[1]-u[1],v[2]-u[2]);
}

inline vec3 operator*(const vec3&v,const vec3& u){
    return vec3(v[0]*u[0],v[1]*u[1],v[2]*u[2]);
}
inline vec3 operator*(const vec3&v,double k){
    return vec3(v[0]*k,v[1]*k,v[2]*k);
}
inline vec3 operator*(double k,const vec3&v){
    return v*k;
}

inline vec3 operator/(const vec3&v,double k){
    return (1/k)*v;
}

inline double dot(const vec3&v,const vec3& u)
{
    return v[0]*u[0]+v[1]*u[1]+v[2]*u[2];
}
inline vec3 unit_vector(const vec3& v){
    return v/v.length();
}
inline vec3 random_in_unit_sphere()
{
    while (true){
        auto p = vec3::random(-1,1);
        if(p.length_squared()<1)
        {
            return p;
        }
    }
}
inline vec3 reflect(const vec3& v,const vec3& n){
    return v-2*dot(v,n)*n;
}

inline vec3 random_unit_vector()
{
    return unit_vector(random_in_unit_sphere());
}
inline vec3 random_on_hemisphere(const vec3& nomal){
    vec3 on_unit_sphere = random_unit_vector();
    if(dot(on_unit_sphere,nomal)>0.0){
        return on_unit_sphere;
    }
    else{
        return -on_unit_sphere;
    }
}
inline vec3 cross(const vec3& u,const vec3& v)
{
    return vec3(u.e[1]*v.e[2]-u.e[2]*v.e[1],
                u.e[2]*v.e[0]-u.e[0]*v.e[2],
                u.e[0]*v.e[1]-u.e[1]*v.e[0]);
}
#endif