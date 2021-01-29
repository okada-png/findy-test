#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1
#define EPSILON 0.0000006

double overlap(double x1, double y1, double x2, double y2);

int main(void) {
printf("%f\n", overlap(0.0, 0.0, 1.0, 1.0)*4);
return 0;
}

double overlap(double x1, double y1, double x2, double y2){
  double x3,y3;
  //return sqrt(pow(x2,2)+pow(y2,2));
  if(sqrt(pow(x2-x1,2)+pow(y2-y1,2)) < EPSILON )return 0;
  else if(sqrt(pow(x1,2)+pow(y1,2))<=MAX && sqrt(pow(x2,2)+pow(y2,2))>=MAX){
    //printf("%lf,%lf,%lf,%lf\n",x1,y1,x2,y2);
    x3=(x1+x2)/2;
    y3=(y1+y2)/2;
    //printf("%lf,%lf,%lf,%lf\n",x1,y1,x3,y3);
    return overlap(x1,y1,x3,y3)+overlap(x1,y3,x3,y2)+overlap(x3,y1,x2,y3)+overlap(x3,y3,x2,y2);
  }else if(sqrt(pow(x1,2)+pow(y1,2))>MAX) return 0;
  else if(sqrt(pow(x2,2)+pow(y2,2))<MAX) return (x2-x1)*(y2-y1);
}
