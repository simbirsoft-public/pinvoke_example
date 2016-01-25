using invoke;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            A a = new A(5);
            System.Console.WriteLine(a.someMethod(6));
            System.Console.ReadKey();
        }
    }
}
