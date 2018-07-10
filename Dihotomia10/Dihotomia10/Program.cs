using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dihotomia10
{
    class Program
    {
        const double delta = 0.000000001;
        const double epsilon = 0.000002;
        public  static double Func(double x)
        {
            return 2 * x * x - 2 * x + 5 / 2;
        }
        public static int Fib(int n)
        {
            if ((n == 0) ||(n == 1)) { return 1; }
            else { return( Fib(n - 2) + Fib(n - 1)); }
        }
        static void Main(string[] args)
        {
            double x0, x1;
            Console.Write("a= ");
           x0= Convert.ToDouble(Console.ReadLine())+delta;
            Console.Write("b= ");
            x1 = Convert.ToDouble(Console.ReadLine()) - delta;
            int n = 0;
            while ((x1 - x0) >= epsilon)
            {
                if (Func(x1) > Func(x0))
                {
                    x1 = (x0 + x1) / 2-delta;
                }
                else
                {
                    x0 = (x0 + x1) / 2+delta;
                }
                n++;
            }
            Console.WriteLine(x0);
            Console.WriteLine(x1);
            Console.WriteLine(n);
            
            Console.ReadLine();
        }
    }
}
