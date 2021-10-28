using System.Data;
using System.Windows;

namespace WPFCalculator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private CalculatorModel model;
        public MainWindow()
        {
            model = new CalculatorModel();
            DataContext = model;
            InitializeComponent();
        }

        private void Btn_seven_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "7";
        }

        private void Btn_eight_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "8";
        }

        private void Btn_nine_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "9";
        }

        private void Btn_multiply_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += " x ";
        }

        private void Btn_four_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "4";
        }

        private void Btn_five_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "5";
        }

        private void Btn_six_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "6";
        }

        private void Btn_minus_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += " - ";
        }

        private void Btn_one_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "1";
        }

        private void Btn_two_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "2";
        }

        private void Btn_three_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "3";
        }

        private void Btn_plus_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += " + ";
        }

        private void Btn_zero_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += "0";
        }

        private void Btn_coma_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent += ",";
        }

        private void Btn_equal_Click(object sender, RoutedEventArgs e)
        {
            var result = ComputeOperation(model.DisplayContent);
            model.DisplayContent += $" = {result}";
        }

        private void Btn_clear_Click(object sender, RoutedEventArgs e)
        {
            model.DisplayContent = string.Empty;
        }

        private static string ComputeOperation(string value)
        {
            return new DataTable().Compute(value.Replace("x", "*"), null).ToString();
        }
    }
}
