#ifndef INTERCAL_H
#define INTERCAL_H
#include<limits>

const double inf = std::numeric_limits<double>::infinity();
class interval{
    public:
        double min,max;
        interval():min(+inf),max(-inf){}
        interval(double min ,double max):min(min),max(max){}
        double size() const{
            return max-min;
        }
        bool contains(double x)const{
            return min<=x&&x<=max;
        }
        bool surround(double x)const{
            return min<x&&x<max;
        }
        double clamp(double x) const{
            if(x<min) return min;
            if(x>max) return max;
            return x;
        }
        static const interval empty,universe;

};
const interval interval:: empty = interval(+inf,-inf);
const interval interval:: universe = interval(+inf,-inf);
#endif