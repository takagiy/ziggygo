#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_NODE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_NODE

#include "./declare.hpp"
#include "./edge.hpp"
#include "./point.hpp"
#include <deque>
#include <forward_list>
#include <limits>

namespace ziggygo {
  struct node {
    point position;
    std::forward_list<edge> edges;
    unsigned long long total_cost;
    bool sure;

    node(point position)
        : position{position},
          total_cost{std::numeric_limits<unsigned long long>::max() / 2},
          sure{false}, edges{} {}

    static auto connect(unsigned long long cost, node *n, node *m) -> void {
      n->edges.push_front(edge{cost, m});
      m->edges.push_front(edge{cost, n});
    }
  };

  auto operator>(const node &lhs, const node &rhs) -> bool {
    return lhs.total_cost > rhs.total_cost;
  }
} // namespace ziggygo

#endif
