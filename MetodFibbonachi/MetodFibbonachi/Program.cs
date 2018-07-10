using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MetodFibbonachi
{
    class Program
    {

        public static int N =7;
        public static double epsilon = 0.5;

        public static double Func(double x)
        {
            return 2 * x * x - 2 * x + 5 / 2;
        }
        public static int Fib(int n)
        {
            if ((n == 1) || (n == 2)) { return 1; }
            else { return (Fib(n - 2) + Fib(n - 1)); }
        }
        static void Main(string[] args)
        {
            double x0, y0,a0,b0,ai,bi,yi,xi,aip1,bip1,yip1,xip1;
            Console.Write("a= ");
            a0 = Convert.ToDouble(Console.ReadLine());
            Console.Write("b= ");
            b0 = Convert.ToDouble(Console.ReadLine());
            x0 = a0 + (b0-a0)*Fib(N-2)/Fib(N);
            y0 = a0 + (b0 - a0) * Fib(N - 1) / Fib(N);
            if (Func(x0) < Func(y0))
            {
                ai = a0;
                bi = y0;
                yi = x0;
                xi = ai + bi-yi;
            }
            else
            {
                ai = x0;
                bi = b0;
                xi = y0;
                yi = ai + bi - xi;
            }

            
            for(int i = 2; i < N; i++)
            { 
                if (Func(xi) < Func(yi))
                {
                    aip1 = ai;
                    bip1 = yi;
                    yip1 = xi;
                    xip1 = aip1 + bip1 - yip1;
                }
                else
                {
                    aip1 = ai;
                    bip1 = bi;
                    xip1 = yi;
                    yip1 = aip1 + bip1 - xip1;
                }
                ai = aip1;
                bi = bip1;
                yi = yip1;
                xi = xip1;
                
            }

            Console.WriteLine(xi);
            Console.WriteLine(yi);

            Console.ReadLine();

        }
    }
}
