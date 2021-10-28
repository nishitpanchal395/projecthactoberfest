using System.Data;
using System.Windows;
using WPFCalculator.Extensions;

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
            model.AssignValue("7");
        }

        private void Btn_eight_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("8");
        }

        private void Btn_nine_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("9");
        }

        private void Btn_multiply_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("x", "*");
        }

        private void Btn_square_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("²", "^2");
        }

        private void Btn_four_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("4");
        }

        private void Btn_five_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("5");
        }

        private void Btn_six_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("6");
        }

        private void Btn_minus_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("-");
        }

        private void Btn_one_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("1");
        }

        private void Btn_two_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("2");
        }

        private void Btn_three_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("3");
        }

        private void Btn_plus_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("+");
        }

        private void Btn_zero_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue("0");
        }

        private void Btn_coma_Click(object sender, RoutedEventArgs e)
        {
            model.AssignValue(",");
        }

        private void Btn_equal_Click(object sender, RoutedEventArgs e)
        {
            var result = model.SanitizeBeforeCoumpute().ComputeOperation();
            model.DisplayContent += $" = {result}";
        }

        private void Btn_clear_Click(object sender, RoutedEventArgs e)
        {
            model.ClearValue();
        }

        private void Btn_delete_Click(object sender, RoutedEventArgs e)
        {
            if (model.DisplayContent.Length <= 0 || model.Operation.Length <= 0)
                return;

            model.DisplayContent = model.DisplayContent[0..^1];
            model.DisplayContent = model.Operation[0..^1];
        }

        private void Btn_exit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
