using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace lab1
{
    public partial class Form1 : Form
    {
        string connectionString  = ConfigurationManager.ConnectionStrings["cn"].ConnectionString;
        string parentTablePrimaryKey = ConfigurationManager.AppSettings["parentTablePrimaryKey"];
        string childTablePrimaryKey = ConfigurationManager.AppSettings["childTablePrimaryKey"];
        string childTableForeignKey = ConfigurationManager.AppSettings["childTableForeignKey"];
        string parentTableName = ConfigurationManager.AppSettings["parentTable"];
        string childTableName = ConfigurationManager.AppSettings["childTable"];
        string parentChildValue = ConfigurationManager.AppSettings["parentChildValue"];
        List<string> childColumnNames = ConfigurationManager.AppSettings["childColumnNames"].Split(',').ToList();
        List<string> parentColumnNames = ConfigurationManager.AppSettings["parentColumnNames"].Split(',').ToList();
        List<string> childColumnNamesUpdate = ConfigurationManager.AppSettings["childColumnNamesUpdate"].Split(',').ToList();



        SqlConnection conn;
        SqlDataAdapter dataAdapter;
        DataSet dataSet;

        public Form1()
        {
            conn = new SqlConnection(connectionString);
            dataAdapter = new SqlDataAdapter();
            dataSet = new DataSet();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'lab1DataSet.Echipe' table. You can move, or remove it, as needed.
            //this.echipeTableAdapter.Fill(this.lab1DataSet.Echipe);
            initCompoonentsDynamic();
            try
            {
                conn.Open();
                dataAdapter.SelectCommand = new SqlCommand("SELECT * FROM " + parentTableName, conn);
                

                if(dataSet.Tables[parentTableName] != null)
                    dataSet.Tables[parentTableName].Clear();
                dataAdapter.Fill(dataSet, parentTableName);


                dataGridView2.AutoGenerateColumns = true;


                dataGridView2.DataSource = dataSet.Tables[parentTableName];

                foreach (DataGridViewTextBoxColumn column in dataGridView2.Columns)
                {
                    Console.WriteLine(column.HeaderText);
                }


                if (dataGridView2.Columns[parentTablePrimaryKey] == null)
                {
                    MessageBox.Show("Table " + parentTableName + " not found in the database.");
                    return;
                }

                dataGridView2.Columns[parentTablePrimaryKey].Visible = false;

                foreach (DataGridViewRow row in dataGridView2.Rows)
                    row.Tag = row.Cells[parentTablePrimaryKey].Value;

                foreach (DataGridViewColumn column in dataGridView2.Columns)
                {
                    if (column.Name.StartsWith("id", StringComparison.OrdinalIgnoreCase))
                    {
                        column.Visible = false;
                    }
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        private void initCompoonentsDynamic()
        {
            foreach(string columnName in childColumnNames)
            {
                TextBox textBox2 = new TextBox();
                Label label2 = new Label();
                textBox2.Name = columnName;
                textBox2.Location = new Point(110, 10 + ((childColumnNames.IndexOf(columnName)+1) * 20));
                textBox2.Size = new Size(200, 20);
                if (columnName == childTableForeignKey)
                {
                    textBox2.ReadOnly = true;
                }
                this.inputPanel.Controls.Add(textBox2);

                label2.Text = columnName;
                label2.Location = new Point(10, 10 + ((childColumnNames.IndexOf(columnName) + 1) * 20));
                label2.Size = new Size(100, 20);
                this.inputPanel.Controls.Add(label2);
            }

            TextBox textBox = new TextBox();
            Label label = new Label();
            textBox.Name = childTablePrimaryKey;
            textBox.Location = new Point(110, 10 + (0 * 20));
            textBox.Size = new Size(200, 20);
            textBox.ReadOnly = true;
            this.inputPanel.Controls.Add(textBox);

            label.Text = childTablePrimaryKey;
            label.Location = new Point(10, 10 + (0 * 20));
            label.Size = new Size(100, 20);
            this.inputPanel.Controls.Add(label);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox.Text == null || textBox.Text == "")
                    {
                        MessageBox.Show("Field " + columnName + " must be completed");
                        return;
                    }
                }

                dataAdapter.InsertCommand = new SqlCommand("INSERT INTO " + childTableName +"(" + string.Join(", ", childColumnNames) + ") VALUES (" + string.Join(", ", childColumnNames.Select(column => "@" + column)) + ")", conn);

                foreach (string columnName in childColumnNames)
                {
                    dataAdapter.InsertCommand.Parameters.Add("@" + columnName, SqlDbType.VarChar).Value = this.inputPanel.Controls[columnName].Text;
                }

                dataAdapter.InsertCommand.ExecuteNonQuery();
                MessageBox.Show("Data for table " + childTableName + " added succesfully!");
                conn.Close();

                dataSet.Tables.Clear();
                dataAdapter.Fill(dataSet, childTableName);
                dataGridView1.DataSource = dataSet.Tables[childTableName];

                foreach (string columnName in childColumnNamesUpdate)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox != null)
                    {
                        textBox.Text = "";
                    }
                }
                TextBox textBoxPrimaryKey = (TextBox)this.inputPanel.Controls[childTablePrimaryKey];
                textBoxPrimaryKey.Text = "";

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                conn.Close();
            }
        }

        private void dataGridView2_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {

                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox != null && !textBox.ReadOnly)
                    {
                        textBox.Text = "";
                    }
                }
                TextBox textBoxPrimaryKey = (TextBox)this.inputPanel.Controls[childTablePrimaryKey];
                textBoxPrimaryKey.Text = "";

                int childForeignKeyValue = Convert.ToInt32(dataGridView2.Rows[e.RowIndex].Cells[childTableForeignKey].Value);

                string queryJucatori2 = "SELECT " +childTableName+"."+childTablePrimaryKey+", " + string.Join(", ", childColumnNames.Select(column => childTableName + "." + column)) + ", " + parentTableName + "." + parentChildValue +
                    " FROM " + childTableName +
                    " INNER JOIN " + parentTableName + " ON " + childTableName + "." + childTableForeignKey + " = " + parentTableName + "." + parentTablePrimaryKey +
                    " WHERE " + parentTableName + "." + parentTablePrimaryKey + " = @" + parentTablePrimaryKey;

                SqlCommand command = new SqlCommand(queryJucatori2, conn);
                command.Parameters.AddWithValue("@"+childTableForeignKey, childForeignKeyValue);
                dataAdapter.SelectCommand = command;

                if (dataSet.Tables[childTableName] != null)
                    dataSet.Tables[childTableName].Clear();
                dataAdapter.Fill(dataSet, childTableName);


                dataGridView1.AutoGenerateColumns = true;


                dataGridView1.DataSource = dataSet.Tables[childTableName];

                dataGridView1.Columns[childTablePrimaryKey].Visible = false;


                foreach (DataGridViewColumn column in dataGridView1.Columns)
                {
                    if (column.Name.StartsWith("id", StringComparison.OrdinalIgnoreCase))
                    {
                        column.Visible = false;
                    }
                }

           
                conn.Close();

                labelSearch.Text = "Entitati din " + dataGridView2.Rows[e.RowIndex].Cells[parentChildValue].Value;
                this.inputPanel.Controls[childTableForeignKey].Text = childForeignKeyValue.ToString();
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox2 = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox2 != null)
                    {
                        textBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[columnName].Value.ToString();
                    }
                }
                TextBox textBox = (TextBox)this.inputPanel.Controls[childTablePrimaryKey];
                if (textBox != null)
                {
                    textBox.Text = dataGridView1.Rows[e.RowIndex].Cells[childTablePrimaryKey].Value.ToString();
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                foreach (string columnName in childColumnNamesUpdate)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox.Text == null || textBox.Text == "")
                    {
                        MessageBox.Show("Field " + columnName + " must be completed");
                        return;
                    }
                }
                conn.Open();
                string updateQuery = "UPDATE " + childTableName + " SET " + string.Join(", ", childColumnNamesUpdate.Select(column => column + "=@" + column)) + " WHERE "+childTablePrimaryKey+"=@"+ childTablePrimaryKey;
                dataAdapter.UpdateCommand = new SqlCommand(updateQuery, conn);
                foreach (string columnName in childColumnNamesUpdate)
                {
                    dataAdapter.UpdateCommand.Parameters.Add("@" + columnName, SqlDbType.VarChar).Value = this.inputPanel.Controls[columnName].Text;
                }
                
                TextBox textBoxPrimaryKey = (TextBox)this.inputPanel.Controls[childTablePrimaryKey];
   
                dataAdapter.UpdateCommand.Parameters.Add("@" + childTablePrimaryKey, SqlDbType.Int).Value = Convert.ToInt32(textBoxPrimaryKey.Text);
                dataAdapter.UpdateCommand.ExecuteNonQuery();
                MessageBox.Show("S a modificat o entitate in tabelul " + childTableName);
                conn.Close();
                dataSet.Tables.Clear();
                dataAdapter.Fill(dataSet, childTableName);
                dataGridView1.DataSource = dataSet.Tables[childTableName];
                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox != null && !textBox.ReadOnly)
                    {
                        textBox.Text = "";
                    }
                }
                textBoxPrimaryKey.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                conn.Close();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox.Text == null || textBox.Text == "")
                    {
                        MessageBox.Show("Field " + columnName + " must be completed");
                        return;
                    }
                    
                }
                string deleteQuery = "DELETE FROM " + childTableName + " WHERE " + string.Join(" AND ", childColumnNames.Select(column => column + " = @" + column));
                conn.Open();
                dataAdapter.DeleteCommand = new SqlCommand(deleteQuery, conn);
                foreach (string columnName in childColumnNames)
                {
                    dataAdapter.DeleteCommand.Parameters.Add("@" + columnName, SqlDbType.VarChar).Value = this.inputPanel.Controls[columnName].Text;
                }
                dataAdapter.DeleteCommand.ExecuteNonQuery();
                MessageBox.Show("S a sters o entitate din tabelul " + childTableName);
                conn.Close();
                dataSet.Tables.Clear();
                dataAdapter.Fill(dataSet, childTableName);
                dataGridView1.DataSource = dataSet.Tables[childTableName];
                foreach (string columnName in childColumnNames)
                {
                    TextBox textBox = (TextBox)this.inputPanel.Controls[columnName];
                    if (textBox != null && !textBox.ReadOnly)
                    {
                        textBox.Text = "";
                    } 
                }
                TextBox textBoxPrimaryKey = (TextBox)this.inputPanel.Controls[childTablePrimaryKey];
                textBoxPrimaryKey.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                conn.Close();

            }
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
