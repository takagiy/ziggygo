#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK
#define COM_GITHUB_TAKAGIY_ZIGGYGO_BLOCK

#include <cstddef>

namespace ziggygo {
  struct block {
    std::size_t width;
    std::size_t height;
    std::size_t left_x;
    std::size_t top_y;

    block(std::size_t width, std::size_t height)
        : width{width}, height{height}, left_x{0}, top_y{0} {}

    block(const block &) = default;

    auto at(std::size_t left_x, std::size_t top_y) -> block & {
      this->left_x = left_x;
      this->top_y = top_y;
      return *this;
    }
  };
} // namespace ziggygo

#endif
