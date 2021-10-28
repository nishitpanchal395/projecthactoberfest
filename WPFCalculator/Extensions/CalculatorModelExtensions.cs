using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace WPFCalculator.Extensions
{
    public static class CalculatorModelExtensions
    {
        public static void AssignValue(this CalculatorModel model, string valueDisplay, string valueOperation = "")
        {
            model.DisplayContent += valueDisplay;

            if (!string.IsNullOrWhiteSpace(valueOperation))
                model.Operation += valueOperation;
            else
                model.Operation += valueDisplay;

        }

        public static void ClearValue(this CalculatorModel model)
        {
            model.DisplayContent = string.Empty;
            model.Operation = string.Empty;
        }

        public static string ComputeOperation(this CalculatorModel value)
        {
            var inputValue = value.Operation;
            var valueToCompute = inputValue;

            var primaryOperatorRegex = new Regex("[\\+\\-\\/\\*]");
            var sqrtOperatorRegex = new Regex("\\^2");

            if (sqrtOperatorRegex.IsMatch(inputValue))
            {
                var inputForPow = inputValue.Split("^2").ToList();
                var outputPow = new List<string>();
                for (int i = 0; i < inputForPow.Count; i++)
                {
                    var item = inputForPow[i];
                    if (string.IsNullOrWhiteSpace(item))
                        continue;

                    if (i == inputForPow.Count - 1)
                    {
                        outputPow.Add(item);
                        continue;
                    }

                    if (primaryOperatorRegex.IsMatch(item))
                    {
                        var subValueRegex = new Regex("[0-9]*$");

                        var tempMember = subValueRegex.Match(item).Value;
                        var tempValue = Math.Pow(Convert.ToDouble(tempMember), 2).ToString();

                        outputPow.Add($"{item.Substring(0, item.Length - tempMember.Length)}{tempValue}");
                    }
                    else
                    {
                        outputPow.Add(Math.Pow(Convert.ToDouble(item), 2).ToString());
                    }
                }

                valueToCompute = string.Concat(outputPow);
            }

            return new DataTable().Compute(valueToCompute, null).ToString();
        }

        public static CalculatorModel SanitizeBeforeCoumpute(this CalculatorModel value)
        {
            if (!string.IsNullOrWhiteSpace(value.Operation))
                return value;

            value.Operation = value.DisplayContent.Replace("²", "^2").Replace("x", "*");
            return value;
        }
    }
}
