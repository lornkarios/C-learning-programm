using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PrItSLAU
{
    public partial class Form2 : Form
    {
        public static int n;
        public static double epsilon;
        public Double[,] MainMatrix;
        public Double[] MainVector;


        public Form2(int n1,double epsilon1)
        {
            InitializeComponent();
            n = n1;
            epsilon = epsilon1;
             MainMatrix = new Double[n, n];
            MainVector = new Double[n];
            for (int i = 0; i < n+1; i++) {
                if (i != n)
                {
                    dataGridView1.Columns.Add("C" + i, "A" + (i + 1));
                }
                else
                {
                    dataGridView1.Columns.Add("C" + i, "b" );
                }

               
            }
            for (int i = 0; i < n; i++)
            {
                dataGridView1.Rows.Add("");
            }
            dataGridView1.AllowUserToAddRows = false;
        }

        public Form2(int n1,double epsilon1, Double[,] MainMatrix1, Double[] MainVector1)
        {
            InitializeComponent();
            n = n1;
            MainMatrix= new Double[n, n];
            MainVector = new Double[n];
            epsilon = epsilon1;
            for (int i = 0; i < n + 1; i++)
            {
                if (i != n)
                {
                    dataGridView1.Columns.Add("C" + i, "C" + (i + 1));
                }
                else
                {
                    dataGridView1.Columns.Add("C" + i, "d");
                }


            }
            for (int i = 0; i < n; i++)
            {
                dataGridView1.Rows.Add("");
            }


            for (int i=0; i < n+1; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != n)
                    {
                        MainMatrix[i, j] = MainMatrix1[i, j];
                        dataGridView1[j, i].Value = MainMatrix[i, j];
                    }
                    else
                    {
                        MainVector[j] = MainVector1[j];
                        dataGridView1[n, j].Value = MainVector[j];
                    }
                }
            }
            OK2.Visible = true;
            OK2.Enabled = true;
            OK.Visible = false;
            OK.Enabled = false;
            dataGridView1.ReadOnly = true;
            dataGridView1.AllowUserToAddRows = false;
            label1.Text = "Итерационная форма";
        }

        private void OK_Click(object sender, EventArgs e)
        {
            bool t = true;
            try
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        
                            MainMatrix[i, j] = Convert.ToDouble(dataGridView1[j, i].Value);
                        
                       
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    MainVector[i] = Convert.ToDouble(dataGridView1[n, i].Value);
                }
            }
            catch { MessageBox.Show("Ошибка!!! введите все ячейки в формате Double!!! пустых быть не должно!"); t = false; }
            if (t)
            {
                this.Hide();
                PrIterMethod pr = new PrIterMethod();
                Form2 f2 = new Form2(n,epsilon,pr.IterForm(MainMatrix,MainVector,n),pr.C2);
                
                f2.ShowDialog();
            }
        }

        private void OK2_Click(object sender, EventArgs e)
        {
            PrIterMethod pr = new PrIterMethod();
            Double[,] C = MainMatrix;
           
            Double[] X = new Double[n];
            Double[] d = MainVector;
            
            if (!pr.ProverkaShod(C, n)) { MessageBox.Show("Данная система не удовлетворяет условию сходимости!!"); }
            else {
                X = pr.MethodI(C,d, n, epsilon);
               // Form2 f2 = new Form2(n, epsilon,C,X);
                //f2.ShowDialog();
                string s = "решение системы равно вектору: {";
                for (int i = 0; i < n; i++)
                {
                    s += X[i]+"; ";
                }
                s += "}";
                MessageBox.Show(s);
               this.Close();
            }
        }
    }
}
