<!--
  Copyright (c) TakagiY 2019
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)
-->

# Solver
The thing what you want is probably a `solver`.

Its constructor takes a `map` and a `cart` to know locations of obstacles and how fat the cart is.

```c++
auto map = ...;

auto solver = ziggygo::solver{map, ziggygo::cart{100, 100}};
```

Then, it can find the shortest route between the two point on the map, that the cart is able to pass through.

```c++
solver.find_path(ziggygo::point{100, 350}, ziggygo::point{500, 700});
```

# Creating a map
The map is constructed by some `block`s. The template parameter (like `<1000, 1000>`) stands for the width and the height of the map.

```c++
auto map = ziggygo::map<1000, 1000>{
    ziggygo::block{100, 100}.at(100, 200),
    ziggygo::block{800, 50}.at(0, 600),
    ziggygo::block{50, 350}.at(700, 200),
    ziggygo::block{100, 200}.at(300, 300)
};
```

The following code represents a block with a width of 50 and a height of 350 and an offset, `x:700, y:200`.

```c++
block{50, 350}.at(700, 200)
```

# Path
The `path` is returned by `solver::find_path`. It contains a list of all waypoints on the route including start and goal.

You can work with `path` in several way.

1. You can treat the `path` as a `std::forward_list<point>` with `operator->`.

```c++
// call std::forward_list::pop_front
path->pop_front();
```

2. `path` provide an interface for *range-based for loop*, `path::begin` and `path::end`.

```c++
for(auto&& waypoint : path) {
    ...
}
```

If no route was found, `solver::find_path` return invalid `path`. `path::avails` can check it.

```c++
if(!path.avails()) {
    // Path is invalid. There is nothing we can do.
    return;
}
```

# Point
The `point` is a trivial struct as below.

```c++
struct point {
    double x;
    double y;
};
```
