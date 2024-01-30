using Calculator.Enums;
using Calculator.Exceptions;
using Calculator.Interfaces;

namespace Calculator.Services
{
    internal class SubtractOperation : IOperation
    {
        private readonly string _operationName = Operations.Sub.ToString();

        public double Call(params double[] args)
        {
            if(args.Length < 2)
            {
                throw new ArgumentOperationException(_operationName);
            }

            double result = args[0];

            foreach(double arg in args.Skip(1))
            {
                result -= arg;
            }

            return result;
        }
    }
}
