namespace lab1
{
    partial class Form1
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.id_jucator = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.nume_juc = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.prenume_juc = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.jucatoriBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.lab1DataSet = new lab1.Lab1DataSet();
            this.jucatoriTableAdapter = new lab1.Lab1DataSetTableAdapters.JucatoriTableAdapter();
            this.echipeBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.echipeTableAdapter = new lab1.Lab1DataSetTableAdapters.EchipeTableAdapter();
            this.idEchipa = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nume_echipa = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.datadeschidereDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.idsponsorDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.idstadionDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.idantrenorDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.jucatoriBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lab1DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.echipeBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.nume_juc,
            this.prenume_juc,
            this.id_jucator});
            this.dataGridView1.DataSource = this.jucatoriBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(523, 45);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(525, 150);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // id_jucator
            // 
            this.id_jucator.DataPropertyName = "id_jucator";
            this.id_jucator.HeaderText = "id_jucator";
            this.id_jucator.MinimumWidth = 6;
            this.id_jucator.Name = "id_jucator";
            this.id_jucator.ReadOnly = true;
            this.id_jucator.Visible = false;
            this.id_jucator.Width = 125;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(522, 228);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "Nume:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(522, 266);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Prenume:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(774, 231);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(88, 16);
            this.label3.TabIndex = 4;
            this.label3.Text = "Nume Echipa";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(607, 228);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(134, 22);
            this.textBox1.TabIndex = 5;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(607, 264);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(134, 22);
            this.textBox2.TabIndex = 6;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(868, 228);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(134, 22);
            this.textBox3.TabIndex = 7;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button2.Location = new System.Drawing.Point(707, 315);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(155, 40);
            this.button2.TabIndex = 8;
            this.button2.Text = "Add";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idEchipa,
            this.nume_echipa,
            this.datadeschidereDataGridViewTextBoxColumn,
            this.idsponsorDataGridViewTextBoxColumn,
            this.idstadionDataGridViewTextBoxColumn,
            this.idantrenorDataGridViewTextBoxColumn});
            this.dataGridView2.DataSource = this.echipeBindingSource;
            this.dataGridView2.Location = new System.Drawing.Point(35, 45);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(450, 359);
            this.dataGridView2.TabIndex = 9;
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellContentClick_1);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Red;
            this.button1.Location = new System.Drawing.Point(637, 361);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(134, 43);
            this.button1.TabIndex = 10;
            this.button1.Text = "Delete";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.Red;
            this.button3.Location = new System.Drawing.Point(807, 361);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(127, 43);
            this.button3.TabIndex = 11;
            this.button3.Text = "Update";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(774, 269);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(68, 16);
            this.label4.TabIndex = 12;
            this.label4.Text = "Id Jucator:";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(868, 267);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(134, 22);
            this.textBox4.TabIndex = 13;
            // 
            // nume_juc
            // 
            this.nume_juc.DataPropertyName = "nume_juc";
            this.nume_juc.HeaderText = "Nume Jucator";
            this.nume_juc.MinimumWidth = 6;
            this.nume_juc.Name = "nume_juc";
            this.nume_juc.Width = 125;
            // 
            // prenume_juc
            // 
            this.prenume_juc.DataPropertyName = "prenume_juc";
            this.prenume_juc.HeaderText = "Prenume Jucator";
            this.prenume_juc.MinimumWidth = 6;
            this.prenume_juc.Name = "prenume_juc";
            this.prenume_juc.Width = 125;
            // 
            // jucatoriBindingSource
            // 
            this.jucatoriBindingSource.DataMember = "Jucatori";
            this.jucatoriBindingSource.DataSource = this.lab1DataSet;
            // 
            // lab1DataSet
            // 
            this.lab1DataSet.DataSetName = "Lab1DataSet";
            this.lab1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // jucatoriTableAdapter
            // 
            this.jucatoriTableAdapter.ClearBeforeFill = true;
            // 
            // echipeBindingSource
            // 
            this.echipeBindingSource.DataMember = "Echipe";
            this.echipeBindingSource.DataSource = this.lab1DataSet;
            // 
            // echipeTableAdapter
            // 
            this.echipeTableAdapter.ClearBeforeFill = true;
            // 
            // idEchipa
            // 
            this.idEchipa.DataPropertyName = "id_echipa";
            this.idEchipa.HeaderText = "id_echipa";
            this.idEchipa.MinimumWidth = 6;
            this.idEchipa.Name = "idEchipa";
            this.idEchipa.ReadOnly = true;
            this.idEchipa.Visible = false;
            this.idEchipa.Width = 125;
            // 
            // nume_echipa
            // 
            this.nume_echipa.DataPropertyName = "nume_echipa";
            this.nume_echipa.HeaderText = "Nume Echipa";
            this.nume_echipa.MinimumWidth = 6;
            this.nume_echipa.Name = "nume_echipa";
            this.nume_echipa.Width = 125;
            // 
            // datadeschidereDataGridViewTextBoxColumn
            // 
            this.datadeschidereDataGridViewTextBoxColumn.DataPropertyName = "data_deschidere";
            this.datadeschidereDataGridViewTextBoxColumn.HeaderText = "Data Infiintarii";
            this.datadeschidereDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.datadeschidereDataGridViewTextBoxColumn.Name = "datadeschidereDataGridViewTextBoxColumn";
            this.datadeschidereDataGridViewTextBoxColumn.Width = 125;
            // 
            // idsponsorDataGridViewTextBoxColumn
            // 
            this.idsponsorDataGridViewTextBoxColumn.DataPropertyName = "id_sponsor";
            this.idsponsorDataGridViewTextBoxColumn.HeaderText = "id_sponsor";
            this.idsponsorDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.idsponsorDataGridViewTextBoxColumn.Name = "idsponsorDataGridViewTextBoxColumn";
            this.idsponsorDataGridViewTextBoxColumn.Visible = false;
            this.idsponsorDataGridViewTextBoxColumn.Width = 125;
            // 
            // idstadionDataGridViewTextBoxColumn
            // 
            this.idstadionDataGridViewTextBoxColumn.DataPropertyName = "id_stadion";
            this.idstadionDataGridViewTextBoxColumn.HeaderText = "id_stadion";
            this.idstadionDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.idstadionDataGridViewTextBoxColumn.Name = "idstadionDataGridViewTextBoxColumn";
            this.idstadionDataGridViewTextBoxColumn.Visible = false;
            this.idstadionDataGridViewTextBoxColumn.Width = 125;
            // 
            // idantrenorDataGridViewTextBoxColumn
            // 
            this.idantrenorDataGridViewTextBoxColumn.DataPropertyName = "id_antrenor";
            this.idantrenorDataGridViewTextBoxColumn.HeaderText = "id_antrenor";
            this.idantrenorDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.idantrenorDataGridViewTextBoxColumn.Name = "idantrenorDataGridViewTextBoxColumn";
            this.idantrenorDataGridViewTextBoxColumn.Visible = false;
            this.idantrenorDataGridViewTextBoxColumn.Width = 125;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1060, 450);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.jucatoriBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lab1DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.echipeBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private Lab1DataSet lab1DataSet;
        private System.Windows.Forms.BindingSource jucatoriBindingSource;
        private Lab1DataSetTableAdapters.JucatoriTableAdapter jucatoriTableAdapter;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridViewTextBoxColumn nume_juc;
        private System.Windows.Forms.DataGridViewTextBoxColumn prenume_juc;
        private System.Windows.Forms.DataGridViewTextBoxColumn id_echipa;
        private System.Windows.Forms.DataGridViewTextBoxColumn id_jucator;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.BindingSource echipeBindingSource;
        private Lab1DataSetTableAdapters.EchipeTableAdapter echipeTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idEchipa;
        private System.Windows.Forms.DataGridViewTextBoxColumn nume_echipa;
        private System.Windows.Forms.DataGridViewTextBoxColumn datadeschidereDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn idsponsorDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn idstadionDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn idantrenorDataGridViewTextBoxColumn;
    }
}

