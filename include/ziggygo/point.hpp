// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

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

  auto operator!=(const point &p, const point &q) -> bool { return !(p == q); }

  auto operator-(const point &p, const point &q) -> point {
    return point{p.x - q.x, p.y - q.y};
  }

  auto distance(const point &p, const point &q) -> double {
    auto dx = p.x - q.x;
    auto dy = p.y - q.y;
    return std::sqrt(dx * dx + dy * dy);
  }

  struct point_comparator {
    auto operator()(const point &lhs, const point &rhs) const -> bool {
      return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
    }
  };
}; // namespace ziggygo

#endif
