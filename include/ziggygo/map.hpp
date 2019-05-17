#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_MAP
#define COM_GITHUB_TAKAGIY_ZIGGYGO_MAP

#include "./block.hpp"
#include "./cart.hpp"
#include "./path.hpp"
#include <cstddef>
#include <initializer_list>
#include <vector>

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class map {
    std::vector<block> blocks_;

  public:
    map(const std::initializer_list<block> &blocks) : blocks_{blocks} {}

    map(const map &) = default;
  }; // namespace ziggygo
} // namespace ziggygo

#endif
