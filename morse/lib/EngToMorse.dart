// import 'dart:js_util';

import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;


late Map dataResponse;
late Map mapResponse;
String finalResponse='';
class EngToMorse extends StatefulWidget {
  
  const EngToMorse({ Key? key }) : super(key: key);
    // late Map dataResponse;
  @override
  _EngToMorseState createState() => _EngToMorseState();
}

class _EngToMorseState extends State<EngToMorse> {
  // late Map dataResponse;
  apiCall() async {
    http.Response response;
    response= await http.get(Uri.parse("https://api.funtranslations.com/translate/morse.json?text=$englishText"));

    if(response.statusCode == 200){
      setState(() {
        var mapResponse = json.decode(response.body);
        var dataResponse = mapResponse['contents'];
        finalResponse= dataResponse['translated'].toString();
      });
    
    }else{
      setState(() {
        finalResponse="Unable to fetch data";
      });
      
    }
  }
  @override
  String englishText="";

  Widget build(BuildContext context) {
    return Scaffold(
       appBar: 
      AppBar(
        iconTheme: IconThemeData(
          color: Colors.black,
        ),
        elevation: 5,
        title: Text("English to Morse", style: TextStyle(color: Colors.black, fontSize: 30,fontWeight: FontWeight.bold), ),
        backgroundColor: Color(0xffFFE5B4),
      ),

      body:
      Container(
        height: double.infinity,
       width: double.infinity,
       color: Colors.amber.shade200,
       padding: EdgeInsets.all(20),
       child: Column(
         mainAxisAlignment: MainAxisAlignment.center,
         children: [

           Container(
             margin: EdgeInsets.all(10),
             child: TextField(
               obscureText: false,
               decoration: new InputDecoration(
                 hintText: "Enter your sentence here",
                 contentPadding: EdgeInsets.all(5)
               ),
               onChanged: (String text){
                 setState(() {
                   englishText=text;
                 });
                 }
             ),
           ),

            Container(
             child: 
             ElevatedButton(onPressed: (){
               apiCall();
             }, child: Text("Translate")),
            ),

            Container(
              child:
              Text(finalResponse, style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),)
            )
         ],
       ),
      )
    );
  }
}