#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_CART
#define COM_GITHUB_TAKAGIY_ZIGGYGO_CART

#include <cstddef>

namespace ziggygo {
    struct cart {
        double width;
        double height;

        cart() = default;
        cart(const cart &) = default;
    };
}

#endif
