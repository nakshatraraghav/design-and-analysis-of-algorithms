#include <bits/stdc++.h>
using namespace std;

class point
{
public:
  int x, y;

  point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  bool equals(point a)
  {
    return (this->x == a.x && this->y == a.y);
  }
};

int cross_product(point p, point q, point r)
{
  return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

int distance(point p, point q)
{
  return sqrt(pow(q.y - p.y, 2) + pow(q.x - p.x, 2));
}

void convex_hull(vector<point> points)
{
  int start = 0, current;
  vector<point> result;
  vector<point> colinear;

  for (int i = 0; i < points.size(); i++)
  {
    if (points[i].x < points[start].x)
    {
      start = i;
    }
  }

  current = start;
  result.push_back(points[start]);

  while (true)
  {
    int next = 0;
    for (int i = 1; i < points.size(); i++)
    {
      if (i == current || i == next)
      {
        continue;
      }

      int cross = cross_product(points[current], points[next], points[i]);
      if (cross > 0)
      {
        next = i;
        colinear.clear();
      }
      else if (cross == 0)
      {
        if (distance(points[current], points[next]) < distance(points[current], points[i]))
        {
          colinear.push_back(points[next]);
          next = i;
        }
        else
        {
          colinear.push_back(points[i]);
        }
      }
    }

    // now push the colinear points
    for (int i = 0; i < colinear.size(); i++)
    {
      result.push_back(colinear[i]);
    }

    // we have found the left most point with respect to the current pouint
    // checking if this next is the initial start point or not
    if (next == start)
    {
      break;
    }

    result.push_back(points[next]);
    current = next;
  }

  for (int i = 0; i < result.size(); i++)
  {
    cout << "(" << result[i].x << ", " << result[i].y << ")\n";
  }
}

int main()
{
  int size, x, y;
  cout << "enter the number of points : ";
  cin >> size;
  vector<point> points;
  cout << "enter the points in x y format:\n ";
  for (int i = 0; i < size; i++)
  {
    cin >> x >> y;
    points.push_back(point(x, y));
  }

  convex_hull(points);
  return 0;
}