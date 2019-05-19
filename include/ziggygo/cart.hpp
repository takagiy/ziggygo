// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_CART
#define COM_GITHUB_TAKAGIY_ZIGGYGO_CART

#include "./declare.hpp"
#include <cstddef>

namespace ziggygo {
  struct cart {
    double width;
    double height;

    cart() = default;
    cart(const cart &) = default;
  };
} // namespace ziggygo

#endif
