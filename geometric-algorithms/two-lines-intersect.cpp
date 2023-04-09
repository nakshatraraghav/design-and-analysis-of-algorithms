#include <bits/stdc++.h>
using namespace std;

class point
{
public:
  int x, y;
};

bool online(point l1, point l2, point p)
{
  int min_x = min(l1.x, l2.x);
  int max_x = max(l1.x, l2.x);
  int min_y = min(l1.y, l2.y);
  int max_y = max(l1.y, l2.y);

  if ((p.x >= min_x && p.x <= max_x) && (p.y >= min_y && p.y <= max_y))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int orientation(point p, point q, point r)
{
  return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool intersect(point p1, point q1, point p2, point q2)
{
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, p2, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
  {
    return true;
  }

  // 4 special cases when lines are co-linear
  if (o1 == 0 && online(p1, q1, p2))
  {
    return true;
  }

  if (o2 == 0 && online(p1, p2, q2))
  {
    return true;
  }

  if (o3 == 0 && online(p2, q2, p1))
  {
    return true;
  }

  if (o4 == 0 && online(p2, q2, q1))
  {
    return true;
  }

  return false;
}

int main()
{
  point p1 = {10, 0}, q1 = {0, 10};
  point p2 = {0, 0}, q2 = {10, 10};
  if (intersect(p1, q1, p2, q2))
  {
    cout << "they intersect";
  }
  else
  {
    cout << "they don't intersect";
  }
  return 0;
}