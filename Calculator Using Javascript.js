<html lang="en">
<head>
    <meta charset="utf-8">
    <title>JavaSctipt Calculator</title>
    <meta name="viewport" content="width=device-width, initial-scale=1"/>
    <link rel="stylesheet" href="style.css"/>
</head>
<body>
    <div class="container">
        <form name="calculatorForm">
            <div class="resultscreen">
                <div class="heading">Live Calculator</div>
                <input type="text" name="evalresult"/>
            </div>
            <div class="buttons">
                <div class="line">
                    <input type="button" name="inpButton7" value="7" onClick="fullCalc(inpButton7.value)"/>
                    <input type="button" name="inpButton8" value="8" onClick="fullCalc(inpButton8.value)"/>
                    <input type="button" name="inpButton9" value="9" onClick="fullCalc(inpButton9.value)"/>
                    <input type="button" name="inpButtondivision" value="/" onClick="fullCalc(inpButtondivision.value)"/>
                </div>
                
                <div class="line">
                    <input type="button" name="inpButton4" value="4" onClick="fullCalc(inpButton4.value)"/>
                    <input type="button" name="inpButton5" value="5" onClick="fullCalc(inpButton5.value)"/>
                    <input type="button" name="inpButton6" value="6" onClick="fullCalc(inpButton6.value)"/>
                    <input type="button" name="inpButtonmultiply" value="*" onClick="fullCalc(inpButtonmultiply.value)"/>
                </div>
                
                <div class="line">
                    <input type="button" name="inpButton1" value="1" onClick="fullCalc(inpButton1.value)"/>
                    <input type="button" name="inpButton2" value="2" onClick="fullCalc(inpButton2.value)"/>
                    <input type="button" name="inpButton3" value="3" onClick="fullCalc(inpButton3.value)"/>
                    <input type="button" name="inpButtonsubtract" value="-" onClick="fullCalc(inpButtonsubtract.value)"/>
                </div>
                
                <div class="line">
                    <input type="button" name="inpButton0" value="0" onClick="fullCalc(inpButton0.value)"/>
                    <input type="button" name="inpButtonDot" value="." onClick="fullCalc(inpButtonDot.value)"/>
                    <input type="button" name="inpButtonAddition" value="+" onClick="fullCalc(inpButtonAddition.value)"/>
                    <input type="button" name="result" value="=" onClick="evalresult.value=eval(evalresult.value)"/>
                </div>
            </div>
        </form>
    </div>

    <script src="script.js"></script>
</body>
</html>
