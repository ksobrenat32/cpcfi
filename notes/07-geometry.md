## Geometry

### Constants

#### PI

```c++
#define PI acos(-1.0)
```

#### Epsilon

```c++
#define EPS 1e-9
```

### Conversions

#### Degree/Radian conversions

```c++
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
```

### Structures

#### Point

```c++
struct point_i { 
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point { 
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};
```

#### Line

```c++
struct line { 
    double a, b, c; 
    // ax + by + c = 0
};
```

### Circle

#### Check if point is inside circle

```c++
int insideCircle(point_i p, point_i c, int r) {
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
    // 0 = inside, 1 = on border, 2 = outside
}
```

#### Arc Length

To calculate the arc use `L = rθ` where θ is in radians.

### Triangle

#### Area using Heron's formula

```c++
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0; // semiperimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

#### Distance between points

```c++
double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
```

#### Perimeter

```c++
double perimeter(double a, double b, double c) {
    return a + b + c;
}

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a);
}
```

### Save int as real number

For more precision you can use scanf:

```c++
int a, b;
scanf("%d.%d", &a, &b);
```
