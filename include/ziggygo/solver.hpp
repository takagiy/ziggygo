#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER
#define COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER

#include "./cart.hpp"
#include "./map.hpp"

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class solver {
    cart cart_;
    map<Width, Height> map_;

  public:
    solver(const cart &cart, const map<Width, Height> &map)
        : cart_{cart}, map_{map} {}

    solver(const solver &) = default;
  };

  template <std::size_t Width, std::size_t Height>
  auto make_solver(const cart & cart, const map<Width, Height> & map) -> solver<Width, Height> {
      return solver<Height, Width>{cart, map};
  }
} // namespace ziggygo

#endif
