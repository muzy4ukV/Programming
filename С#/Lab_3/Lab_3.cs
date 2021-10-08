using System;

namespace Lab_3
{
    class Lab_3
    {
        static void Main(string[] args)
        {
            Console.Write("Enter accuracy: ");
            double accuracy = Convert.ToDouble(Console.ReadLine());
            double e = 1;
            int i = 0;
            int fact = 1;
            double current = 0;
            do
            {
                e += current;
                i += 1;
                fact *= i;
                current = 1.0 / fact;
            } while (current > accuracy);

            Console.WriteLine($"e = {e}");
        }
    }
}
