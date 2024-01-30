using Calculator.Interfaces;
using Calculator.Services;

namespace Calculator
{
    internal class Calculator
    {
        private Dictionary<string, IOperation> operations = new Dictionary<string, IOperation>(StringComparer.OrdinalIgnoreCase)
        {
            ["add"] = new AddOperation(),
            ["sub"] = new SubtractOperation(),
            ["mul"] = new MultiplyOperation(),
            ["div"] = new DivideOperation()
        };

        public Calculator()
        { }

        public void Run()
        {
            while(true)
            {
                Console.Write("op: ");
                string operation = Console.ReadLine()!.ToLower();

                if(operations.TryGetValue(operation, out IOperation op))
                {
                    Console.Write("args: ");
                    string[] argStrings = Console.ReadLine()!
                                                .Split(new char[] { ' ', '\t' },
                                                        StringSplitOptions.RemoveEmptyEntries);

                    double[] args = new double[argStrings.Length];

                    for(int i = 0; i < argStrings.Length; i++)
                    {
                        if(!double.TryParse(argStrings[i], out args[i]))
                        {
                            Console.WriteLine("Invalid argument: " + argStrings[i]);
                            break;
                        }
                    }

                    try
                    {
                        double result = op.Call(args);
                        Console.WriteLine("Result: " + result);
                    }
                    catch(Exception ex)
                    {
                        Console.WriteLine("Error: " + ex.Message);
                    }
                }
                else
                {
                    Console.WriteLine("Unknown operation: " + operation);
                }
            }
        }
    }
}
