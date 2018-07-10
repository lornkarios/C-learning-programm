namespace PrItSLAU
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.OK = new System.Windows.Forms.Button();
            this.OK2 = new System.Windows.Forms.Button();
            this.form2BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.form2BindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.form2BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.form2BindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(41, 61);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(274, 39);
            this.label1.TabIndex = 1;
            this.label1.Text = "Введите матрицу:";
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(30, 103);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(712, 304);
            this.dataGridView1.TabIndex = 2;
            // 
            // OK
            // 
            this.OK.Location = new System.Drawing.Point(323, 413);
            this.OK.Name = "OK";
            this.OK.Size = new System.Drawing.Size(111, 26);
            this.OK.TabIndex = 3;
            this.OK.Text = "OK";
            this.OK.UseVisualStyleBackColor = true;
            this.OK.Click += new System.EventHandler(this.OK_Click);
            // 
            // OK2
            // 
            this.OK2.Enabled = false;
            this.OK2.Location = new System.Drawing.Point(337, 415);
            this.OK2.Name = "OK2";
            this.OK2.Size = new System.Drawing.Size(75, 23);
            this.OK2.TabIndex = 4;
            this.OK2.Text = "OK";
            this.OK2.UseVisualStyleBackColor = true;
            this.OK2.Visible = false;
            this.OK2.Click += new System.EventHandler(this.OK2_Click);
            // 
            // form2BindingSource
            // 
            this.form2BindingSource.DataSource = typeof(PrItSLAU.Form2);
            // 
            // form2BindingSource1
            // 
            this.form2BindingSource1.DataSource = typeof(PrItSLAU.Form2);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(754, 451);
            this.Controls.Add(this.OK2);
            this.Controls.Add(this.OK);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.Text = "Ввод Матрицы";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.form2BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.form2BindingSource1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource form2BindingSource;
        private System.Windows.Forms.BindingSource form2BindingSource1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button OK;
        private System.Windows.Forms.Button OK2;
    }
}