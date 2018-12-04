package com.tarena.fly;

import java.util.Random;

/**
 * �зɻ�: �Ƿ����Ҳ�ǵ���
 */
public class Airplane extends FlyingObject implements Enemy {
	private int speed = 3;  //�ƶ�����
	public int airplaneIndex = 1;
	
	/** ��ʼ������ */
	public Airplane(){
		this.image = ShootGame.airplane;
		width = image.getWidth();
		height = image.getHeight();
		y = -height;          
		Random rand = new Random();
		x = rand.nextInt(ShootGame.WIDTH - width);
	}
	
	public Airplane(int xx,int yy){
		this.image = ShootGame.bossShots;
		width = image.getWidth();
		height = image.getHeight();
		y = yy;
		x = xx;
	}
	
	/** ��ȡ���� */
	@Override
	public int getScore() {  
		return 5;
	}

	/** //Խ�紦�� */
	@Override
	public 	boolean outOfBounds() {   
		return y>ShootGame.HEIGHT;
	}
	
	public void setAirplaneIndex(int airplaneIndex) {
		this.airplaneIndex = airplaneIndex;
	}

	/** �ƶ� */
	@Override
	public void step() {   
		y += airplaneIndex*speed;
	}

}