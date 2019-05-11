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
    std::size_t padding_x;
    std::size_t padding_y;

    block(std::size_t width, std::size_t height)
        : width{width}, height{height}, padding_x{0}, padding_y{0} {}

    block(const block &) = default;

    auto pad(std::size_t padding_x, std::size_t padding_y) -> block & {
      this->padding_x = padding_x;
      this->padding_y = padding_y;
      return *this;
    }
  };

  struct path {};

  namespace _ {
    struct node {};
    struct graph {};

    template <class Map>
    auto fill(Map &is_block, const block &block) {
      auto block_left = block.padding_x;
      auto block_right = block.padding_x + block.width;
      auto block_top = block.padding_y;
      auto block_bottom = block.padding_y + block.height;

      for (auto x = block_left; x < block_right; ++x) {
        for (auto y = block_top; y < block_bottom; ++y) {
          is_block[x][y] = true;
        }
      }
    }
  } // namespace _

  template <std::size_t Width, std::size_t Height>
  class map {
    std::array<std::array<bool, Height>, Width> is_block_;
    std::vector<block> blocks_;

  public:
    template <class... Blocks>
    map(const cart &cart, const Blocks &... blocks) : is_block_{}, blocks_{blocks...} {
      for (auto &&block : blocks_) {
        _::fill(is_block_, block);
      }
    }

    map(const map &) = default;

    auto find_path() -> path { return path{}; }

    auto is_block(std::size_t x, std::size_t y) -> bool {
      return is_block_[x][y];
    }
  };
} // namespace ziggygo

#endif
