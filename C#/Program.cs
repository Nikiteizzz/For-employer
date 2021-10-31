using System;
using System.Data.SqlClient;
using System.Threading.Tasks;
using Microsoft.SqlServer.Server;

namespace NewAuthoriz
{
    class Program
    {
        struct User
        {
            public string login;
            public string password;
            public int role;
            public int idInDb;
        }
        static void Main(string[] args)
        {
            User curr_user;
            curr_user.role = -1;
            string connectionString = "Server=(local)\\SQLEXPRESS;Database=UserData;Trusted_Connection=True;";
            string buff_login, buff_password;
            bool flag = true;
            using (SqlConnection connector = new SqlConnection(connectionString))
            {
                connector.Open();
                Console.WriteLine("Подкоючение открыто!");
                while (flag)
                {
                    SqlCommand command = new SqlCommand("SELECT * FROM tab", connector);
                    SqlDataReader reader = command.ExecuteReader();
                    if (reader.HasRows)
                    {
                        Console.Write("Введите логин: ");
                        curr_user.login = Console.ReadLine();
                        Console.Write("Введите пароль: ");
                        curr_user.password = Console.ReadLine();
                        while (reader.Read() && curr_user.role < 0)
                        {
                            buff_login = reader.GetValue(0).ToString();
                            buff_password = reader.GetValue(1).ToString();
                            if (curr_user.login == buff_password && curr_user.password == buff_password)
                            {
                                curr_user.login = buff_login;
                                curr_user.password = buff_password;
                                curr_user.role = Convert.ToInt32(reader.GetValue(2));
                                curr_user.idInDb = Convert.ToInt32(reader.GetValue(3));
                                Console.WriteLine("Успешно!");
                                flag = false;
                            }
                        }
                        if(curr_user.role == -1)
                        {
                            Console.WriteLine("Ошибка! Проверьте правильность логина и пароля!");
                        }
                    }
                    else
                    {
                        Console.WriteLine("В базе нет данных(");
                        flag = false;
                    }
                    reader.Close();
                }
            }
            Console.ReadLine();
        }
    }
}
