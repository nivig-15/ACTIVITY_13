#include <stdio.h>
#include<math.h>
typedef struct
{
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float length;
	float breadth;
	float area;
}rectangle;
int input_n_value()
{
	int n;
	printf("Enter the number of rectangles: ");
	scanf("%d",&n);
return n; 
}
rectangle input()
{
	rectangle p;
printf("\nEnter the coordinate values of point 1: ");
scanf("%f%f",&p.x1,&p.y1);
printf("Enter the coordinate values of point 2: ");
scanf("%f%f",&p.x2,&p.y2);
printf("Enter the coordinate values of point 3: ");
scanf("%f%f",&p.x3,&p.y3);
return p;
}
void input_values(int n, rectangle r[n])
{
	printf("Enter the coordinate values in 1 decimal point floating format!! ");
	for(int i=0;i<n;i++)
	{
		printf("\nThe coordinates for rectangle %d",i+1);
		r[i]=input();
    }
}
void display(rectangle *pt)
{
	printf("\nThe coordinate values of point 1: ");
printf("(%.1f,%.1f)",pt->x1,pt->y1);
printf("\nThe coordinate values of point 2: ");
printf("(%.1f,%.1f)",pt->x2,pt->y2);
printf("\nThe coordinate values of point 3: ");
printf("(%.1f,%.1f)",pt->x3,pt->y3);
}

void display_values(int n, rectangle r[n])
{
	for(int i=0;i<n;i++)
	{
		printf("\nThe coordinates for rectangle %d",i+1);
		display(&r[i]);
    }
}
/*float distance_2_points(distance *p)
{
    
    float result;
    result=sqrt(pow(((p->x2)-(p->x1)),2)+pow(((p->y2)-(p->y1)),2));
    return result;
}*/
void compute_area(rectangle *pt)
{
	//distance p;
	//*p=&pt
    //rectangle r;
	pt->length=sqrt(pow(((pt->x2)-(pt->x1)),2)+pow(((pt->y2)-(pt->y1)),2));
	pt->breadth=sqrt(pow(((pt->x3)-(pt->x2)),2)+pow(((pt->y3)-(pt->y3)),2));
	//r.breadth=distance_2_points(&p);
	//printf("\nLength: %.1f",r.length);
	//printf("\nBreadth: %.1f ",r.breadth);
	float area;
	pt->area=pt->length*pt->breadth;
	//printf("\nArea: %.2f",area);
}
void compute_n_area(int n,rectangle r[n])
{
	for(int i=0;i<n;i++)
	{
		compute_area(&r[i]);
    }
}
void output(rectangle *res)
{
    printf("\nArea of rectangle with vertices (%.1f,%.1f) (%.1f,%.1f) (%.1f,%.1f) is %.1f",res->x1,res->y1,res->x2,res->y2,res->x3,res->y3,res->area);
}
void output_n_values(int n , rectangle r[n])
{
    for(int i=0;i<n;i++)
    {
        output(&r[i]);
    }
}
int main()
{
	int n;
	n=input_n_value();
	rectangle r[n];
	input_values(n,r);
	display_values(n,r);
	compute_n_area(n,r);
	output_n_values(n,r);
	return 0;
}
