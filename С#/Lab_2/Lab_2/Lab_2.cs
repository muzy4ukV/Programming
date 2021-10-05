using System;

namespace Lab_2
{
    class Lab_2
    {
        static void Main(string[] args)
        {
            Console.Write("Write X value: ");
            double x = Convert.ToDouble(Console.ReadLine());
            Console.Write("Write A value: ");
            double A = Convert.ToDouble(Console.ReadLine());
            double y;
            if (x < 0)
            {
                y = x;
            }
            else
            {
                y = A;
            }
            Console.WriteLine($"y:= {y}");
        }
    }
}
