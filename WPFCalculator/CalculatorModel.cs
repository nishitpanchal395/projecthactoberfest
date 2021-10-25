using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace WPFCalculator
{
    public class CalculatorModel : INotifyPropertyChanged
    {
        private string displayContentValue = string.Empty;

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

        public event PropertyChangedEventHandler PropertyChanged;
        private void NotifyPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }

}
