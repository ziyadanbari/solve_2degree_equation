#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const char INVALID_DATA_MESSAGE[] = "The data entered is invalid";
void calculateXIfDeltaEqualToZero(float a, float b, float delta, float *x) {
    if (delta != 0) {
        printf("Sorry. Delta is not 0");
        exit(1);
    }
    *x = -b / (2 * a);
}

void calculateXIfDeltaGreaterThanZero(float a, float b,float delta, float *x1, float *x2) {
    if (delta <= 0) {
        printf("Sorry. Delta is less or equal to 0");
        exit(1);
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

void calculateX(float delta,float a, float b, float c, float *x1, float *x2) {
    if (delta > 0) {
        calculateXIfDeltaGreaterThanZero(a, b, delta, x1, x2);
    }else if (delta == 0) {
        calculateXIfDeltaEqualToZero(a,b, delta, x1);
    }else {
        printf(INVALID_DATA_MESSAGE);
        exit(1);
    }
}

void calculateDelta(float a, float b, float c,float *delta) {
    *delta = pow(b, 2) - (4 * a * c);
    if (*delta < 0) {
        printf(INVALID_DATA_MESSAGE);
        exit(1);
    }
}



int main() {
    float a,b,c,delta,x1,x2;
    a = b = c = delta = x1 = x2 = 0;
    printf("Enter a: ");
    scanf("%f",&a);
    printf("Enter b: ");
    scanf("%f",&b);
    printf("Enter c: ");
    scanf("%f",&c);
    if (a == 0) {
        printf(INVALID_DATA_MESSAGE);
        exit(1);
    }
    calculateDelta(a,b,c,&delta);
    calculateX(delta,a,b,c,&x1,&x2);
    if (delta >= 0) {
        printf("Delta: %f\n", delta);
        if (x1 != x2) {
            printf("x1: %f\n", x1);
            printf("x2: %f\n", x2);
        } else {
            printf("x: %f\n", x1);
        }
    } else {
        printf(INVALID_DATA_MESSAGE);
    }
    return 0;
}