using invoke;
using System;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            A a = new A(5);

            Console.Write("A(5).someMethod(6): ");
            Console.WriteLine(a.someMethod(6));
            D d = new D(new B(), new C());
            Console.Write("D(new B(), new C()).method(5): ");
            Console.WriteLine(d.method(5));
            try
            {
                Console.WriteLine(d.method(30));
            }
            catch (ModuleException ex)
            {
                Console.Write("An exception with code: ");
                Console.WriteLine(ex.Code);
            }
            Console.ReadKey();
        }
    }
}
