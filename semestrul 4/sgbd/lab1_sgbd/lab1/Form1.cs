using System;
using System.Collections.Generic;
using System.ComponentModel;
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
        SqlConnection conn = new SqlConnection("Data Source=DESKTOP-QFDCA28;Initial Catalog=Lab1;Integrated Security=True");
        SqlDataAdapter dataAdapter = new SqlDataAdapter();
        DataSet dataSet = new DataSet("Lab1DataSet");

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'lab1DataSet.Echipe' table. You can move, or remove it, as needed.
            this.echipeTableAdapter.Fill(this.lab1DataSet.Echipe);
            try
            {
                
                conn.Open();
                dataAdapter.SelectCommand = new SqlCommand("SELECT * FROM Echipe", conn);
                dataSet.Clear();
                dataAdapter.Fill(dataSet, "Echipe");
                
                dataGridView2.DataSource = dataSet.Tables["Echipe"];
                //dataGridView2.Columns["id_echipa"].Visible = false;
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

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string queryForEchipa = "SELECT id_echipa FROM Echipe WHERE nume_echipa = @nume_echipa";
                conn.Open();

                SqlCommand command = new SqlCommand(queryForEchipa, conn);
                command.Parameters.AddWithValue("@nume_echipa", textBox3.Text);
                var result = command.ExecuteScalar();
                if (result == null)
                {
                    MessageBox.Show("Echipa nu exista in baza de date!");
                    conn.Close();
                    return;
                }
                int idEchipa = Convert.ToInt32(result);

                dataAdapter.InsertCommand = new SqlCommand("INSERT INTO Jucatori (nume_juc, prenume_juc, id_echipa) VALUES (@nume_juc, @prenume_juc, @id_echipa)", conn);
                dataAdapter.InsertCommand.Parameters.Add("@nume_juc", SqlDbType.VarChar).Value = textBox1.Text;
                dataAdapter.InsertCommand.Parameters.Add("@prenume_juc", SqlDbType.VarChar).Value = textBox2.Text;
                dataAdapter.InsertCommand.Parameters.Add("@id_echipa", SqlDbType.Int).Value = idEchipa;

                dataAdapter.InsertCommand.ExecuteNonQuery();
                MessageBox.Show("Jucator adaugat cu succes!");
                conn.Close();

                dataSet.Tables.Clear();
                dataAdapter.Fill(dataSet, "Jucatori");
                dataGridView1.DataSource = dataSet.Tables["Jucatori"];

                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
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
                int idEchipa = Convert.ToInt32(dataGridView2.Rows[e.RowIndex].Cells["idEchipa"].Value);
                string numeEchipa = dataGridView2.Rows[e.RowIndex].Cells["nume_echipa"].Value.ToString();
                string queryJucatori = @"
                SELECT Jucatori.id_jucator, Jucatori.nume_juc, Jucatori.prenume_juc, 
                Echipe.nume_echipa 
                FROM Jucatori 
                INNER JOIN Echipe ON Jucatori.id_echipa = Echipe.id_echipa
                WHERE Echipe.id_echipa = @idEchipa";

                conn.Open();
                SqlCommand command = new SqlCommand(queryJucatori, conn);
                command.Parameters.AddWithValue("@idEchipa", idEchipa);
                dataAdapter.SelectCommand = command;

                dataSet.Tables.Clear();
                dataAdapter.Fill(dataSet, "Jucatori");
                dataGridView1.AutoGenerateColumns = true; // Ensure auto-generate columns is enabled
                dataGridView1.DataSource = dataSet.Tables["Jucatori"];
                conn.Close();
                dataGridView1.Columns["nume_echipa"].HeaderText = "Nume Echipa";
                textBox3.Text = numeEchipa;
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            { 
                int idJucator = Convert.ToInt32(dataGridView1.Rows[e.RowIndex].Cells["id_jucator"].Value);
                string numeJucator = dataGridView1.Rows[e.RowIndex].Cells["nume_juc"].Value.ToString();
                string prenumeJucator = dataGridView1.Rows[e.RowIndex].Cells["prenume_juc"].Value.ToString();
                string numeEchipa = dataGridView1.Rows[e.RowIndex].Cells["nume_echipa"].Value.ToString();
                textBox1.Text = numeJucator;
                textBox2.Text = prenumeJucator;
                textBox3.Text = numeEchipa;
                textBox3.ReadOnly = true;
                textBox4.Text = idJucator.ToString();

            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox3.ReadOnly)
            {
                try
                {
                    conn.Open();
                    string updateQuery = "UPDATE Jucatori SET nume_juc = @nume_juc, prenume_juc = @prenume_juc WHERE id_jucator=@id_jucator";
                    dataAdapter.UpdateCommand = new SqlCommand(updateQuery, conn);
                    dataAdapter.UpdateCommand.Parameters.Add("@nume_juc", SqlDbType.VarChar).Value = textBox1.Text;
                    dataAdapter.UpdateCommand.Parameters.Add("@prenume_juc", SqlDbType.VarChar).Value = textBox2.Text;
                    dataAdapter.UpdateCommand.Parameters.Add("@id_jucator", SqlDbType.Int).Value = Convert.ToInt32(textBox4.Text);
                    dataAdapter.UpdateCommand.ExecuteNonQuery();
                    MessageBox.Show("Jucator modificat cu succes!");
                    conn.Close();
                    dataSet.Tables.Clear();
                    dataAdapter.Fill(dataSet, "Jucatori");
                    dataGridView1.DataSource = dataSet.Tables["Jucatori"];
                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";
                    textBox3.ReadOnly = false;
                    textBox4.Text = "";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    conn.Close();
                }
            }
            else
            {
                MessageBox.Show("Alegeti un jucator pentru a-l modifica!");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox3.ReadOnly)
            {
                try
                {
                    string deleteQuery = "DELETE FROM Jucatori WHERE nume_juc = @nume_juc AND prenume_juc = @prenume_juc";
                    conn.Open();
                    dataAdapter.DeleteCommand = new SqlCommand(deleteQuery, conn);
                    dataAdapter.DeleteCommand.Parameters.Add("@nume_juc", SqlDbType.VarChar).Value = textBox1.Text;
                    dataAdapter.DeleteCommand.Parameters.Add("@prenume_juc", SqlDbType.VarChar).Value = textBox2.Text;
                    dataAdapter.DeleteCommand.ExecuteNonQuery();
                    MessageBox.Show("Jucator sters cu succes!");
                    conn.Close();
                    dataSet.Tables.Clear();
                    dataAdapter.Fill(dataSet, "Jucatori");
                    dataGridView1.DataSource = dataSet.Tables["Jucatori"];
                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";
                    textBox3.ReadOnly = false;
                    textBox4.Text = "";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    conn.Close();

                }
            }
            else
            {
                MessageBox.Show("Alegeti un jucator din tabel pentru a-l sterge!!");
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
