using Calculator.Enums;
using Calculator.Exceptions;
using Calculator.Interfaces;

namespace Calculator.Services
{
    internal class MultiplyOperation : IOperation
    {
        private readonly string _operationName = Operations.Mul.ToString();

        public double Call(params double[] args)
        {
            if(args.Length < 2)
            {
                throw new ArgumentOperationException(_operationName);
            }

            double result = 1.0;

            foreach(var arg in args)
            {
                result *= arg;
            }

            return result;
        }
    }
}
