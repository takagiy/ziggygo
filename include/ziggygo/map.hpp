#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_MAP
#define COM_GITHUB_TAKAGIY_ZIGGYGO_MAP

#include "./block.hpp"
#include "./cart.hpp"
#include "./path.hpp"
#include <cstddef>
#include <vector>

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class map {
    std::vector<block> impassible_areas_;

  public:
    template <class... Blocks>
    map(const cart &cart, const Blocks &... blocks)
        : impassible_areas_{blocks...} {
      auto padding_x = cart.width / 2;
      auto padding_y = cart.height / 2;

      for (auto &block : impassible_areas_) {
        block.left -= padding_x;
        block.right += padding_x;
        block.top -= padding_y;
        block.bottom += padding_y;
      }
    }

    map(const map &) = default;

    auto find_path() -> path { return path{}; }
  };
} // namespace ziggygo

#endif
