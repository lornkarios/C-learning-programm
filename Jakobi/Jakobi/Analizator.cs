using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jakobi
{
    class Analizator
    {
        public string Analiz(string uravnenie)
        {
            char c;
            int i = 0;
            while (i!=uravnenie.Count())
            {
                c = uravnenie[i];
                if (c == '(')
                {
                    while (c != ')')
                    {
                        i++;
                        c = uravnenie[i];
                    }
                }

            }
        }
    }
}
