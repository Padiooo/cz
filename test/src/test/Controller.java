package test;

import java.util.Observable;
import java.util.Observer;

public class Controller implements Observer {
	
	private Model model;
	private View myView;
	public Controller (Model model, View myView) {
		this.model = model;
		this.myView = myView;
		this.model.addObserver(this);
		this.model.increment();		
	}
	
	@Override
	public void update(Observable o, Object arg) {
		this.myView.string();
	}
		
}
