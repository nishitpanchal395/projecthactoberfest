let isSpinning =true;
const fix = () =>{
  document.querySelector('.zdog-canvas').height = window.innerHeight;
  document.querySelector('.zdog-canvas').width = window.innerWidth;
}
fix();
window.addEventListener('resize',fix);



let illo = new Zdog.Illustration({
  element:'.zdog-canvas',
  dragRotate: true,
    onDragStart: function() {
    isSpinning = false;
  },
});
let ellipsy = new Zdog.Ellipse({
  addTo: illo,
  width: 40,
  height: 200,
  // diameter: 30,
  stroke: 10,
  color: '#646',

  translate: {z:200},
  fill: true,

});

new Zdog.Rect({
addTo: ellipsy,
width: 140,
height: 40,
stroke: 12,
translate:{z:10},
color: '#E62',
fill: true,
})

let semicircle = new Zdog.Ellipse({
  addTo: illo,
  diameter: 80,
  quarters: 2,
  stroke: 20,
  color: '#C25',
});

// const animate = () =>{
//   if(isSpinning){
//   illo.rotate.y -= 0.03;
//   ellipsy.rotate.x += 0.04;
  
//   }
//   illo.updateRenderGraph();
//   requestAnimationFrame(animate);
// }
// animate();

illo.updateRenderGraph();
window.addEventListener('mousemove',(e)=>{
  console.log(e);
  illo.rotate.y = 0.01*e.screenX;
  illo.rotate.x = 0.01*e.screenY;
  // illo.rotate.x = 0.1*e.clientX;
  illo.updateRenderGraph();
})

