#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include<memory.h>

class sphere : public hittable{
    public:
        sphere(const point3& center, double radius, shared_ptr<material> mat) : center(center), radius(std::fmax(0, radius)),mat(mat){
            // TODO : init mat
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override{
            vec3 oc = center - r.origin();
            auto a = dot(r.direction(), r.direction());
            auto h = dot(r.direction(), oc);
            auto c = dot(oc, oc) - radius * radius;
            auto d = h * h - a * c;

            if(d < 0.0) return false;

            auto sqrtd = std::sqrt(d);
            
            auto root = (h - sqrtd) / a;
            if( !ray_t.surround(root)){
                root = (h + sqrtd) / a;
                if( !ray_t.surround(root)){
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(root);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = mat;
            return true;
        }

    private:
        point3 center;
        double radius;
        std::shared_ptr<material> mat;
};

#endif