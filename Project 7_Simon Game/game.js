var buttonColours = ["red", "blue", "green", "yellow"];

var gamePattern = [];
var userClickedPattern = [];

var started1 = false;
var started2 = false;
var level = 0;

$(".start").click(function () {
 if (!started2)
 {
  nextSequence();
  started2 = true;
 }
});

$(document).keypress(function ()
{
 if (!started1)
 {
  nextSequence();
  started1 = true;
 }
});

$(".btn").on("click", function (event)
{
 var userChosenColour = event.target.id;
 playSound(userChosenColour);
 animatePress(userChosenColour);
 userClickedPattern.push(userChosenColour);
 checkAnswer(userClickedPattern.length - 1);
});

function checkAnswer(currentLevel)
{
 var totalGamePatternLength = gamePattern.length - 1;

 if (userClickedPattern[currentLevel] === gamePattern[currentLevel])
 {
  if (currentLevel === totalGamePatternLength)
  {
   setTimeout(function () {
    nextSequence();
   }, 1000);
   userClickedPattern = [];
  }
 }
 else
 {
  playSound("wrong");

  $("body").addClass("game-over");
  setTimeout(function () {
   $("body").removeClass("game-over");
  }, 200)

  $("h1").text("Game Over, Press any Key to Restart");


  startOver();
 }
}

function nextSequence()
{
 level++;
 $("h1").text("Level " + level);
 var randomNumber = Math.floor(Math.random() * 4);
 var randomChosenColour = buttonColours[randomNumber];
 gamePattern.push(randomChosenColour);

 $("#" + randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);
 var audio = new Audio("sounds/" + randomChosenColour + ".mp3");
 audio.play();
}

function playSound(name)
{
 var audio = new Audio("sounds/" + name + ".mp3");
 audio.play();
}

function animatePress(currentColour)
{
 $("." + currentColour).addClass("pressed");

 setTimeout(function () {
  $("." + currentColour).removeClass("pressed");
 }, 100); 
}

function startOver()
{
 level = 0;
 gamePattern = [];
 userClickedPattern = [];
 started1 = false;
 started2 = false;
}