#include <ziggygo/line.hpp>

TEST_CASE("Line crossings are detected", "[line][crosses]") {
  using ziggygo::line;
  using ziggygo::point;
  CHECK(line{point{-100, 0}, point{100, 0}}.crosses(
      line{point{0, -100}, point{0, 100}}));
  CHECK(line{point{0, -100}, point{0, 100}}.crosses(
      line{point{-100, 0}, point{100, 0}}));
  CHECK(line{point{20, 80}, point{70, 30}}.crosses(
      line{point{40, 20}, point{60, 130}}));
  CHECK(line{point{40, 20}, point{60, 130}}.crosses(
      line{point{20, 80}, point{70, 30}}));
  CHECK(!line{point{20, 80}, point{80, 30}}.crosses(
      line{point{20, 90}, point{90, 70}}));
  CHECK(!line{point{80, 40}, point{40, 170}}.crosses(
      line{point{80, 50}, point{140, 170}}));
  CHECK(!line{point{120, 60}, point{140, 170}}.crosses(
      line{point{120, 170}, point{160, 180}}));
}

TEST_CASE("Line does not cross itselves", "[line][cross][self]") {
  using ziggygo::line;
  using ziggygo::point;
  auto l0 = line{point{-100, 0}, point{100, 0}};
  auto l1 = line{point{0, -100}, point{0, 100}};
  auto l2 = line{point{20, 80}, point{70, 30}};
  auto l3 = line{point{40, 20}, point{60, 130}};
  auto l4 = line{point{20, 80}, point{80, 30}};
  auto l5 = line{point{80, 40}, point{40, 170}};
  auto l6 = line{point{120, 60}, point{140, 170}};

  for (auto &&line : {l0, l1, l2, l3, l4, l5, l6}) {
    CHECK(!line.crosses(line));
  }
}
