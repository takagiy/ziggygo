#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER
#define COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER

#include "./cart.hpp"
#include "./declare.hpp"
#include "./line.hpp"
#include <forward_list>

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class solver {
    cart cart_;
    std::forward_list<line> walls_;

  public:
    solver(const cart &cart, const map<Width, Height> &map)
        : cart_{cart}, walls_{} {
      for (auto &&rect : map.blocks_) {
        auto l = rect.left - cart.width;
        auto r = rect.right + cart.width;
        auto t = rect.top - cart.height;
        auto b = rect.bottom + cart.height;

        walls_.push_front(line{point{l, t}, point{r, t}});
        walls_.push_front(line{point{l, b}, point{r, b}});
        walls_.push_front(line{point{l, t}, point{l, b}});
        walls_.push_front(line{point{r, t}, point{r, b}});
      }
    }

    solver(const solver &) = default;
  };

  template <std::size_t Width, std::size_t Height>
  auto make_solver(const cart &cart, const map<Width, Height> &map)
      -> solver<Width, Height> {
    return solver<Height, Width>{cart, map};
  }
} // namespace ziggygo

#endif
