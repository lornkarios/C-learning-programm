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
    public partial class Form3 : Form
    {
        
        public Double[] MainVector;
        public int iteration;
        public int n;
        public double epsilon;
        public List<string> uravneniya = new List<string>();

        public Form3(int n1, double epsilon1,Double[] MainVector1,int iteration1)
        {
            InitializeComponent();
            MainVector = MainVector1;
            iteration = iteration1;
            n = n1;
            epsilon = epsilon1;
        }
        public Form3(int n1, double epsilon1, Double[] MainVector1, int iteration1, List<string> uravneniya1)
        {
            InitializeComponent();
            MainVector = MainVector1;
            iteration = iteration1;
           
            for (int i = 0; i < uravneniya1.Count; i++)
            {
                uravneniya.Add(uravneniya1[i]);
            }
            
            n = n1;
            epsilon = epsilon1;
            label1.Text = "Введите "+iteration+"-ое уравнение:";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (iteration < n)
            {
                uravneniya.Add(textBox1.Text);
                this.Hide();
                
                Form3 f2 = new Form3(n, epsilon, MainVector, iteration + 1,uravneniya);

                f2.ShowDialog();
            }
            else
            {

            }
        }
    }
}
