#ifndef RTWEEEKEND_H
#define RTWEEEKEND_H
#pragma once
#include<cmath>
#include<iostream>
#include<limits>
#include<memory>
using std::make_shared;
using std::shared_ptr;

#include"interval.h"

const double infinity = std::numeric_limits<double>::infinity();
const double pi=3.141592653589793285;

inline double degress_to_radians(double degress){
    return degress*pi /180;
}

inline double  random_double(){
    return std::rand() /(RAND_MAX + 1.0);
}

inline double random_double(double min,double max)
{
    return min+(max-min) * random_double();
}
#include"color.h"
#include"ray.h"
#include"vec3.h"

#endif