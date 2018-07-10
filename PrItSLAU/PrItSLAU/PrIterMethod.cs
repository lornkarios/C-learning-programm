using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrItSLAU
{
    class PrIterMethod
    {
        public Double[,] C1;

        public Double[] C2;



        

        

        public Double[,] IterForm(Double[,] A, Double[] b, int n)
        {
            C1 = new Double[n, n];
           C2 = new Double[n];
            //получение итерационной формы системы
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    
                        
                   
                        if (i == j)
                        {
                            C1[i, j] = 0;
                        }
                        else
                        {
                            C1[i, j] = -A[i, j] / A[i, i];
                        }
                    
                }
                C2[i] = b[i]/ A[i, i];
            }
            
            return C1;
        }

        public bool ProverkaShod(Double[,] C, int n)
        {
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    sum += C[i, j] * C[i, j];
                }
            }
            return !(Math.Sqrt(Math.Abs(sum)) > 1);
        }

        public Double[] MethodI(Double[,] C, Double[] d, int n,double epsilon)
        {
            Double[] X0 = new Double[n];
            double delta;
            Double[] E = new Double[n];
            Double[] X = new Double[n];
           
            for (int i = 0; i < n; i++) { X0[i] = d[i]; }
            do
            {
                for (int i = 0; i < n; i++)
                {
                    X[i] = 0;
                    for (int j = 0; j < n; j++)
                    {
                        X[i]+= C[i, j] * X0[j];
                    }
                    X[i] += d[ i];
                    E[i]= Math.Abs(X[i] - X0[i]);
                }
                delta = E[0];
                for (int i = 1; i < n; i++)
                {
                    if (delta < E[i])
                    {
                        delta = E[i];
                    }
                }
                
                for (int i = 0; i < n; i++) { X0[i] = X[i]; }
            } while (delta>epsilon);
            return X;
        }
                
    }
}


 

