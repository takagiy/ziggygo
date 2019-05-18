#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER
#define COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER

#include "./declare.hpp"
#include "./cart.hpp"
#include <forward_list>

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class solver {
    cart cart_;
    std::forward_list<line> walls_;

  public:
    solver(const cart &cart, const map<Width, Height> &map)
        : cart_{cart}, walls_{} {
    }

    solver(const solver &) = default;
  };

  template <std::size_t Width, std::size_t Height>
  auto make_solver(const cart & cart, const map<Width, Height> & map) -> solver<Width, Height> {
      return solver<Height, Width>{cart, map};
  }
} // namespace ziggygo

#endif
