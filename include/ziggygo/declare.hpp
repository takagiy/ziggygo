#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_DECLARE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_DECLARE

#include <cstddef>

namespace ziggygo {
    struct point;

    struct line;

    struct cart;

    struct block;

    struct path;

    template <std::size_t, std::size_t>
    class map;

    template <std::size_t, std::size_t>
    class solver;
};

#endif
