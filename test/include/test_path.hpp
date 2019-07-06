// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#include <ziggygo.hpp>

TEST_CASE("Path will be invalid if any route were found, and won't if found.",
          "[path][avails]") {
  auto map = ziggygo::map<500, 500>{
      ziggygo::block{100, 10}.at(0, 0), ziggygo::block{100, 10}.at(0, 99),
      ziggygo::block{10, 100}.at(0, 0), ziggygo::block{10, 100}.at(99, 0)};

  auto solver = ziggygo::solver{ziggygo::cart{100, 100}, map};

  auto invalid_path = solver.find_path(ziggygo::point{50, 50}, ziggygo::point{300, 300});

  auto valid_path1 = solver.find_path(ziggygo::point{30, 20}, ziggygo::point{80, 20});

  auto valid_path2 = solver.find_path(ziggygo::point{300, 300}, ziggygo::point{200, 0});

  CHECK(!invalid_path.avails());
  CHECK(valid_path1.avails());
  CHECK(valid_path2.avails());

}
