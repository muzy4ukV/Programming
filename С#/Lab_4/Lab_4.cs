using System;

namespace Lab_4
{
    class Lab_4
    {
        static void Main(string[] args)
        {
            Console.Write("Enter n: ");                          //Ініацілізація змінних
            int n = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter a: ");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter b: ");
            double b = Convert.ToDouble(Console.ReadLine());
            double ri = 0;
            double[] rn = new double[n];                     //Створення масиву для запису послідовності
            double h = (b - a) / n;
            for (int i = 1; i <= n; i++)                         //Обрахування членів послідовності і їх запис у масив
            {
                ri = a + (i * h);
                rn[i - 1] = ri;
            }
            foreach (double v in rn)                             //Виведення масиву
            {
                Console.Write(v.ToString() + " ");
            }
        }
    }
}
