namespace Calculator.Exceptions
{
    internal class ArgumentOperationException : ArgumentException
    {
        public ArgumentOperationException(string operationName)
            : base(operationName.ToUpper() + " requires at least two arguments")
        {
        }
    }
}
