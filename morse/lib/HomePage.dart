import 'package:flutter/material.dart';
import 'package:morse/EngToMorse.dart';
// import 'dart:js_util';


class MyHomePage extends StatefulWidget {
  const MyHomePage({ Key? key }) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      
      appBar: 
      AppBar(
        elevation: 5,
        title: Text("Morse Coder Decoder", style: TextStyle(color: Colors.black, fontSize: 30,fontWeight: FontWeight.bold), ),
        backgroundColor: Color(0xffFFE5B4),
      ),

     body: Container(
       height: double.infinity,
       width: double.infinity,
       color: Colors.amber.shade200,
       padding: EdgeInsets.all(20),
       child: Container(
         padding: EdgeInsets.all(20),
          // color: Colors.amber.shade500,
          decoration: BoxDecoration(
            color: Colors.amber.shade500,
            borderRadius: BorderRadius.all(Radius.circular(8))
          ),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  ElevatedButton(onPressed: (){
                    Navigator.push(context,
                    MaterialPageRoute(builder: (context) => EngToMorse()));
                  },
                  style: ButtonStyle(
              backgroundColor: MaterialStateProperty.all(Color(0xffFFE5B4)),
              padding: MaterialStateProperty.all(EdgeInsets.all(10)),
            ),
                  // padding : EdgeInsets.all(10)
                   child:
                          Text("English\n    to\n Morse",
                          style: TextStyle(
                            fontSize: 30,
                            fontWeight: FontWeight.bold,
                            color: Colors.black
                          ),
                          ),
                          // padding : EdgeInsets.all(10)
                           
                   ),

                  ElevatedButton(onPressed: (){
                     Navigator.push(context,
                    MaterialPageRoute(builder: (context) => EngToMorse()));
                 
                  },
                  style: ButtonStyle(
              backgroundColor: MaterialStateProperty.all(Color(0xffFFE5B4)),
              padding: MaterialStateProperty.all(EdgeInsets.all(10)),
            ),
                  // padding : EdgeInsets.all(10)
                   child:
                          Text(" Morse\n    to\nEnglish",
                          style: TextStyle(
                            fontSize: 30,
                            fontWeight: FontWeight.bold,
                            color: Colors.black
                          ),
                          ),
                          // padding : EdgeInsets.all(10)
                           
                   ),
                ],
              )
            ],
          )
       ),
     ),
    );
  }
}