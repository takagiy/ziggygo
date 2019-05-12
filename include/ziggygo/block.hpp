#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK
#define COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK

#include <cstddef>

namespace ziggygo {
  struct block {
    std::size_t left;
    std::size_t right;
    std::size_t top;
    std::size_t bottom;

    block(std::size_t width, std::size_t height)
        : left{0}, top{0}, right{width}, bottom{height} {}

    block(const block &) = default;

    auto at(std::size_t left, std::size_t top) -> block & {
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
