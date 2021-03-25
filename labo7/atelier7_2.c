#include <stdio.h>
#include <math.h>

struct Point_s { // Un point en 2D
    double x;  // Sa coordonnée x
    double y;  // Sa coordonnée y
};

struct Segment_s {
    struct Point_s p1;
    struct Point_s p2;
};

struct Triangle_s {
    struct Point_s points[3];
};

void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2);
double longueurSegment(const struct Segment_s *segment);

void initialiserTriangle(struct Triangle_s *triangle,
                          double x1, double y1,
                          double x2, double y2,
                          double x3, double y3);

double perimetreTriangle(const struct Triangle_s *triangle);
int main(){

}

void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2){
  segment->p1.x=x1,
  segment->p1.y=y1;
  segment->p2.x=x2;
  segment->p2.y=y2;
}

double longueurSegment(const struct Segment_s *segment){
    double longueur = sqrt(pow(segment->p1.x-segment->p2.x,2)+pow(segment->p2.y-segment->p2.y , 2));
    return longueur; 
}

void initialiserTriangle(struct Triangle_s *triangle,
                          double x1, double y1,
                          double x2, double y2,
                          double x3, double y3){
                          triangle->points[0].x=x1;
                          triangle->points[0].y=y1;
                          triangle->points[1].x=x2;
                          triangle->points[1].y=y2;
                          triangle->points[2].x=x3;
                          triangle->points[2].y=y3;
                          }

double perimetreTriangle(const struct Triangle_s *triangle){
    struct Segment_s segment1 ={triangle->points[0] , triangle->points[1]};
    struct Segment_s segment2 ={triangle->points[0] , triangle->points[2]};   
    struct Segment_s segment3 ={triangle->points[1] , triangle->points[2]};
    double perimetre = longueurSegment(segment1) + longueurSegment(segment2) + longueurSegment(segment3);
    return perimetre;
}