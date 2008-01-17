// Example program for the linear_least_square_fitting function on a set of circles in 2D

#include <CGAL/Cartesian.h>
#include <CGAL/linear_least_squares_fitting_2.h>

#include <list>

typedef double               FT;
typedef CGAL::Cartesian<FT>  K;
typedef K::Line_2            Line;
typedef K::Point_2           Point;
typedef K::Circle_2          Circle;

int main()
{
  std::list<Circle> circles;
  circles.push_back(Circle(Point(0.0, 0.0),9.0));
  circles.push_back(Circle(Point(0.0,10.0),49.0));
  circles.push_back(Circle(Point(10.0,0.0),49.0));

  Line line;
  Point centroid;

  linear_least_squares_fitting_2(circles.begin(),circles.end(),line,CGAL::PCA_dimension_2_tag());
  linear_least_squares_fitting_2(circles.begin(),circles.end(),line,CGAL::PCA_dimension_1_tag());

  linear_least_squares_fitting_2(circles.begin(),circles.end(),line,centroid,CGAL::PCA_dimension_2_tag());
  linear_least_squares_fitting_2(circles.begin(),circles.end(),line,centroid,CGAL::PCA_dimension_1_tag());

  return 0;
}
