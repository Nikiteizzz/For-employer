﻿using System;
using System.IO;

namespace authoriz
{
    class Program
    {
        struct User
        {
            public string login;
            public string password;
            public int role;
        }
        static void Main()
        {
            User Curr_user;
            bool flag = true;
            string buffer;
            string[] Buff_data = new string[3];
            while (flag)
            {
                Console.WriteLine("Enter login: ");
                Curr_user.login = Console.ReadLine();
                Console.WriteLine("Enter password: ");
                Curr_user.password = Console.ReadLine();
                Curr_user.role = -1;
                using (StreamReader File = new StreamReader("d:\\accounts.txt"))
                {
                    while (!File.EndOfStream)
                    {
                        buffer = File.ReadLine();
                        Buff_data = buffer.Split();
                        if ((Curr_user.login == Buff_data[0]) && (Curr_user.password == Buff_data[1]))
                        {
                            Curr_user.role = Convert.ToInt32(Buff_data[2]);
                            Console.WriteLine("Success!");
                            flag = false;
                        }
                    }
                }
                if(Curr_user.role == -1)
                {
                    Console.WriteLine("Failed! Check your login or password!");
                }
            }
            Console.ReadLine();
        }
    }
}