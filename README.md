## Usage

```c++
#include <ziggygo.hpp>
#include <ziggygo/extra.hpp>

auto main() -> int {
  // make 1000 x 1000 map containing 4 obstacles
  auto map = ziggygo::map<1000, 1000> {
    ziggygo::block{100, 100}.at(100, 100),
    ziggygo::block{500, 50}.at(300, 600),
    ziggygo::block{150, 100}.at(700, 100),
    ziggygo::block{100, 200}.at(300, 700)
  };

  // make solver by specifying size of cart(agent)
  auto solver = ziggygo::make_solver(ziggygo::cart{100, 100}, map);

  // find shortest route between 2 points on the map
  auto path =
      solver.find_path(ziggygo::point{500, 400}, ziggygo::point{500, 700});

  // save the result as a svg image
  ziggygo::extra::svg("path.svg", 1000, 1000).draw(map).draw(solver).draw(path);
}
```

### Output

* black ... obstacle
* blue... shortest route
* yellow ... shadow of the cart on a point
* green ...  possible path
<img src="/doc/image/path.svg" alt="path.svg" width="600px">
