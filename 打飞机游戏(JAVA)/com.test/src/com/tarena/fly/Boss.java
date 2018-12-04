package com.tarena.fly;

public class Boss extends FlyingObject{
	public int life;
	private int xspeed = 1;
	public Boss() {
		life = 500;
		image = ShootGame.boss;
		width = image.getWidth();
		height = image.getHeight();
		x = 150;
		y = 40;
		// TODO Auto-generated constructor stub
	}
	@Override
	public boolean outOfBounds() {
		return y>ShootGame.HEIGHT;
		// TODO Auto-generated method stub
	}

	@Override
	public void step() {
		if(xspeed>0)
			x += xspeed;
		else if(xspeed<0)
			x += xspeed;
		
		if(x > ShootGame.WIDTH-width){  
			xspeed = -1;
		}
		if(x < 0){
			xspeed = 1;
		}
		// TODO Auto-generated method stub
	
	}
	
//	public void setLife(int tlife) {
//		this.life = tlife;
//	}
	public Airplane[] bossShoot() {
		int xStep = width/3;      //4°ë
		int yStep = 100;  //²½
		Airplane[] airplanes = new Airplane[3];
		airplanes[0] = new Airplane(x+xStep-65,y+yStep); 
		airplanes[1] = new Airplane(x+2*xStep-65,y+yStep);
		airplanes[2] = new Airplane(x+3*xStep-65,y+yStep);
		airplanes[0].setAirplaneIndex(2);
		airplanes[1].setAirplaneIndex(2);
		airplanes[2].setAirplaneIndex(2);
		return airplanes;
		}
	}
