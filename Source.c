////#include <stdio.h>
////#include <stdlib.h>
////#include <math.h>
////
////#define eps 0.0001
////
////double f(double x);
////double metod_hord(double x1, double x2, unsigned int N, unsigned int debug);
////
////
////int main()
////{
////    double x1, x2, root;
////    unsigned int N = 100, debug = 1; // debug = 0 - no debug.   1 - print results at every iteration
////
////
////    do {
////        system("cls");
////        printf("x1=");
////        scanf_s("%lf", &x1);
////        printf("x2=");
////        scanf_s("%lf", &x2);
////    } while (f(x1) * f(x2) > 0);
////
////    root = metod_hord(x1, x2, N, debug);
////
////    printf("\n\nx=%lf   f(x)=%lf", root, f(root));
////
////    return 0;
////}
////
////
//////-------------------------------------------------------------------------
////
////double f(double x)
////{
////    return 2 * pow(x - 4, 3) + 2 * x;
////}
////
////
//////-------------------------------------------------------------------------
////
////
////double metod_hord(double x1, double x2, unsigned int N, unsigned int debug)
////{
////
////    double xi;
////    int n = 1;
////
////    do {
////        xi = (f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1));
////
////        if (f(xi) * f(x1) > 0)
////            x1 = xi;
////        else
////            x2 = xi;
////
////
////        if (debug == 1)
////            printf("\n%d  %lf    %lf", n, xi, f(xi));
////
////        n++;
////
////    } while (fabs(f(xi)) > eps);
////
////
////   //����� �����������
////    //������� ��� ��������:
////    double F(double x) {
////        return x * (x - 9) * (x + 14);
////    }
////    //������� ����������� �������:
////    double FindRoot(double (*f)(double), double a, double b, double eps) {
////        double c;
////        while ((b - a) / 2 > eps) {
////            c = (a + b) / 2;
////            if ((f(a) * f(c)) > 0) a = c;
////            else b = c;
////        }
////        return c;
////    }
////    int main() {
////        //��������, ������� � ������:
////        double a, b, eps, x;
////        cout << "interval: ";
////        cin >> a;
////        cin >> b;
////        //�������� ����������� ���������
////        if (F(a) * F(b) > 0) {
////            cout << "Wrong interval!\n";
////            return 0;
////        }
////        cout << "error: ";
////        cin >> eps;
////        //����� ������:
////        x = FindRoot(F, a, b, eps);
////        cout << ("x = ");
////
////    return xi;
////}
////    int main(){
////
////    using namespace std;
////    double find(double x, double eps)
////    {
////        double f, df; int iter = 0;
////        cout << "x0= " << x << " ";
////        do {
////           // f = sin(M_PI * x / 180) - 1 / x;
////            df = M_PI / 180 * cos(M_PI * x / 180) + 1 / (x * x);
////            x = x - f / df;
////            iter++;
////        } while (fabs(f) > eps && iter < 20000);
////        cout << iter << " iterations" << endl;
////        return x;
////    }
////    int main()
////    {
////        cout << find(1, 0.00001);
////        cin.get(); return 0;
////    }
////                


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include < time.h >

#define eps 0.0001  //���������� �� ������ � ����� ����� eps


double f(double x); //�������� ������� ��� ��� ��������� �����
double metod_hord(double x1, double x2, unsigned int N, unsigned int debug); //N - ������� ��������, debug- ����� ������������ ������� �� �� �� ������� �������� ����� �������� 
//�������� ������������ � ����� ������� method_hord



double metod_polovinogo_dilenna(double x1, double x2, unsigned int N, unsigned int debug);

double metod_dotychnyx(double x1, unsigned int N, unsigned int debug);



int main()
{
	//double eps = 0.0001;
	int msec = 0, trigger = 10; // 10ms 
	clock_t before = clock();
	



	//long int ttime; // // ���������� ��� ���������� �������� �������
	system("chcp 1251"); 

	double x1, x2, root; // x1 x2 ������� �� ����� �������� ������ ������, root - ������ �����
	unsigned int v, N = 100, debug = 1; // debug = 0 no debug. 1 - print result at each iteration
	printf("1)����� ����\n2)����� ����������� ������\n 3)����� ������� (����� ��������) ");
	do
	{
		
		

		printf("\n����� - ");
		scanf("\n%u, ", &v);

	} while (v != 1 && v != 2 && v != 3); //���� ���� ������������ �� ��� �� ���� �� �������� 1, 2 ��� 3 
	system("cls");
	
	if (v == 1) //��������� ������ ����
	{
		do {
			clock_t difference = clock() - before;
			msec = difference * 1000 / CLOCKS_PER_SEC;

			system("cls");
			printf("x1=");
			scanf("%lf", &x1);
			printf("x2=");
			scanf("%lf", &x2);

		} while (f(x1) * f(x2) > 0 /*|| f(x1)<0 && f(x2)<0*/);

		printf("Time taken %d seconds %d milliseconds \n",
			msec / 1000, msec % 1000);

		root = metod_hord(x1, x2, N, debug); // ���� ����������� �������� ���������� ����, ����������� �������  metod_hord � ����������� ��������� 

		printf("\n\nx=%lf  f(x)=%lf", root, f(root));//������� �������� � �� �������
	}
	else if (v == 2) //��������� ������ ����������� ������ 
	{
		do {
			clock_t difference = clock() - before;
			msec = difference * 1000 / CLOCKS_PER_SEC;

			system("cls");
			printf("x1=");
			scanf("%lf", &x1);
			printf("x2=");
			scanf("%lf", &x2);

		} while (f(x1) * f(x2) > 0);
		

		root = metod_polovinogo_dilenna(x1, x2, N, debug);
		printf("\n\nx=%lf  f(x)=%lf", root, f(root));

		printf("\nTime taken %d seconds %d milliseconds \n",
			msec / 1000, msec % 1000);

	}
	else if (v == 3) //��������� ������ ��������
	{
		//do {
			//clock_t difference = clock() - before;
			//msec = difference * 1000 / CLOCKS_PER_SEC;

		printf("x1=");
		scanf("%lf", &x1);

	//} while

		//printf("\nTime taken %d seconds %d milliseconds (%d iterations)\n",
			//msec / 1000, msec % 1000);

		root = metod_dotychnyx(x1, N, debug);
		printf("\n\nx=%lf  f(x)=%lf", root, f(root));
	}

	

	return 0;
}

double f(double x)
{
	return 2 * pow(x - 4, 3) + 2 * x; // ������� pow ��� � � ��� 2(x-4)^3+2x=0
}



//---------------------------------------------------------------------------------------------------------------//
double metod_hord(double x1, double x2, unsigned int N, unsigned int debug) // �������� ���������� � ����� �������  metod_hord
{
	double xI; // ���������� ����� � ��� ����� �������� ��� ������ 
	int n = 1;
	do
	{
		xI = ((f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1))); // ����� � �������� 

		if (f(xI) * f(x1) > 0) // ���� f(xI) � f(x1) ����������� � ���� ��������
		{
			x1 = xI;
		}
		else
		{
			x2 = xI;   //� ������ �������, ���� � ��� f(xI) � f(x1) ����������� �� ����� ���������� �� ������� �� f(xI) ����������� � ���� �������� �  f(x2)  
		}
		if (debug == 1)
			printf("\n %d %lf  %lf", n, xI, f(xI)); // � - �����

		n++;
	} while (fabs(f(xI) > eps)); // ���� ������ f(xI) ���� ����� eps



	return xI;
}

//---------------------------------------------------------------------------------------------------------------//
double metod_polovinogo_dilenna(double x1, double x2, unsigned int N, unsigned int debug) {  // �������� ���������� � ����� �������  metod_polovinogo_dilenna

	double xj; // ���� ����� �� ������� ������
	int n = 1;
	do
	{
		xj = (x1 + x2) / 2;   // ����� � ��������

		if (f(xj) < 0 /*x1 <= f(xj) <= xj*/)
		{
			x1 = xj;
		}
		else if (f(xj) > 0/*xj <=f(xj) <= x2*/)
		{
			x2 = xj;
		}
		if (debug == 1)
			printf("\n %d %lf  %lf", n, xj, f(xj)); //������� �������� xj 
		n++;

	} while (fabs(x1 - x2) >= eps); // ���� ������ (x1 - x2) ���� ����� ��� ���������� eps



	return xj;

}
//---------------------------------------------------------------------------------------------------------------//

double metod_dotychnyx(double x1, unsigned int N, unsigned int debug)  // �������� ���������� � ����� �������  metod_dotychnyx
{
	double xJ; // �������� �������
	int n = 1, h = 0.1;// h - ����

	double x = 0;
	double fr;
	do
	{
		fr = (f(x1 + 0.1) - f(x1)) / h; // �������

		/*double x = fr * x1;*/
		xJ = f(x1) + (fr * (x - x1));


		xJ = x1 - (f(x1) / fr); // ����� � ��������

		if (debug == 1)
			printf("\n %d %lf  %lf", n, xJ, f(xJ)); //������� �������� xJ
		n++;

	} while (fabs(f(xJ)) <= eps); // ���� ������ (f(xJ)) ���� ����� ��� ���������� eps
	return xJ;

}




