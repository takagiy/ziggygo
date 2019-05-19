// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK
#define COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK

#include "./declare.hpp"
#include <cstddef>

namespace ziggygo {
  struct block {
    double left;
    double right;
    double top;
    double bottom;

    block(double width, double height)
        : left{0}, top{0}, right{width}, bottom{height} {}

    block(const block &) = default;

    auto at(double left_x, double top_y) -> block & {
      auto width = right - left;
      auto height = bottom - top;
      left = left_x;
      top = top_y;
      right = left + width;
      bottom = top + height;
      return *this;
    }
  };
} // namespace ziggygo

#endif
