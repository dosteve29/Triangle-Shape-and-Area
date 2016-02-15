/* Hyunseung Do */
/* hyunseung.do@temple.edu */
/* due: 021516 */

/* this program determines the type of triangle a user enters  */
/* and calculates the area of the triangle */

/* preprocessor directive */
#include <stdio.h>
#include <math.h>

/* function prototype */
int valid_triangle(double, double, double);
double area_of_triangle(double, double, double);

int equilateral_triangle(double, double, double);
int right_triangle(double, double, double);
int obtuse_triangle(double, double, double);
int acute_triangle(double, double, double);
int isoceles_triangle(double, double, double);

/* main function */
int main(void){
	/* variable declaration */
	double side1 = 0.0;
	double side2 = 0.0;
	double side3 = 0.0;
	double area = 0.0;

	/* accept sides from the user */
	printf("Please enter the first side of the triangle: ");
	scanf("%lf", &side1);
	printf("Please enter the second side of the triangle: ");
	scanf("%lf", &side2);
	printf("Please enter the third side of the triangle: ");
	scanf("%lf", &side3);

	/* proceed with the main program objective */
	/* use if and else to branch out first the validity of the triangle */
	/* then the shape, and check if the triangle is also isoceles */
	/* 0 is false, 1 is true */

        /* calculate the area of the triangle */
        area = area_of_triangle(side1, side2, side3);

	/* this is valid */
	if (valid_triangle(side1, side2, side3) == 1){
        //equilateral triangles are never isoceles
        if (equilateral_triangle(side1, side2, side3) == 1){
            printf("\nEquilateral!\n");
        }

        //right triangle
        else if (right_triangle(side1, side2, side3)== 1){
            //check if triangle is isoceles also
            if (isoceles_triangle(side1, side2, side3) == 1){
                printf("\nIsoceles right triangle!\n");
            }
            else {
                printf("\nRight triangle!\n");
            }
        }

        //obtuse triangle
        else if (obtuse_triangle(side1, side2, side3) == 1){
            //check if triangle is isoceles also
            if (isoceles_triangle(side1, side2, side3) == 1){
                printf("\nIsoceles obtuse triangle!\n");
            }
            else {
                printf("\nObtuse triangle!\n");
            }
        }

        //acute triangle
        else if (acute_triangle(side1, side2, side3) == 1){
            //check if triangle is isoceles also
            if (isoceles_triangle(side1, side2, side3) == 1){
                printf("\nIsoceles acute triangle!\n");
            }
            else {
                printf("\nAcute triangle!\n");
            }
        }
        //print out the area of the triangle after determining the shape
        printf("The area of the triangle is: %.2f\n", area);

	}

	//this is invalid
	else {
		printf("\nThe triangle is invalid because the length of one side is greater than or equal to the sum of the lengths of the other two sides\n");
	}

	return (0);
}

/* determines if the triangle is valid */
int valid_triangle(double side1, double side2, double side3){
	/* triangle is invalid if one side is greater than or equal to the sum of other sides */
	if (side1 >= side2 + side3) {
		return 0;
	}

	else if (side2 >= side1 + side3){
		return 0;
	}

	else if (side3 >= side2 + side1){
		return 0;
	}

	else {
		return 1;
	}

}

/* calculates the area of the triangle */
double area_of_triangle(double side1, double side2, double side3){
	double s = (side1 + side2 + side3) / (2.0);
	double area = sqrt((s) * (s - side1) * (s - side2) * (s - side3));
	return area;
}

int equilateral_triangle(double side1, double side2, double side3){
	//all sides are the same
	if (side1 == side2 && side2 == side3 && side1 == side3){
		return 1;
	}
	else {
		return 0;
	}
}

int right_triangle(double side1, double side2, double side3){
	//is a^2 + b^2 = c^2
	if ((pow(side1, 2.0)) + (pow(side2, 2.0)) == (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side1, 2.0)) + (pow(side3, 2.0)) == (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side1, 2.0)) == (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side3, 2.0)) == (pow(side1, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side1, 2.0)) == (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side2, 2.0)) == (pow(side1, 2.0))) {
		return 1;
	}

	else {
		return 0;
	}
}

int obtuse_triangle(double side1, double side2, double side3){
	//is a^2 + b^2 < c^2
	if ((pow(side1, 2.0)) + (pow(side2, 2.0)) < (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side1, 2.0)) + (pow(side3, 2.0)) < (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side1, 2.0)) < (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side3, 2.0)) < (pow(side1, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side1, 2.0)) < (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side2, 2.0)) < (pow(side1, 2.0))) {
		return 1;
	}

	else {
		return 0;
	}
}

int acute_triangle(double side1, double side2, double side3){
	//is a^2 + b^2 > c^2
	if ((pow(side1, 2.0)) + (pow(side2, 2.0)) > (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side1, 2.0)) + (pow(side3, 2.0)) > (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side1, 2.0)) > (pow(side3, 2.0))) {
		return 1;
	}

	else if ((pow(side2, 2.0)) + (pow(side3, 2.0)) > (pow(side1, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side1, 2.0)) > (pow(side2, 2.0))) {
		return 1;
	}

	else if ((pow(side3, 2.0)) + (pow(side2, 2.0)) > (pow(side1, 2.0))) {
		return 1;
	}

	else {
		return 0;
	}
}

int isoceles_triangle(double side1, double side2, double side3){
	//any two sides are equal
	if (side1 == side2 || side2 == side3 || side1 == side3){
		return 1;
	}
	else {
		return 0;
	}
}
