using Calculator.Enums;
using Calculator.Exceptions;
using Calculator.Interfaces;

namespace Calculator.Services
{
    internal class AddOperation : IOperation
    {
        private readonly string _operationName = Operations.Add.ToString();

        public double Call(params double[] args)
        {
            if(args.Length < 2)
            {
                throw new ArgumentOperationException(_operationName);
            }

            double result = 0;

            foreach(var arg in args)
            {
                result += arg;
            }

            return result;
        }
    }
}
