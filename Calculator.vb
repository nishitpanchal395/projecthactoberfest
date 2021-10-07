Option Explicit On
Option Strict On

Public Structure Calculator
    Private _a As Double
    Private _b As Double

    Public Property a() As Double
        Get
            Return _a
        End Get
        Set(value As Double)
            _a = value
        End Set
    End Property

    Public Property b() As Double
        Get
            Return _b
        End Get
        Set(value As Double)
            _b = value
        End Set
    End Property

    Public Function Add() As Double
        Return _a + _b
    End Function

    Public Function Subtract() As Double
        Return _a - _b
    End Function

    Public Function Multiply() As Double
        Return _a * _b
    End Function

    Public Function Divide() As Double
        Return _a / _b
    End Function
End Structure