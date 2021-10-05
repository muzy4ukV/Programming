using System;

namespace Lab_1
{
    class Lab_1
    {
        static void Main()
        {
            Console.WriteLine("Введіть  координату x першої вершини:");    // вводимо дані
            int x1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введіть  координату y першої вершини:");
            int y1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введіть  координату x другої вершини:");
            int x2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введіть  координату y другої вершини:");
            int y2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введіть  координату x третьої вершини:");
            int x3 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введіть  координату y третьої вершини:");
            int y3 = Convert.ToInt32(Console.ReadLine());

            double dist1 = Math.Sqrt((Math.Pow((x2 - x1), 2)) + (Math.Pow((y2 - y1), 2))); // обраховуємо довжину сторін
            double dist2 = Math.Sqrt((Math.Pow((x3 - x2), 2)) + (Math.Pow((y3 - y2), 2)));
            double dist3 = Math.Sqrt((Math.Pow((x3 - x1), 2)) + (Math.Pow((y3 - y1), 2)));

            double perimeter = dist1 + dist2 + dist3; // обраховуємо периметр
            double pivper = perimeter / 2;
            double TriangleArea = Math.Sqrt(pivper * (pivper - dist1) * (pivper - dist2) * (pivper - dist3)); // обраховуємо площу

            Console.WriteLine($"Периметр: {perimeter} Площа{TriangleArea}"); // виводимо результат

        }
    }
}
