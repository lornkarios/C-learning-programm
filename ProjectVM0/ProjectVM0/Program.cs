using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectVM0
{
    class Program
    {
        public static double epsilon = 0.00001;
        static void Main(string[] args)
        {
            
            Int32 n;
            Console.Write("Введите n=");
            n =Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите матрицу:");
            double[,] A = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    A[i, j] = Convert.ToDouble(Console.ReadLine());
                   
                }
               
            }
            Console.WriteLine("Введите вектор y0:");
            double[] y0 = new double[n];
            for (int i = 0; i < n; i++)
            {
                y0[i] = Convert.ToDouble(Console.ReadLine());
            }
                
            double norma = Math.Abs(y0[0]);

            //находим чебышевскую норму
            for (int i = 0; i < n; i++)
            {
                if (Math.Abs(y0[i]) > norma)
                {
                    norma = Math.Abs(y0[i]);
                }
            }

            //находим вектор x0
            double[] x0 = new double[n];
            double[] xkm1 = new double[n];
            double[] yk = new double[n];
            double[] xk = new double[n];
            double[] lm1 = new double[n];
            Console.WriteLine("Введите вектор lm1:");
            for (int i = 0; i < n; i++)
            {
                lm1[i] = Convert.ToDouble(Console.ReadLine());
            }

           
            double[] l = new double[n];

            for (int i = 0; i < n; i++)
            {
                x0[i]= y0[i]/ norma;
                xkm1[i] = x0[i];
            }

            //наш итеративный алгоритм
            
            do
            {
                //приравниваем xkm1 к xk
              //  for (int i = 0; i < n; i++)
                //{

                  //  xkm1[i] = xk[i];
                //}
                //умножение xk-1 на матрицу A
                for (int i =0; i < n; i++)
                {
                    yk[i] = 0;
                    for (int j = 0; j < n; j++)
                    {
                        yk[i] = yk[i] + A[i, j] * xkm1[j];
                    }
                }

                //вычисляем норму вектора yk
                norma = Math.Abs(yk[0]);
                for (int i = 0; i < n; i++)
                {
                    if (Math.Abs(yk[i]) > norma)
                    {
                        norma = Math.Abs(yk[i]);
                    }
                }
                //находим вектор xk и лямбда
                
                for (int i = 0; i < n; i++)
                {
                    xk[i] = yk[i] / norma;
                    if (Math.Abs(xkm1[i]) > epsilon)
                    {
                        l[i] = yk[i] / xkm1[i];
                    }
                    else
                    {
                        l[i] = 0;
                    }
                    
                }

                for (int i = 0; i < n; i++)
                {
                    xk[i] = yk[i] / norma;
                    if (Math.Abs(xkm1[i]) > epsilon)
                    {
                        l[i] = yk[i] / xkm1[i];
                    }
                    else
                    {
                        l[i] = 0;
                    }

                }
                //проверка на выход
                bool t =true;
                for (int i = 0; i < n; i++)
                {
                    if (l[i] == 0) { continue; }
                    if (Math.Abs(l[i] - lm1[i]) > epsilon)
                    {
                        t = false;
                        break;
                    }
                }
                if (t) { break; }
                for (int i = 0; i < n; i++)
                {
                    xkm1[i] = xk[i];
                    lm1[i] = l[i];
                }
            }
            while (true);
            double l1=0;
            for (int i = 0; i < n; i++)
            {
                l1 += l[i];
            }
            l1 = l1/n;
            Console.Write("l1= ");
            Console.WriteLine( l1);
            Console.WriteLine("xk:");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(Convert.ToString(xk[i]), " ");
            }
            Console.ReadKey();
        }
    }
}
