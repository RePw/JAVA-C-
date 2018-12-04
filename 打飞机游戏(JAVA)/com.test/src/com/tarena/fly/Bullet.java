package com.tarena.fly;

import java.awt.image.BufferedImage;

/**
 * �ӵ���:�Ƿ�����
 */
public class Bullet extends FlyingObject {
	private int speed = 3;  //�ƶ����ٶ�
	
	/** ��ʼ������ */
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

	/** �ƶ� */
	@Override
	public void step(){   
		y-=4*speed;
	}

	/** Խ�紦�� */
	@Override
	public boolean outOfBounds() {
		return y<-height;
	}

}