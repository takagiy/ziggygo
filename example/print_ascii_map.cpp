#include <cstdio>
#include <ziggygo.hpp>

auto main() -> int {
  auto field = ziggygo::map<100, 100>{
      ziggygo::cart{10, 10}, ziggygo::block{10, 20}.at(10, 10),
      ziggygo::block{15, 15}.at(50, 70), ziggygo::block{100, 5}.at(0, 60),
      ziggygo::block{30, 30}.at(70, 10)};

  // print ascii map
  for (std::size_t y = 0; y < 100; ++y) {
    for (std::size_t x = 0; x < 100; ++x) {
      if (field.is_block(x, y)) {
        std::printf("##");
      } else {
        std::printf("..");
      }
    }
    std::printf("\n");
  }
}
