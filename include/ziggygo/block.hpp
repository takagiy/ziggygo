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
