package test;

import java.util.Observable;

public class Model extends Observable {
	
	private int a;
	
	public Model () {
		this.a = 0;
	}
	
	public int getA() {
		return this.a;
	}
	
	public void increment() {
		for (int i = 0; i < 100; i++) {
			this.a++;
			setChanged();
			notifyObservers();
		}
	}
}
