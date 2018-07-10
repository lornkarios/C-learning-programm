using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jacobi
{
    class Program
    {
        public static double deltaP = 0.00001;
        public static double Uravn(Double[] nZnach, int num,double delta,int nom)
        {
            switch (nom)
            {
                case 2:
                    {
                        double x = nZnach[0];
                        double y = nZnach[1];
                        switch (num)
                        {

                            case 1:
                                x += delta;
                                return x * x + x - y * y - 0.15;
                                break;
                            case 2:
                                y += delta;
                                return x * x - y + y * y + 0.17;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    }
                case 3:
                    {
                        double x = nZnach[0];
                        double y = nZnach[1];
                        //double z = nZnach[2];
                        switch (num)
                        {

                            case 1:
                                x += delta;
                                return Math.Exp(x-1) + x*Math.Log(y+2)-1;
                                break;
                            case 2:
                                y += delta;
                                return Math.Sin(x+y)* Math.Sin(x + y) +y * y*y + 1;
                                break;
                            
                            default:
                                return 0;
                                break;
                        }
                        break;
                    }
                case 4:
                    {
                        double x = nZnach[0];
                        double y = nZnach[1];
                        double z = nZnach[2];
                        switch (num)
                        {

                            case 1:
                                x += delta;
                                return Math.Exp(x - 1) + x * Math.Log(x +y*z) - 1;
                                break;
                            case 2:
                                y += delta;
                                return Math.Sin(x + z) * Math.Sin(x + z) + Math.Cos(y*y)/z +(z+2)*(z+2);
                                break;

                            case 3:
                                z += delta;
                                return x + y * y - z * z * z - 2;
                                break;
                            default:
                                return 0;
                                break;
                        }
                        break;
                    }
                default:
                    return 0;
                    break;
            }
        }
        public static double Norma(Double[] xkoe, Double[] xkp1oe)
        {
            double sum=0;
            for (int i = 0; i < xkoe.Count(); i++)
            {
                sum += (xkoe[i] - xkp1oe[i])*(xkoe[i] - xkp1oe[i]);
            }
            return Math.Sqrt(sum);
        }

        static void Main(string[] args)
        {
            int n,m;
            double epsilon;
            Console.WriteLine("Введите m номер уравнений:");
            m=Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите n количество уравнений:");
            n = Convert.ToInt32(Console.ReadLine());
            Double[] xkoe = new Double[n];
            Double[] xkp1oe = new Double[n];
            Console.WriteLine("Введите вектор начальных значений:");
            for (int i = 0; i < n; i++)
            {
                xkoe[i]=Convert.ToDouble(Console.ReadLine());
            }
            Console.WriteLine("Введите погрешность:");
            epsilon=Convert.ToDouble(Console.ReadLine());
            do
            {
              

                for (int i = 0; i < n; i++)
                {
                    
                    double prUravn = (Uravn(xkoe, i+1, deltaP,m) - Uravn(xkoe, i+1, 0,m)) / deltaP;
                    xkp1oe[i] = xkoe[i] - Uravn(xkoe, i+1, 0,m) / (prUravn);
                  
                }
                for (int i = 0; i < n; i++)
                {

                    double a = xkoe[i];
                    xkoe[i] = xkp1oe[i];
                    xkp1oe[i] = a;

                }
            }
            while (Norma(xkoe,xkp1oe)>epsilon);
            Console.WriteLine("Вектор решения:");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(xkoe[i]);
            }
            Console.ReadLine();
        }
    }
}
