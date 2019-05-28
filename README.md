# ziggygo - Find the shortest path in the field containing rectangular obstacles.

## Example

```c++
#include <ziggygo.hpp>
#include <ziggygo/extra.hpp>

auto main() -> int {
  // make a 1000 x 1000 map containing four obstacles
  auto map = ziggygo::map<1000, 1000>{
    ziggygo::block{100, 100}.at(100, 200),
    ziggygo::block{800, 50}.at(0, 600),
    ziggygo::block{50, 350}.at(700, 200),
    ziggygo::block{100, 200}.at(300, 300)
  };

  // make a solver by specifying the size of the cart(agent)
  auto solver = ziggygo::make_solver(ziggygo::cart{100, 100}, map);

  // find the shortest route between two points on the map
  auto path =
      solver.find_path(ziggygo::point{100, 350}, ziggygo::point{500, 700});

  // save the result as a svg image
  ziggygo::extra::svg("path.svg", 1000, 1000).draw(map).draw(path, ziggygo::cart{100, 100});
}
```

### Output

<img src="/doc/image/path.svg" alt="path.svg" width="600px">

* black ... obstacle
* red... shortest route
* pink ... shadow of the cart on a point
