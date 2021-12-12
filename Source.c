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
////   //Метод половинного
////    //Функція для полинома:
////    double F(double x) {
////        return x * (x - 9) * (x + 14);
////    }
////    //Функція знаходження корення:
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
////        //Интервал, похибка і корень:
////        double a, b, eps, x;
////        cout << "interval: ";
////        cin >> a;
////        cin >> b;
////        //Перевірка правильності інтегралу
////        if (F(a) * F(b) > 0) {
////            cout << "Wrong interval!\n";
////            return 0;
////        }
////        cout << "error: ";
////        cin >> eps;
////        //пошук рішення:
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

#define eps 0.0001  //наближення до кореня в межах певної eps


double f(double x); //прототип функції для якої знаходимо корінь
double metod_hord(double x1, double x2, unsigned int N, unsigned int debug); //N - кількість ітерацій, debug- режим налагодження відповідає за те чи потрібно виводити кожну ітерацію 
//алгоритм реалізовується в межах функції method_hord



double metod_polovinogo_dilenna(double x1, double x2, unsigned int N, unsigned int debug);

double metod_dotychnyx(double x1, unsigned int N, unsigned int debug);



int main()
{
	//double eps = 0.0001;
	int msec = 0, trigger = 10; // 10ms 
	clock_t before = clock();
	



	//long int ttime; // // Переменная для сохранения текущего времени
	system("chcp 1251"); 

	double x1, x2, root; // x1 x2 початок та кінець діапазону пошуку кореня, root - зберігає корінь
	unsigned int v, N = 100, debug = 1; // debug = 0 no debug. 1 - print result at each iteration
	printf("1)Метод хорд\n2)Метод половинного ділення\n 3)Метод Ньютона (метод дотичних) ");
	do
	{
		
		

		printf("\nМетод - ");
		scanf("\n%u, ", &v);

	} while (v != 1 && v != 2 && v != 3); //цикл буде виконуватися до тих пір коли не виберемо 1, 2 або 3 
	system("cls");
	
	if (v == 1) //виконання методу хорд
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

		root = metod_hord(x1, x2, N, debug); // після проходження перевірки початкових умов, викликається функція  metod_hord і передаються параметри 

		printf("\n\nx=%lf  f(x)=%lf", root, f(root));//вивести значення х та функції
	}
	else if (v == 2) //виконання методу половинного ділення 
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
	else if (v == 3) //виконання методу дотичних
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
	return 2 * pow(x - 4, 3) + 2 * x; // функція pow для х у кубі 2(x-4)^3+2x=0
}



//---------------------------------------------------------------------------------------------------------------//
double metod_hord(double x1, double x2, unsigned int N, unsigned int debug) // алгоритм виконується в межах функції  metod_hord
{
	double xI; // координата точки в якій хорда перетинає вісь абсцис 
	int n = 1;
	do
	{
		xI = ((f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1))); // згідно з формулою 

		if (f(xI) * f(x1) > 0) // якщо f(xI) и f(x1) знаходяться в одній півплощині
		{
			x1 = xI;
		}
		else
		{
			x2 = xI;   //в іншому випадку, якщо у нас f(xI) и f(x1) знаходяться по різних півплощинах це значить що f(xI) знаходиться в одній півплощині з  f(x2)  
		}
		if (debug == 1)
			printf("\n %d %lf  %lf", n, xI, f(xI)); // п - номер

		n++;
	} while (fabs(f(xI) > eps)); // поки модуль f(xI) буде більше eps



	return xI;
}

//---------------------------------------------------------------------------------------------------------------//
double metod_polovinogo_dilenna(double x1, double x2, unsigned int N, unsigned int debug) {  // алгоритм виконується в межах функції  metod_polovinogo_dilenna

	double xj; // нова точка на середині відрізку
	int n = 1;
	do
	{
		xj = (x1 + x2) / 2;   // згідно з формулою

		if (f(xj) < 0 /*x1 <= f(xj) <= xj*/)
		{
			x1 = xj;
		}
		else if (f(xj) > 0/*xj <=f(xj) <= x2*/)
		{
			x2 = xj;
		}
		if (debug == 1)
			printf("\n %d %lf  %lf", n, xj, f(xj)); //вивести значення xj 
		n++;

	} while (fabs(x1 - x2) >= eps); // поки модуль (x1 - x2) буде більше або дорівнювати eps



	return xj;

}
//---------------------------------------------------------------------------------------------------------------//

double metod_dotychnyx(double x1, unsigned int N, unsigned int debug)  // алгоритм виконується в межах функції  metod_dotychnyx
{
	double xJ; // значення рівняння
	int n = 1, h = 0.1;// h - крок

	double x = 0;
	double fr;
	do
	{
		fr = (f(x1 + 0.1) - f(x1)) / h; // похідна

		/*double x = fr * x1;*/
		xJ = f(x1) + (fr * (x - x1));


		xJ = x1 - (f(x1) / fr); // згідно з формулою

		if (debug == 1)
			printf("\n %d %lf  %lf", n, xJ, f(xJ)); //вивести значення xJ
		n++;

	} while (fabs(f(xJ)) <= eps); // поки модуль (f(xJ)) буде менше або дорівнювати eps
	return xJ;

}




