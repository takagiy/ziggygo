#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_POINT
#define COM_GITHUB_TAKAGIY_ZIGGYGO_POINT

#include "./declare.hpp"
#include <cmath>

namespace ziggygo {
    struct point {
        double x;
        double y;
    };

    auto cross_norm(const point &p, const point &q) -> double {
        return (p.x * q.y) - (p.y * q.x);
    }

    auto operator==(const point &p, const point &q) -> bool {
        return p.x == q.x && p.y == q.y;
    }

    auto operator!=(const point &p, const point &q) -> bool {
        return !(p == q);
    }
    
    auto operator-(const point &p, const point &q) -> point {
        return point{p.x - q.x, p.y - q.y};
    }

    auto distance(const point &p, const point &q) -> double {
        auto dx = p.x - q.x;
        auto dy = p.y - q.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

#endif
