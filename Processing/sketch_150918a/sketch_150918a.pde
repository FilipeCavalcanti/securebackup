float rand;

void setup(){
 size(620,480,P3D); 
}

void draw(){
 background(255,255,255);
 translate(310,240,0);  
 rand=random(360); 
 rotateY(rand);
 println(rand);
 fill(0,0,255);
 box(200,200,200);
 delay(50);
}