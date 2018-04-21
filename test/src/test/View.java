package test;

public class View {
	Model model;
	
	public View(Model model) {
		this.model = model;
	}
	
	public void string() {
		System.out.println(this.model.getA());
	}
}
