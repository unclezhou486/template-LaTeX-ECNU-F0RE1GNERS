#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    int T;
    scanf("%d", &T); // 读取测试数据组数
    for (int i = 0; i < T; i++) {
        double x, y, R;
        scanf("%lf %lf", &x, &y); // 读取已知点的坐标
        R = hypot(x, y); // 计算半径 R

        // 计算角度 t
        double t = fabs(atan(y/x));
        if(x<0&&y<0) t+=PI;
        else if(x<0&&y>0) t=PI-t;
        else if(x>0&&y<0) t=2*PI-t;
        //printf("%f\n",t);
        // 计算另外两个点的坐标
        double x1 = R * cos(t + (2.0 * PI / 3.0));
        double y1 = R * sin(t + (2.0 * PI / 3.0));
        double x2 = R * cos(t - (2.0 * PI / 3.0));
        double y2 = R * sin(t - (2.0 * PI / 3.0));

        // 根据 y 坐标（以及 x 坐标）的优先级来输出两个点的坐标
        if (y1 < y2) {
            printf("%.3f %.3f %.3f %.3f\n", x1, y1, x2, y2);
        } else {
            printf("%.3f %.3f %.3f %.3f\n", x2, y2, x1, y1);
        }
    }
    return 0;
}