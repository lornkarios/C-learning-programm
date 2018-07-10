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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (nBox.Text != "")
            {
                Form f2;
                int i = 0;
                double j = 0;
                bool t = true;
                try
                {
                    i = Convert.ToInt32(nBox.Text); j = Convert.ToDouble(eBox.Text);

                }
                catch
                {
                    MessageBox.Show("Обе формы нужно заполнить в следующем формате 1-ую целым числом,2-ую рациональным!" +
                  "Формы не должны быть пустыми!!!"); t = false;
                }
                if (t)
                {
                    f2 = new Form2(i, j);
                    f2.Owner = this;
                    f2.ShowDialog();
                }
            }
        }
    }
}
