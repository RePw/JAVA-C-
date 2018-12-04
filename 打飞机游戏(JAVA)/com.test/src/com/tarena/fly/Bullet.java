package com.tarena.fly;

import java.awt.image.BufferedImage;

/**
 * 子弹类:是飞行物
 */
public class Bullet extends FlyingObject {
	private int speed = 3;  //移动的速度
	
	/** 初始化数据 */
	public Bullet(int x,int y){
		this.x = x;
		this.y = y;
		this.image = ShootGame.bullet;
	}
	public Bullet(int x,int y,BufferedImage xBufferedImage){
		this.x = x;
		this.y = y;
		this.image = xBufferedImage;
	}

	/** 移动 */
	@Override
	public void step(){   
		y-=4*speed;
	}

	/** 越界处理 */
	@Override
	public boolean outOfBounds() {
		return y<-height;
	}

}