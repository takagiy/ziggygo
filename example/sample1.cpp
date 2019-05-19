// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#include <ziggygo.hpp>
#include <ziggygo/extra.hpp>

auto main() -> int {
  auto map = ziggygo::map<1000, 1000>{ziggygo::block{100, 100}.at(100, 100),
                                      ziggygo::block{500, 50}.at(300, 600),
                                      ziggygo::block{150, 100}.at(700, 100),
                                      ziggygo::block{100, 200}.at(300, 700)};

  auto solver = ziggygo::make_solver(ziggygo::cart{100, 100}, map);

  auto path =
      solver.find_path(ziggygo::point{500, 400}, ziggygo::point{500, 700});

  ziggygo::extra::svg("path.svg", 1000, 1000).draw(map).draw(solver).draw(path);
}
