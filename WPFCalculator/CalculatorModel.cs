using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace WPFCalculator
{
    public class CalculatorModel : INotifyPropertyChanged
    {
        private string displayContentValue = string.Empty;
        private string operationValue = string.Empty;

        public string DisplayContent
        {
            get => displayContentValue;
            set
            {
                if (value != displayContentValue)
                {
                    displayContentValue = value;
                    NotifyPropertyChanged();
                }
            }
        }
        public string Operation
        {
            get => operationValue;
            set
            {
                if (value != operationValue)
                {
                    operationValue = value;
                    NotifyPropertyChanged();
                }
            }
        }

        internal bool Any(Func<object, bool> p)
        {
            throw new NotImplementedException();
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void NotifyPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }

}
