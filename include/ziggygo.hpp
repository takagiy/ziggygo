#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO
#define COM_GITHUB_TAKAGIY_ZIGGYGO

#include <array>
#include <cstddef>
#include <vector>

namespace ziggygo {
  struct cart {
    std::size_t width;
    std::size_t height;

    cart() = default;
    cart(const cart &) = default;
  };

  struct block {
    std::size_t width;
    std::size_t height;
    std::size_t position_left;
    std::size_t position_top;

    block(std::size_t width, std::size_t height)
        : width{width}, height{height}, position_left{0}, position_top{0} {}

    block(const block &) = default;

    auto at(std::size_t position_left, std::size_t position_top) -> block & {
      this->position_left = position_left;
      this->position_top = position_top;
      return *this;
    }
  };

  struct path {};

  namespace _ {
    struct node {};
    struct graph {};
  } // namespace _

  template <std::size_t Width, std::size_t Height>
  class map {
    std::vector<block> impassible_areas_;

  public:
    template <class... Blocks>
    map(const cart &cart, const Blocks &... blocks)
        : impassible_areas_{blocks...} {
      auto padding_left = cart.width / 2;
      auto padding_top = cart.height / 2;

      for (auto &block : impassible_areas_) {
          block.position_left -= padding_left;
          block.width += cart.width;
          block.positon_top -= padding_top;
          block.height += cart.height;
      }
    }

    map(const map &) = default;

    auto find_path() -> path { return path{}; }
  };
} // namespace ziggygo

#endif
