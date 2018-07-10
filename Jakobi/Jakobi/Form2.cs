using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Jakobi
{
    public partial class Form2 : Form
    {
        public static int n;
        public static double epsilon;
        public Double[] MainMatrix;
       


        public Form2(int n1, double epsilon1)
        {
            InitializeComponent();
            n = n1;
            epsilon = epsilon1;
            MainMatrix = new Double[n];
          
            for (int i = 0; i < n ; i++)
            {
                
                    dataGridView1.Columns.Add("C" + i, "A" + (i + 1));
                

            }
            dataGridView1.Rows.Add();
            dataGridView1.AllowUserToAddRows = false;
        }

        

        private void OK_Click_1(object sender, EventArgs e)
        {
            bool t = true;
            try
            {
                for (int i = 0; i < n; i++)
                {
                    

                        MainMatrix[i] = Convert.ToDouble(dataGridView1[i, 0].Value);


                    
                }

            }
            catch { MessageBox.Show("Ошибка!!! введите все ячейки в формате Double!!! пустых быть не должно!"); t = false; }
            if (t)
            {
                this.Hide();
                
                Form3 f2 = new Form3(n, epsilon, MainMatrix,1);

                f2.ShowDialog();
            }
        }


    }
}
