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

    auto at(double left, double top) -> block & {
      auto width = right - left;
      auto height = bottom - top;
      this->left = left;
      this->top = top;
      this->right = left + width;
      this->bottom = top + height;
      return *this;
    }
  };
} // namespace ziggygo

#endif
